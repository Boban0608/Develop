/*
Задание 3 (необязательное)
Роботы приходят в очередь и называют(вводят с клавиатуры) свои порядковые номера (целые 
положительные). Комната, в которой роботы-андроиды занимают своё место, имеет ограниченный 
размер (который равен capacity вектора, в который вы их записываете). Когда комната заполняется,
роботам приходится “переходить” в другую комнату, чуть больше (но вы этого не видите). 
Необходимо отследить, когда в комнате будет оставаться всего 2 свободных места для роботов, и 
вывести сообщение об этом на экран.
Последний робот будет иметь номер -1.
*/

#include <iostream>
#include <vector>
using namespace std;
vector <int> check_value(vector <int> mass, int val){
    while (mass.size() != 0 && mass[mass.size() - 1] < val){
        mass.pop_back();
    }
    mass.push_back(val);
    return mass;
}
void get_queue (vector <int> m){
    for (int i = 0; i < m.size(); i++){
        cout << m[i] << " ";
    }
}
int main() {
  cout << "\nРоботы(push_back)\n";
  cout << "--------------------------------\n";  
  vector <int> queue;
  int num = 0;
  while (num != -1){
    cout << "Enter robot's number(-1 for exit and statistic): ";
    cin >> num;
    if (num == -1) break;
    else queue = check_value(queue, num);
  }  
  cout << "-------------------\n";
  get_queue(queue);
  cout << "\n-------------------\n";
  return 0; 
}