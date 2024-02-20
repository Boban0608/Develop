/*
Умный дом
Что нужно сделать
Разработайте упрощённую модель умного дома для дачи. Выполните симуляцию его работы на 
протяжении двух дней. Стартовое время для симуляции умного дома 00:00. Есть несколько датчиков: 
датчик температуры снаружи, датчик температуры внутри дома. В доме расположен электронный умный 
щиток с автоматами. Каждый автомат отвечает за включение и отключение определённых устройств 
или групп устройств:
отключение и включение питания всего дома;
основные розетки дома;
свет внутри дома;
наружный свет в саду;
отопление в помещении;
отопление водопровода, идущего из скважины с насосом;
кондиционер в помещении.
Есть несколько условий по включению/отключению техники в доме и вне его.
Как только температура снаружи падает ниже 0 °С, надо включить систему обогрева водопровода. 
Если температура снаружи поднялась выше 5 °С, то систему обогрева водопровода нужно отключить.
Если на дворе вечер (время больше 16:00 и меньше 5:00 утра) и снаружи есть какое-то движение, 
то необходимо включить садовое освещение. Если движения нет или время не вечернее, то света 
снаружи быть не должно.
Если температура в помещении упала ниже 22 °С, должно включиться отопление. Как только 
температура равна или поднимается выше 25 °С, отопление автоматически отключается.
Если температура в помещении поднялась до 30 °С, включается кондиционер. Как только температура 
становится 25 °С, кондиционер отключается.
Всё освещение в доме также умное и поддерживает настройку цветовой температуры для комфортного 
нахождения. Каждый день начиная с 16:00 и до 20:00 температура цвета должна плавно изменяться 
с 5000K до 2700К. Разумеется, это изменение должно происходить, если свет сейчас включён. 
В 00:00 температура сбрасывается до 5000К.
Все события по отключению и включению устройств должны выводиться в консоль явным образом. 
Если устройство не изменило своё состояние (осталось включённым или выключенным), событие 
генерироваться не должно! Если свет в доме включён, должна отображаться текущая цветовая 
температура.
Программа выполняется следующим образом:
Каждый час пользователь сообщает состояние всех основных датчиков и света (температура снаружи, 
температура внутри, есть ли движение снаружи, включён ли свет в доме).
Данные параметры вводятся разом в одну строку через пробел, а потом парсятся в переменные из 
строкового буфера stringstream.
Информация о движении выводится в формате yes/no.
Включение и отключение света происходит с помощью on/off.
Рекомендации
Состояние переключателей можно хранить в перечислении вида:
enum switches 
{> 
    LIGHTS_INSIDE = 1, 
    LIGHTS_OUTSIDE = 2, 
    HEATERS = 4, 
    WATER_PIPE_HEATING = 8, 
    CONDITIONER = 16 
};
Чтобы включить обогреватель, нужно написать switches_state |= HEATERS; Чтобы выключить — 
switches_state &= ~HEATERS;
Пример работы программы:
Temperature inside, temperature outside, movement, lights:
10 10 yes on
Heaters ON!
Lights ON!
Color temperature: 5000K
Temperature inside, temperature outside, movement, lights:
10 10 yes on
Color temperature: 5000K
Temperature inside, temperature outside, movement, lights:
30 30 yes on
Heaters OFF!
Conditioner ON!
Color temperature: 5000K
Temperature inside, temperature outside, movement, lights:
30 30 yes on
Color temperature: 5000K
Temperature inside, temperature outside, movement, lights:
*/
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
enum switches {
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};
int switches_state;
vector <string> home_data;
bool SwichState (int t_o, int t_in, string move, string lights, int time){
    if (t_o < -50 || t_o > 50 ||
        t_in < -50 || t_in > 50 ||
        move != "y" && move != "n" ||
        lights != "on" && lights != "off"){
            cout << "Wrong input! Try again in write format or check t (- 50 - + 50)\n";
            return false;
        } else {
            if (t_o < 0 && !(switches_state & WATER_PIPE_HEATING)) {                
                switches_state |= WATER_PIPE_HEATING;
                cout << "Water pipe heaters ON!\n"; 
            } else if (t_o > 5 && (switches_state & WATER_PIPE_HEATING)) {
                switches_state &= ~WATER_PIPE_HEATING;
                cout << "Water pipe heaters OFF!\n";
            }
            if (time < 5 && move == "y" && !(switches_state & LIGHTS_OUTSIDE) || 
                time > 16 && move == "y" && !(switches_state & LIGHTS_OUTSIDE) || 
                time < 29 && move == "y" && !(switches_state & LIGHTS_OUTSIDE) || 
                time > 40 && move == "y" && !(switches_state & LIGHTS_OUTSIDE)) {
                    switches_state |= LIGHTS_OUTSIDE;
                    cout << "Lights outsight ON!\n";
                }
            else if (move == "n" && (switches_state & LIGHTS_OUTSIDE)){
                switches_state &= ~LIGHTS_OUTSIDE;
                cout << "Lights outsight OFF!\n";
            }
            if (t_in < 22 && !(switches_state & HEATERS)) {
                switches_state |= HEATERS;
                cout << "Heaters ON!\n";
            }
            else if (t_in >= 25 && (switches_state & HEATERS)) {
                switches_state &= ~HEATERS;
                cout << "Heaters OFF!\n";
            }
            if (t_in >= 30 && !(switches_state & CONDITIONER)) {
                switches_state |= CONDITIONER;
                cout << "Conditioner ON!\n";
            }
            else if (t_in <= 25 && (switches_state & CONDITIONER)) {
                switches_state &= ~CONDITIONER;
                cout << "Conditioner OFF!\n";
            }
            if (lights == "on") switches_state |= LIGHTS_INSIDE;
            else switches_state &= ~LIGHTS_INSIDE;            
            if (time >= 16 && (switches_state & LIGHTS_INSIDE) && time < 17 ||
                time >= 40 && (switches_state & LIGHTS_INSIDE) && time < 41) cout  << "Color temperature: 5000K\n";
            else if (time >= 17 && (switches_state & LIGHTS_INSIDE) && time < 18 ||
                     time >= 41 && (switches_state & LIGHTS_INSIDE) && time < 42) cout  << "Color temperature: 4000K\n";
            else if (time >= 18 && (switches_state & LIGHTS_INSIDE) && time < 19 ||
                     time >= 42 && (switches_state & LIGHTS_INSIDE) && time < 43) cout  << "Color temperature: 3400K\n";
            else if (time >= 19 && (switches_state & LIGHTS_INSIDE) && time < 24 ||
                     time >= 43 && (switches_state & LIGHTS_INSIDE) && time < 44) cout  << "Color temperature: 2700K\n";
            else if (switches_state & LIGHTS_INSIDE) cout << "Color temperature: 5000K\n";
            return true;
        }
}
main() {
  cout << "----------------\n";
  cout << "Smart House\n";
  cout << "----------------\n";
  string sensors;
  int time = 0;
  do { 
    bool check;
    cout << "Input sensor conditions in format - t_outside t_inside movement_outside(y/n) house_ligth?(on/off):\n";
    getline(cin, sensors);
    stringstream temp_sensor(sensors);
    int t_outside, t_inside;
    string movement_outside, house_light;
    temp_sensor >> t_outside >> t_inside >> movement_outside >> house_light;
    check = SwichState(t_outside, t_inside, movement_outside, house_light, time);
    if (check) time++;
  } while(time < 48);
  return 0; 
}