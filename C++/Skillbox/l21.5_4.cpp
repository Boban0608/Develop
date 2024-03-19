/*
Пошаговая ролевая игра (дополнительная задача)
Что нужно сделать
Реализуйте упрощённую версию пошаговой ролевой игры.
Действие разворачивается на карте размером 20 на 20 клеток. По клеткам перемещаются игрок 
и его противники.
После каждого хода игрока карта показывается вновь со всеми противниками на ней:
игрок помечается буквой P; 
противники — буквой E;
пустые места — точкой.
Каждый персонаж игры представлен в виде структуры с полями: 
«Имя»;
«Жизни»;
«Броня»;
«Урон».
Сначала создаётся пять противников в случайных клетках карты:
Имена противникам задаются в формате Enemy #N, где N — порядковый номер. 
Уровень жизни противников задаётся случайно — от 50 до 150. 
Уровень брони варьируется от 0 до 50. 
Урон тоже выбирается случайно — от 15 до 30.
Игрок конструирует своего персонажа самостоятельно. Задаёт все его параметры, включая имя. 
Все персонажи появляются в случайных местах карты.
Игрок ходит с помощью команд: L, R, U, D (по первым буквам слов left, right, up, down). 
В зависимости от команды выбирается направление перемещения: влево, вправо, вверх, вниз.
Противники перемещаются в случайном направлении.
Если игрок перемещается в сторону, где уже кто-то находится, он наносит этому персонажу 
урон. Противники при этом никогда не бьют друг друга: они просто пропускают ход и остаются 
на своём месте. За пределы карты (20 на 20 клеток) ходить нельзя никому. Если кто-то 
выбрал направление за границами, ход пропускается.
Формула расчёта урона совпадает с той, что была в материале. Жизни уменьшаются на размер 
урона. При этом броня тоже сокращается на приведённый урон.
Игра заканчивается, когда умирают либо все противники, либо игрок. В первом случае на 
экран выводится сообщение о победе, во втором — о поражении.
Если в начале хода игрок вводит команду save или load вместо направления перемещения, то 
игра либо сохраняет своё состояние в файл, либо загружает это состояние из файла.
Советы и рекомендации
Для определения команды персонажа можно внутри структуры данных о нём завести флаг.
Для отображения координат персонажей можно использовать структуру вектора из другой 
задачи, но заменить типы координат.
Для сохранения параметров игры и их загрузки можно работать с текстовыми данными. 
Однако записать всё в двоичном формате проще, главное — соблюдать последовательность 
полей:
std::ofstream file("save.bin", std::ios::binary);
    for (int i = 0; i < 6; ++i) {

        file.write((char*)&(characters[i].position),
                   sizeof(characters[i].position));
…
При загрузке используйте ifstream и ту же последовательность полей.
Задание необязательно сдавать на проверку. Но если хотите это сделать, куратор будет 
учитывать следующее: 
Корректно работает сохранение и загрузка в игре.
После загрузки все атрибуты игрока, включая имя, восстанавливаются из файла.
После загрузки количество противников на поле соответствует количеству противников при 
сохранении.
Все игроки после загрузки появляются в местах, где они находились при сохранении.
При ходе игрока не появляются новые противники.
Перед загрузкой файла сохранения проверяется, есть ли он в операционной системе.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
struct Character 
{
    char label;
    string name;
    int health;
    int shield;
    int damage;
    int x;
    int y;
};
int count = 0;
void FieldInit(char mass[][20], Character &player, Character enemy[])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (i == player.y && j == player.x)
            {
                mass[i][j] = player.label;
            } else if (i == enemy[0].y && j == enemy[0].x)
            {
                mass[i][j] = enemy[0].label;
            } else if (i == enemy[1].y && j == enemy[1].x) 
            {
                mass[i][j] = enemy[1].label;
            } else if (i == enemy[2].y && j == enemy[2].x)
            {
                mass[i][j] = enemy[2].label;
            } else if (i == enemy[3].y && j == enemy[3].x)
            {
                mass[i][j] = enemy[3].label;
            } else if (i == enemy[4].y && j == enemy[4].x)
            {
                mass[i][j] = enemy[4].label;
            } else mass[i][j] = '.';
        }
    }
}
void FieldPrint (char mass[][20])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------\n";
}
Character PlayerInit()
{
    Character p;
    cout << "Input person name:\n";
    cin >> p.name;
    cout << "Input person health:\n";
    cin >> p.health;
    cout << "Input person shield:\n";
    cin >> p.shield;
    cout << "Input person damage:\n";
    cin >> p.damage;
    p.label = 'P';
    p.x = rand() % 20;
    p.y = rand() % 20;
    return p;
}
Character EnemyInit(int x)
{
    x++;
    Character e;
    e.name = "Enemy " + to_string(x);
    e.label = 'E';
    e.health = rand() % 101 + 50;
    e.shield = rand() % 51;
    e.damage = rand() % 16 + 15;
    e.x = rand() % 20;
    e.y = rand() % 20;
    return e;
}
void GetShot (Character &player, Character enemy[])
{
    for (int i = 0; i < 5; i++)
    {
        if (player.x == enemy[i].x && player.y == enemy[i].y)
        {
            cout << "____________________________________________\n";
            cout << player.name << ". You hit the enemy!\n";
            cout << "Your health: " << player.health << endl;
            cout << "Your shield: " << player.shield << endl;
            cout << "Your damage: " << player.damage << endl;
            cout << "____________________________________________\n";
            cout << enemy[i].name << " health before: " << enemy[i].health << endl;
            cout << enemy[i].name << " shield before: " << enemy[i].shield << endl;
            cout << "____________________________________________\n";
            player.shield -= enemy[i].damage;
            if (player.shield < 0)
            {
                player.health += player.shield;
                player.shield = 0;
            }
            enemy[i].shield -= player.damage;
            if (enemy[i].shield < 0)
            {
                enemy[i].health += enemy[i].shield;
                enemy[i].shield = 0;
            }
            if (enemy[i].health <= 0)
            {
                enemy[i].health = 0;
                cout << enemy[i].name << " was killed!\n";
                cout << "____________________________________________\n";
                enemy[i].label = '.';
                enemy[i].x = -20;
                enemy[i].y = -20;
                count ++;
             } else 
            {
                cout << enemy[i].name << " health: " << enemy[i].health << endl;
                cout << enemy[i].name << " shield: " << enemy[i].shield << endl;
                cout << "____________________________________________\n";
            }
        }        
    }
}
void EnemyMove (Character &player, Character enemy[])
{
    for (int i = 0; i < 5; i++)
    {
        while(true)
        {
            int move = rand() % 4;
            if (move == 0)
            {
                enemy[i].x++;
                if (enemy[i].x > 19)
                {
                    enemy[i].x--;
                } else if (enemy[i].x == player.x && enemy[i].y == player.y)
                {
                    GetShot(player, enemy);
                    enemy[i].x--;
                } else break;
            } else if (move == 1)
            {
                enemy[i].x--;
                if (enemy[i].x < 0)
                {
                    enemy[i].x++;
                } else if (enemy[i].x == player.x && enemy[i].y == player.y)
                {
                    GetShot(player, enemy);
                    enemy[i].x++;
                }
                else break;
            } else if (move == 2)
            {
                enemy[i].y++;
                if (enemy[i].y > 19)
                {
                    enemy[i].y--;
                } else if (enemy[i].x == player.x && enemy[i].y == player.y)
                {
                    GetShot(player, enemy);
                    enemy[i].y--;
                } else break;
            } else if (move == 3)
            {
                enemy[i].y--;
                if (enemy[i].y < 0)
                {
                    enemy[i].y++;
                } else if (enemy[i].x == player.x && enemy[i].y == player.y)
                {
                    GetShot(player, enemy);
                    enemy[i].y++;
                } else break;
            }
        }    
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (enemy[i].x == enemy[j].x && enemy[i].y == enemy[j].y)
            {
                enemy[i].x--;
            }
        }
    }
}
void PlayGame(char mass[][20], Character &player, Character enemy[])
{
    while(true)
    {
        cout << "Make your move (L - left, R - right, U - up, D - down) or 's' for save 'q' for exit\n";
        char move;
        cin >> move;
        if(move == 'L')
        {
            if (player.x == 0)
            {
                cout << "You get left field edge and can't move left!\n";
                cout << "____________________________________________\n";
                EnemyMove(player, enemy);
            } else 
            {
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if (mass[i][j] == 'P' && mass[i][j - 1] != 'E')
                        {
                            player.x--;                            
                            EnemyMove(player, enemy);
                        } else if (mass[i][j] == 'P' && mass[i][j - 1] == 'E')
                        {
                            player.x--;
                            GetShot(player, enemy);                            
                            EnemyMove(player, enemy);
                        }
                    }
                }
            }
        } else if (move == 'R')
        {
            if (player.x == 19)
            {
                cout << "You get left field edge and can't move right!\n";
                cout << "____________________________________________\n";
                EnemyMove(player, enemy);
            } else 
            {
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if (mass[i][j] == 'P' && mass[i][j + 1] != 'E')
                        {
                            player.x++;                            
                            EnemyMove(player, enemy);                            
                        } else if (mass[i][j] == 'P' && mass[i][j + 1] == 'E')
                        {
                            player.x++;
                            GetShot(player, enemy);                            
                            EnemyMove(player, enemy);
                        }
                    }
                }
            }
        } else if (move == 'U')
        {
            if (player.y == 0)
            {
                cout << "You get left field edge and can't move up!\n";
                cout << "____________________________________________\n";
                EnemyMove(player, enemy);
            } else 
            {
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if (mass[i][j] == 'P' && mass[i - 1][j] != 'E')
                        {
                            player.y--;                            
                            EnemyMove(player, enemy);                            
                        } else if (mass[i][j] == 'P' && mass[i - 1][j] == 'E')
                        {
                            player.y--;
                            GetShot(player, enemy);                            
                            EnemyMove(player, enemy);
                        }
                    }
                }
            }
        }else if (move == 'D')
        {
            if (player.y == 19)
            {
                cout << "You get left field edge and can't move down!\n";
                cout << "____________________________________________\n";
                EnemyMove(player, enemy);
            } else 
            {
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if (mass[i][j] == 'P' && mass[i + 1][j] != 'E')
                        {
                            player.y++;                            
                            EnemyMove(player, enemy);                            
                        } else if (mass[i][j] == 'P' && mass[i + 1][j] == 'E')
                        {
                            player.y++;
                            GetShot(player, enemy);                            
                            EnemyMove(player, enemy);
                        }
                    }
                }
            }
        } else if (move == 'q')
        {
            cout << "You input 'q' for exit.\n";
            cout << "Bye-bye!\n";
            cout << "--------------\n";
            break;
        } else if (move == 's')
        {
            ofstream stream("state.bin", ios::binary);
            stream.write((char*) &player.label, sizeof(player.label));
            int len = player.name.length();
            stream.write((char*) &len, sizeof(len));
            stream.write((char*) player.name.c_str(), len);
            stream.write((char*) &player.health, sizeof(player.health));
            stream.write((char*) &player.shield, sizeof(player.shield));
            stream.write((char*) &player.damage, sizeof(player.damage));
            stream.write((char*) &player.x, sizeof(player.x));
            stream.write((char*) &player.y, sizeof(player.y));
            for (int i = 0; i < 5; i++)
            {
                stream.write((char*) &enemy[i].label, sizeof(enemy[i].label));
                int len = enemy[i].name.length();
                stream.write((char*) &len, sizeof(len));
                stream.write((char*) enemy[i].name.c_str(), len);
                stream.write((char*) &enemy[i].health, sizeof(enemy[i].health));
                stream.write((char*) &enemy[i].shield, sizeof(enemy[i].shield));
                stream.write((char*) &enemy[i].damage, sizeof(enemy[i].damage));
                stream.write((char*) &enemy[i].x, sizeof(enemy[i].x));
                stream.write((char*) &enemy[i].y, sizeof(enemy[i].y));
            }
            stream.close();
        } else cout << "Incorrect input, try again!\n";
        FieldInit(mass, player, enemy);
        FieldPrint(mass);
        if (count == 5)
        {
            cout << player.name << " is win!!!!\n";
            break;
        } else if (player.health < 0)
        {
            cout << player.name << " was killed!!. Enemy is win!!!\n";
            break;
        }
    }
    
}
main() 
{
  cout << "----------------\n";
  cout << "Game.\n";
  cout << "----------------\n";
  string input;
  char field[20][20];
  cout << "Enter 'l' for load the game or 'n' for new game.\n";
  cin >> input;
  Character player;
  Character enemy[5];
  for (int i = 0; i < 5; i++)
  {
     enemy[i] = {EnemyInit(i)};
  }
  if (input == "l")
  {
    ifstream stream("state.bin", ios::binary);
    if (stream.is_open())
    {
        while(!stream.eof())
        {
            stream.read((char*) &player.label, sizeof(player.label));
            int len;
            stream.read((char*) &len, sizeof(len));
            player.name.resize(len);
            stream.read((char*) player.name.c_str(), len);
            stream.read((char*) &player.health, sizeof(player.health));
            stream.read((char*) &player.shield, sizeof(player.shield));
            stream.read((char*) &player.damage, sizeof(player.damage));
            stream.read((char*) &player.x, sizeof(player.x));
            stream.read((char*) &player.y, sizeof(player.y));
            for(int i = 0; i < 5; i++)
            {
                stream.read((char*) &enemy[i].label, sizeof(enemy[i].label));
                stream.read((char*) &len, sizeof(len));
                enemy[i].name.resize(len);
                stream.read((char*) enemy[i].name.c_str(), len);
                stream.read((char*) &enemy[i].health, sizeof(enemy[i].health));
                stream.read((char*) &enemy[i].shield, sizeof(enemy[i].shield));
                stream.read((char*) &enemy[i].damage, sizeof(enemy[i].damage));
                stream.read((char*) &enemy[i].x, sizeof(enemy[i].x));
                stream.read((char*) &enemy[i].y, sizeof(enemy[i].y));
            }
        }
        stream.close();
    } else 
    {
        cout << "Error reading file statement\n";
        cout << "----------------\n";
        player =  PlayerInit();
    }
  } else player = PlayerInit();
  FieldInit(field, player, enemy);
  FieldPrint(field);
  PlayGame(field, player, enemy);
  cout << "__________________\n";
  cout << "Game over! Thank you for playing!\n";
  cout << "__________________\n";
  return 0; 
}