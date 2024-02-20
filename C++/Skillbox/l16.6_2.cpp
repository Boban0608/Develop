/*
Сшиватель дробных чисел
Что нужно сделать
Напишите небольшую программу. Из целой и дробной частей числа, которые в отдельности вводит 
пользователь, составьте новое число с плавающей точкой (типа double) и выведите это число 
обратно в консоль для проверки. Целая часть — это часть числа, которая находится до точки 
(запятой), дробная — после.
Рекомендации
Вам потребуется функция StringToDouble — std::stod. Она принимает на вход строку, содержащую в 
себе число.
*/

#include <iostream>
using namespace std;
main() {
  cout << "----------------\n";
  cout << "Merge float numbers\n";
  cout << "----------------\n";
  string start_part;
  string end_part;
  double number;
  do {
    cout << "Input first part: ";
    cin >> start_part;
    cout << "Input second part: ";
    cin >> end_part;
    number = stod(start_part + '.' + end_part);
    cout << "Your number: " << number << endl;
  } while(true);
  return 0; 
}