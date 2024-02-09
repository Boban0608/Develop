/*
Пупырка
После посылки из Китая осталась спецплёнка для бережной перевозки груза — пупырка. Всего в 
пупырке 12 на 12 шариков-пузырьков. Состояние любого пузырька: он либо целый, либо нет, то 
есть true или false (тип массива — bool). Для начала требуется реализовать отдельную функцию 
инициализации пупырки начальным состоянием: полностью целая пупырка, все элементы true.
Программа заключается в последовательном лопании целых регионов пузырьков. Перед каждым таким 
лопанием надо показывать пользователю полностью всю плёнку: o — это целый пузырёк, 
x — лопнутый. Это тоже надо выделить в отдельную функцию. Итак, как выглядит само лопание. 
Пользователь вводит две координаты: начала региона и конца региона. Процедура лопания пузырей 
должна быть реализована с помощью отдельной функции, все аргументы должны проверяться на 
валидность, что они в в рамках диапазона возможных значений, иначе должна быть выведена ошибка. 
После лопания каждого пузыря, который не был ещё лопнут до того, в консоль должно выводиться 
сообщение “Pop!”.
Лопание должно продолжаться до последнего пузырька. Как только вся пупырка потрачена, программа 
заканчивает выполнение. Вы можете подсчитать окончание в самой функции по отображению пузырьков 
плёнки, так как функция выполняется после каждого лопания.
Советы и рекомендации
Обратите внимание, что лопание пузырей делается с помощью региона, а не одной точки.
Регион задаётся двумя координатами, это координаты углов прямоугольника.
При лопании региона достаточно запустить цикл только по этим элементам. Не нужно проходить 
каждый раз по всей матрице.
Всю область плёнки удобно представить в виде двумерного массива типа bool.
Инициализировать вручную такой массив сложно, лучше воспользоваться вложенными циклами.
Для проверки на целостность одной ячейки (если вы используете тип bool) можно не сравнивать её 
с истиной, а указать в условии имя переменной.
Например, вместо:
if (shell[i][j] == true)
{
  …
}
Достаточно записать:
if (shell[i][j])
{
  …
}
Такой трюк можно проделывать с переменными типа bool.
Что оценивается
Программа заканчивает выполнение только после того, как не осталось целых пузырей.
Лопание пузырей производится с помощью прямоугольной области.
*/

#include <iostream>
using namespace std;
void film_init(bool film[][12]){
  for (int i = 0; i < 12; i++){
    for (int j = 0; j < 12; j++){
      film[i][j] = true;
    }
  }
}
bool show_film(bool film[][12]){
  bool empty = true;
  for (int i = 0; i < 12; i++){
    for (int j = 0; j < 12; j++){
      if (film[i][j]){
        cout << "O" << " ";
        empty = false;
      } else {
        cout << "X" << " ";
      }
    }
    cout << endl;
  }  
  return empty;
}
void pop_bubble (bool film[][12], int i, int j, int k, int l){
  i--;
  j--;
  k--;
  l--;
  int x = j;
  for (; i <= k; i++){
    for (; j <= l; j++){
      if (film[i][j]){
        cout << "POP\n";
        film[i][j] = false;
      }
    }
    j = x;
  }
}
main() {
  cout << "----------------\n";
  cout << "'POP' programm\n";
  cout << "----------------\n";
  bool film[12][12];
  film_init(film);
  show_film(film);
  cout << "----------------\n";
  cout << "You see the film with bubble.\n";
  cout << "You can 'pop' any in range 12x12\n";
  cout << "Just enter range in format - 'row' 'column' for 1-st coordinate\n";
  cout << "Then the same for 2-nd coordinate\n";
  cout << "----------------\n";
  bool check = false;
  while(!check){
    int a, b, c, d;
    cout << "Input 1-st coordinate (1 1 for example): ";
    cin >> a >> b;
    cout << "Input 2-nd coordinate: ";
    cin >> c >> d;
    if (a < 1 || a > 12 || b < 1 || b > 12 
      || c < 1 || c > 12 || d < 1 || d > 12){
      cout << "Out of range! Try another coordinate!\n";
    } else {
      pop_bubble(film, a, b, c, d);
      check = show_film(film);
    }
    
  }
  return 0; 
}