/*
Очередь из роботов
Повторите программу из теоретического материала. Напишите электронную очередь для андроидов. 
Их количество неизвестно заранее. Каждый андроид вводит с клавиатуры свой идентификационный 
номер - целое число. Нужно сохранить их номера в векторе в том порядке, в котором они 
записывались в очередь.
*/

#include <iostream>
#include <vector>
using namespace std;
int main() {
  cout << "\nОчередь из роботов\n";
  cout << "--------------------------------\n";  
  vector <int> queue = {232, 23, 456, 4756};
  int num = 0;
  while (num != -1){
    int count = queue.size();
    vector <int> newqueue(count + 1);
    cout << "Enter robot number: ";
    cin >> num;
    for (int i = 0; i < count; i++){
        newqueue[i] = queue[i];
    }
    newqueue[count] = num;
    queue = newqueue;
  }
  for (int i = 0; i < queue.size(); i++)
    cout << queue[i] << " ";
  return 0; 
}