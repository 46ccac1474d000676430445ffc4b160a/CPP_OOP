#ifndef TIME_H
#define TIME_H

#include <time.h>
#include <cstdlib>
#include <ostream>

using namespace std;

//time.h
class Time
{
protected:
    long  seconds;			//количество секунд относительно начала суток

public:
    Time();	//Конструктор без параметров, создает объект
            // используя параметры системного времени
            //(часы, минуты и секунды).
    Time(int h, int m, int s);  //Конструктор с параметрами
    ~Time();			        //Деструктор

    //Функции доступа
    int get_hour();
    int get_min();
    int get_sec();

    Time& set_hour(int);
    Time& set_min(int);
    Time& set_sec(int);

    Time diffTime(const Time& t);	        //разность между текущим и объектом a.
    void showTime(int x, int y, int color); //отображения времени в точке
                                            // с координатами x и y: 09:15:45
    Time& inkr(); 				            //функция инкремента (увеличение на 1 сек)

    //функции сравнения
    int equals(const Time&)const;	//равенство двух объектов Time
    int more(const Time&)const; 	//сравнение двух объектов Time на больше
    int less(const Time&)const; 	//сравнение двух объектов Time на меньше

    friend std::ostream& operator << (std::ostream& o, const Time &t);

};

#endif // TIME_H
