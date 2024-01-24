/*
Задание 1
Пользователь вводит с клавиатуры число n, а затем -- n целых чисел.
Необходимо вычислить их среднее арифметическое и вывести на экран.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  cout << "\nВектор 1\n";
  cout << "--------------------------------\n";  
  int n;
  cout << "How many numbers do you want to input?\n";
  cin >> n;
  vector <int> mas(n);
  int middle = 0;
  for (int i = 0; i < n; ++i){
    cout << "Enter " << i + 1 << " number\n";
    cin >> mas[i];
    middle += mas[i];
  }
  cout << "Arithmetic mean is " << (middle / n);
  return 0; 
}