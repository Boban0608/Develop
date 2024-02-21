/*
Разработка детектора PNG-файла
Что нужно сделать
Разработайте программу, которая получает на вход, в стандартный ввод, путь к файлу. На выходе 
программа должна определить, является ли данный файл PNG-изображением. Данная процедура не 
просто должна смотреть на расширение файла, но и произвести минимальный анализ его 
внутренностей, в бинарном режиме.
Внутренности валидного бинарного файла начинаются со специального 8-байтового заголовка. Нас 
будут интересовать первые четыре байта. Первый байт всегда имеет значение −119 (число со 
знаком минус), а следующие — это просто символы ‘P’, ‘N’, ‘G’, расположенные друг за другом. 
Обратите внимание, что все они в верхнем регистре.
По результатам проверки пути и внутренностей требуется сообщить пользователю о результате 
проверки в стандартный вывод.
Советы и рекомендации
Чтобы определить расширение файла, используйте функцию substr, которая получает офсет и длину 
подстроки и возвращает её.
Что оценивается
Для произвольных путей файлов, введённых пользователем, требуется выдавать корректный 
результат — являются ли они PNG-файлами или нет.
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void CheckPath(string &path, ifstream &path_buffer){
    path_buffer.open(path);
    while(!path_buffer.is_open()) {
        cout << "Path file is incorrect! Try again.\n";
        cin >> path;
        path_buffer.open(path); 
    }
    path_buffer.close();
}
void IsPNG(string &path, ifstream &path_buffer){
    string ext = path.substr(path.length() - 3);
    if (ext != "png"){
        cout << "File extention is not png!";
        return;
    }
    path_buffer.open(path, ios::binary);
    char tmp[4];
    path_buffer.read(tmp, 4);
    if (tmp[0] != char(-119) || tmp[1] != 'P' 
        || tmp[2] != 'N' || tmp[3] != 'G'){
        cout << "It's not real PNG file!\n";    
    } else cout << "It's real PNG file. Congratulations!\n";
    path_buffer.close();
}
main() {
  cout << "----------------\n";
  cout << "PNG identifier.\n";
  cout << "----------------\n";
  string path;
  cout << "Input path to file PNG:\n";
  cin >> path;
  ifstream path_buffer;
  CheckPath(path, path_buffer);
  IsPNG(path, path_buffer);
  return 0; 
}