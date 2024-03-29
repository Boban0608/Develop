/*
Матрицы
Требуется реализовать небольшую программу для сравнения двух двумерных матриц размером 4 × 4 
на предмет их полного равенства. Если матрицы равны друг другу, необходимо взять одну из матриц 
и привести её к диагональному виду. Программа принимает на вход две целочисленные матрицы A и B,
которые вводятся с помощью std::cin, и сравнивает их на предмет полного равенства. Если матрицы 
равны, то об этом сообщается в стандартном выводе. Алгоритм должен быть по возможности 
оптимальным и не проводить лишних операций. Если матрицы не равны, выводится соответствующее 
сообщение и выполнение программы прекращается. Если матрицы равны, то из них выбирается одна и 
преобразуется в диагональную. Конвертация в диагональную форму делается путём простейшего 
зануления всех элементов, лежащих вне главной диагонали. Напомню, что диагональная матрица — 
это такая матрица, у которой все элементы вне диагонали равны нулю. Диагональ матрицы, в свою 
очередь, — это все элементы, расположенные по диагонали от первого элемента первой строки до 
последнего элемента последней строки. Итоговую диагональную матрицу можно расположить на месте 
прежней матрицы, не используя дополнительных переменных. Результат преобразования требуется 
вывести в консоль для проверки. Ищите именно оптимальное решение, оно довольно простое.
Советы и рекомендации
Чтобы не производить лишних вычислений, стоит при первом же расхождении значений в 
соответствующих ячейках завершить алгоритм.
Если хотя бы один элемент матриц не совпадает, можно сразу останавливать проверку.
Чтобы в результате получить диагональную матрицу, достаточно пройти по каждому элементу массива 
и занулить его, если строка не равна столбцу.
Достаточно привести матрицу к диагональному виду. Делать алгоритмическое преобразование не нужно.
Сравнение матриц и приведение матрицы к диагональному виду лучше оформить в виде отдельных 
функций.
Что оценивается
Программа корректно сравнивает две матрицы и в случае совпадения формирует диагональную матрицу.
*/

#include <iostream>
using namespace std;
bool check_equal(int mat1[][4], int mat2[][4]){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (mat1[i][j] != mat2[i][j]){
                return false;
            }
        }
    }
    return true;
}
void diag_matrix(int mat[][4]){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (i != j){
                mat[i][j] = 0;
            }
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
main() {
  cout << "----------------\n";
  cout << "Matrix comparing\n";
  cout << "----------------\n";
  int mat1 [4][4], mat2[4][4];
  bool equal;
  cout << "You need to input 2 matrix(4x4).\n";
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      cout << "Input first matrix element: ";
      cin >> mat1[i][j];
    }   
  }
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      cout << "Input second matrix element: ";
      cin >> mat2[i][j];
    }   
  } 
  equal = check_equal(mat1, mat2);
  if (equal){
    cout << "The matrixes is equal!\n";
    cout << "----------------\n";
    cout << "Diagonal matrix is: \n";
    diag_matrix(mat1);
  } else {
    cout << "----------------\n";
    cout << "The matrixes isn't equal!";
  }  
  return 0; 
}