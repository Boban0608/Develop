/*
Задание 2
Робот приходит в очередь и заставляет уходить из конца очереди всех, чей номер меньше, 
чем у него, а потом становится в очередь сам. Последний робот будет иметь номер -1 
(и, соответственно, не сможет никого выгнать, так как остальные имеют положительные 
номера). Когда он пришёл, нужно вывести все номера в очереди на экран.
*/

#include <iostream>
#include <vector>
using namespace std;
vector <int> check_value(vector <int> mass, int val){
    int i = 0;
    while (i < mass.size()){
        if (mass[i] < val) {
            for (int j = i; j < mass.size(); ++j){
                mass[j] = mass[j + 1];
            }
            mass.pop_back();
            i = 0;
        } else i++;
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
  vector <int> queue = {};
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