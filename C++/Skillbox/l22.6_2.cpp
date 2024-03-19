/*
Регистратура
Что нужно сделать
Напишите программу «Регистратура».
На вход программе приходят строки с фамилиями или строка Next. Пришедшие люди становятся 
в очередь, а по запросу Next необходимо вызвать в регистратуру человека с фамилией, 
идущей первой в лексикографическом порядке (по алфавиту), и вывести его фамилию на экран. 
Фамилии пациентов могут повторяться.
Каждый запрос (на добавление и вывод) должен работать за O(logn).
Пример:
← Sidorov
← Ivanov
← Ivanov
← Petrov
← Next
→ Ivanov
← Next
→ Ivanov
← Next
→ Petrov
Чек-лист для проверки задачи
Программа корректно выводит фамилии в лексикографическом порядке.
Программа использует только заголовочные файлы <iostream>, <string>, <map>. 
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;
void Queue(map <string, string> &regist, string &input)
{
    map <string, string>::iterator it = regist.find(input);
    if (it != regist.end())
    {
        it -> second.push_back('1') ;
    } else 
    {
        regist.insert(make_pair(input, input));
    }
}
void PrintNext (map <string, string> &regist, string &input)
{
    if (regist.begin() -> first != regist.begin() -> second)
    {
        cout << regist.begin() -> first << endl;
        regist.begin() -> second.pop_back();
    } else
    {
        cout << regist.begin() -> first << endl;
        regist.erase(regist.begin());
    }
}
main() 
{
  cout << "----------------\n";
  cout << "Registrator.\n";
  cout << "----------------\n";
  map <string, string> regist;
  while (true)
  {
    string input;
    cin >> input;
    if (input == "Next")
    {
        PrintNext(regist, input);
    } else if (input == "Exit")
    {
        break;
    } else 
    {
        Queue(regist, input);
    }
  }
  return 0;
}