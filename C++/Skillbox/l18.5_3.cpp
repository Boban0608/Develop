/*
Напишите рекурсивную функцию, которая принимает большое число n типа long long и переменную 
ans, а возвращает void. После завершения работы функции в переменной ans должно оказаться 
количество чётных цифр в записи числа n. 
Пример:
int ans;
evendigits(9 223 372 036 854 775 806, ans);
//ans == 10
Пояснение: 9 223 372 036 854 775 806
Чек-лист для проверки задачи
Функция принимает корректные типы данных, тип возвращаемого значения —  void.
Функция не использует библиотек кроме <iostream>.
Функция рекурсивная.
Функция содержит параметр по ссылке.
*/
#include <iostream>
using namespace std;
void EvenDigits (long long& num, int& ans){
    if (!num) return;
    int tmp = num%10;
    if (tmp%2 == 0) ans ++;
    num /=10;
    EvenDigits(num, ans);    
}
main() {
  cout << "----------------\n";
  cout << "Recursion\n";
  cout << "----------------\n";
  long long num;
  cout << "Input big number:\n";
  cin >> num;
  int ans = 0;
  EvenDigits(num, ans);
  cout << "Even digits in big number - " << ans;
  return 0; 
}