#include <iostream>
#include <stdio.h>
#include <stdbool.h>

class data1
{
protected:
    int _year;
    int _month;
    int _day;

public:
    data1(int year = 1, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    data1(const data1 &n)
    {
        _year = n._year;
        _month = n._month;
        _day = n._day;
    }
    void print();
    data1 operator+(int n);
    data1 &operator+=(int n);
    data1 &operator-=(int n);
    data1 operator-(int n);
    bool operator>(const data1 &n);
    bool operator>=(const data1 &n);
    bool operator==(const data1 &n);
    bool operator<(const data1 &n);
    bool operator<=(const data1 &n);
    int operator-(const data1 &n);
    bool operator!=(const data1 &n);
    data1 operator++(int);
    data1 &operator++();
    data1 &operator--();
    data1 operator--(int);
    ~data1()
    {
        _year = _month = _day = 0;
    }
};