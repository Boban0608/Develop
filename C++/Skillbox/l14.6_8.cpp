/*
Морской бой (дополнительное задание)
Требуется реализовать упрощённую игру в морской бой. Игровое поле размером 10 на 10 клеток. 
Участвуют два игрока. В арсенале каждого из них 4 маленьких кораблика размером в одну клетку, 
3 небольших корабля размером в две клетки, 2 средних корабля размером в три клетки и один 
большой корабль размером в четыре клетки. Для простоты клетки поля пронумерованы по вертикали 
от 0 до 9 и по горизонтали от 0 до 9. Мы не будем использовать классические наименования 
клеток, такие как B4, C6, а просто два индекса. Вначале игроки по очереди расставляют корабли, 
начиная с самых маленьких и заканчивая большими. Маленькие корабли в одну клетку расставляются 
с помощью указания одной клетки-точки на поле, к примеру 2,1. Корабли размерностью от двух 
клеток и выше расставляются с помощью координат их начала и конца, к примеру: 0,1–0,3. Корабли 
могут быть установлены только строго вертикально или горизонтально. Установка корабля по 
диагонали недопустима, об этом тоже надо сообщить пользователю. Если корабль не может быть 
размещён на заданных клетках из-за того, что он столкнётся с другим кораблём (окажется на его 
клетках) или выйдет за пределы поля, то игроку должно быть сделано предупреждение, после 
которого он должен переставить корабль на новые валидные координаты. В нашем упрощённом 
варианте игры мы не будем обсчитывать соприкосновения кораблей друг с другом, а потому корабли 
вполне можно будет размещать друг к другу вплотную, борт к борту. После того как все корабли 
расставлены, начинается игра. Игроки по очереди атакуют друг друга, называя координаты 
выстрела. После выстрела в консоль выводится информация о его результате: попал или мимо. 
Если выстрел успешен,клетка, на кото рой был корабль (или его фрагмент), затирается и 
становится пустой. Игра заканчивается тогда, когда все корабли одной из сторон будут полностью 
уничтожены. Как только это произойдёт, в консоль выводится информация с номером игрока, 
который победил.
Советы и рекомендации
Действия игроков практически одинаковые, их можно объединить в функции.
В программе достаточно иметь два поля, по одному на каждого игрока.
Лучше создать три отдельные функции: одну для размещения одного корабля, еще одну как обёртку 
над первой (она будет размещать все корабли), а третью для удара по координате. Также вам 
потребуются два глобальных массива для двух отдельных участков моря:
bool field_1[10][10]; 
bool field_2[10][10];
Что оценивается
Корабли расставляются правильно.
Есть возможность выиграть.
Реализован понятный и удобный для пользователя интерфейс игры.
*/

#include <iostream>
using namespace std;
void landscape_init (bool landscape[][10]){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            landscape[i][j] = false;
        }
    }
}
void show_field (bool landscape[][10]){
    for (int i = 0; i < 11; i++){
      if (i == 0){ 
        cout << "  ";
        for (int j = 0; j < 10; j++){
          cout << " " << j + 1;
        }
      } else {
        for (int j = 0; j < 11; j++){
            if (j == 0){
                if (i == 10) cout << i << " ";
                else cout << i << "  ";
            } else {
                if (landscape[i-1][j-1]) cout << "X ";
                else cout << ". ";
            }
        }
      }
      cout << endl;
    }
}
void small_ship_location (bool landscape[][10]){
    show_field(landscape);
    int shipCnt = 4;
    while (shipCnt){
        cout << "Input small ship coordinate(3 3 for ex): ";
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (landscape[x][y]){
            cout << "This field is occupied!\n";
            cout << "Try another coordinate!\n";
        } else {
            landscape[x][y] = true;
            cout << "Your ship is located!\n";
            shipCnt--;
        }
        show_field(landscape);
    }
}
bool check_rightness(bool landscape[][10], int x, int y, int x1, int y1){
    for (; x <= x1; x++){
        for (; y <= y1; y++){
            if (landscape[x][y]){
                return false; 
            }
        }
    }
    return true;
}
int ship_done (bool landscape[][10], bool correctness, int x, int y, int x1, int y1, int tmp){
    if (correctness){
        for (; x <= x1; x++){
            for (int j = y; j <= y1; j++){
                landscape[x][j] = true;
            }
        }
        cout << "Your ship is located!\n";
        tmp --;
        show_field(landscape);
    } else {
        cout << "You enter wrong coordinate!\n";
        cout << "Coordinate shuold start from small to big coordinate!\n";
        cout << "Try again!\n";
    }
    return tmp;
}
void ship_location (bool landscape[][10]){
    int shipCnt = 6;
    while (shipCnt){
        int hugeShip = 1;
        while (hugeShip){
            cout << "Input huge ship coordinate (3 3 6 3 for ex): \n";
            bool correctness;
            int x, y, x1, y1;
            cin >> x >> y >> x1 >> y1;
            x--;
            y--;
            x1--;
            y1--;
            if (x == x1 && y1 == (y + 3) || y == y1 && x1 == (x + 3)){
                correctness = check_rightness(landscape, x, y, x1, y1);
                if (correctness) shipCnt--;
                hugeShip = ship_done(landscape, correctness, x, y, x1, y1, hugeShip);
            } else cout << "Wrong input!\n";
        }
        int bigShip = 2;
        while (bigShip){
            cout << "Input big ship coordinate (3 3 6 3 for ex): \n";
            bool correctness;
            int x, y, x1, y1;
            cin >> x >> y >> x1 >> y1;
            x--;
            y--;
            x1--;
            y1--;
            if (x == x1 && y1 == (y + 2) || y == y1 && x1 == (x + 2)){
              correctness = check_rightness(landscape, x, y, x1, y1);
              if (correctness) shipCnt--;
              bigShip = ship_done(landscape, correctness, x, y, x1, y1, bigShip);
            } else cout << "Wrong input!\n";
        }
        int middleShip = 3;
        while (middleShip){
            cout << "Input middle ship coordinate (3 3 6 3 for ex): \n";
            bool correctness;
            int x, y, x1, y1;
            cin >> x >> y >> x1 >> y1;
            x--;
            y--;
            x1--;
            y1--;
            if (x == x1 && y1 == (y + 1) || y == y1 && x1 == (x + 1)){
              correctness = check_rightness(landscape, x, y, x1, y1);
              if (correctness) shipCnt--;
              middleShip = ship_done(landscape, correctness, x, y, x1, y1, middleShip);
            } else cout << "Wrong input!\n";
        }        
    }    
}
bool player_shot (bool landscape[][10], bool game[][10], int x, int y){
    x--;
    y--;
    if (landscape[x][y]){
        cout << "----------------\n";
        cout << "Nice shot!\n";
        cout << "----------------\n";
        landscape[x][y] = false;
        game[x][y] = true;
        return true;
    } else {
        cout << "----------------\n";
        cout << "You miss!\n";
        cout << "----------------\n";
        return false;
    }
}
bool check_game (bool landscape[][10]){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (landscape[i][j]) return true;
        }
    }
    return false;
}
void display_field_shot (bool field[][10]){
    for (int i = 0; i < 11; i++){
      if (i == 0){ 
        cout << "  ";
        for (int j = 0; j < 10; j++){
          cout << " " << j + 1;
        }
      } else {
        for (int j = 0; j < 11; j++){
            if (j == 0){
                if (i == 10) cout << i << " ";
                else cout << i << "  ";
            } else {
                if (field[i-1][j-1]) cout << "X ";
                else cout << ". ";
            }
        }
      }
      cout << endl;
    }
}
main() {
  cout << "----------------\n";
  cout << "Sea battle\n";
  cout << "----------------\n";
  bool landscape1[10][10], landscape2[10][10], game1[10][10], game2[10][10];
  landscape_init(landscape1);
  landscape_init(landscape2);
  landscape_init(game1);
  landscape_init(game2);
  string player1, player2;
  cout << "Hi, player1! Input your name: \n";
  cin >> player1;
  cout << "Hi, player2! Input your name: \n";
  cin >> player2;
  cout << player1 << ". Your turn to locate ships!\n";
  small_ship_location(landscape1);
  ship_location(landscape1);
  cout << player2 << ". Your turn to locate ships!\n";
  small_ship_location(landscape2);
  ship_location(landscape2);
  cout << "----------------\n";
  cout << "Location complete!\n";
  cout << "----------------\n";
  bool game = true;
  bool player = true;
  while (game) {
    int x, y;
    if (player){
        cout << player1 << ". It's your turn!\n";
        cout << "Enter coordinate to shot: ";
        cin >> x >> y;
        bool shot;
        shot = player_shot(landscape2, game1, x, y);
        if (!shot) player = false;
        game = check_game(landscape2);
        if (!game) cout << player1 << ". You WIN!!!\n";
        display_field_shot(game1);
    } else {
        cout << player2 << ". It's your turn!\n";
        cout << "Enter coordinate to shot: ";
        cin >> x >> y;
        bool shot;
        shot = player_shot(landscape1, game2, x, y);
        if (!shot) player = true;
        game = check_game(landscape1);
        if (!game) cout << player2 << ". You WIN!!!\n";
        display_field_shot(game2);
    }
  }
  return 0; 
}