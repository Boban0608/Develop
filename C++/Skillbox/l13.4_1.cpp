/*
Задание 1
С помощью push_back() реализуйте очередь из роботов-андроидов. Роботы приходят в очередь и называют(вводят с клавиатуры) свои 
порядковые номера (целые положительные). Последний робот в очереди всегда имеет номер -1. Когда он пришёл, необходимо вывести на 
экран все номера в очереди.
*/

#include <iostream>
#include <vector>
using namespace std;
void get_queue (vector <int> m){
    for (int i = 0; i < m.size(); i++){
        cout << m[i] << " ";
    }
}
int main() {
  cout << "\nРоботы(push_back)\n";
  cout << "--------------------------------\n";  
  vector <int> queue = {};
  int num = 0;
  while (num != -1){
    cout << "Enter robot's number: ";
    cin >> num;
    if (num == -1) break;
    else queue.push_back(num);
  }
  cout << "-------------------\n";
  get_queue(queue);
  cout << "\n-------------------\n";
  return 0; 
}