#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <random>
using namespace std;
int proverkanumber()
{
    while (true)
    {
        cout << "\nВведите номер задания - |1|(Шарики), |2|(БЗ_1), |3|(БЗ_2), |4|(БЗ_3), |5|(БЗ_4), |6|(БЗ_5), чтобы выйти введите (0)" << endl;
        int numberzd;
        cin >> numberzd;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте ещё раз" << '\n';
        }
        else
        {
            cin.ignore(32767, '\n');
            return numberzd;
        }
    }
}

int proverka1()
{
    while (true)
    {
        int proverka;
        cin >> proverka;
        if (cin.fail() || (proverka > 10) || (proverka < 1))
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте ещё раз" << '\n'
                 << '\n';
        }
        else
        {
            cin.ignore(32767, '\n');
            return proverka;
        }
    }
}

int proverka2()
{
    while (true)
    {
        int proverka2;
        cin >> proverka2;
        if (cin.fail() || (proverka2 < 0))
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте ещё раз" << '\n'
                 << '\n';
        }
        else
        {
            cin.ignore(32767, '\n');
            return proverka2;
        }
    }
}

int proverka3()
{
    while (true)
    {
        int proverka3;
        cin >> proverka3;
        if (cin.fail() || (proverka3 < 1))
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте ещё раз" << '\n'
                 << '\n';
        }
        else
        {
            cin.ignore(32767, '\n');
            return proverka3;
        }
    }
}

int proverka4()
{
    while (true)
    {
        int proverka4;
        cin >> proverka4;
        if (cin.fail() || (proverka4 < 0))
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте ещё раз" << '\n'
                 << '\n';
        }
        else
        {
            cin.ignore(32767, '\n');
            return proverka4;
        }
    }
}

int proverka5()
{
    while (true)
    {
        int proverka5;
        cin >> proverka5;
        if (cin.fail() || (proverka5 < 1000) || (proverka5 > 9999))
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте ещё раз" << '\n'
                 << '\n';
        }
        else
        {
            cin.ignore(32767, '\n');
            return proverka5;
        }
    }
}

int Fibonachi(int fib)
{
    if ((fib == 1) || (fib == 2))
    {
        return 1;
    }
    else
    {
        return (Fibonachi(fib - 1) + Fibonachi(fib - 2));
    }
}

void BZ_5()
{
    int fib;
    cout << "Введите номер числа Фибоначчи, и получите все числа Фибоначчи до вашего числа" << endl;
    fib = proverka2();
    cout << endl;
    for (int i = 1; i <= fib; i++)
    {
        cout << i << ')' << ' ' << Fibonachi(i) << endl;
    }
}

void BZ_4()
{
    srand(time(NULL));
    int randomnoechoslo1, zagadchislo1;
    char otveti[4] = {'-', '-', '-', '-'};
    bool f = 1, ans = 1;
    string randomnoechoslo2, zagadchislo2;
    cout << "Компьютер задумывает ЧЕТЫРЕХЗНАЧНОЕ число, не содержащее двух одинаковых цифр" << endl;
    while (f)
    {
        randomnoechoslo1 = rand() % 8999 + 1000;
        randomnoechoslo2 = to_string(randomnoechoslo1);
        ans = 1;
        for (int i = 0; i < 3; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                if (randomnoechoslo2[i] == randomnoechoslo2[j])
                {
                    ans = 0;
                    break;
                }
            }
            if (ans == 0)
            {
                break;
            }
        }
        if (ans != 0)
        {
            /*cout << randomnoechoslo1 << endl;*/
            while ((otveti[0] == '-') || (otveti[1] == '-') || (otveti[2] == '-') || (otveti[3] == '-'))
            {
                cout << "Какое число загадал компьютер?" << endl;
                zagadchislo1 = proverka5();
                zagadchislo2 = to_string(zagadchislo1);
                for (int i = 0; i < 4; i++)
                {
                    if (randomnoechoslo2[i] == zagadchislo2[i])
                    {
                        otveti[i] = '+';
                    }
                    else
                    {
                        otveti[i] = '-';
                    }
                }
                for (int i = 0; i < 4; i++)
                {
                    cout << otveti[i];
                }
                cout << endl;
            }
            f = 0;
        }
    }
}

void BZ_3()
{
    srand(time(NULL));
    int dlinamassivov, k = -1;
    cout << "Введите длину массива" << endl;
    dlinamassivov = proverka4();
    int *massivechisel1 = new int[dlinamassivov];
    int *massivechisel2 = new int[dlinamassivov];
    for (int i = 0; i < dlinamassivov; i++)
    {
        massivechisel1[i] = rand() % 100;
    }
    for (int i = 0; i < dlinamassivov; i++)
    {
        massivechisel2[i] = massivechisel1[i];
    }
    cout << endl;
    for (int i = 0; i < dlinamassivov; i++)
    {
        cout << i << '\t';
    }
    cout << endl;
    for (int i = 0; i < dlinamassivov; i++)
    {
        cout << massivechisel1[i] << '\t';
    }
    for (int i = 0; i < dlinamassivov; i++)
    {
        for (int j = 0; j < (dlinamassivov - i - 1); j++)
        {
            if (massivechisel2[j] > massivechisel2[j + 1])
            {
                swap(massivechisel2[j], massivechisel2[j + 1]);
            }
        }
    }
    cout << '\n'
         << '\n';
    for (int i = 0; i < dlinamassivov; i++)
    {
        for (int j = 0; j < dlinamassivov; j++)
        {
            if ((massivechisel2[i] == massivechisel1[j]))
            {
                if (k != j)
                {
                    cout << j << '\t';
                    k = j;
                    break;
                }
                else
                {
                    k = j;
                }
            }
        }
    }
    cout << endl;
    delete[] massivechisel1;
    delete[] massivechisel2;
}

void BZ_2()
{
    int naturalchislo, deliteli, chetchik = 1;
    cout << "Введите натуральное число, и мы найдем все совершенные числа меньшие вашего числа" << endl;
    naturalchislo = proverka3();
    for (int i = 2; i <= naturalchislo; i++)
    {
        deliteli = 0;
        for (int j = 1; j < ((i / 2) + 1); j++)
        {
            if ((i % j) == 0)
            {
                deliteli += j;
            }
        }
        if (deliteli == i)
        {
            cout << chetchik << "-ое совершенное число - " << i << endl;
            chetchik += 1;
        }
    }
}

void BZ_1()
{
    int year1;
    cout << "Введите номер года(положительное целое число)" << endl;
    year1 = proverka2();
    if ((((year1 % 10) + (year1 % 100)) == 0) && (year1 > 90))
    {
        cout << "Номер столетия(век) = " << (year1 / 100) << endl;
    }
    else if (year1 > 90)
    {
        cout << "Номер столетия(век) = " << ((year1 / 100) + 1) << endl;
    }
    else
    {
        cout << "Номер столетия(век) = 0" << endl;
    }
}

void SharikiF()
{
    int n, answer = 0;
    string shariki, perestanovki;
    cout << "Введите количество шариков (от 1 до 10)" << endl;
    n = proverka1();
    for (int i = 48; i < (48 + n); i++)
    {
        shariki.push_back(i);
        perestanovki.push_back(i);
    }
    do
    {
        for (int i = 0; i < n; i++)
        {
            if (perestanovki[i] == shariki[i])
            {
                answer += 1;
                break;
            }
        }
    } while (next_permutation(perestanovki.begin(), perestanovki.end()));
    cout << "Количество подходящих ситуаций = " << answer << endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int numberzd;
    bool flag = 1;
    while (flag)
    {
        numberzd = proverkanumber();
        switch (numberzd)
        {
        case 1:
            SharikiF();
            break;
        case 2:
            BZ_1();
            break;
        case 3:
            BZ_2();
            break;
        case 4:
            BZ_3();
            break;
        case 5:
            BZ_4();
            break;
        case 6:
            BZ_5();
            break;
        case 0:
            flag = 0;
            break;
        default:
            cout << "Таких вариантов не было!!!" << endl;
            break;
        }
    }
    return 0;
}