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

struct Triangle {
    Point abc[3];
    //инициализация - конструктор
    Triangle(Point A = Point(0, 0), Point B = Point(0, 0), Point C = Point(0, 0)) {
        abc[0] = A;
        abc[1] = B;
        abc[2] = C;
    }
    //вывод информации о координатах треугольника
    void print() {
        cout << "\n\n Координаты треугольника: ";
        for (int i = 0; i < 3; i++) {
            abc[i].print();
        }
    }
    //Метод для вычисление длин сторон треугольника
    double Length() {
        double a, b, c;
        a = sqrt((abc[0].x - abc[1].x) * (abc[0].x - abc[1].x) + (abc[0].y - abc[1].y) * (abc[0].y - abc[1].y));
        b = sqrt((abc[0].x - abc[2].x) * (abc[0].x - abc[2].x) + (abc[0].y - abc[2].y) * (abc[0].y - abc[2].y));
        c = sqrt((abc[1].x - abc[2].x) * (abc[1].x - abc[2].x) + (abc[1].y - abc[2].y) * (abc[1].y - abc[2].y));
        cout << "\n Длина стороны A: " << a << "\n Длина стороны B: " << b << "\n Длина стороны C: " << c;
        return 0;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
}
