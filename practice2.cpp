// Процедурное программирование
// Домашнее задание №2

// Задание 1

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    double r, R, h, l;
    cout << "Для вычисления объёма и полной поверхности усечённого конуса введите высоту, радиус нижнего основания, радиус верхнего основания и образующую." << endl;
    cout << "Введите радиус нижнего основания (R)" << endl;
    cin >> R;
    cout << "Введите радиус верхнего основания (r)" << endl;
    cin >> r;
    cout << "Введите высоту (h)" << endl;
    cin >> h;
    cout << "Введите образующую (l)" << endl;
    cin >> l;
    if (((pow(R - r, 2)) + (pow(h, 2))) == (pow(l, 2)))
    {
        cout << "Объём усечённого конуса (V) = " << ((pow(3, -1)) * M_PI * h * ((pow(R, 2)) + R * r + (pow(r, 2)))) << endl;
        cout << "Полная поверхность усечённого конуса (S) = " << M_PI * ((pow(R, 2)) + (R + r) * l + (pow(r, 2))) << endl;
    }
    else
    {
        cout << "Усечённого конуса с такими значениями не существует!" << endl;
    }
    return 0;
}

// Задание 2

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    double a, x;
    cout << "Введите число a" << endl;
    cin >> a;

    return 0;
}

// Задание 3

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    double x, y, b;
    cout << "Введите x" << endl;
    cin >> x;
    cout << "Введите y" << endl;
    cin >> y;
    cout << "Введите b" << endl;
    cin >> b;
    if (((b - y) > 0) && ((b - x) >= 0))
    {
        cout << "z = " << (log(b - y) * (sqrt(b - x))) << endl;
    }
    else
    {
        cout << "Ошибка, введите другие значения" << endl;
    }
    return 0;
}

// Задание 4

#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    int i, n;
    cout << "Введите натуральное число" << endl;
    cin >> n;
    if (n > 0)
    {
        for (i = 1; i <= 10; i++)
        {
            cout << n << " ";
            n = n + 1;
        }
    }
    return 0;
}

// Задание 5

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    double x;
    x = -4;
    while (x <= 4)
    {
        cout << "При x = " << x << " ; "
             << "y = " << (((x * x) - 2 * x + 2) / (x - 1)) << endl;
        x = x + (0.5);
    }
    return 0;
}