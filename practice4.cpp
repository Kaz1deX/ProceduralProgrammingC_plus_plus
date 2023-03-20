#include <iostream>
#include <fstream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
using namespace std;
int Indexback(char element, char bykvi[])
{
    for (int i = 0; i < 36; i++)
    {
        if (element == bykvi[i])
        {
            return i;
        }
    }
}
int Desiatichnoe(string oldnumber, int osnovanie, char bykvi[])
{
    int desiatichnoesumma = 0, stepen = 0;
    for (int i = ((oldnumber.size()) - 1); i >= 0; i--)
    {
        desiatichnoesumma += Indexback(oldnumber[i], bykvi) * (pow(osnovanie, stepen));
        stepen += 1;
    }
    return desiatichnoesumma;
}
string Novoeosnovanie(int desiatichnoesumma, int newnumber, char bykvi[])
{
    int desiatichnoesumma0 = desiatichnoesumma;
    string answer, answer2;
    while (desiatichnoesumma0 > 0)
    {
        answer += bykvi[desiatichnoesumma0 % newnumber];
        desiatichnoesumma0 = desiatichnoesumma0 / newnumber;
    }
    for (int i = ((answer.size()) - 1); i >= 0; i--)
    {
        answer2 += answer[i];
    }
    return answer2;
}
char zadanie11(double cena1, double cena2, double cena3, double maxim)
{
    if (maxim == cena1)
    {
        return ('1');
    }
    if (maxim == cena2)
    {
        return ('2');
    }
    if (maxim == cena3)
    {
        return ('3');
    }
}
char zadanie12(double cena1, double cena2, double cena3, double minim)
{
    if (minim == cena1)
    {
        return ('1');
    }
    if (minim == cena2)
    {
        return ('2');
    }
    if (minim == cena3)
    {
        return ('3');
    }
}
int Decoder(char c)
{
    switch (c)
    {
    case 'I':
        return 1;
        break;
    case 'V':
        return 5;
        break;
    case 'X':
        return 10;
        break;
    case 'L':
        return 50;
        break;
    case 'C':
        return 100;
        break;
    case 'D':
        return 500;
        break;
    case 'M':
        return 1000;
        break;
    default:
        return 0;
        break;
    }
}

char Sign(double x)
{
    if (x > 0)
    {
        return '+';
    }
    else if (x == 0)
    {
        return '0';
    }
    else
    {
        return '-';
    }
}

double Priamo(double dlina, double shirina)
{
    return (dlina * shirina);
}

double Triangle(double storona, double visota)
{
    return (0.5 * storona * visota);
}

double Krug(double radius)
{
    return ((M_PI) * (pow(radius, 2)));
}

int Randomnoe(int chislo_1, int chislo_2, int chislo_3)
{
    if (chislo_2 == -1)
    {
        return 0;
    }
    else if (chislo_2 == 0)
    {
        return 0;
    }
    else if (chislo_2 > 0)
    {
        return ((chislo_1 * Randomnoe(chislo_1, ((chislo_2)-1), chislo_3) + chislo_2) % chislo_3);
    }
    else
    {
        return 0;
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    const int width = 20, length = 110, cenacomission = 2, prodavec = 3, tovar = 4;
    int numberzd, figura, chislo_1, chislo_2, chislo_3, summa = 0, tmp = 0, res = 0, y, aaa[prodavec][tovar], osnovanie, newnumber, index1 = 0, index2 = 10, maximocnovanie = -1000000;
    bool flag = 1, flag2 = 1, flag3 = 1;
    double s, sum, x, dlina, shirina, storona, visota, radius, bbb[tovar][cenacomission], ccc[prodavec][cenacomission], maxim1, minim1, maxim2, minim2, summa8 = 0;
    char a[width][length], bykvi[36];
    string str, rimsk, oldnumber;
    fstream file;
    while (flag)
    {
        cout << "\nДз №4. Введите номер задания - (1) (2) (3) (4) (5) (6) (7) (8) (9) , чтобы выйти введите (0)" << endl;
        cin >> numberzd;
        switch (numberzd)
        {
        case 1:
            cout << endl;
            sum = 0;
            str = "   ";
            file.open("C:\\Users\\Maxim\\Desktop\\Zadanie4(1).txt");
            if (!file.is_open())
            {
                cout << "Ошибка открытия файла" << endl;
            }
            else
            {
                cout << "Файл открыт" << endl;
                cout << endl;
                cout << "Введите 10 чисел" << endl;
                cout << endl;
                for (int i = 0; i < 10; i++)
                {
                    cout << "Введите " << i + 1 << " число" << endl;
                    cin >> s;
                    file << s << " ";
                }
                file.seekg(0);
                do
                {
                    if (file >> s)
                    {
                        sum += s;
                    }
                    else
                    {
                        file.clear();
                        file.ignore(1, ' ');
                    }
                } while (!file.eof());
                cout << "\nСумма чисел = " << sum << endl;
                file.seekg(0);
                getline(file, str);
                cout << str << endl;
            }
            file.close();
            break;
        case 2:
            cout << endl;
            cout << "Введите число" << endl;
            cin >> x;
            cout << "Знак вашего числа "
                 << "(" << Sign(x) << ")" << endl;
            break;
        case 3:
            cout << endl;
            while (flag2)
            {
                cout << "\nВыберите площадь какой фигуры вы хотите найти : Прямоугольник(1) , Треугольник(2) , Круг(3) , ВЫХОД(0)" << endl;
                cin >> figura;
                switch (figura)
                {
                case 1:
                    cout << "Введите длину прямоугольника" << endl;
                    cin >> dlina;
                    cout << "Введите ширину прямоугольника" << endl;
                    cin >> shirina;
                    if ((dlina > 0) && (shirina > 0))
                    {
                        cout << "Площадь прямоугольника = " << Priamo(dlina, shirina) << endl;
                    }
                    else
                    {
                        cout << "Ошибка, такую площадь нельзя посчитать" << endl;
                    }
                    break;
                case 2:
                    cout << "Введите сторону треугольника" << endl;
                    cin >> storona;
                    cout << "Введите высоту, проведённую к этой стороне треугольника" << endl;
                    cin >> visota;
                    if ((storona > 0) && (visota > 0))
                    {
                        cout << "Площадь треугольника = " << Triangle(storona, visota) << endl;
                    }
                    else
                    {
                        cout << "Ошибка, такую площадь нельзя посчитать" << endl;
                    }
                    break;
                case 3:
                    cout << "Введите радиус круга" << endl;
                    cin >> radius;
                    if (radius > 0)
                    {
                        cout << "Площадь круга = " << Krug(radius) / (M_PI) << "PI или " << Krug(radius) << endl;
                    }
                    else
                    {
                        cout << "Ошибка, такую площадь нельзя посчитать" << endl;
                    }
                    break;
                case 0:
                    flag2 = 0;
                    break;
                default:
                    cout << "Таких вариантов не было!!!" << endl;
                    break;
                }
            }
            break;
        case 4:
            cout << endl;
            for (int i = 0; i < 6; i++)
            {
                for (int i = 0; i < 8; i++)
                {
                    cout << "* ";
                }
                for (int i = 0; i < 17; i++)
                {
                    cout << "- ";
                }
                cout << endl;
            }
            for (int i = 0; i < 7; i++)
            {
                for (int i = 0; i < 25; i++)
                {
                    cout << "- ";
                }
                cout << endl;
            }
            break;
        case 5:
            cout << endl;
            for (int i = 0; i < width; i++)
            {
                for (int j = 0; j < length; j++)
                {
                    a[i][j] = ' ';
                }
            }
            for (double x = -0.8; x < 10; x += 0.1)
            {
                y = int(sin(x) * 10);
                a[10 + y][10 + int(x * 10)] = '*';
            }
            for (int i = 0; i < length; i++)
            {
                a[10][i] = '-';
            }
            for (int i = 0; i < width; i++)
            {
                a[i][41] = '|';
            }
            for (int i = 0; i < width; i++)
            {
                for (int j = 0; j < length; j++)
                {
                    cout << a[i][j];
                }
                cout << endl;
            }
            break;
        case 6:
            cout << endl;
            cout << "Введите римскую запись числа" << endl;
            cin >> rimsk;
            if ((count(rimsk.begin(), rimsk.end(), 'I') <= 3) && (count(rimsk.begin(), rimsk.end(), 'V') <= 1) && (count(rimsk.begin(), rimsk.end(), 'X') <= 3) && (count(rimsk.begin(), rimsk.end(), 'L') <= 1) && (count(rimsk.begin(), rimsk.end(), 'C') <= 3) && (count(rimsk.begin(), rimsk.end(), 'D') <= 1))
            {
                if (rimsk[0] == '-')
                {
                    for (int i = 1; i < rimsk.size(); i++)
                    {
                        if (Decoder(rimsk[i]) == 0)
                        {
                            flag3 = 0;
                            break;
                        }
                    }
                    if (flag3)
                    {
                        for (int i = 1; i < rimsk.size(); i++)
                        {
                            int n = Decoder(rimsk[i]);
                            if (n < tmp)
                            {
                                res += tmp;
                                tmp = n;
                            }
                            else if (n > tmp)
                            {
                                if (tmp == 0)
                                {
                                    tmp = n;
                                }
                                else
                                {
                                    res += n - tmp;
                                    tmp = 0;
                                }
                            }
                            else if (n == tmp)
                            {
                                res += tmp + n;
                                tmp = 0;
                            }
                        }
                        summa += res + tmp;
                        cout << (-(summa)) << endl;
                        summa = 0;
                        res = 0;
                        tmp = 0;
                    }
                    else
                    {
                        cout << "Ошибка, в римской записи так нельзя" << endl;
                    }
                }
                else if (rimsk[0] != '-')
                {
                    for (int i = 0; i < rimsk.size(); i++)
                    {
                        if (Decoder(rimsk[i]) == 0)
                        {
                            flag3 = 0;
                            break;
                        }
                    }
                    if (flag3)
                    {
                        int tmp = 0;
                        int res = 0;
                        for (int i = 0; i < rimsk.size(); i++)
                        {
                            int n = Decoder(rimsk[i]);
                            if (n < tmp)
                            {
                                res += tmp;
                                tmp = n;
                            }
                            else if (n > tmp)
                            {
                                if (tmp == 0)
                                {
                                    tmp = n;
                                }
                                else
                                {
                                    res += n - tmp;
                                    tmp = 0;
                                }
                            }
                            else if (n == tmp)
                            {
                                res += tmp + n;
                                tmp = 0;
                            }
                        }
                        summa += res + tmp;
                        cout << summa << endl;
                        summa = 0;
                        res = 0;
                        tmp = 0;
                    }
                    else
                    {
                        cout << "Ошибка, в римской записи так нельзя" << endl;
                    }
                }
            }
            else
            {
                cout << "Ошибка, в римской записи так нельзя" << endl;
            }
            break;
        case 7:
            cout << endl;
            cout << "Чтобы построить псевдослучайное число введите 3 числа" << endl;
            cout << "Введите 1-е число" << endl;
            cin >> chislo_1;
            cout << "Введите 2-е число" << endl;
            cin >> chislo_2;
            cout << "Введите 3-е число" << endl;
            cin >> chislo_3;
            if (chislo_2 >= 0)
            {
                cout << "Псевдослучайное число = " << Randomnoe(chislo_1, chislo_2, chislo_3) << endl;
            }
            else
            {
                cout << "Ошибка, 2-е число должно быть неотрицательным" << endl;
            }
            break;
        case 8:
            cout << endl;
            aaa[0][0] = 5;
            aaa[0][1] = 2;
            aaa[0][2] = 0;
            aaa[0][3] = 10;
            aaa[1][0] = 3;
            aaa[1][1] = 5;
            aaa[1][2] = 2;
            aaa[1][3] = 5;
            aaa[2][0] = 20;
            aaa[2][1] = 0;
            aaa[2][2] = 0;
            aaa[2][3] = 0;
            bbb[0][0] = 1.20;
            bbb[0][1] = 0.50;
            bbb[1][0] = 2.80;
            bbb[1][1] = 0.40;
            bbb[2][0] = 5.00;
            bbb[2][1] = 1.00;
            bbb[3][0] = 2.00;
            bbb[3][1] = 1.50;
            for (int i = 0; i < prodavec; i++)
            {
                for (int j = 0; j < cenacomission; j++)
                {
                    ccc[i][j] = 0;
                }
            }
            for (int i = 0; i < prodavec; i++)
            {
                for (int j = 0; j < cenacomission; j++)
                {
                    for (int k = 0; k < tovar; k++)
                    {
                        ccc[i][j] += aaa[i][k] * bbb[k][j];
                    }
                }
            }
            for (int i = 0; i < prodavec; i++)
            {
                for (int j = 0; j < cenacomission; j++)
                {
                    cout << ccc[i][j] << " ";
                }
                cout << endl;
            }
            maxim1 = max(max(ccc[0][0], ccc[1][0]), ccc[2][0]);
            minim1 = min(min(ccc[0][0], ccc[1][0]), ccc[2][0]);
            maxim2 = max(max(ccc[0][1], ccc[1][1]), ccc[2][1]);
            minim2 = min(min(ccc[0][1], ccc[1][1]), ccc[2][1]);
            cout << "\n1) " << zadanie11(ccc[0][0], ccc[1][0], ccc[2][0], maxim1) << " продавец выручил больше всего денег с продажи" << endl;
            cout << "   " << zadanie12(ccc[0][0], ccc[1][0], ccc[2][0], minim1) << " продавец выручил меньше всего денег с продажи" << endl;
            cout << "\n2) " << zadanie11(ccc[0][1], ccc[1][1], ccc[2][1], maxim2) << " продавец получил наибольшие комиссионные" << endl;
            cout << "   " << zadanie12(ccc[1][1], ccc[1][1], ccc[2][1], minim2) << " продавец получил наименьшие комиссионные" << endl;
            cout << "\n3) "
                 << "Общая сумма денег, вырученных за проданные товары = " << ccc[0][0] + ccc[1][0] + ccc[2][0] << endl;
            cout << "\n4) "
                 << "Сумма всех комиссионных = " << ccc[0][1] + ccc[1][1] + ccc[2][1] << endl;
            for (int i = 0; i < prodavec; i++)
            {
                for (int j = 0; j < cenacomission; j++)
                {
                    summa8 += ccc[i][j];
                }
            }
            cout << "\n5) Общая сумма всех денег = " << summa8 << endl;
            break;
        case 9:
            cout << endl;
            cout << "Введите число с основанием от 2 до 36" << endl;
            cin >> oldnumber;
            cout << "Введите основание этого числа" << endl;
            cin >> osnovanie;
            cout << "Введите основание, в которое хотите перевести число" << endl;
            cin >> newnumber;
            for (int i = 48; i < 58; i++)
            {
                bykvi[index1] = char(i);
                index1 += 1;
            }
            index1 = 0;
            for (int i = 65; i < 91; i++)
            {
                bykvi[index2] = char(i);
                index2 += 1;
            }
            index2 = 10;
            if ((newnumber > 1) && (oldnumber[0] != '-') && (osnovanie > 1))
            {
                for (int i = 0; i < (oldnumber.size()); i++)
                {
                    if (Indexback(oldnumber[i], bykvi) > maximocnovanie)
                    {
                        maximocnovanie = Indexback(oldnumber[i], bykvi);
                    }
                }
                if (osnovanie > maximocnovanie)
                {
                    cout << "Ваше число = " << oldnumber << endl;
                    cout << "Ваше число в 10-ой СС = " << Desiatichnoe(oldnumber, osnovanie, bykvi) << endl;
                    cout << "Ваше число в " << newnumber << "-ой СС = " << Novoeosnovanie(Desiatichnoe(oldnumber, osnovanie, bykvi), newnumber, bykvi) << endl;
                    maximocnovanie = -1000000;
                }
                else
                {
                    cout << "Ошибка, введите другое значение" << endl;
                }
            }
            else
            {
                cout << "Ошибка, введите другое значение" << endl;
            }
            break;
        case 0:
            flag = 0;
            break;
        default:
            cout << endl;
            cout << "Таких вариантов не было!!!" << endl;
            break;
        }
    }
    return 0;
}