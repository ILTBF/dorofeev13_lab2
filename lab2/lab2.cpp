#define _CRT_SECURE_NO_WARNINGS
#include "locale.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <Windows.h>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

struct Point {
    double x, y;
    //инициализация - конструктор
    Point(double x_ = 0.0, double y_ = 0.0) {
        x = x_;
        y = y_;
    }
    //вывод информации о точке
    void print() {
        cout << "\n точка (" << x << ", " << y << ")";
    }
    //замена точки
    void setX(double x_) {
        x = x_;
    }
    void setY(double y_) {
        y = y_;
    }

};

int main()
{
    setlocale(LC_ALL, "Russian");
}
