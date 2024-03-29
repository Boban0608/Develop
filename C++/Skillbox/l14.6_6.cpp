/*
Проход змейкой (дополнительное задание)
Есть двумерный массив целых чисел размером 5 на 5 элементов. Его надо инициализировать и 
отобразить на экране. Особенность именно в способе этой инициализации. Элементы должны быть 
инициализированы не последовательно, а змейкой: в конце каждой строки мы должны не переходить 
к первому элементу следующей строки, а начать наоборот, с последнего элемента и так далее. 
В конечном отображении массива числа должны быть упорядочены по возрастанию, но змеевидно от 
строке к строке. Сама же последовательность чисел — это простое линейное возрастание от 0 до 
24, для её учёта можно завести отдельную переменную.
Попытайтесь решить эту задачу используя минимальное количество временных переменных и без 
условных переходов if. Если вы найдёте формулу индексации, будет замечательно! Она может быть 
весьма витиеватой..
Советы и рекомендации
Результирующий массив должен выглядеть так:
0 1 2 3 4 
9 8 7 6 5 
10 11 12 13 14 
19 18 17 16 15 
20 21 22 23 24
Внешний и внутренний циклы идут от 0 до 5, тут ничего нового. Первый индекс (строка) тоже без 
сюрпризов: это значение счётчика внешнего цикла:
for (int i = 0; i < 5; ++i) { 
        for (int j = 0; j < 5; ++j) { 
            digits[i][...] = number; 
            number += 1; 
        } 
… 
    }

Самое сложное тут — это номер столбца. Чтобы сначала двигаться слева направо, а на следующей 
строке наоборот, стоит завести переменную-множитель, которая на чётных строках будет равна 1. 
На нечётных строках меняет знак: multiplier *= −1;
Что оценивается
В решении не используются условные конструкции.
*/

#include <iostream>
using namespace std;
void snake_init(int snake[][5]){
    int count = 0;
    int multi = -1;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            snake[i][2 + multi * 2 - multi * j] = count;
            count++;
        }
        multi *= -1;
    }
}
void show_snake (int snake[][5]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << snake[i][j] << " ";
        }
        cout << endl;
    }
}
main() {
  cout << "----------------\n";
  cout << "'Snake' walk\n";
  cout << "----------------\n";
  int snake[5][5];
  snake_init(snake);
  show_snake(snake);
  return 0; 
}