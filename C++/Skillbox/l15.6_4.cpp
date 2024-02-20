/*
Вам даётся массив целых чисел, отсортированных по возрастанию. Необходимо вывести его на экран 
отсортированным в порядке возрастания модуля чисел.
Пример:
Массив {-100,-50, -5, 1, 10, 15}
Вывод: 1, -5, 10, 15, -50, -100
Советы и рекомендации
Положительные числа уже отсортированы в порядке возрастания модулей.
*/

#include <iostream>
#include <vector>
using namespace std;
vector <int> module_sorting(vector <int> a){
    for (int i = 0; i < a.size(); i++){
        for (int j = 1; j < a.size() - i; j++){
            int mod = 0;
            if (a[j - 1] < 0){
                mod = a[j - 1] * (-1);
                if (mod > a[j]){
                    int tmp = 0;
                    tmp = a[j - 1];
                    a[j - 1] = a[j];
                    a[j] = tmp;
                }
            } 
        }
    }
    return a;
}
vector <int> module_sorting2(vector <int> a){
    for (int i = a.size() - 1; i >= 0; i--){
        for (int j = 0; j < i; j++){
            int mod1 = 0;
            if (a[i] < 0) mod1 = a[i] * (-1);
            else mod1 = a[i];
            int mod = 0;
            if (a[j] < 0){
                mod = a[j] * (-1);
                if (mod1 < mod){
                    int tmp = 0;
                    tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
            } else if (mod1 < a[j]){
                int tmp = 0;
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    return a;
}
void show_array (vector <int> a){
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
}
main() {
  cout << "----------------\n";
  cout << "Sorting by module\n";
  cout << "----------------\n";
  vector <int> a{-100,-50, -5, 1, 10, 15};
  vector <int> b = a;
  a = module_sorting(a);
  b = module_sorting2(b);
  show_array(a);
  cout << endl;
  show_array(b);
  return 0; 
}