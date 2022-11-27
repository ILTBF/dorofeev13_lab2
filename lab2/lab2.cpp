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

struct Circle {
    Point O;
    double R;
    //инициализация - конструктор
    Circle(Point A = Point(0, 0), double r = 10.0) : O(A), R(r) {
    }
    //Метод для вычисления площади окружности
    double S() {
        return 3.14 * R * R;
    }
    //Метод для вычисление длины окружности
    double L() {
        return 2 * 3.14 * R;
    }
    //вывод информации окружности
    void print() {
        cout << "\n\n Окружность с радиусом " << R << "\n с центром в";
        O.print();
        cout << "\n Площадь: " << S() << "\n Длина окружности: " << L();
    }
    void setPointX(double x) {
        O.setX(x);
    }
    void setPointY(double y) {
        O.setY(y);
    }
};

struct ListPoint {
    Point* points = NULL;
    string name;
    int N = 10;
    //инициализация - конструктор
    ListPoint(unsigned int n = 10, string name = "No name") : N(n), name(name) {
        this->name = string(name);
        points = new Point[N];//выделение динамической памяти для массива точек
    }
    //заполнение массива
    void setPoints() {
        srand(time(NULL));
        for (int i = 0; i < N; i++) {
            points[i].x = rand() % 100;
            points[i].y = rand() % 100;
        }
    }
    //вывод информации о массиве точек
    void print() {
        cout << "\n Кол-во точек: " << N;
        cout << "\n Название массива: " << name;
        for (int i = 0; i < N; i++) {
            points[i].print();
        }
    }
    ~ListPoint() {
    }
};

struct Line {
    ListPoint P;
    string color = "red";
    //инициализация - конструктор
    Line(unsigned int n = 10, string c = "green") : color(c) {
        P = ListPoint(n, "Точки для ломанной линии");
        P.setPoints();
    }
    //вывод информации о ломанной линии
    void print() {
        cout << "\n Ломанная линия, цвет: " << color;
        P.print();
    }
};



int main()
{
    setlocale(LC_ALL, "Russian");
    //статическая память
    Line A = Line(9, "blue");
    A.print();
    cout << "\n";
    //динамическая память
    Line* B = new Line(5, "black");
    B->print();
    delete B;
    //статическая память
    Circle C = Circle(Point(1.0, 1.0), 9.0);
    C.print();
    C.setPointX(2.2);
    C.setPointY(4.8);
    C.print();
    //динамическая память
    Circle* D = new Circle(Point(2.4, 3.3), 4.5);
    D->S();
    D->L();
    D->print();
    delete D;

    Triangle tt = Triangle(Point(1.1, 2.2), Point(3.2, 4.2), Point(2.9, 7.2));
    tt.print();
    tt.Length();
}
