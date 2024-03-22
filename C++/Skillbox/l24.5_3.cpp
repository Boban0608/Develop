/*
Реализация программы таймера
Что нужно сделать
Реализуйте работу точного таймера с визуальной отдачей.
В начале программы пользователь вводит количество минут и секунд, которые требуется 
засечь на таймере, и нажимает «Ввод».
После этого начинается обратный отсчёт времени, о чём незамедлительно и последовательно 
сообщается пользователю. Формат вывода такой же, как и при вводе интервала: минуты и секунды.
Как только отсчёт на таймере иссяк, программа сообщает об этом с помощью вывода в консоль 
специального сообщения. Сообщение вместо аудиосигнала может выглядеть так: DING! DING! DING!
Советы и рекомендации
Для ввода значения для засекания времени используйте std::get_time, но в качестве формата 
запросите только минуты и секунды. Целевое время для остановки таймера вычислите сами с 
помощью манипуляции над текущим std::time. Количество оставшегося времени выводите в цикле 
и вычислите его самостоятельно с помощью обращения с типом std::time_t как с секундами.
Что оценивается
Корректность работы программы при разных заданных дефинициях макросов.
*/

#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
void CountDown(tm &timeinfo)
{
    time_t future_time = time(nullptr) + 60 * timeinfo.tm_min + timeinfo.tm_sec;
    tm * local_future = localtime(&future_time);
    time_t current_time = time(nullptr);
    cout << "--==Timer is started==--\n" << endl;
    cout << "Finnish time - " << local_future->tm_hour << ":" << local_future->tm_min 
         << ":" << local_future->tm_sec << endl;
    for (;future_time >= current_time;)
    {
        if (current_time != time(nullptr))
        {
            tm * local_current = localtime(&current_time);
            cout << local_current->tm_hour << ":" << local_current->tm_min 
                 << ":" << local_current->tm_sec << endl;
            current_time = time(nullptr);
        }

    }
    cout << "DING! DING! DING!" << endl;
    cout << "--==Timer is finished==--";
}
main ()
{
    cout << "----------------\n";
    cout << "Timer.\n";
    cout << "----------------\n"; 
    cout << endl;
    cout << "Input necessary time in format [mm:ss]\n";
    time_t t = time(nullptr);
    tm timeinfo = *localtime(&t);
    cin >> get_time(&timeinfo, "%M:%S");
    cout << "----------------\n";
    CountDown(timeinfo);
    return 0;
}
