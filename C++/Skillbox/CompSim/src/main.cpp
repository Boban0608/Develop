/*
Проект симулятора работы компьютера
Что нужно сделать
Реализуйте простую модель работы персонального компьютера в качестве многомодульного 
проекта. В компьютере несколько основных, условных компонент.
Центральный процессор (cpu) — должен иметь функцию compute, которая складывает 8 чисел 
из буфера оперативной памяти (см. далее) и выводит результат в консоль.
Оперативная память (ram) — содйержит буфер на 8 целых чисел, которые можно заполнить 
функцией write и считать функцие read.
Жёсткий диск (disk) — имеет в себе две функции, save и load. Функция save должна 
сохранить состояние 8 чисел из оперативной памяти на постоянный носитель в файл data.txt. 
Функция load — загрузить их с носителя в оперативную память.
Графическая карта (gpu) — выводит в консоль 8 чисел из оперативной памяти.
Клавиатура (kbd) — позволяет ввести 8 чисел и разместить их в оперативной памяти.
Каждая компонента должна располагаться в отдельном модуле, с отдельным заголовочным 
файлом. Основной модуль программы (main.cpp) должен считывать пользовательский ввод 
команды, которая соответствует отдельным функциям устройств: sum (вычисление суммы), 
save (сохранить в файл), load (загрузить из файла), input (ввести с клавиатуры), 
display (вывести на экран). Команда exit — выходит из программы.
Советы и рекомендации
Тщательно продумайте зависимости между модулями и теми файлами, которые должны быть 
включены в исходные файлы. Не забывайте про #pragma once в заголовочных файлах.
В заголовочных файлах модулей располагайте только объявления функций. Их определения 
должны быть уже в исходных файлах (CPP).
Что оценивается
Обращение к буферу оперативной памяти делается только через модуль ram, напрямую доступ 
к буферу не осуществляется.
Программа и составленные CMake-файлы конфигурации проекта работают корректно.
Для программы создано два файла CMakeLists.txt, один в основной директории, второй в 
директории src.
В файлах CPP в поле всех #include-директив используется только название файла, не 
должно быть #include-директив с указанием папки. Не допускается:
../include/.. .h
D:/.../include/.. .h
*/

#include <iostream>
#include "cpu.h"
#include "disk.h"
#include "gpu.h"
#include "kbd.h"
#include "command.h"
using namespace std;
int main()
{
    cout << "----------------\n";
    cout << "Computer simulation.\n";
    cout << "----------------\n" << endl;
    cout << "Welcome to computer simulator.\n";
    cout << "You need to enter command below.\n" << endl;
    cout << "--== Starting your PC simulation ==--\n" << endl;  
    while(true)
    {
        cout << "Choose the command [1-5] below:\n";
        cout << "1 - SUM - to sum numbers\n";
        cout << "2 - SAVE - to save result to file\n";
        cout << "3 - LOAD - to load from file\n";
        cout << "4 - INPUT - to input numbers from keyboard\n";
        cout << "5 - DISPLAY to display inputed numbers on the screen\n";
        cout << "6 - EXIT to exit programm\n";
        string input;
        Command cmd;
        cin >> input;
        cmd = GetCommand(input);
        if (cmd == EXIT)
        {
            cout << "______________\n";
            cout << "Thank you for using simulator!\n";
            cout << "Bye-Bye!\n";
            cout << "______________\n";
            break;
        } else if (cmd == SUM)
        {
            cout << "______________\n" << endl; 
            Compute();
            cout << "______________\n" << endl;
        } else if (cmd == SAVE)
        {
            cout << "______________\n" << endl;
            Save();
            cout << "______________\n" << endl;
        } else if (cmd == LOAD)
        {
            cout << "______________\n" << endl;
            Load();
            cout << "______________\n" << endl;
        } else if (cmd == INPUT)
        {
            cout << "______________\n" << endl;
            Input();
            cout << "______________\n" << endl;
        } else if (cmd == DISPLAY)
        {
            cout << "______________\n" << endl;
            cout << endl << "Inputed numbers:\n" << endl;
            Display();
            cout << "______________\n" << endl;
        } else
        {
            cout << "______________\n" << endl;
            cout << "Wrong input!\n" << endl;
            cout << "______________\n" << endl;
        }   
    }
    return 0;
}
