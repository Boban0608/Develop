/*
Многоквартирный дом
Что нужно сделать
На вход программе поступают десять фамилий в формате строк. Это фамилии жильцов квартир с 
первой по десятую. Необходимо прочитать эти фамилии и записать в одномерный массив. Далее 
пользователь вводит три номера квартир. Необходимо вывести в консоль фамилию жильца, 
проживающего в этой квартире. Если пользователь введёт некорректный номер квартиры, 
необходимо сообщить ему об этом.
Пример
← SidorovA 
← IvanovA 
← PetrovA 
← SidorovB 
← IvanovB 
← PetrovB 
← SidorovC 
← IvanovC 
← PetrovC 
← SidorovD 
←10 
→SidorovD 
←1 
→SidorovA 
←5 
→IvanovB
Что оценивается
Используется массив строк для хранения данных.
В коде не используются библиотеки, кроме <iostream> и <string>.
Программа проверяет доступность элемента по индексу и выдаёт корректный результат.
*/

#include <iostream>
#include<string>
using namespace std;
string getFlatOwener(string surname[10], int i){    
    return surname[i - 1];
}
bool check(int i){
    if (i < 1 || i > 10) return false;
    return true;
}
int main() {
  cout << "\nМногоквартирный дом\n";
  cout << "--------------------------------\n";  
  string surname[10];
  int flatNum;
  cout << "Enter 10 surnames: \n";
  for (int i = 0; i < 10; i++){
    cout << "Enter " << i + 1 << " flat owener:\n";
    cin >> surname[i];
  }  
  cout << "--------------------------------\n";
  cout << "Enter 3 flat numbers: \n";
  for (int i = 0; i < 3; ++i){
    bool isOk = false;
    do {
        cout << "Enter " << i + 1 << " number:\n";
        cin >> flatNum;
        isOk = check(flatNum);
        } while (!isOk);
    cout << "This flat own " << getFlatOwener(surname, flatNum) << "\n";
  }
  return 0; 
}