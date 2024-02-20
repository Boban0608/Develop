/*
Разработка программы поиска слов в файле
Что нужно сделать
Составьте небольшой текстовый файл «words.txt», в котором последовательно, через пробелы и 
переносы строк расположены различные слова. Можете использовать любые англоязычные слова. 
Разработайте программу, которая искала бы среди этих слов нужное пользователю и выводила бы 
общее количество повторений этого слова. 0 — если слово вообще не присутствует в файле.
Что оценивается
Корректность работы программы на созданных вами вводных данных. Число найденных слов должно 
соответствовать.
*/
#include <iostream>
#include <fstream>
using namespace std;
main() {
  cout << "----------------\n";
  cout << "Words seaker.\n";
  cout << "----------------\n";
  char word[50], tmp[50];
  ifstream file;
  cout << "Input word you wish to find: \n";
  cin >> word;
  file.open("C:\\mingw64\\Develop\\C++\\Skillbox\\words.txt");
  int count = 0;
  while (!file.eof()){
    file >> tmp;
    for (int i = 0; word[i] != '\0'; i++){
        if (word[i] != tmp[i]) break;
        else if (word[i + 1] == '\0') count ++;
    }
  }
  file.close();
  cout << count << " words find in txt file.\n";
  return 0; 
}