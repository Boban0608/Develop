/*
Роботы и коррупция*
Улучшите электронную очередь для роботов. К нам приходят роботы разного социального статуса. 
Каждый робот вводит не только свой уникальный номер, но и свое место в очереди. Например, 
пусть в нашей очереди 10 роботов и к нам приходит 11-й. Сначала он вводит свой номер, как и 
раньше, а затем свое место в очереди - например, 5. В этом случае он должен оказаться в 
очереди пятым, а все остальные, начиная со старого пятого - подвинуться дальше в конец очереди.
Реализуйте функцию std::vector<int> add_to_position(std::vector vec, int val, int position)
*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
vector <int> add_to_position(vector <int> queue, int val, int position){
    int count = queue.size();
    assert(position < count);
    vector <int> newqueue(count + 1);
    for (int i = 0; i < position - 1; i++){
        newqueue[i] = queue[i];
    }
    newqueue[position - 1] = val;
    for (int i = position; i <= count; i++){
        newqueue[i] = queue[i - 1];
    }
    return newqueue;
}
int main() {
  cout << "\nРоботы и коррупция\n";
  cout << "--------------------------------\n";  
  vector <int> queue = {232, 23, 456, 4756};
  int num = 0;
  int pos;
  while (num != -1){
    cout << "Enter robot number or -1 for exit: ";
    cin >> num;
    if (num == -1) break;
    cout << "Enter position in queue: ";
    cin >> pos;
    queue = add_to_position(queue, num, pos);
  }
  for (int i = 0; i < queue.size(); i++)
    cout << queue[i] << " ";
  return 0; 
}