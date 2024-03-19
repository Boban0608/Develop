/*
Анализ заполненности вагонов в поезде* (дополнительное задание)
Что нужно сделать
В поезде всего 10 вагонов. В каждом из этих вагонов может находиться до 20 пассажиров — 
это их оптимальное количество. Проанализируйте количество людей в каждом вагоне и 
сначала сообщите об излишне заполненных вагонах, далее о вагонах с пустыми 
пассажирскими местами. В заключение выведите общее количество пассажиров во всех 
вагонах.
При старте программы пользователь вводит количество пассажиров в каждом вагоне. 
Замечания о вагонах должны выводиться в стандартную консоль.
При выполнении задания пользоваться нельзя напрямую пользоваться for-циклами, только 
опосредованно, через макросы.
Советы и рекомендации
С помощью макроса реализуйте модульный способ вызова функции над элементами массива. 
Сами функции реализуйте отдельно, в виде обычных классических функций (не макросов).
Модульный способ вызова функции печати текста через макрос:
#define CALL(func) { func("Hello, Skillbox!"); }
void print(std::string str) {
   std::cout << str << std::endl;
}
int main() {
   CALL(print);
   return 0;
}
Обязательно просмотрите итоговый код после препроцессинга из CLion с помощью 
Shift-Shift → Preprocess current TU.
Что оценивается
Корректность работы программы. Модульность и элегантность решения с помощью макросов.
*/

#include <iostream>
#include <vector>

using namespace std;
vector <int> train;
int passum = 0;
#define TRAIN(func) for (int i = 0; i < 10; i++) {func(i);} 
#define PEOPLE(funcl) for (int k = 0; k < train.size(); k++) {funcl(k);}
void VectorInit (int num)
{
    cout << "Input persons number in " << num + 1 << " wagon: ";
    int persons;
    cin >> persons;
    train.push_back(persons);
}
void CheckOverLoad(int i)
{
    if (train[i] > 20)
    {
        cout << "Wagon " << i + 1 << " is overloaded on " << train[i] - 20 << " persons\n";
    }
}
void CheckMisLoad(int i)
{
    if (train[i] < 20)
    {
        cout << "Wagon " << i + 1 << " is missload on " << 20 - train[i] << " persons\n";
    }
}
void SumPass(int i)
{
    passum += train[i];
}
main ()
{
    cout << "----------------\n";
    cout << "Wagon fullness.\n";
    cout << "----------------\n";
    TRAIN(VectorInit);
    cout << "____________________\n";
    PEOPLE(CheckOverLoad);
    cout << "____________________\n";
    PEOPLE(CheckMisLoad);
    cout << "____________________\n";
    PEOPLE(SumPass)
    cout << "Passenger sum is: " << passum << endl;
    cout << "____________________\n";
    return 0;
}
