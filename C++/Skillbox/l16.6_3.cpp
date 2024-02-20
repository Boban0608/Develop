/*
Калькулятор
Что нужно сделать
Создайте небольшую программу для вычисления простых действий с числами. При запуске программа 
ожидает пользовательского ввода во временную переменную строку. После ввода строки она 
распарсивается на отдельные члены. Строка записывается в форме “<число-1><действие><число-2>” 
(без пробелов). Оба числа — это значения с плавающей точкой, повышенной точности (double). 
Действие может быть одним из: +, −, /, *. Результат действия выводится в стандартный вывод 
cout.
Рекомендации
Чтобы разделить полученную строку на отдельные элементы — числа и оператор, воспользуйтесь 
строковым потоком. Для этого создайте пустую строку std::string buffer и дайте пользователю 
возможность при помощи std::cin ввести в неё команду. Затем оберните полученную строку так: 
std::stringstream buffer_stream(buffer); Это позволит вам  получить каждый из трёх компонентов 
команды: buffer_stream >> a >> operation >> b;
*/

#include <iostream>
#include <sstream>
using namespace std;
double get_result(double a, double b, char action){
    double tmp = 0;
    if (action == '+') tmp = a + b;
    else if  (action == '-') tmp = a - b;
    else if (action == '*') tmp = a * b;
    else if (action == '/') tmp = a / b;
    return tmp;
}
main() {
  cout << "----------------\n";
  cout << "Calculator\n";
  cout << "----------------\n";
  string buffer;
  double number1;
  double number2;
  char operation;
  double result;
  do {
    cout << "Input math action: ";
    cin >> buffer;
    stringstream buffer_stream(buffer);
    buffer_stream >> number1 >> operation >> number2;
    result = get_result(number1, number2, operation);
    cout << result << endl; 
  } while(true);
  return 0; 
}