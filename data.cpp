#include "data.h"

using namespace std;
int getmonthday(int year, int month)
{
    int day[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        day[2] = 29;
    }
    return day[month];
}
data1 &data1::operator+=(int n)
{
    if (n < 0)
    {
        return *this -= (-n);
    }
    _day += n;
    while (_day > getmonthday(_year, _month))
    {
        _day -= getmonthday(_year, _month);
        _month++;
        if (_month == 13)
        {
            _year++;
            _month = 1;
        }
    }
    return *this;
}

data1 data1::operator+(int n)
{
    data1 tmp = *this;
    tmp += n;
    return tmp;
}
void data1::print()
{
    cout << _year << "年" << _month << "月" << _day << "日" << endl;
}
data1 &data1::operator-=(int n)
{
    if (n < 0)
    {
        return *this += (-n);
    }
    _day -= n;
    while (_day <= 0)
    {
        _month--;
        if (_month == 0)
        {
            _year--;
            _month = 12;
        }
        _day += getmonthday(_year, _month);
    }
    return *this;
}
data1 data1::operator-(int n)
{
    data1 tmp = *this;
    tmp -= n;
    return tmp;
}
bool data1::operator==(const data1 &n)
{
    return _year == n._year &&
           _month == n._month &&
           _day == n._day;
}
bool data1::operator>(const data1 &n)
{
    if (_year > n._year)
    {
        return true;
    }
    if (_year < n._year)
    {
        return false;
    }
    if (_month > n._month)
    {
        return true;
    }
    if (_month < n._month)
    {
        return false;
    }
    if (_day > n._day)
    {
        return true;
    }
    if (_day <= n._day)
    {
        return false;
    }
    return false;
}
bool data1::operator>=(const data1 &n)
{
    return ((*this > n) || (*this == n));
}
bool data1::operator<(const data1 &n)
{
    return (!(*this >= n));
}
bool data1::operator<=(const data1 &n)
{
    return (!(*this > n));
}
bool data1::operator!=(const data1 &n)
{
    return (!(*this == n));
}
int data1::operator-(const data1 &n)
{
    if (*this == n)
    {
        return 0;
    }
    int flag = 1;
    data1 max = *this;
    data1 min = n;
    if (max < min)
    {
        min = *this;
        max = n;
        flag = -1;
    }
    int i = 1;
    while (min + 1 < max)
    {
        min++;
        i++;
    }
    return (i * flag);
}
data1 data1::operator++(int)
{
    data1 tmp = *this;
    *this += 1;
    return tmp;
}
data1 &data1::operator++()
{
    *this += 1;
    return *this;
}
data1 &data1::operator--()
{
    *this -= 1;
    return *this;
}
data1 data1::operator--(int)
{
    data1 tmp = *this;
    *this -= 1;
    return tmp;
}