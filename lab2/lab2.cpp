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

class Point1 {
public:
    double x, y;
public:
    Point1(double x_ = 0.0, double y_ = 0.0) {
        x = x_;
        y = y_;
    }
    void print() {
        cout << "\n точка (" << x << ", " << y << ")";
    }
    void setX(double x_) {
        x = x_;
    }
    void setY(double y_) {
        y = y_;
    }
};

class Circle1 {
private:
    Point1 O;
    double R;
public:
    Circle1() {}
    Circle1(Point1 A, double r) {
        O = A;
        R = r;
    }
    double S() {
        return 3.14 * R * R;
    }
    //Метод для вычисление длины окружности
    double L() {
        return 2 * 3.14 * R;
    }
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

class Triangle1 {
private:
    Point1 abc[3];
public:
    Triangle1() {}
    Triangle1(Point1 A, Point1 B, Point1 C) {
        abc[0] = A;
        abc[1] = B;
        abc[2] = C;
    }
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

class ListPoint1 {
private:
    Point1* points = NULL;
    string name;
    int N = 10;
public:
    ListPoint1() {}
    ListPoint1(int n, string name_) {
        N = n;
        this->name = string(name_);
        points = new Point1[N];//выделение динамической памяти для массива точек
    }
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
    ~ListPoint1() {
    }
};

class Line1 {
private:
    ListPoint1 P;
    string color;
public:
    Line1() {}
    Line1(int n, string c) {
        color = c;
        P = ListPoint1(n, "Точки для ломанной линии");
        P.setPoints();
    }
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

    ////////////////////////////////////////////////////////////////////////////

    Triangle1 t = Triangle1(Point1(1.0, 2.0), Point1(3.2, 4.1), Point1(2.0, 5.0));
    t.print();
    t.Length();
    cout << "\n";
    Line1 l = Line1(7, "yellow");
    l.print();

    Circle1 c = Circle1(Point1(2.1, 3.5), 9);
    c.print();

    Circle1 mas1[2]; //Статический массив со статическими окружностями
    mas1[0] = c;
    mas1[0].print();
    Circle1 c1 = Circle1(Point1(3.5, 5.1), 7);
    mas1[1] = c1;
    mas1[1].print();

    Circle1* mas2 = new Circle1[2]; //Динамический массив с динамическими окружностями
    mas2[0] = c;
    mas2[0].print();
    delete[] mas2;

    Circle1 mas3[2]; ////Массив с ссылками на объекты
    Circle1* c2 = new Circle1(Point1(1.4, 2.5), 11);
    mas3[0] = *c2;
    mas3[0].print();
    delete c2;
}
