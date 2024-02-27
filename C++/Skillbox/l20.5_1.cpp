/*
Запись в ведомость учёта
Что нужно сделать
В одном из прошлых заданий вы уже создавали программу для чтения и анализа ведомости выплат. 
Теперь попробуйте создать простую программу для записи в эту ведомость.
Формат ведомости прежний: 
Сначала идёт имя и фамилия получателя денежных средств, далее — дата выдачи в формате 
ДД.ММ.ГГГГ. 
Запись завершает сумма выплаты в рублях. 
Данные разделяются между собой пробелами. 
В конце каждой записи должен быть расположен перевод строки.
При старте программы пользователь последовательно вводит данные для новой записи, которые 
затем записываются в файл в текстовом режиме. Программа должна добавлять новые записи в 
конец файла, не удаляя его текущее содержимое.
Рекомендации
Валидируйте введённые файлы перед записью, хотя бы минимально.
Для валидации даты в указанном формате можно использовать функции std::stoi и std::subtr с 
корректно указанным диапазоном символов в дате. К примеру, вызов std::stoi(date.substr(3, 2)) 
вычленит из строковой даты целочисленный месяц для последующего анализа.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
bool CheckData(string &sal, string &d){
  int tmp;
  stringstream(sal) >> tmp;
  if (tmp <= 0){
    cout << "Salory can't be less than '0'\n";
    return false;
  } else if (tmp > 200000){
    cout << "Max salory - 200000!";
    return false;
  }  
  int day = stoi(d.substr(0,2));
  int month = stoi(d.substr(3,2));
  if(d[2] != ':' && d[2] != '.' || d[5] != ':' && d[5] != '.' || d.length() != 10){
    cout << "Invalid date format!\n";
    cout << "It should be DD:MM:YYYY\n";
    return false;
  } else if (stoi(d.substr(3,2)) < 1 || stoi(d.substr(3,2)) > 12){
    cout << "Invalid month input!\n";
    cout << "It shoud be from 1 to 12\n";
    return false;
  } else if (day < 1 || (day > 29 && month == 2) 
            || (day > 30 && (month == 4 || month == 6
            || month == 9 || month == 11)) || (day > 31
            && (month == 1 || month == 3 || month == 5
            || month == 7 || month == 8 || month == 10
            || month == 12))){
    cout << "Invalid date input!\n";
    cout << "This mounth don't have such date!\n";
    return false;
  }  
  return true;
}
main() {
  cout << "----------------\n";
  cout << "Table writing in file\n";
  cout << "----------------\n";
  string path, name, surname, salary, date;
  cout << "Input filename to writting a table:\n";
  cin >> path;
  ofstream table("C:\\mingw64\\Develop\\C++\\Skillbox\\" + path + ".txt", ios::app);
  while(true){  
    bool validity;
    cout << "Input data in table in format - 'Name Surname Salory DD.MM.YYYY'(or q for exit)\n";
    cin >> name;
    if (name == "q" or name == "Q") break;
    cin >> surname >> salary >> date;
    validity = CheckData(salary, date);
    if (!validity){
        cout << "Try again!\n";
    } else {
        table << name << " " << surname << " " << salary << " " << date << endl;
    }
  }
  table.close();
  return 0; 
}