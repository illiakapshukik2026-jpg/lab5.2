// Lab 5_2.cpp
// Варіант 6
// Обчислення суми ряду Тейлора для ln(1-x) за допомогою функцій

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Прототипи функцій
double S(const double x, const double eps, int& n, double s);
double A(const double x, const int n, double a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    // Введення початкових даних
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(12) << "ln(1-x)" << " |"
        << setw(12) << "S" << " |"
        << setw(7) << "n" << " |" << endl;
    cout << "-------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        s = S(x, eps, n, s);

        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(12) << setprecision(5) << log(1.0 - x) << " |"
            << setw(12) << setprecision(5) << s << " |"
            << setw(7) << n << " |" << endl;

        x += dx;
    }
    cout << "-------------------------------------------------" << endl;

    return 0;
}

// Обчислення наступного члена ряду через попередній
double A(const double x, const int n, double a)
{
    return -a * x * (n - 1.0) / n;
}

// Обчислення суми ряду з точністю eps
double S(const double x, const double eps, int& n, double s)
{
    n = 1;
    double a = -x; // Перший доданок (при n = 1)
    s = a;
    do {
        n++;
        a = A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
    return s;
}