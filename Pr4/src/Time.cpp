#include "Time.h"

Time::Time()
{
//    time_t ft = time(nullptr);
//    std::tm* t = localtime(&ft);
//    seconds = t->tm_hour * 3600 + t->tm_min * 60 + t->tm_sec;
}

Time::Time(int h, int m, int s) :
    seconds( (h%24)*3600 + (m%1440)*60 + (s%86400) )
{
}

Time::~Time()
{
}

int Time::get_hour()
{
    return seconds / 3600;
}

int Time::get_min()
{
    return seconds % 3600 / 60;
}

int Time::get_sec()
{
    return seconds % 3600 % 60;
}

Time& Time::set_hour(int h)
{
    seconds = (seconds % 3600) + (h%24)*3600;
    return *this;
}

Time& Time::set_min(int m)
{
    seconds = (seconds / 3600 * 3600) + ((m%1440) * 60) + (seconds % 3600 % 60);
    return *this;
}

Time& Time::set_sec(int s)
{
    seconds = (seconds / 3600 * 3600) + (seconds % 3600 / 60 * 60) + (s%86400);
    return *this;
}

Time Time::diffTime(const Time& t)
{
    return Time(0, 0, abs(seconds - t.seconds) );
}

void Time::showTime(int x, int y, int color)
{

}

Time& Time::inkr()
{
    seconds = (++seconds) % 86400;
    return *this;
}

int Time::equals(const Time& t) const
{
    return !(seconds - t.seconds);
}

int Time::more(const Time& t) const
{
    return seconds > t.seconds;
}

int Time::less(const Time& t) const
{
    return seconds < t.seconds;
}

std::ostream& operator << (std::ostream& o, const Time &t)
{
    return o << (t.seconds / 3600) << ':' << (t.seconds % 3600 / 60) << ':' << (t.seconds % 3600 % 60);
}

