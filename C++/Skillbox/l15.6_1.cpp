/*
Вам даётся массив целых чисел. Необходимо найти такие два индекса i и j в этом массиве, что 
сумма a[i], a[i+1], a[i+2], … a[j] будет максимально возможной и вывести их.

a = {-2,1,-3,4,-1,2,1,-5,4}

Тогда наибольшая сумма последовательных элементов находится между индексами 3 и 6: {4,-1,2,1}, 
сумма = 6. Необходимо вывести 3 и 6.
*/

#include <iostream>
#include <vector>
using namespace std;
main() {
  cout << "----------------\n";
  cout << "Searching array index\n";
  cout << "----------------\n";
  vector <int> a{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int sum = 0;
  int minind = 0;
  int maxind = 0;
  int biggestSum = 0;
  for (int i = 0; i < a.size() - 1; i++){
    sum = a[i];
    for (int j = i + 1; j < a.size(); j++){
        sum += a[j];
        if (sum > biggestSum){
            minind = i;
            maxind = j;
            biggestSum = sum;
        }
    }
  }
  cout << minind << " " << maxind;
  return 0; 
}