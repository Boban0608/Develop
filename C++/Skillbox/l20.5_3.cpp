/*
Симуляция игры «Рыбалка»
Что нужно сделать
Реализуйте простую симуляцию игры в рыбалку. Задание выполните в Google Docs.
В исходном текстовом файле реки (river.txt) задайте список из разных видов рыб, которые можно 
в ней поймать. Рыбок может быть сколько угодно, а виды могут повторяться.
Как должна работать симуляция:
В начале программы пользователь указывает, какую именно рыбу он собирается ловить (её вид). 
После этого из первого файла друг за другом осуществляется чтение его содержимого, вид за видом.
Если на отдельных шагах вид совпал с указанным пользователем, в выходной файл basket.txt 
(корзинка) записывается этот вид.
В конце программы показывается, сколько было поймано рыб за текущую ловлю. 
Программу можно запускать несколько раз, при этом уже пойманные рыбы должны сохраняться в 
файле-корзинке.
Рекомендация
Пример содержания исходного файла:
sunfish
shad
carp
bass
bullhead
carp
walleye
catfish
carp
*/
#include <iostream>
#include <fstream>
using namespace std;
void ResultLog(string &fish){
  string opath = "basket.txt";
  ofstream logging(opath, ios::app);
  while(!logging.is_open()){
    cout << "File save error!\n";
    cout << "Try to input filename manually.\n";
    cin >> opath;
    ofstream logging(opath, ios::app);
  }
  logging << fish << endl;
  logging.close();
}
void Fishing(string &path, string &fish, int &c){
  string tmp;
  ifstream fishing(path);
  while(!fishing.is_open()){
    cout << "File open error!\n";
    cout << "Try to input path manually.\n";
    cin >> path;
    ifstream fishing(path);
  }
  while(!fishing.eof()){
    fishing >> tmp;
    if (tmp == fish){
      c++;
      ResultLog(fish);
    } 
  }
  fishing.close();
}
main() {
  cout << "----------------\n";
  cout << "Fishing simulation\n";
  cout << "----------------\n";
  string ipath = "river.txt";
  string fish;
  int count = 0;
  cout << "Enter fish you want to catch: \n";
  cin >> fish;
  Fishing(ipath, fish, count);
  cout << "You catch " << count << " " << fish << " for the fishing!\n";
  return 0; 
}