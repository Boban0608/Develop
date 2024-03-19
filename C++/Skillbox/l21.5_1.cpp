/*
Реализация программы чтения ведомости
Что нужно сделать
Реализуйте программу чтения информации из ведомости по учёту выплат. Сама ведомость 
представляет собой следующую таблицу: 
имя и фамилия человека; 
количество денег, которые были выплачены лицу; 
дата выплаты в формате ДД.ММ.ГГГГ.
На основе данных из ведомости следует подсчитать общее количество выплаченных средств и 
определить человека с максимальной суммой выплат.
Пример данных ведомости
Tom Hanks 35500 10.11.2020
Rebecca Williams 85000 1.1.2021
Sally Field 15600 15.8.2021
Michael Humphreys 29400 23.5.2020
Harold Herthum 74300 9.6.2019
George Kelly 45000 12.3.2018
Bob Penny 12500 13.5.2020
John Randall 23400 2.10.2020
Sam Anderson 6500 15.7.2020
Margo Moorer 12350 24.2.2019
Что оценивается
Корректное отображение общей суммы выплат и самого крупного получателя денежных средств.


NEW TASK
Вы уже создавали программу чтения и записи ведомости. Теперь её нужно обобщить и дополнить использованием структур.
Формат ведомости прежний:
сначала — имя и фамилия получателя денег;
далее — дата выдачи в формате ДД.ММ.ГГГГ;
затем — сумма выплаты в рублях.
Данные разделяются пробелами. В конце каждой записи должен быть перевод строки. Структура данных должна соответствовать этому формату.
При старте программы пользователь отправляет команду: list или add. Команда list осуществляет чтение из файла ведомости, как и прежде, 
только уже в структуре данных, и отображает их на экране.
Команда add добавляет новую запись в конец ведомости.
Советы и рекомендации
Чтобы определить, где заканчивается файл, используйте функцию file.eof().
Из-за завершающего переноса строки при чтении данных из файла стоит отдельно прочитать имя получателя денег. Если после чтения имени 
получателя денег признак file.eof() принял значение true — значит, файл закончился.
Используйте вектор структур. Для выбора команды потребуется подобная конструкция:
if (command == "list")
{
…
}
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const string path = "register.txt";
struct Person
{
    string name = "noname";
    string surname = "nosurname";
    int salary = 0;
    string date = "01.01.1900";
};
void TableDisplay()
{
    ifstream reestr(path, ios::binary);
    if(!reestr.is_open())
    {
        cout << "An error opening file! Check the path!\n";
        return;
    }
    int maxMoney = 0, sum = 0;
    string maxName, maxSurname;
    while(!reestr.eof())
    {
        Person person;
        int len;
        reestr.read((char*) &len, sizeof(len));
        person.name.resize(len);
        reestr.read((char*) person.name.c_str(), len);        
        reestr.read((char*) &len, sizeof(len));
        person.surname.resize(len);
        reestr.read((char*) person.surname.c_str(), len);        
        reestr.read((char*) &person.salary, sizeof(person.salary));        
        reestr.read((char*) &len, sizeof(len));
        person.date.resize(len);
        reestr.read((char*) person.date.c_str(), len);
        if (person.salary)
        {
            cout << person.name << " ";
            cout << person.surname << " ";
            cout << person.salary << " ";
            cout << person.date << endl;
        }
        if (maxMoney < person.salary) {
            maxMoney = person.salary;
            maxName = person.name;
            maxSurname = person.surname;
        }
        sum += person.salary;
    }
    reestr.close();
    cout << "----------------\n";
    cout << "Sum payment - " << sum << endl;
    cout << "Max person payment - \n";
    cout << maxName;
    cout << " ";   
    cout << maxSurname;    
    cout << " " << maxMoney << endl;
    cout << "----------------\n";
}
void CheckSalary(Person &person)
{
    while(true)
    {
        cout << "Input person salary: \n";
        cin >> person.salary;
        if (person.salary <= 0 || person.salary > 200000)
        {
            cout << "Wrong input! Salary must be in range from 1 to 200000\n";
        } else break;
    }
}
void CheckDate(Person &person)
{
    while(true)
    {
        cout << "Input payment date: \n";
        cin >> person.date;
        if (person.date.length() != 10)
        {
            cout << "Wrong date length. Date format - DD.MM.YYYY\n";
        }
        int day = stoi(person.date.substr(0, 2));
        int month = stoi(person.date.substr(3,2));
        int year = stoi(person.date.substr(6,4));
        if (year < 1900 || year > 2024)
        {
            cout << "Wrong year! Year rate - 1900-2024\n";
        } else if (month < 1 || month > 12)
        {
            cout << "Invalid month input!\n";
            cout << "It shoud be from 1 to 12\n";
        } else if (day < 1 || (day > 29 && month == 2) 
            || (day > 30 && (month == 4 || month == 6
            || month == 9 || month == 11)) || (day > 31
            && (month == 1 || month == 3 || month == 5
            || month == 7 || month == 8 || month == 10
            || month == 12)))
        {
            cout << "Invalid date input!\n";
            cout << "This mounth don't have such date!\n";
        } else break;
    }
}
void EditTable()
{
    ofstream reestr(path, ios::binary | ios::app);
    Person person;
    cout << "Input person name: \n";
    cin >> person.name;
    cout << "Input person surname: \n";
    cin >> person.surname;
    CheckSalary(person);
    CheckDate(person);
    int len;
    len = person.name.length();
    reestr.write((char*) &len, sizeof(len));
    reestr.write((char*) person.name.c_str(), len);
    len = person.surname.length();
    reestr.write((char*) &len, sizeof(len));
    reestr.write((char*) person.surname.c_str(), len);
    reestr.write((char*) &person.salary, sizeof(person.salary));
    len = person.date.length();
    reestr.write((char*) &len, sizeof(len));
    reestr.write((char*) person.date.c_str(), len);
    reestr.close();
    return;
}
main() 
{
  cout << "----------------\n";
  cout << "Working salary table.\n";
  cout << "----------------\n";
  string input;
  while(true)
  {
    cout << "Enter 'list' for display salary table 'add' for adding data or 'q' for exit: ";
    cin >> input;
    if (input == "list")
    {
        TableDisplay();
    } else if (input == "add")
    {
        EditTable();
    } else if (input == "q")
    {
        cout << "----------------\n";
        cout << "Thank you for using our programm! Bye-bye!!\n";
        cout << "----------------\n";
        break;
    } else
    {
        cout << "Wrong input! Try again. 'List', 'add' or 'q': \n";
    }
  }
  return 0; 
}