// Процедурное программирование
// Домашнее задание №1

// Задание 1

#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Ваше имя - Максим" << endl;
    return 0;
}

// Задание 2

#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    double x, y;
    cout << "Введите первое число" << endl;
    cin >> x;
    cout << "Введите второе число" << endl;
    cin >> y;
    cout << "Сумма = " << x + y << endl;
    cout << "Разность = " << x - y << endl;
    cout << "Произведение = " << x * y << endl;
    if (y != 0)
    {
        cout << "Частное = " << x / y << endl;
    }
    else
    {
        cout << "Частного нет, потому что на 0 делить нельзя" << endl;
    }
    return 0;
}

// Задание 3

#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    double b, c;
    cout << "Чтобы найти x уравнения bx + c = 0, нужно ввести b и c" << endl;
    cout << "Введите b" << endl;
    cin >> b;
    cout << "Введите c" << endl;
    cin >> c;
    if (b != 0)
    {
        cout << "x = " << (0 - c) / b << endl;
    }
    else if (c != 0)
    {
        cout << "Уравнение не имеет решений" << endl;
    }
    else
    {
        cout << "Уравнение имеет множество решений" << endl;
    }
    return 0;
}

// Задание 4

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    double a, b, c, d;
    cout << "Чтобы найти x уравнения ax^2 + bx + c = 0, нужно ввести a, b, c" << endl;
    cout << "Введите a" << endl;
    cin >> a;
    cout << "Введите b" << endl;
    cin >> b;
    cout << "Введите c" << endl;
    cin >> c;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                cout << "Уравнение имеет множество решений" << endl;
            }
            else
            {
                cout << "Уравнение не имеет решений" << endl;
            }
        }
        else
        {
            cout << "x = " << (0 - c) / b << endl;
        }
    }
    else
    {
        d = ((b * b) - (4 * a * c));
        if (d < 0)
        {
            cout << "Уравнение не имеет решений" << endl;
        }
        else if (d == 0)
        {
            cout << "x = " << ((-b) / (2 * a)) << endl;
        }
        else
        {
            cout << "x = " << ((-b) + (sqrt(d))) / (2 * a) << " и " << ((-b) - (sqrt(d))) / (2 * a) << endl;
        }
    }
    return 0;
}

// Задание 5

#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    string a, b, c;
    cout << "На все вопросы отвечайте da или net" << endl;
    cout << "На улице день?" << endl;
    cin >> a;
    if (a == "da")
    {
        cout << "Шторы раздвинуты?" << endl;
        cin >> b;
        if (b == "da")
        {
            cout << "В комнате светло" << endl;
        }
        else
        {
            cout << "Лампа включена?" << endl;
            cin >> c;
            if (c == "da")
            {
                cout << "В комнате светло" << endl;
            }
            else
            {
                cout << "В комнате тёмно" << endl;
            }
        }
    }
    else
    {
        cout << "Лампа включена?" << endl;
        cin >> c;
        if (c == "da")
        {
            cout << "В комнате светло" << endl;
        }
        else
        {
            cout << "В комнате тёмно" << endl;
        }
    }
    return 0;
}