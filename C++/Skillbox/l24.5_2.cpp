/*
Реализация программы напоминания о днях рождения
Что нужно сделать
Реализуйте простую программу по вычислению ближайшего дня рождения.
В начале программы пользователь последовательно вводит данные о днях рождения своих 
друзей: вводит имя друга и саму дату рождения полностью, включая месяц и год, в формате 
год/месяц/день. Сигналом окончания ввода дней рождения является “end” введённое в 
качестве имени.
После этого программа вычисляет ближайший день рождения по отношению к текущему времени 
и выводит его на экран вместе с именем в удобном, локальном формате - месяц/день. 
Если день рождения уже был в этом году, данные о пользователе пропускаются. Если у 
кого-то из друзей день рождения сегодня, то в консоль выводится специальное сообщение 
об этом. Учтите, что таких сообщений может быть несколько, ведь сразу несколько людей 
могут иметь дни рождения в один день.
Советы и рекомендации
Для подсчёта ближайшего дня используйте данные из структуры даты std::tm.
Что оценивается
Корректность работы программы.
*/

#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;
struct FriendBirth
{
    string name;
    time_t t = time(nullptr);
    tm* birth = localtime(&t);
    int mounth;
    int day;
};
string ans;
time_t start, finish;
vector <FriendBirth> base;
#define MENU(func) while(ans != "end") {func();}
void GetData ()
{
    FriendBirth current;
    cout << endl;
    cout << "Input friend's name or 'end' for exit:\n";
    getline(cin, current.name);
    cout << "____________________\n";
    if (current.name == "end")
    {
        ans = "end";
    } else
    {
        cout << endl;
        cout << "Input " << current.name << "'s birth in format [dd/mm/yyyy]:\n";
        cin >> get_time(current.birth, "%d/%m/%Y");
        current.mounth = current.birth->tm_mon;
        current.day = current.birth->tm_mday;
        cout << "____________________\n";
        ans = "";
        base.push_back(current);
        cin.get();
    }
}
void GetBirth ()
{
    time_t t = time(nullptr);
    tm local = *localtime(&t);
    string name = base[0].name;
    int minMounth = base[0].mounth;
    int minDay = base[0].day;
    for (int i = 0; i < base.size(); i++)
    {
        if (base[i].mounth >= local.tm_mon)
        {
            if (minMounth > base[i].mounth)
            {
                minMounth = base[i].mounth;
                minDay = base[i].day;
                name = base[i].name;
            } else if (minMounth = base[i].mounth)
            {
                if (minDay > base[i].day)
                {
                    minDay = base[i].day;
                    name = base[i].name;
                }
            }
        }
    }
    cout << endl << "Closest birthday: \n";
        cout << name << " ";
        cout << minDay << "/" << minMounth + 1 << endl << endl;
        if (minMounth == local.tm_mon && minDay == local.tm_mday)
        {
            cout << name << " celebrate birthday today!\n" << endl;
        }
}
main ()
{
    cout << "----------------\n";
    cout << "Birthday.\n";
    cout << "----------------\n"; 
    MENU(GetData);
    cout << endl;
    cout << "Calculate the closest birthday\n";
    cout << "----------------\n";
    GetBirth();
    return 0;
}
