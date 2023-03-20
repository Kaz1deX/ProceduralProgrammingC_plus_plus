// Номер 1

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    double S, r, p, n;
    cout << "Введите сумму займа рублей (S)" << endl;
    cin >> S;
    cout << "Введите количество лет (n)" << endl;
    cin >> n;
    cout << "Введите процент (p)" << endl;
    cin >> p;
    r = p / 100;
    if (((1 + r) < 0) && (int(n) != n))
    {
        cout << "Ошибка, отрицательные числа можно возводить только в степень целого числа" << endl;
    }
    else
    {
        if (((((pow(1 + r, n)) - 1)) != 0) && (n > 0))
        {
            cout << "S = " << S << " Руб./коп." << endl;
            cout << "n = " << n << " Лет(год(а))" << endl;
            cout << "p = " << p << " %" << endl;
            cout << "m = " << (S * r * (pow(1 + r, n))) / (12 * ((pow(1 + r, n)) - 1)) << " Руб./коп. в месяц" << endl;
        }
        else if ((((pow(1 + r, n)) - 1)) == 0)
        {
            cout << "Месячная выплата (m) = " << S / (n * 12) << " Руб./коп. в месяц" << endl;
        }
        else
        {
            cout << "Ошибка, введите другие значения" << endl;
        }
    }
    return 0;
}

// Номер 2
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    cout << fixed << setprecision(2);
    double S, r, m0, p, m, n;
    int k = 1;
    cout << "Введите сумму займа рублей (S)" << endl;
    cin >> S;
    cout << "Введите количество лет (n)" << endl;
    cin >> n;
    cout << "Введите месячную выплату (m0)" << endl;
    cin >> m0;
    if (n > 0)
    {
        for (p = -100; p <= 200; p += 0.01)
        {
            r = p / 100;
            m = (S * r * (pow(1 + r, n))) / (12 * ((pow(1 + r, n)) - 1));
            if (((((pow(1 + r, n)) - 1)) == 0) && ((abs((S / (n * 12)) - m0)) <= 0.01))
            {
                cout << "Номер " << k << endl;
                cout << "+++++ "
                     << "S = " << S << " Руб./коп." << endl;
                cout << "+++++ "
                     << "n = " << n << " Лет(год(а))" << endl;
                cout << "+++++ "
                     << "p = " << abs(p) << " %" << endl;
                cout << "+++++ "
                     << "m = " << S / (n * 12) << " Руб./коп. в месяц" << endl;
                break;
            }
            else if ((((pow(1 + r, n)) - 1)) == 0)
            {
                cout << "Номер " << k << endl;
                cout << "S = " << S << " Руб./коп." << endl;
                cout << "n = " << n << " Лет(год(а))" << endl;
                cout << "p = " << abs(p) << " %" << endl;
                cout << "m = " << S / (n * 12) << " Руб./коп. в месяц" << endl;
            }
            if (((((pow(1 + r, n)) - 1)) != 0) && (((abs(m - m0)) <= 0.01)))
            {
                cout << "Номер " << k << endl;
                cout << "+++++ "
                     << "S = " << S << " Руб./коп." << endl;
                cout << "+++++ "
                     << "n = " << n << " Лет(год(а))" << endl;
                cout << "+++++ "
                     << "p = " << p << " %" << endl;
                cout << "+++++ "
                     << "m = " << m << " Руб./коп. в месяц" << endl;
                break;
            }
            else if ((((pow(1 + r, n)) - 1)) != 0)
            {
                cout << "Номер " << k << endl;
                cout << "S = " << S << " Руб./коп." << endl;
                cout << "n = " << n << " Лет(год(а))" << endl;
                cout << "p = " << p << " %" << endl;
                cout << "m = " << m << " Руб./коп. в месяц" << endl
                     << endl;
                k += 1;
            }
        }
    }
    else
    {
        cout << "Ошибка, введите другие значения" << endl;
    }
    return 0;
}

// Номер (3) создать файл в программе

#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    ofstream fout;
    fout.open("PetruninFile.txt", ofstream::app);
    if (!fout.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
    }
    else
    {
        string s;
        cout << "Файл открыт" << endl;
        cout << "Введите число" << endl;
        cin >> s;
        fout << s << endl;
    }
    fout.close();
    return 0;
}

// Номер 3

#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    ifstream fin;
    fin.open("C:\\Users\\Maxim\\Desktop\\PetruninZadanie3.txt");
    if (!fin.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
    }
    else
    {
        cout << "Файл открыт" << '\n'
             << '\n';
        string s;
        while (!fin.eof())
        {
            s = "";
            getline(fin, s);
            cout << s << endl;
        }
        cout << endl;
    }
    fin.close();
    return 0;
}

// Номер 4

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    ifstream fin;
    fin.open("C:\\Users\\Maxim\\Desktop\\PetruninZadanie3.txt");
    if (!fin.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
    }
    else
    {
        cout << "Файл открыт" << '\n'
             << '\n';
        double s;
        do
        {
            if (fin >> s)
            {
                cout << s << endl;
            }
            else
            {
                fin.clear();
                fin.ignore(1, ' ');
            }
        } while (!fin.eof());
        cout << endl;
    }
    fin.close();
    return 0;
}

// Номер 5

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    string s;
    int n;
    char k;
    ifstream fin;
    fin.open("C:\\Users\\Maxim\\Desktop\\MyText.txt");
    if (!fin.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
    }
    else
    {
        cout << "Файл открыт" << endl;
        getline(fin, s);
        n = s.size();
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < (n - 1); j++)
            {
                if (((s[j] > s[j + 1]) && ((tolower(s[j]) == tolower(s[j + 1])))) || ((s[j] > s[j + 1]) && ((tolower(s[j]) > tolower(s[j + 1])))) || ((s[j] < s[j + 1]) && ((tolower(s[j]) > tolower(s[j + 1])))))
                {
                    k = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = k;
                }
            }
        }
        cout << s;
    }
    return 0;
}