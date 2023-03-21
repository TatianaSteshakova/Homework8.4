#include <iostream>

using namespace std;

class Function {
public:
    virtual double evaluate(double x) = 0;
    virtual void printResult() = 0;
};

class Ellipse : public Function {
private:
    double a, b;
    double y;
public:
    Ellipse(double a, double b) : a(a), b(b) {}
    double evaluate(double x) {
        y = b * sqrt(1 - x * x / (a * a));
        return y;
    }
    void printResult() {
        cout << "Значение y на эллипсе: " << y << endl;
    }
};

class Hyperbola : public Function {
private:
    double a, b;
    double y;
public:
    Hyperbola(double a, double b) : a(a), b(b) {}
    double evaluate(double x) {
        y = b * sqrt(1 + x * x / (a * a));
        return y;
    }
    void printResult() {
        cout << "Значение y на гиперболе: " << y << endl;
    }
};

class Parabola : public Function {
private:
    double a;
    double y;
public:
    Parabola(double a) : a(a) {}
    double evaluate(double x) {
        y = a * x * x;
        return y;
    }
    void printResult() {
        cout << "Значение y на параболе: " << y << endl;
    }
};

void print(Function& f, double x) {
    cout << "f(" << x << ") = " << f.evaluate(x) << endl;
    f.printResult();
}

int main() {
    setlocale(0, "Rus");

    Function* f1 = new Ellipse(2, 3);
    Function* f2 = new Hyperbola(2, 3);
    Function* f3 = new Parabola(2);

    double x = 0.5;

    cout << "Указатели на базовый класс:" << endl;
    print(*f1, x);
    print(*f2, x);
    print(*f3, x);

    delete f1;
    delete f2;
    delete f3;

    return 0;
}
