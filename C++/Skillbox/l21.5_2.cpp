/*
Модель данных для посёлка
Что нужно сделать
Используя структуры данных, создайте подробную модель посёлка.
Что известно:
Посёлок состоит из участков, у каждого участка свой номер.
На любом участке может стоять жилой дом, а также другие сооружения: 
гараж, 
сарай (бытовка),
баня. 
Дана информация о площади, которую каждое здание занимает на участке.
В доме может быть 1–3 этажа, на этаже — 2–4 комнаты:
спальня,
кухня,
ванная,
детская,
гостиная.
Дана информация о количестве комнат и высоте потолка на каждом этаже.
Дана информация о площади, которую занимает каждая комната.
В доме и бане может быть печь с трубой.
Для всех упомянутых сущностей нужно объявить структуры данных.
Обязательно для выполнения задания
Опишите структуры данных для создания модели посёлка. Структуры должны быть:
связными и легко расширяемыми,
без дублирующих конструкций.
Реализуйте заполнение структур данных.
Пользователь заполняет данные о посёлке: вводит общее количество участков, а потом 
детализирует каждый.
Сначала указывается количество построек на участке, а затем — информация, какие это 
постройки, сколько этажей в доме, какие комнаты наэтажах.
После ввода данных можно рассчитать суммарный параметр, например процент земли, занимаемой 
постройками, от общей площади посёлка. 
Главное в этой задаче не операция подсчёта, а структуры данных.
Советы и рекомендации
Используйте знания о типах данных в C++. 
Можете применять перечисления и векторы, создавать структуры внутри структур и так далее.
Перечислите комнаты и типы зданий следующим образом:
enum room_type
{
    living,
    children,
    …
Затем используйте полученный тип внутри структуры. Алгоритм заполнения каждого объекта 
одинаковый: 
создать объект нужного типа, 
ввести с клавиатуры значения, 
добавить объект в вектор при помощи push_back.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
enum room_type
{
    living = 1,
    children = 2,
    kitchen = 4,
    bath = 8,
    bedroom = 16
};
struct Floor
{
    int rooms_amount = 2;
    double ceiling_height;
    room_type room1;
    room_type room2;
    room_type room3;
    room_type room4;
    room_type room5;
};
struct Floors
{
    int floor_amount = 1;
    Floor floor1;
    Floor floor2;
    Floor floor3;
};
struct Living_house
{
    Floors floors;
    double square = 0;
    bool owen = false;
};
struct Bath_house
{
    double square = 0;
    bool owen = false;
};
struct Barn
{
    double square = 0;
};
struct Garage
{
    double square = 0;
};
struct Section
{
    Living_house home;
    Bath_house bath_house;
    Barn barn;
    Garage garage;
    int buildings_amount;
};
void NumberSection (vector<Section> &loc)
{
    cout << "Input the number of section on location:\n";
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        Section section[i];
        loc.push_back(section[i]);
    }
    return;
}
void InputData (vector<Section> &loc)
{
    int section, buildings_amount;
    cout << "----------------\n";
    cout << "Input section number you want to change\n";
    cin >> section;
    cout << "----------------\n";
    cout << "You choose section number " << section << endl;
    section--;
    cout << "How much buildings has the section?\n";
    cin >> loc[section].buildings_amount;
    for (int i = 0; i < loc[section].buildings_amount; i++)
    {
        int tmp;
        cout << "Choose building type for " << i + 1 << " building\n";
        cout << "1. House\n";
        cout << "2. Bathhouse\n";
        cout << "3. Barn\n";
        cout << "4. Garage\n";
        cin >> tmp;
        if (tmp == 1)
        {
            cout << "What is the house square?\n";
            cin >> loc[section].home.square;
            cout << "Does the house have a owen(y/n)?\n";
            char ans;
            cin >> ans;
            if (ans == 'y')
            {
                loc[section].home.owen = true;
            }
            cout << "How much floors does house have(from 1 to 3)?\n";
            cin >> loc[section].home.floors.floor_amount;
            for (int j = 0; j < loc[section].home.floors.floor_amount; j++)
            {
                if (j == 0)
                {
                    cout << "What is the ceiling height on "<< j + 1 << " floor?\n";
                    cin >> loc[section].home.floors.floor1.ceiling_height;
                    cout << "How much rooms does the floor " << j + 1 << " have?\n";                
                    cin >> loc[section].home.floors.floor1.rooms_amount;
                    for (int k = 0; k < loc[section].home.floors.floor1.rooms_amount; k++)
                    {
                        cout << "What's the room " << k + 1 << " ?\n";
                        cout << "1. Living room\n";
                        cout << "2. Children room\n";
                        cout << "3. Kithen\n";
                        cout << "4. Bath\n";
                        cout << "5. Bedroom\n";
                        int room_type;
                        cin >> room_type;
                        if (room_type == 1)
                        {
                            loc[section].home.floors.floor1.room1 = living;
                        } else if (room_type == 2)
                        {
                            loc[section].home.floors.floor1.room2 = children;
                        } else if (room_type == 3)
                        {
                            loc[section].home.floors.floor1.room3 = kitchen;
                        } else if (room_type == 4)
                        {
                            loc[section].home.floors.floor1.room4 = bath;
                        } else if (room_type == 5)
                        {
                            loc[section].home.floors.floor1.room5 = bedroom;
                        } else
                        {
                            cout << "Wrong input!\n";
                        }
                    }
                }
                else if (i == 1)            
                {
                    cout << "What is the ceiling height on "<< j + 1 << " floor?\n";
                    cin >> loc[section].home.floors.floor2.ceiling_height;
                    cout << "How much rooms does the floor " << j + 1 << " have?\n";                
                    cin >> loc[section].home.floors.floor2.rooms_amount;
                    for (int k = 0; k < loc[section].home.floors.floor2.rooms_amount; k++)
                    {
                        cout << "What's the room " << k + 1 << " ?\n";
                        cout << "1. Living room\n";
                        cout << "2. Children room\n";
                        cout << "3. Kithen\n";
                        cout << "4. Bath\n";
                        cout << "5. Bedroom\n";
                        int room_type;
                        cin >> room_type;
                        if (room_type == 1)
                        {
                            loc[section].home.floors.floor2.room1 = living;
                        } else if (room_type == 2)
                        {
                            loc[section].home.floors.floor2.room2 = children;
                        } else if (room_type == 3)
                        {
                            loc[section].home.floors.floor2.room3 = kitchen;
                        } else if (room_type == 4)
                        {
                            loc[section].home.floors.floor2.room4 = bath;
                        } else if (room_type == 5)
                        {
                            loc[section].home.floors.floor2.room5 = bedroom;
                        } else
                        {
                            cout << "Wrong input!\n";
                        }
                    }
                }
                else if (i == 2)
                {
                    cout << "What is the ceiling height on "<< j + 1 << " floor?\n";
                    cin >> loc[section].home.floors.floor3.ceiling_height;
                    cout << "How much rooms does the floor " << j + 1 << " have?\n";                
                    cin >> loc[section].home.floors.floor3.rooms_amount;
                    for (int k = 0; k < loc[section].home.floors.floor3.rooms_amount; k++)
                    {
                        cout << "What's the room " << k + 1 << " ?\n";
                        cout << "1. Living room\n";
                        cout << "2. Children room\n";
                        cout << "3. Kithen\n";
                        cout << "4. Bath\n";
                        cout << "5. Bedroom\n";
                        int room_type;
                        cin >> room_type;
                        if (room_type == 1)
                        {
                            loc[section].home.floors.floor3.room1 = living;
                        } else if (room_type == 2)
                        {
                            loc[section].home.floors.floor3.room2 = children;
                        } else if (room_type == 3)
                        {
                            loc[section].home.floors.floor3.room3 = kitchen;
                        } else if (room_type == 4)
                        {
                            loc[section].home.floors.floor3.room4 = bath;
                        } else if (room_type == 5)
                        {
                            loc[section].home.floors.floor3.room5 = bedroom;
                        } else
                        {
                            cout << "Wrong input!\n";
                        }
                    }
                }
                
            }

        } else if (tmp == 2)
        {
            cout << "What's the bathhouse square?\n";
            cin >> loc[section].bath_house.square;
            cout << "Does the bathhouse have a owen(y/n)?\n";
            char ans;
            cin >> ans;
            if (ans == 'y')
            {
                loc[section].bath_house.owen = true;
            }
        } else if (tmp == 3)
        {
            cout << "What's the barn square?\n";
            cin >> loc[section].barn.square;
        } else if (tmp == 4)
        {
            cout << "What's the garage square?\n";
            cin >> loc[section].garage.square;
        } else
        {
            cout << "Wrong input!\n";
        }
    }
    cout << "----------------\n";
    cout << "Enter menu item number or 'q' for exit to previos menu \n";
    cout << "----------------\n";

}
void DisplayData (vector<Section> &loc)
{
    cout << "What section do you want to display?\n";
    int section;
    cin >> section;
    cout << "Info about section " << section << endl;
    section--;
    cout << "Section has " << loc[section].buildings_amount << " buildings.\n";
    if (loc[section].home.square > 1)
    {
        cout << "It has living house with square " << loc[section].home.square << endl;
    }
    if (loc[section].bath_house.square > 1)
    {
        cout << "It has bathhous with square " << loc[section].bath_house.square << endl;
    }
    if (loc[section].barn.square > 1)
    {
        cout << "It has barn with square " << loc[section].barn.square << endl;
    }
    if (loc[section].garage.square > 1)
    {
        cout << "It has garage with square " << loc[section].garage.square << endl;
    }
}
main() 
{
  cout << "----------------\n";
  cout << "Country model.\n";
  cout << "----------------\n";
  string input;
  vector <Section> location; 
  while(true)
  {
    cout << "Enter menu item number or 'q' for exit \n";
    cout << "1. Change the number of sections\n";
    cout << "2. Input section data\n";
    cout << "3. Display info\n";
    cin >> input;
    if (input == "1")
    {
        NumberSection(location);
    } else if (input == "2")
    {
        InputData(location);
    } else if (input == "3")
    {
        DisplayData(location);
    } else if (input == "q")
    {
        cout << "----------------\n";
        cout << "Thank you for using our programm! Bye-bye!!\n";
        cout << "----------------\n";
        break;
    } else
    {
        cout << "Wrong input! Try again. '1', '2' or 'q': \n";
    }
  }
  return 0; 
}