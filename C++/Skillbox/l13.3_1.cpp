/*
Задание 1
На витрине стоят несколько роботов, у каждого есть свой номер. Номера задаются с клавиатуры 
(сначала вводится число n, потом -- n номеров роботов). Далее вводится число m и после этого 
-- m индексов (от 0 до количества оставшихся роботов на витрине). Когда введён очередной 
индекс -- робота покупают, то есть он покидает витрину, а остальные роботы “группируются”, 
смещаясь на один шаг назад. Необходимо вывести список оставшихся, после всех покупок, роботов.
Пример: на витрине стояли роботы {100, 200, 250, 300}. Сначала забрали робота с индексом 1, 
то есть с номером 200, осталось {100,250,300}. Потом забрали робота с индексом 1, то есть с 
номером 250, осталось {100,300}
*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
vector <int> add_robots(vector <int> robots, int amount){
    robots.resize(robots.size() + amount);
    int size = robots.size();
    for (int i = size - amount; i < size; i++){
        cout << "Enter robot number: ";
        cin >> robots[i];
    }
    cout << "---------------------\n";
    cout << "You add " << amount << " robots\n";
    cout << "---------------------\n"; 
    return robots;
}
vector <int> sell_robots(vector <int> robots, int amount){
    for (int i = 0; i < amount; i++){
        int id;
        cout << "Enter robot index to sell (0 - " << robots.size() - 1 << "): ";
        cin >> id;
        if (id < 0 || id > robots.size() - 1) {
            cout << "Wrong input!\n";
            break;
        }
        for (int i = id; i < robots.size(); i++){
            robots[i] = robots[i+1];
        }
        robots.resize(robots.size() - 1);
    }
    cout << "---------------------\n";
    cout << "You sell " << amount << " robots\n";
    cout << "---------------------\n";
    return robots;
}
int main() {
  cout << "\nРоботы(продажа)\n";
  cout << "--------------------------------\n";  
  vector <int> queue = {};
  int num, amount = 0, choise = 0;
  while (choise != 4){
    cout << "Enter item:" << endl;
    cout << "1. To add robots" << endl;
    cout << "2. To sell robots" << endl;
    cout << "3. To statistic" << endl;
    cout << "4. To exit" << endl;
    cin >> choise;
    if (choise == 1){
        cout << "Enter robot amount to add: ";
        cin >> amount;
        if (amount <= 0) {
            cout << "You input wrong value!\n";
        } else queue = add_robots(queue, amount);   
    } else if(choise == 2){
        if (queue.size() != 0){
            cout << "Enter robot amount to sell: ";
            cin >> amount;
            if (amount <= 0) {
                cout << "You input wrong value!\n";
            } else queue = sell_robots(queue, amount);
        } else {
            cout << "---------------------\n";
            cout << "Base is empty! We don't have robots!\n";
            cout << "---------------------\n";
        }
    }  else if(choise == 3){
        cout << "---------------------\n";
        cout << "Statisic:" << endl;
        for (int i = 0; i < queue.size(); i++)
                cout << queue[i] << " ";
            cout << endl;
        cout << "--------------\n";
    }
  }  
  return 0; 
}