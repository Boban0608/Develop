/*
Реализация программы чтения ведомости
Что нужно сделать
Реализуйте программу чтения информации из ведомости по учёту выплат. Сама ведомость 
представляет собой следующую таблицу: 
имя и фамилия человека; 
количество денег, которые были выплачены лицу; 
дата выплаты в формате ДД.ММ.ГГГГ.
На основе данных из ведомости следует подсчитать общее количество выплаченных средств и 
определить человека с максимальной суммой выплат.
Пример данных ведомости
Tom Hanks 35500 10.11.2020
Rebecca Williams 85000 1.1.2021
Sally Field 15600 15.8.2021
Michael Humphreys 29400 23.5.2020
Harold Herthum 74300 9.6.2019
George Kelly 45000 12.3.2018
Bob Penny 12500 13.5.2020
John Randall 23400 2.10.2020
Sam Anderson 6500 15.7.2020
Margo Moorer 12350 24.2.2019
Что оценивается
Корректное отображение общей суммы выплат и самого крупного получателя денежных средств.
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int GetIntMoney(char (&money)[10]){
    int tmp = stoi(money);
    return tmp;
}
void DisplayResult(ifstream& reestr, const string& path){
    reestr.open(path);
    if(!reestr.is_open()){
        cout << "An error opening file! Check the path!\n";
        return;
    }
    int maxMoney = 0, sum = 0;
    char maxName[20], maxSurname[20];
    while(!reestr.eof()){
        char name[20], surname[20], money[10], date[11];
        reestr >> name >> surname >> money >> date;
        int moneyInt;
        moneyInt = GetIntMoney(money);
        if (maxMoney < moneyInt) {
            maxMoney = moneyInt;
            for (int i = 0; name[i] != '\0'; i++){
                maxName[i] = name[i];
            }
            for (int i = 0; surname[i] != '\0'; i++){
                maxSurname[i] = surname[i];
            }
        }
        sum += moneyInt;
    }
    reestr.close();
    cout << "Sum payment - " << sum << endl;
    cout << "Max person payment - \n";
    for (int i = 0; maxName[i] != '\0'; i++){
        cout << maxName[i];
    }
    cout << " ";
    for (int i = 0; maxSurname[i] != '\0'; i++){
        cout << maxSurname[i];
    }
    cout << " " << maxMoney;
}
main() {
  cout << "----------------\n";
  cout << "Table reading.\n";
  cout << "----------------\n";
  const string path = "register.txt";
  ifstream reestr;
  DisplayResult(reestr, path);
  return 0; 
}