/*
Лечебница
Напишите программу для картотеки пациентов лечебницы. С клавиатуры вводится неизвестное 
количество целых положительных чисел - возрастов пациентов. Когда пациенты заканчиваются, 
медсестра вводит число -1. Это говорит программе о том, что пора заканчивать с приемом 
пациентов и переходить к расчету статистики.
 
Напишите программу, складывающую в вектор целые положительные числа, пока не поступит 
отрицательное число. После этого выведите среднее значение всех введенных чисел и их количество.
*/

#include <iostream>
#include <vector>
using namespace std;
int get_average (vector <int> b, int s){
    int average = 0;
    for (int i = 0; i < s; i++){
        average += b[i];
    }
    return (average / s);
}
int main() {
  cout << "\nЛечебница\n";
  cout << "--------------------------------\n";  
  vector <int> ageBase = {};
  int age = 0;
  while (age != -1){
    int count = ageBase.size();
    vector <int> newageBase(count + 1);
    cout << "Enter patient age or -1 for exit: ";
    cin >> age;
    for (int i = 0; i < count; i++){
        newageBase[i] = ageBase[i];
    }
    if (age == -1) break;
    newageBase[count] = age;
    ageBase = newageBase;
  }
  cout << ageBase.size() << " entries in database.\n";
  cout << "Average age in database - " << get_average(ageBase, ageBase.size());
  return 0; 
}