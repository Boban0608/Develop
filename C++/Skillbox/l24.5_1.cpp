/*
Реализация программы учёта времени
Что нужно сделать
Используя функцию получения текущего времени std::time, реализуйте простейший 
менеджер учёта времени.
Пользователь взаимодействует с программой с помощью команд:
Команда begin начинает отслеживание новой задачи. После ввода этой команды 
пользователь должен ввести название задачи, над которой он планирует сейчас 
работать. Если уже была начата какая-то другая задача, предыдущая должна быть 
автоматически завершена и начата новая.
Команда end заканчивает отслеживание текущей задачи. Если текущей начатой задачи 
нет, то команда ничего не делает.
Команда status выводит на экран информацию о всех законченных задачах и времени, 
которое было на них потрачено. Также выводится название текущей выполняемой задачи, 
если таковая имеется.
Команда exit выходит из программы.
Советы и рекомендации
Тип std::time_t принимайте за секунды и с помощью него рассчитывайте время в часах, 
которое было затрачено.
Что оценивается
Корректность работы программ
*/

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
using namespace std;
struct task_state
{
    string task_name;
    double task_time;
};
string ans, task;
bool task_status = false;
time_t start, finish;
vector <task_state> base;
#define MENU(func) while(ans != "quit") {func();}
void GetTitle ()
{
    cout << "____________________\n";
    cout << "Input task title:\n";
    cin.get();
    getline(cin, task);
    cout << "____________________\n";
}
void SetData ()
{
    finish = time(nullptr);
    double gap = difftime(finish, start);
    task_state current;
    current.task_name = task;
    current.task_time = gap;
    base.push_back(current);
}
void Menu()
{
    cout << "Input menu command:\n";
    cout << "- begin - to track new task\n";
    cout << "- end - to finish current task\n";
    cout << "- status - for info about all tasks\n";
    cout << "- quit - for exit programm\n";
    cout << "____________________\n";
    cin >> ans;
    if (ans == "begin")
    {
        if (task_status)
        {
            SetData();
            task_status = true;
            start = time(nullptr);
            GetTitle();
        } else
        {
            task_status = true;
            start = time(nullptr);
            GetTitle();
        }
    } else if (ans == "end")
    {
        task_status = false;
        SetData();
        task = "";
    } else if (ans == "status")
    {
        for (int i = 0; i < base.size(); i++)
        {
            cout << endl << "Task: " << base[i].task_name << endl;
            cout << "Wasted time: " << base[i].task_time / 3600 << " hour"<< endl;
        }
        cout << endl << "Current task: " << task << endl << endl;
    } else if (ans == "quit")
    {
        cout << "____________________\n";
        cout << "Thank you for using our programm!\n";
        cout << "Bye-bye!!\n";
        cout << "____________________\n";
    } else
    {
        cout << "____________________\n";
        cout << "Incorrect input!\n";
        cout << "Try again!\n";
        cout << "____________________\n";
    }
}
main ()
{
    cout << "----------------\n";
    cout << "Time tracking.\n";
    cout << "----------------\n"; 
    MENU(Menu);
    return 0;
}
