/*
Реализация игры «Что? Где? Когда?»
Что нужно сделать
Реализуйте простую версию интеллектуальной игры «Что? Где? Когда?». 
Как происходит игра
В начале каждого хода игроки вращают волчок, то есть выбирают сектор на 
столе, который сейчас играет. Всего таких секторов 13. Сектор выбирается 
так: с клавиатуры вводится офсет (смещение) относительно текущего сектора 
на барабане. Исходя из этого офсета вычисляется новый активный сектор, который 
и будет играть в этом ходе. Если выпавший сектор уже играл, выбирает следующий 
неигравший за ним. В начале всей игры стрелка установлена на первом секторе.
Как только играет какой-то из секторов, с него берётся письмо с вопросом — то 
есть считывается из файла данного сектора. Вопрос показывается на экране.
После того как вопрос показан, от игрока ожидается ответ на него. Игрок вводит 
этот ответ с помощью стандартного ввода. То, что он ввёл, сравнивается с ответом, 
который хранится во втором файле, ассоциированном с активным сектором. Данный файл 
должен содержать лишь одно слово-ответ.
Если ответ знатока-игрока был правильным, ему начисляется один балл. Если неверен, 
то балл уходит телезрителям.
Игра продолжается до тех пор, пока или игрок, или зрители не наберут шесть баллов. 
После этого называется победитель и программа заканчивает работу.
Что оценивается
Игра должна корректно работать от первого хода до последнего. В результате обязательно 
должен выявляться победитель.
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void InitQtrue(bool (&qtrue)[13]){
    for (int i = 0; i < 13; i++){
        qtrue[i] = true;
    }
}
void GetQuest(ifstream &buffer, string &path,bool (&qtrue)[13], int &offset){
    cout << "Your turn. Spin the spinning top!\n";
    cout << "Input offset for next question(1-13): ";
    int tmp;
    string question;
    cin >> tmp;
    offset += tmp;
    if (offset > 13) offset -= 13;
    while (!qtrue[offset - 1]){
        offset++;
    }
    qtrue[offset - 1] = false;
    buffer.open(path);
    for (int i = 0; i < offset; i++){
      getline(buffer, question);
    } 
    buffer.close();
    cout << question << endl;
}
bool GetAnswer(ifstream &buffer, string &path, int &offset){
    string answer;
    string tmp;
    cout << "Input your answer: ";
    cin >> answer;
    buffer.open(path);
    for (int i = 0; i < offset; i++){
      getline(buffer, tmp);
    }
    buffer.close();
    return(answer == tmp);
}
main() {
  cout << "----------------\n";
  cout << "What, where, when?\n";
  cout << "----------------\n";
  string qpath = "question.txt";
  string apath = "answer.txt";
  ifstream qpath_buffer, apath_buffer;
  int offset = 0;
  bool qtrue[13];
  InitQtrue(qtrue);
  int gamer = 0;
  int viewer = 0;
  while (gamer != 6 && viewer != 6){
    bool answer;
    GetQuest(qpath_buffer, qpath, qtrue, offset);
    answer = GetAnswer(apath_buffer, apath, offset);
    cout << endl << endl << "----------------\n";
    if (answer) {
        cout << "Right anwer! Point for gamers!\n";
        gamer++;
    }
    else {
        cout << "Nice try! But point goes to TV viewers!\n";
        viewer++;
    }
    cout << "----------------\n" << endl << endl;
    cout << "Current result (gamer, viewer): " << gamer << " " << viewer << endl << endl;
  }  
  if (gamer > viewer) cout << "Gamer TEAM is winner!!!";
  else cout << "Viewer TEAM is winner!!!";
  return 0; 
}