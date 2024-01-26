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
vector <int> add_robots(vector <int> mass, int val){
    for (int i = 0; i < mass.size(); i++){
      if (mass[i] == 0) {
        mass[i] = val;
        break;
      }
    }
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
    if (queue.size() == 0){
      cout << "--------------------------------\n";
      cout << "Not anouth space for robots!\n";
      cout << "There are 5 positions added.\n";
      cout << "--------------------------------\n";
      queue.resize(queue.size() + 5);
    }
    else if(queue[queue.size() - 3] != 0){
      cout << "--------------------------------\n";
      cout << "There are only 2 position for robots!\n";
      cout << "Robots will be move to another room!\n";
      cout << "--------------------------------\n";
      queue.resize(queue.size() + 5);
    }
    if (num == -1) break;
    else queue = add_robots(queue, num);
  }  
  cout << "-------------------\n";
  get_queue(queue);
  cout << "\n-------------------\n";
  return 0; 
}