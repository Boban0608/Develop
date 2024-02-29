/*
Симуляция работы банкомата
Что нужно сделать
Реализуйте упрощённую симуляцию работы банкомата. 
Учтите следующее:
В банкомате могут храниться только бумажные купюры номиналом 100, 200, 500, 1 000, 2 000 и 
5 000 рублей.
Максимально в банкомате может храниться только 1 000 купюр. Все они записываются в отдельный 
файл. 
У банкомата, как у устройства, две основных операции — снятие денег пользователем и наполнение 
деньгами инкассаторами банка.
Состояние банкомата должно храниться в отдельном бинарном файле, автономно. Хранение в 
бинарном виде улучшает производительность программы и уменьшает размер данных.
Банкомат работает следующим образом:
При старте программа проверяет наличие файла .bin. Если он есть (данные по банкомату были 
сохранены), данные загружаются и на экран выводится информация о текущем состоянии банкомата: 
сколько сейчас купюр каждого номинала и общая сумма. Если файла нет — банкомат «пустой».
При вводе «+» заполняются недостающие купюры и выводится информация о текущем состоянии 
банкомата: сколько сейчас купюр каждого номинала и общая сумма. Количество купюр рассчитывается 
так, чтобы банкомат был заполнен полностью. Все купюры при этом выбираются случайным образом.
При вводе «−» симулируется снятие пользователем денег. Пользователь указывает сумму с 
точностью до 100 рублей. Считайте, что каждый клиент обладает неограниченным балансом в 
системе и теоретически может снять любую сумму. Выдача происходит начиная с купюр большего 
номинала. Если запрошенная сумма не может быть снята из-за отсутствия подходящих купюр в 
машине, показывается сообщение, что эта операция невозможна. После выдачи денег на экран 
выдаётся информация о текущем состоянии банкомата: сколько сейчас купюр каждого номинала и 
общая сумма.
При выходе из программы сохраняем состояние банкомата в файл. 
Рекомендации
Вы можете хранить массив купюр целиком, помечая отсутствующие позиции нулями.
Выход из программы рекомендуется сделать по отдельной команде, а команды «+» и «−» получать в 
цикле.
*/
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
ifstream CheckStatement(){
    ifstream state("statement.bin", ios::binary);
    if(!state.is_open()){
        cout << "Error reading file statement\n";
        cout << "----------------\n";
        state.close();
        ofstream saving("statement.bin", ios::binary);
        saving.close();
        ifstream stateNew("statement.bin", ios::binary);
        return stateNew;
    }
    return state;
}

void PrintState(bool mass[][1000]){
    int one = 0, two = 0, five = 0, thausand = 0, twothausand = 0, fivethausand = 0; 
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 1000; j++){
            if (i == 0 && mass[i][j]) one++;
            else if (i == 1 && mass[i][j]) two++;
            else if (i == 2 && mass[i][j]) five++;
            else if (i == 3 && mass[i][j]) thausand++;
            else if (i == 4 && mass[i][j]) twothausand++;
            else if (i == 5 && mass[i][j]) fivethausand++;
        }
    }
  cout << "Banknote 100 - " << one << " pc's" << endl;
  cout << "Banknote 200 - " << two << " pc's" << endl;
  cout << "Banknote 500 - " << five << " pc's" << endl;
  cout << "Banknote 1000 - " << thausand << " pc's" << endl;
  cout << "Banknote 2000 - " << twothausand << " pc's" << endl;
  cout << "Banknote 5000 - " << fivethausand << " pc's" << endl;
  cout << "Total sum - " << one * 100 + two * 200 + five * 500 + thausand * 1000 + twothausand * 2000 + fivethausand * 5000 << endl;
}
void SaveStatement(bool mass[][1000]){
    ofstream saving("statement.bin", ios::binary);
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 1000; j++){
            if (i == 0 && mass[i][j]){
                int len;
                string tmp = "100";
                len = tmp.length();
                saving.write((char*) &len, sizeof(len));
                saving.write((char*) tmp.c_str(), len);
            }    
            else if (i == 1 && mass[i][j]){
                int len;
                string tmp = "200";
                len = tmp.length();
                saving.write((char*) &len, sizeof(len));
                saving.write((char*) tmp.c_str(), len);
            }
            else if (i == 2 && mass[i][j]){
                int len;
                string tmp = "500";
                len = tmp.length();
                saving.write((char*) &len, sizeof(len));
                saving.write((char*) tmp.c_str(), len);
            }
            else if (i == 3 && mass[i][j]){
                int len;
                string tmp = "1000";
                len = tmp.length();
                saving.write((char*) &len, sizeof(len));
                saving.write((char*) tmp.c_str(), len);
            }
            else if (i == 4 && mass[i][j]){
                int len;
                string tmp = "2000";
                len = tmp.length();
                saving.write((char*) &len, sizeof(len));
                saving.write((char*) tmp.c_str(), len);
            }
            else if (i == 5 && mass[i][j]){
                int len;
                string tmp = "5000";
                len = tmp.length();
                saving.write((char*) &len, sizeof(len));
                saving.write((char*) tmp.c_str(), len);
            }
        }
    }
    saving.close();
}
void AmountInit(bool mass[][1000]){
  for (int i = 0; i < 6; i++){
    for (int j = 0; j < 1000; j++){
        mass[i][j] = false;
    }
  }
  ifstream state = CheckStatement();
  while(!state.eof()){
    int len;
    state.read((char*) &len, sizeof(len));
    string banknote;
    banknote.resize(len);
    state.read((char*) banknote.c_str(), len);
    for (int i = 0; i < 6; i++){
      for(int j = 0; j < 1000; j++){        
        if (i == 0 && banknote == "100"){
          if (!mass[i][j]){
            mass[i][j] = true;
            break;
          }
        } else if (i == 1 && banknote == "200"){
          if (!mass[i][j]){
            mass[i][j] = true;
            break;
          } 
        } else if (i == 2 && banknote == "500"){
          if (!mass[i][j]){
            mass[i][j] = true;
            break;
          }
        } else if (i == 3 && banknote == "1000"){
          if (!mass[i][j]){
            mass[i][j] = true;
            break;
          }
        } else if (i == 4 && banknote == "2000"){
          if (!mass[i][j]){
            mass[i][j] = true;
            break;
          }
        } else if (i == 5 && banknote == "5000"){
          if (!mass[i][j]){
            mass[i][j] = true;
            break;
          }
        }
      }
    }
  }
  state.close();  
}
void AddingMoney(bool mass[][1000]){
    int count = 0;
    while (count <= 1000){
        count = 0;
        int tmp = rand() % 6;
        int tmp1 = rand() % 1000;
        if (!mass[tmp][tmp1]) mass[tmp][tmp1] = true;
        for (int i = 0; i < 6; i++){
            for (int j = 0; j < 1000; j++){
                if (mass[i][j]) count++;
            }
        }
    }
    PrintState(mass);
}
bool CheckMoney(bool mass[][1000], int money){
  for (int i = 5; i >= 0; i--){
    for (int j = 0; j < 1000; j++){
        if (money >= 5000 && i == 5){
            if (mass[i][j]) money -= 5000;
            if (!money) return true;
        } else if (money >= 2000 && i == 4){
            if (mass[i][j]) money -= 2000;
            if (!money) return true;
        } else if (money >= 1000 && i == 3){
            if (mass[i][j]) money -= 1000;
            if (!money) return true;
        } else if (money >= 500 && i == 2){
            if (mass[i][j]) money -= 500;
            if (!money) return true;
        } else if (money >= 200 && i == 1){
            if (mass[i][j]) money -= 200;
            if (!money) return true;
        } else if (money >= 100 && i == 0){
            if (mass[i][j]) money -= 100;
            if (!money) return true;
        }
    }
  }
  return false;
}
void DeleteMoney(bool mass[][1000]){
    int money;
    cout << "Input sum multiple of 100\n";
    cin >> money;
    bool moneyCheck = CheckMoney(mass, money);
    if (moneyCheck){
        for (int i = 5; i >= 0; i--){
            for (int j = 999; j >= 0; j--){
                if (money >= 5000 && i == 5){
                    if (mass[i][j]) {
                        money -= 5000;
                        mass[i][j] = false;
                    }                    
                } else if (money >= 2000 && i == 4){
                    if (mass[i][j]) {
                        money -= 2000;
                        mass[i][j] = false;
                    }
                } else if (money >= 1000 && i == 3){
                    if (mass[i][j]) {
                        money -= 1000;
                        mass[i][j] = false;
                    }
                } else if (money >= 500 && i == 2){
                    if (mass[i][j]) {
                        money -= 500;
                        mass[i][j] = false;
                    }
                } else if (money >= 200 && i == 1){
                    if (mass[i][j]) {
                        money -= 200;
                        mass[i][j] = false;
                    }
                } else if (money >= 100 && i == 0){
                    if (mass[i][j]) {
                        money -= 100;
                        mass[i][j] = false;
                    }
                } 
            }
        }
        cout << "----------------\n";
        cout << "You get your money\n";
        cout << "----------------\n";
    } else {
        cout << "----------------\n";
        cout << "It's not enougth banknot!\n";
        cout << "Try another sum\n";
        cout << "----------------\n";
    }
    PrintState(mass);
}
main() {
  cout << "----------------\n";
  cout << "Cash machine simulation\n";
  cout << "----------------\n";
  srand(time(nullptr));
  bool amount[6][1000];
  string operation = "";
  AmountInit(amount);
  PrintState(amount);
  cout << "----------------\n";
  cout << "You can start operation\n";
  cout << "----------------\n";
  while (operation != "q"){
    cout << "Input '+' for add money, '-' for get money or 'q' for exit\n";
    cin >> operation;
    if (operation == "+"){
        AddingMoney(amount);
    } else if (operation == "-"){
        DeleteMoney(amount);
    } else if (operation == "q"){
        SaveStatement(amount);
    }
  }
  return 0; 
}