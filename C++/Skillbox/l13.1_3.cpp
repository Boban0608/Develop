/*
Задание 3
Пользователь вводит с клавиатуры число n, а затем -- n целых чисел. Необходимо отыскать 
второе по величине из этих чисел и вывести на экран.
*/

#include <iostream>
#include <vector>
using namespace std;
int get_second_number(vector <int> &m, int s){
    for (int i = 0; i < s; i++){
        for (int j = 0; j < s - i; j++){
            if(m[j] < m [j + 1]){
                m[j] += m[j + 1];
                m[j + 1] = m[j] - m[j + 1];
                m[j] -= m[j + 1];
            }
        }
    }
    return m[1];

}
int main() {
  cout << "\nВектор 3\n";
  cout << "--------------------------------\n";  
  int n;
  cout << "How many numbers do you want to input?\n";
  cin >> n;
  vector <int> mas(n);
  for (int i = 0; i < n; ++i){
    cout << "Enter " << i + 1 << " number\n";
    cin >> mas[i];
  }
  int s = mas.size();
  cout << "Second big number is " << get_second_number(mas, s);
  return 0; 
}