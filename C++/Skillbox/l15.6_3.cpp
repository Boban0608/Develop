/*
С клавиатуры вводятся числа. Когда пользователь вводит «-1»,  необходимо выводить на экран 
пятое по возрастанию число среди введённых. Когда пользователь вводит «-2», программа завершает 
работу.
Пример:
ввод: 7 5 3 1 2 4 6 -1
вывод: 5 (в отсортированном виде массив выглядит так: {1,2,3,4,5,6,7})
ввод: 1 1 1 -1
вывод: 2 (в отсортированном виде массив выглядит так: {1,1,1,1,2,3,4,5,6,7})
ввод -2
завершение программы
Советы и рекомендации
Нужно удостовериться, что можно вывести требуемое число (может быть меньше пяти чисел).
*/

#include <iostream>
#include <vector>
using namespace std;
vector <int> get_sort(vector <int> a){
  for (int i = 0; i < a.size(); i++){
    for (int j = 1; j < a.size() - i; j++){
      if (a[j - 1] > a[j]){
        int tmp = a[j - 1];
        a[j - 1] = a[j];
        a[j] = tmp;
      }
    }
  }
  return a;
}
void show_array(vector <int> a){
  for (int i = 0; i < a.size(); i++){
    cout << a[i] << " ";
  }
  cout << endl;
}
main() {
  cout << "----------------\n";
  cout << "5 number in array\n";
  cout << "----------------\n";
  vector <int> a;
  cout << "Input numbers/ -1 for result/ -2 for exit.\n";
  while(true){
    int num;
    cin >> num;
    if (num == -1){
      cout << a[4] << endl;
      show_array(a);
    } else if (num == -2){
      cout << "By-by!!!\n";
      cout << "----------------\n";
      break;
    } else {
      a.push_back(num);
      if (a.size() > 1) a = get_sort(a);
    }
  }
  return 0; 
}