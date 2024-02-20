/*
Напишите функцию, принимающую два указателя на char*, по которым размещены две строки.
Функция должна возвращать true, если вторая строка является подстрокой первой.
Пример
const char* a = "Hello world";
const char* b = "wor";
const char* c = "banana";
std::cout << substr(a,b) << " " << substr(a,c);
// true false
Const-квалификатор
Const является квалификатором типа, применяемым к переменным, значения которых нельзя изменять.
Например, если в коде написать:
const int a = 2;
то впоследствии значение переменной невозможно будет изменить, а запись вида
a = 3;
приведёт к ошибке компилятора.
Чек-лист для проверки задачи
Функция принимает корректные типы данных, тип возвращаемого значения — bool.
Для работы со строками разрабатываемая функция может использовать только стандартную функцию 
strlen, входящую в библиотеку <cstring>. Допускается не использовать стандартные функции, а 
размер строки определять по нуль-символу ‘\0’.
Функция корректно определяет, является ли вторая строка подстрокой первой.
*/
#include <iostream>
using namespace std;
bool CompareString(const char* str, const char* substr){
    int i = 0;
    bool tmp = false;
    while (*(str + i) != '\0'){
        if (*(str + i) == *substr){
            for (int j = 0; *(substr + j) != '\0'; j++){
                if (*(str + i + j) == *(substr + j)){
                    tmp = true;
                } else tmp = false;
            }
        }
        i++;
    }
    return tmp;
}
main() {
  cout << "----------------\n";
  cout << "Pointer 3\n";
  cout << "----------------\n";
  const char* a = "Hello world";
  const char* b = "wor";
  const char* c = "banana";
  cout << CompareString(a, b) << " " << CompareString(a, c);
  return 0; 
}