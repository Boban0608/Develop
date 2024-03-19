/*
Анаграммы 
Что нужно сделать
Напишите функцию, которая принимает две строки и возвращает true, если первая строка является анаграммой второй (то есть можно 
получить первую строку из второй путём перестановки букв местами), и false иначе. Для достижения хорошей асимптотики 
решения рекомендуется использовать std::map.
Пример анаграммы: лекарство — стекловар
Чек-лист для проверки задачи
Функция принимает корректные типы данных, тип возвращаемого значения — bool.
Функция не использует библиотек, кроме <iostream>, <map>, <string>.
Функция корректно определяет, являются ли строки анаграммами.
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;
void InputDict (map<string, map<char, int>> dict, string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        dict[word][word[i]] = 1;
    }
}
main() 
{
  cout << "----------------\n";
  cout << "Anagram.\n";
  cout << "----------------\n";
  map <string, int> first;
  map <string, int> second;
  while (true)
  {
    cout << "Input 2 word for check anagram or 'q' for exit.\n";
    cout << "Input 1-st word for check: ";
    string input;
    cin >> input;
    if (input == "q") break;
    InputDict(first, input);
    cout << "Input 2-nd word for check: ";
    cin >> input;
    InputDict(dict, input);
    
  }
  return 0;
}