/*
Математический вектор
Что нужно сделать
Реализуйте структуру двумерного математического вектора и основные операции над ним. 
Обе координаты вектора (x и y) должны быть вещественными числами.
Начиная работу с программой, пользователь вводит команду. Затем в зависимости от команды 
пользователь вводит аргументы. Это могут быть как векторы, так и обычные скалярные 
значения. Результат помещается в стандартный вывод. Это тоже может быть или вектор, 
или скаляр.
Реализуйте в виде отдельных функций операции:
сложение двух векторов — команда add;
вычитание двух векторов — команда subtract;
умножение вектора на скаляр — команда scale;
нахождение длины вектора — команда length;
нормализация вектора — команда normalize.
Советы и рекомендации
Для выбора команды используйте конструкцию вида if (operation == "add"). Тут так и 
напрашиваются отдельные функции для каждой операции.
*/
#include <iostream>
using namespace std;
struct Vec 
{
    float x;
    float y;
};
void GetSum ()
{
    Vec a, b;
    cout << "Input coordinate 1-st vector in format [x y]\n";
    cin >> a.x >> a.y;
    cout << "Input coordinate 2-nd vector in format [x y]\n";
    cin >> b.x >> b.y;
    Vec c {a.x + b.x, a.y + b.y};
    cout << "----------------\n";
    cout << "Vector sum - \n" ;
    printf("x = %.2f, y = %.2f \n", c.x, c.y);
    cout << "----------------\n";
}
void GetDiff()
{
    Vec a, b;
    cout << "Input coordinate 1-st vector in format [x y]\n";
    cin >> a.x >> a.y;
    cout << "Input coordinate 2-nd vector in format [x y]\n";
    cin >> b.x >> b.y;
    Vec c {a.x - b.x, a.y - b.y};
    cout << "----------------\n";
    cout << "Vector difference - \n" ;
    printf("x = %.2f, y = %.2f \n", c.x, c.y);
    cout << "----------------\n";
}
void GetComposition()
{
    Vec a;
    float b;
    cout << "Input coordinate vector in format [x y]\n";
    cin >> a.x >> a.y;
    cout << "Input scalar number\n";
    cin >> b;
    Vec c {a.x * b, a.y * b};
    cout << "Vector multiplying by a scalar - \n" ;
    printf("x = %.2f, y = %.2f \n", c.x, c.y);
    cout << "----------------\n";    
}
void GetLength()
{
    Vec a;
    cout << "Input coordinate vector in format [x y]\n";
    cin >> a.x >> a.y;
    float b = (a.x * a.x + a.y * a.y);
    cout << "Vector length - \n" ;
    cout << b << endl;
    cout << "----------------\n";
}
void GetNorm()
{
    Vec a;
    cout << "Input coordinate vector in format [x y]\n";
    cin >> a.x >> a.y;
    float b = (a.x * a.x + a.y * a.y);
    a.x *= 1 / b;
    a.y *= 1 / b;
    cout << "Vector normalization - \n";
    printf ("x = %.2f, y = %.2f \n", a.x, a.y);
    cout << "----------------\n";
}
main() 
{
  cout << "----------------\n";
  cout << "Math vector.\n";
  cout << "----------------\n";
  string input;
  Vec base {0, 0};
  while(true)
  {
    cout << "Input menu item\n";
    cout << "add - to adding vectors\n";
    cout << "subtract - to vectors subtraction\n";
    cout << "scale - to multiplying a vector by a scalar\n";
    cout << "length - to finding vector length\n";
    cout << "normalize - to vector normalization\n";
    cout << "q - for exit\n";
    cin >> input;
    if (input == "add")
    {
        GetSum();
    } else if (input == "subtract")
    {
        GetDiff();
    } else if (input == "scale")
    {
        GetComposition();
    } else if (input == "length")
    {
        GetLength();
    } else if (input == "normalize")
    {
        GetNorm();
    } else if (input == "q")
    {
        cout << "----------------\n";
        cout << "Thank you for using our programm! Bye-bye!!\n";
        cout << "----------------\n";
        break;
    } else
    {
        cout << "Wrong input! Try again.\n";
    }
  }
  return 0; 
}