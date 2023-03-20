#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
struct stranastrochka
{
    string numbernumber;
    string country;
    int zoloto;
    int serebro;
    int bronza;
    int vsegomed;
    int vsegoochk;
};
int proverkamedali()
{
    while (true)
    {
        int medali;
        cin >> medali;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте ещё раз" << '\n'
                 << '\n';
        }
        else
        {
            cin.ignore(32767, '\n');
            return medali;
        }
    }
}
void Sortik(stranastrochka **massivestrochka2, int colvostran)
{
    for (int i = 0; i < colvostran; i++)
    {
        for (int j = 0; j < (colvostran - 1 - i); j++)
        {
            if (((massivestrochka2[j]->zoloto) + (massivestrochka2[j]->serebro)) < ((massivestrochka2[j + 1]->zoloto) + (massivestrochka2[j + 1]->serebro)))
            {
                stranastrochka *peremennaya = massivestrochka2[j];
                massivestrochka2[j] = massivestrochka2[j + 1];
                massivestrochka2[j + 1] = peremennaya;
            }
        }
    }
}
void Zadanie5_23()
{
    fstream olympic;
    ofstream olympic2;
    olympic2.open("C:\\Users\\Maxim\\Desktop\\Zadanie5(23).txt", ofstream::out);
    olympic2.close();
    olympic.open("C:\\Users\\Maxim\\Desktop\\Zadanie5(23).txt");
    if (!olympic.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
    }
    else
    {
        string namestrani;
        int medaligold, medalisilver, medalibronze, summamedalei, summaochkov, colvostran = 0;
        cout << "Файл открыт" << '\n'
             << '\n';
        cout << "Подведение итогов Олимпийских игр" << '\n';
        cout << "Введите кол-во стран " << '\n';
        colvostran = proverkamedali();
        stranastrochka *massivestrochka = new stranastrochka[colvostran];
        stranastrochka **massivestrochka2 = new stranastrochka *[colvostran];
        olympic << "   "
                << "Страна" << '\t' << "Золото" << '\t' << "Серебро" << '\t' << "Бронза" << '\t' << "Всего медалей" << '\t' << "Всего очков" << '\n';
        for (int i = 0; i < colvostran; i++)
        {
            summaochkov = 0;
            summamedalei = 0;
            cout << "Введите название " << i + 1 << " страны" << '\n';
            cin >> namestrani;
            cout << "Введите кол-во золотых медалей страны " << namestrani << '\n';
            medaligold = proverkamedali();
            summamedalei += medaligold;
            summaochkov += medaligold * 7;
            cout << "Введите кол-во серебряных медалей страны " << namestrani << '\n';
            medalisilver = proverkamedali();
            summamedalei += medalisilver;
            summaochkov += medalisilver * 6;
            cout << "Введите кол-во бронзовых медалей страны " << namestrani << '\n';
            medalibronze = proverkamedali();
            summamedalei += medalibronze;
            summaochkov += medalibronze * 5;
            if (namestrani == "США")
            {
                olympic << i + 1 << ") " << namestrani << '\t' << '\t' << medaligold << '\t' << medalisilver << '\t' << medalibronze << '\t' << summamedalei << '\t' << '\t' << summaochkov << '\n';
            }
            else
            {
                olympic << i + 1 << ") " << namestrani << '\t' << medaligold << '\t' << medalisilver << '\t' << medalibronze << '\t' << summamedalei << '\t' << '\t' << summaochkov << '\n';
            }
        }
        olympic.clear();
        olympic.seekg(59);
        for (int i = 0; i < colvostran; i++)
        {
            olympic >> massivestrochka[i].numbernumber >> massivestrochka[i].country >> massivestrochka[i].zoloto >> massivestrochka[i].serebro >> massivestrochka[i].bronza >> massivestrochka[i].vsegomed >> massivestrochka[i].vsegoochk;
        }
        for (int i = 0; i < colvostran; i++)
        {
            massivestrochka2[i] = &massivestrochka[i];
        }
        cout << '\n';
        cout << "    "
             << "Страна" << '\t' << "Золото" << '\t' << "Серебро" << '\t' << "Бронза" << '\t' << "Всего медалей" << '\t' << "Всего очков" << '\n';
        for (int i = 0; i < colvostran; i++)
        {
            if ((massivestrochka2[i]->country) == "США")
            {
                cout << i + 1 << ")  " << massivestrochka2[i]->country << '\t' << '\t' << massivestrochka2[i]->zoloto << '\t' << massivestrochka2[i]->serebro << '\t' << massivestrochka2[i]->bronza << '\t' << massivestrochka2[i]->vsegomed << '\t' << '\t' << massivestrochka2[i]->vsegoochk << '\n';
            }
            else
            {
                cout << i + 1 << ")  " << massivestrochka2[i]->country << '\t' << massivestrochka2[i]->zoloto << '\t' << massivestrochka2[i]->serebro << '\t' << massivestrochka2[i]->bronza << '\t' << massivestrochka2[i]->vsegomed << '\t' << '\t' << massivestrochka2[i]->vsegoochk << '\n';
            }
        }
        Sortik(massivestrochka2, colvostran);
        cout << '\n'
             << '\n';
        cout << "    "
             << "Страна" << '\t' << "Золото" << '\t' << "Серебро" << '\t' << "Бронза" << '\t' << "Всего медалей" << '\t' << "Всего очков" << '\n';
        for (int i = 0; i < colvostran; i++)
        {
            if ((massivestrochka2[i]->country) == "США")
            {
                cout << i + 1 << ")  " << massivestrochka2[i]->country << '\t' << '\t' << massivestrochka2[i]->zoloto << '\t' << massivestrochka2[i]->serebro << '\t' << massivestrochka2[i]->bronza << '\t' << massivestrochka2[i]->vsegomed << '\t' << '\t' << massivestrochka2[i]->vsegoochk << '\n';
            }
            else
            {
                cout << i + 1 << ")  " << massivestrochka2[i]->country << '\t' << massivestrochka2[i]->zoloto << '\t' << massivestrochka2[i]->serebro << '\t' << massivestrochka2[i]->bronza << '\t' << massivestrochka2[i]->vsegomed << '\t' << '\t' << massivestrochka2[i]->vsegoochk << '\n';
            }
        }
        olympic.clear();
        olympic.seekp(0, ios::end);
        olympic << '\n'
                << '\n'
                << '\n'
                << '\n';
        olympic << "   "
                << "Страна" << '\t' << "Золото" << '\t' << "Серебро" << '\t' << "Бронза" << '\t' << "Всего медалей" << '\t' << "Всего очков" << '\n';
        for (int i = 0; i < colvostran; i++)
        {
            if ((massivestrochka2[i]->country) == "США")
            {
                olympic << i + 1 << ") " << massivestrochka2[i]->country << '\t' << '\t' << massivestrochka2[i]->zoloto << '\t' << massivestrochka2[i]->serebro << '\t' << massivestrochka2[i]->bronza << '\t' << massivestrochka2[i]->vsegomed << '\t' << '\t' << massivestrochka2[i]->vsegoochk << '\n';
            }
            else
            {
                olympic << i + 1 << ") " << massivestrochka2[i]->country << '\t' << massivestrochka2[i]->zoloto << '\t' << massivestrochka2[i]->serebro << '\t' << massivestrochka2[i]->bronza << '\t' << massivestrochka2[i]->vsegomed << '\t' << '\t' << massivestrochka2[i]->vsegoochk << '\n';
            }
        }
        delete[] massivestrochka2;
    }
    olympic.close();
}
int provekrastolbikov()
{
    while (true)
    {
        cout << "Введите количество столбцов двумерного массива" << endl;
        int stolbik;
        cin >> stolbik;
        if (cin.fail() || (stolbik < 1))
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте ещё раз" << '\n'
                 << '\n';
        }
        else
        {
            cin.ignore(32767, '\n');
            return stolbik;
        }
    }
}
int provekrastrok()
{
    while (true)
    {
        cout << "Введите количество строк двумерного массива" << endl;
        int stroki;
        cin >> stroki;
        if (cin.fail() || (stroki < 1))
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте ещё раз" << '\n'
                 << '\n';
        }
        else
        {
            cin.ignore(32767, '\n');
            return stroki;
        }
    }
}
int proverkadvymernogomassiva()
{
    while (true)
    {
        cout << "Введите число" << endl;
        int choslodvymern;
        cin >> choslodvymern;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте ещё раз" << '\n'
                 << '\n';
        }
        else
        {
            cin.ignore(32767, '\n');
            return choslodvymern;
        }
    }
}
void Zadanie4_46()
{
    cout << "Для создания двумерного массива введите кол-во строк и столбцов" << endl;
    int stroki = provekrastrok(), stolbiki = provekrastolbikov(), summastroki = 0;
    int **dvymerniymassive = new int *[stroki];
    for (int i = 0; i < stroki; i++)
    {
        dvymerniymassive[i] = new int[stolbiki];
    }
    for (int i = 0; i < stroki; i++)
    {
        for (int j = 0; j < stolbiki; j++)
        {
            dvymerniymassive[i][j] = proverkadvymernogomassiva();
        }
    }
    cout << '\n';
    for (int i = 0; i < stroki; i++)
    {
        summastroki = 0;
        for (int j = 0; j < stolbiki; j++)
        {
            cout << dvymerniymassive[i][j] << '\t';
            summastroki += dvymerniymassive[i][j];
        }
        cout << "Сумма элементов строки = " << summastroki;
        cout << '\n';
    }
    for (int i = 0; i < stroki; i++)
    {
        delete[] dvymerniymassive[i];
    }
    delete[] dvymerniymassive;
}
string Novoeosnovanie(int desiatichnoesumma)
{
    int desiatichnoesumma0 = desiatichnoesumma, index1 = 0, index2 = 10;
    string answer, answer2;
    char bykvi[36];
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
    while (desiatichnoesumma0 > 0)
    {
        answer += bykvi[desiatichnoesumma0 % 16];
        desiatichnoesumma0 = desiatichnoesumma0 / 16;
    }
    for (int i = ((answer.size()) - 1); i >= 0; i--)
    {
        answer2 += answer[i];
    }
    return answer2;
}
string Desiatichnoe(int troichnoechislo)
{
    int desiatichnoesumma = 0, stepen = 0, troichnoechislo0, k = 0;
    troichnoechislo0 = troichnoechislo;
    while (troichnoechislo0 > 0)
    {
        troichnoechislo0 = troichnoechislo0 / 10;
        k += 1;
    }
    for (int i = 0; i < k; i++)
    {
        desiatichnoesumma += (troichnoechislo % 10) * (pow(3, stepen));
        stepen += 1;
        troichnoechislo = troichnoechislo / 10;
    }
    return Novoeosnovanie(desiatichnoesumma);
}
int proverkanaCC2(int choslodtroichnoi)
{
    bool znakCC = 1;
    if (choslodtroichnoi < 1)
    {
        return 0;
    }
    else
    {
        while (choslodtroichnoi > 0)
        {
            if ((choslodtroichnoi % 10) >= 3)
            {
                znakCC = 0;
                break;
            }
            choslodtroichnoi = choslodtroichnoi / 10;
        }
        if (znakCC == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int proverkanaCC()
{
    while (true)
    {
        cout << "Введите число в 3-ой СС" << endl;
        int choslodtroichnoi;
        cin >> choslodtroichnoi;
        if (cin.fail() || !(proverkanaCC2(choslodtroichnoi)))
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте ещё раз" << '\n'
                 << '\n';
        }
        else
        {
            cin.ignore(32767, '\n');
            return choslodtroichnoi;
        }
    }
}
int provekrakolvachisel()
{
    while (true)
    {
        cout << "Введите количество чисел" << endl;
        int razmermassivetroichn;
        cin >> razmermassivetroichn;
        if (cin.fail() || (razmermassivetroichn < 1))
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте ещё раз" << '\n'
                 << '\n';
        }
        else
        {
            cin.ignore(32767, '\n');
            return razmermassivetroichn;
        }
    }
}
void Zadanie4_23()
{
    int razmermassivetroichn = provekrakolvachisel();
    int *massivetroichn = new int[razmermassivetroichn];
    string *massiveshestnad = new string[razmermassivetroichn];
    for (int i = 0; i < razmermassivetroichn; i++)
    {
        massivetroichn[i] = proverkanaCC();
    }
    for (int i = 0; i < razmermassivetroichn; i++)
    {
        massiveshestnad[i] = Desiatichnoe(massivetroichn[i]);
    }
    cout << "\nМассив из чисел в 3-ой СС:" << endl;
    for (int i = 0; i < razmermassivetroichn; i++)
    {
        cout << massivetroichn[i] << ' ';
    }
    cout << "\n\nМассив из чисел в 16-ой СС:" << endl;
    for (int i = 0; i < razmermassivetroichn; i++)
    {
        cout << massiveshestnad[i] << ' ';
    }
    cout << '\n';
    delete[] massivetroichn;
    delete[] massiveshestnad;
}
void Zadanie3_6()
{
    string slova6, odnoslovo, minimslovo;
    fstream filezd3_6;
    ofstream filezd3_6_2;
    filezd3_6_2.open("C:\\Users\\Maxim\\Desktop\\Zadanie3(6).txt");
    filezd3_6_2.close();
    int minim3_6 = 1000000000;
    filezd3_6.open("C:\\Users\\Maxim\\Desktop\\Zadanie3(6).txt");
    if (!filezd3_6.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
    }
    else
    {
        cout << "Введите слова" << '\n'
             << '\n';
        getline(cin, slova6);
        filezd3_6 << slova6;
        filezd3_6.clear();
        filezd3_6.seekg(0);
        while (!filezd3_6.eof())
        {
            getline(filezd3_6, odnoslovo, ' ');
            if ((odnoslovo.length()) < minim3_6)
            {
                minim3_6 = (odnoslovo.length());
                minimslovo = odnoslovo;
            }
        }
        filezd3_6.clear();
        filezd3_6.seekg(0);
        while (!filezd3_6.eof())
        {
            getline(filezd3_6, odnoslovo, ' ');
            if ((odnoslovo.length()) == minim3_6)
            {
                cout << "Минимальное слово - " << odnoslovo << "  Его длина - " << minim3_6 << '\n';
            }
        }
    }
    filezd3_6.close();
}
int numbersoglbykvi(char bykva)
{
    switch (bykva)
    {
    case ('b'):
        return 0;
    case ('c'):
        return 1;
    case ('d'):
        return 2;
    case ('f'):
        return 3;
    case ('g'):
        return 4;
    case ('h'):
        return 5;
    case ('j'):
        return 6;
    case ('k'):
        return 7;
    case ('l'):
        return 8;
    case ('m'):
        return 9;
    case ('n'):
        return 10;
    case ('p'):
        return 11;
    case ('q'):
        return 12;
    case ('r'):
        return 13;
    case ('s'):
        return 14;
    case ('t'):
        return 15;
    case ('v'):
        return 16;
    case ('w'):
        return 17;
    case ('x'):
        return 18;
    case ('z'):
        return 19;
    default:
        return 20;
    }
}
char bykvisoglnumber(int bykva)
{
    switch (bykva)
    {
    case (0):
        return 'b';
    case (1):
        return 'c';
    case (2):
        return 'd';
    case (3):
        return 'f';
    case (4):
        return 'g';
    case (5):
        return 'h';
    case (6):
        return 'j';
    case (7):
        return 'k';
    case (8):
        return 'l';
    case (9):
        return 'm';
    case (10):
        return 'n';
    case (11):
        return 'p';
    case (12):
        return 'q';
    case (13):
        return 'r';
    case (14):
        return 's';
    case (15):
        return 't';
    case (16):
        return 'v';
    case (17):
        return 'w';
    case (18):
        return 'x';
    case (19):
        return 'z';
    }
}
void Zadanie3_23()
{
    string strochkasimvolov;
    fstream filezd3;
    ofstream filezd3_2;
    filezd3_2.open("C:\\Users\\Maxim\\Desktop\\Zadanie3(23).txt");
    filezd3_2.close();
    char symbolzd3, chastabykva;
    int soglbykvi[21]{}, maxim = 0;
    filezd3.open("C:\\Users\\Maxim\\Desktop\\Zadanie3(23).txt");
    if (!filezd3.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
    }
    else
    {
        cout << "Файл открыт" << '\n'
             << '\n';
        cout << "Введите согласные английские буквы" << '\n'
             << '\n';
        getline(cin, strochkasimvolov);
        filezd3 << strochkasimvolov;
        filezd3.clear();
        filezd3.seekg(0);
        while (filezd3 >> symbolzd3)
        {
            soglbykvi[numbersoglbykvi(tolower(symbolzd3))] += 1;
        }
        for (int i = 0; i < 20; i++)
        {
            if (soglbykvi[i] > maxim)
            {
                maxim = soglbykvi[i];
                chastabykva = bykvisoglnumber(i);
            }
        }
        if (maxim == 0)
        {
            cout << "Нет английских согласных букв" << endl;
        }
        else
        {
            for (int i = 0; i < 20; i++)
            {
                if (maxim == soglbykvi[i])
                {
                    cout << "Наиболее частая согласная - " << bykvisoglnumber(i) << " Количество - " << maxim << endl;
                }
            }
            cout << endl;
        }
    }
    filezd3.close();
}
int proverkadlinaresheta()
{
    while (true)
    {
        cout << "Введите натуральное число большее 2" << endl;
        int dlinaresheta;
        cin >> dlinaresheta;
        if ((cin.fail()) || (dlinaresheta <= 2))
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте ещё раз" << '\n'
                 << '\n';
        }
        else
        {
            cin.ignore(32767, '\n');
            return dlinaresheta;
        }
    }
}
void Zadanie2()
{
    cout << "Найдём все простые числа от 2 до введённого вами натурального числа" << endl;
    int dlinaresheta = 0;
    dlinaresheta = proverkadlinaresheta();
    int *resheto = new int[dlinaresheta]{};
    for (int i = 2; i * i < dlinaresheta; i++)
    {
        if (resheto[i] == 0)
        {
            for (int j = i * i; j < dlinaresheta; j += i)
            {
                resheto[j] = 1;
            }
        }
    }
    cout << "Все простые числа от 2 до " << dlinaresheta << ":" << endl;
    for (int i = 2; i < dlinaresheta; i++)
    {
        if (resheto[i] == 0)
        {
            cout << i << '\n';
        }
    }
    delete[] resheto;
}
int proverkaevklid1()
{
    while (true)
    {
        cout << "Введите 1 число" << endl;
        int x;
        cin >> x;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте ещё раз" << '\n'
                 << '\n';
        }
        else
        {
            cin.ignore(32767, '\n');
            return x;
        }
    }
}
int proverkaevklid2()
{
    while (true)
    {
        cout << "Введите 2 число" << endl;
        int y;
        cin >> y;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте ещё раз" << '\n'
                 << '\n';
        }
        else
        {
            cin.ignore(32767, '\n');
            return y;
        }
    }
}
void Zadanie1()
{
    int x, y, x1, y1;
    cout << "Введите два числа" << endl;
    x = abs(proverkaevklid1());
    y = abs(proverkaevklid2());
    x1 = x;
    y1 = y;
    if ((x == 0) && (y == 0))
    {
        cout << "Бесконечность" << endl;
    }
    else if (((x == 0) && (y != 0)) || ((x != 0) && (y == 0)))
    {
        cout << "Наибольший делитель этих двух чисел = " << max(x, y) << endl;
    }
    else
    {
        while ((x1 > 0) && (y1 > 0))
        {
            if (x1 > y1)
            {
                x1 = x1 - y1;
            }
            else
            {
                y1 = y1 - x1;
            }
        }
        cout << "1-й способ(вычитанием) - Наибольший делитель этих двух чисел = " << x1 << endl;
        while ((max(x, y) % min(x, y)) != 0)
        {
            if (x > y)
            {
                x = x % y;
            }
            else
            {
                y = y % x;
            }
        }
        cout << "2-й способ(делением) - Наибольший делитель этих двух чисел = " << min(x, y) << endl;
    }
}
int proverkanumber()
{
    while (true)
    {
        cout << "\nДз №5. Введите номер задания - |1|  |2|  |3|(3.23)  |4|(3.6)  |5|(4.23)  |6|(4.46)  |7|(5.23) , чтобы выйти введите (0)" << endl;
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
int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int numberzd;
    bool flag = 1;
    while (flag)
    {
        numberzd = proverkanumber();
        switch (numberzd)
        {
        case 1:
            Zadanie1();
            break;
        case 2:
            Zadanie2();
            break;
        case 3:
            Zadanie3_23();
            break;
        case 4:
            Zadanie3_6();
            break;
        case 5:
            Zadanie4_23();
            break;
        case 6:
            Zadanie4_46();
            break;
        case 7:
            Zadanie5_23();
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