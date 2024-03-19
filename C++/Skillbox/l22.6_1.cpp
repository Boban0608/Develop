/*
Телефонный справочник
Что нужно сделать
Напишите программу «Телефонный справочник».
На вход программе поступают запросы трёх типов:
69-70-30 Ivanov — добавить телефон и фамилию абонента в справочник
69-70-30 — узнать фамилию абонента по номеру телефона
Ivanov — узнать телефон абонента по фамилии 
Необходимо выводить в консоль ответ на запросы 2 и 3. Обратите внимание, что абоненты по 
разным номерам могут иметь одинаковые фамилии. В таком случае на запрос 3 необходимо выдать 
все номера через пробелы. 
Операции запросов должны работать за O(logn) или O(logn × количество номеров с этой фамилией).
Чек-лист для проверки задачи
Программа корректно выводит фамилии и списки номеров.
Программа использует только заголовочные файлы <iostream>, <string>, <map> и, возможно, вектор.
*/
#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;
const string DATABASE_PATH = "phonebook.bin";
void SetData (map <string, string> &phonebook)
{
    string phone, surname;
    cout << "Enter phonebook data in format [000-00-00] [surname]\n";
    cin >> phone >> surname;
    phonebook.insert({phone, surname});
    cout << "_______________________\n";
    cout << "You input data to database: " << phonebook.find(phone) -> first 
    << " " << phonebook.find(phone) -> second << endl;
    cout << "_______________________\n";
    ofstream buffer (DATABASE_PATH, ios::binary | ios::app);
    int len = phonebook.find(phone) -> first.length();
    buffer.write ((char*) &len, sizeof(len));
    buffer.write ((char*) phonebook.find(phone) -> first.c_str(), len);
    len = phonebook.find(phone) -> second.length();
    buffer.write ((char*) &len, sizeof(len));
    buffer.write ((char*) phonebook.find(phone) -> second.c_str(), len);
    buffer.close();
}
void SearchSurname (map <string, string> &phonebook)
{
    string phone;
    cout << "Input phonenumber: ";
    cin >> phone;
    cout << "_______________________\n";
    cout << "Searching in the database ....\n";
    cout << "_______________________\n";
    if (phonebook.find(phone) != phonebook.end())
    {
        cout << "Surname: " << phonebook.find(phone) -> second << endl;
        cout << "_______________________\n";
    } else 
    {
        cout << "Phonenumber " << phone << " is not in the database!\n";
        cout << "_______________________\n";
    }
}
void SearchPhonenumber (map <string, string> &phonebook)
{
    string surname;
    cout << "Input surname: ";
    cin >> surname;
    cout << "_______________________\n";
    cout << "Searching in the database ....\n";
    cout << "_______________________\n";
    cout << "Phonenumber:\n";
    for (map<string, string>::iterator it = phonebook.begin();
        it != phonebook.end(); it++)
    {
        if (it -> second == surname)
        {
            cout << it -> first << " ";
        }
    }
    cout << endl;
    cout << "_______________________\n";
}
void Exit ()
{
    cout << "_______________________\n";
    cout << "Thank you for using our programm\n";
    cout << "Bye-bye!!!\n";
    cout << "_______________________\n";
}
void PhonebookInit (map <string, string> &phonebook)
{
    string phone, surname;
    ifstream buffer(DATABASE_PATH, ios::binary);
    if (buffer.is_open())
    {
        while(true)
        {
            int len;
            buffer.read ((char*) &len, sizeof(len));
            phone.resize(len);
            buffer.read ((char*) phone.c_str(), len);
            buffer.read ((char*) &len, sizeof(len));
            surname.resize(len);
            buffer.read ((char*) surname.c_str(), len);
            if(buffer.eof()) break;
            phonebook.insert ({phone, surname});
        }
    } else
    {
        cout << "Database file is not found!\n";
        cout << "Creating new database.\n";
        cout << "----------------\n";
    }
    buffer.close();
}
main() 
{
  cout << "----------------\n";
  cout << "Phonebook.\n";
  cout << "----------------\n";
  map <string, string> phonebook;
  PhonebookInit(phonebook);
  while (true)
  {
    cout << "Choose menu item:\n";
    cout << "1. For adding record to database\n";
    cout << "2. For search surname by phonenumber\n";
    cout << "3. For search phonenumber by surname\n";
    cout << "4. For exit\n";
    string ans;
    cin >> ans;
    if (ans == "1")
    {
        SetData(phonebook);
    } else if (ans == "2")
    {
        SearchSurname(phonebook);
    } else if (ans == "3")
    {
        SearchPhonenumber(phonebook);
    } else if (ans == "4")
    {
        Exit();
        break;
    } else 
    {
        cout << "Wrong input!! Try again!!\n";
    }
  }
  return 0;
}