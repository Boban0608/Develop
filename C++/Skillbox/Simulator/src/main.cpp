/*
Что нужно сделать
Реализуйте простой симулятор проведения медицинской операции у пациента. Пользователь 
выступает в роли хирурга, который запрашивает инструменты у ассистента и применяет их 
сообразно ситуации.
Пользователь взаимодействует с программой с помощью команд. Команды не имеют сложной 
встроенной логики: они просто принимают нужные данные в качестве аргументов и выводят 
сообщения в консоль о выполнении. Данные команд — это одна или две двумерные точки в 
формате double с координатами X и Y соответственно.
Команда scalpel — принимает на вход две двумерные координаты начала и конца разреза или 
линии отсечения. При выполнении в консоль выводится сообщение о том, что был сделан разрез 
между введёнными координатами.
Команда hemostat принимает на вход одну точку, в которой требуется сделать зажим, о чём 
также сообщает в консоль.
Команда tweezers — пинцет, как и зажим, принимает одну точку для применения. Сообщение 
об этом выводится в консоль.
Команда suture — хирургическая игла, которая делает шов между двумя указанными точками.
Операция всегда начинается с команды scalpel и заканчивается командой suture. Для окончания 
работы программы их параметры-точки должны совпасть.
Программу требуется реализовать именно с помощью одного заголовочного файла и одного файла 
с исходным кодом (CPP). В заголовочном файле должны находиться функции-инструменты. В 
основном файле — основная логика программы, обработка ввода пользователя.
Советы и рекомендации
Создайте структуру с типом двумерной координаты (точки) вместе с набором функций для ввода 
этой координаты из консоли, её вывода в консоль и сравнения на предмет равенства. Для этих 
целей удобнее всего создать ещё один заголовочный файл.
Обратите внимание на порядок команд.
Заголовочные файлы с расширением .h следует расположить в папке include. Файлы исходного 
кода с расширением .cpp — в папке src.
Что оценивается
Все команды вводятся пользователем через стандартный ввод.
Программа и CMake-файл конфигурации проекта работают корректно.
*/

#include <iostream>
#include "commands.h"
#include "struct.h"
using namespace std;
int main()
{
    incision incision;
    suturestr suturestr;
    cout << "----------------\n";
    cout << "Surgery simulation.\n";
    cout << "----------------\n" << endl;
    cout << "Welcome to surgery simulator.\n";
    cout << "You need to enter command below.\n" << endl;
    cout << "First of all you have to make incision.\n"<< endl;
    cout << "--== Starting your surgery ==--\n" << endl;
    incision = Scalpel();
    while(true)
    {
        cout << "Choose the command [1-4] below to continue the surgery:\n";
        cout << "1 - Scalpel - to make incision\n";
        cout << "2 - Hemostat - to clamp\n";
        cout << "3 - Tweezers - to use tweezers\n";
        cout << "4 - Suture - to sew incision\n";
        cout << "5 - to exit programm\n";
        string input;
        command cmd;
        cin >> input;
        cmd = GetCommand(input);
        if (cmd == quit)
        {
            cout << "______________\n";
            cout << "Thank you for using simulator!\n";
            cout << "Bye-Bye!\n";
            cout << "______________\n";
            break;
        } else if (cmd == scalpel)
        {
            incision = Scalpel();
        } else if (cmd == hemostat)
        {
            Hemostat();
        } else if (cmd == tweezers)
        {
            Tweezers();
        } else if (cmd == suture)
        {
            suturestr = Suture();
            if (suturestr.x == incision.x0 && suturestr.y == incision.y0)
            {
                incision.x0 = 0;
                incision.y0 = 0;
            } else if (incision.x0 == 0 && incision.y0 == 0 && 
                       suturestr.x == incision.x1 && suturestr.y == incision.y1)
            {
                SimEnd();
                break;
            }
        } else
        {
            cout << "Wrong input!\n" << endl;
        }    
    }
    return 0;
}
