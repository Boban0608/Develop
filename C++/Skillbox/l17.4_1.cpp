/*
Напишите функцию, принимающую два указателя на int и меняющую местами содержимое этих 
указателей.
*/
#include <iostream>
using namespace std;
void SwapFunc(int* a, int* b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
main() {
  cout << "----------------\n";
  cout << "Pointer 1\n";
  cout << "----------------\n";
  int a = 5, b = 10;
  SwapFunc(&a, &b);
  cout << a << " " << b;
  return 0; 
}