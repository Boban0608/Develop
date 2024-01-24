/*
Задание 2
Пользователь вводит с клавиатуры число n, а затем -- n действительных (дробных) чисел. 
Необходимо вывести их все в обратном порядке (то есть сначала то число, которые пользователь 
ввёл последним и так далее).
*/

#include <iostream>
#include <vector>
using namespace std;
void get_mass(vector <float> &m, int s){
    for (int i = s - 1; i >=0; i--){
        cout << m[i] << " ";
    }

}
int main() {
  cout << "\nВектор 2\n";
  cout << "--------------------------------\n";  
  int n;
  cout << "How many numbers do you want to input?\n";
  cin >> n;
  vector <float> mas(n);
  int middle = 0;
  for (int i = 0; i < n; ++i){
    cout << "Enter " << i + 1 << " number\n";
    cin >> mas[i];
    middle += mas[i];
  }
  int s = mas.size();
  get_mass(mas, s);
  return 0; 
}