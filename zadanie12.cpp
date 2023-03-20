#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;
void Sortik_up(int massivesortic[], int n) // Функция сортирует массив по возрастанию
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (massivesortic[j] > massivesortic[j + 1])
            {
                swap(massivesortic[j], massivesortic[j + 1]); // Меняем местами элементы
            }
        }
    }
}
void Sortik_down(int massivesortic[], int n) // Функция сортирует массив по убыванию
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (massivesortic[j] < massivesortic[j + 1])
            {
                swap(massivesortic[j], massivesortic[j + 1]); // Меняем местами элементы
            }
        }
    }
}
int massive(char massiveletters[], char letter1) // Возвращает индекс нужного элемента
{
    for (int i = 0; i < 8; i++)
    {
        if (massiveletters[i] == letter1)
        {
            return i;
        }
    }
}
char proverkaletter(char massiveletters[]) // Функция проверяет есть ли вводимая пользователем буква на шахматной доске
{
    char proverka;
    while (true)
    {
        cin >> proverka;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Такой БУКВЫ нет на шахматной доске" << endl;
            cout << "Введите БУКВУ ещё раз"
                 << "\n\n";
        }
        else
        {
            cin.ignore(32767, '\n');
            for (int i = 0; i < 8; i++)
            {
                if (massiveletters[i] == proverka)
                {
                    return proverka;
                }
            }
            cout << "Такой БУКВЫ нет на шахматной доске" << endl;
            cout << "Введите БУКВУ ещё раз"
                 << "\n\n";
        }
    }
}
double proverkanumber(double massivenumbers[]) // Функция проверяет есть ли вводимая пользователем цифра на шахматной доске
{
    double proverka;
    while (true)
    {
        cin >> proverka;
        if (cin.fail() || (proverka != round(proverka)))
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Такой ЦИФРЫ нет на шахматной доске" << endl;
            cout << "Введите ЦИФРУ ещё раз"
                 << "\n";
        }
        else
        {
            cin.ignore(32767, '\n');
            for (int i = 0; i < 8; i++)
            {
                if (massivenumbers[i] == proverka)
                {
                    return proverka;
                }
            }
            cout << "Такой ЦИФРЫ нет на шахматной доске" << endl;
            cout << "Введите ЦИФРУ ещё раз"
                 << "\n\n";
        }
    }
}
int main()
{
    SetConsoleCtrlHandler(NULL, TRUE);
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    const int stroka = 8, stolb = 8;
    int x, y, z, n, matrix[stroka][stolb];
    double number1, number2, massivenumbers[stroka] = {1, 2, 3, 4, 5, 6, 7, 8};
    char letter1, letter2, massiveletters[stolb] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for (int i = 0; i < stroka; i++) // Заполняем матрицу случайными целыми числами от 1 до 100
    {
        for (int j = 0; j < stolb; j++)
        {
            matrix[i][j] = rand() % 100 + 1;
        }
    }
    cout << '\n';
    for (int i = 0; i < stroka; i++) // Печатаем заполненную матрицу на экран
    {
        cout << 8 - i << '|' << '\t'; // Шахматная разметка строк
        for (int j = 0; j < stolb; j++)
        {
            cout << matrix[i][j] << '\t';
        }
        cout << "\n\n";
    }
    cout << "\n\tA\tB\tC\tD\tE\tF\tG\tH\n"; // Шахматная разметка столбцов
    while (true)
    {
        cout << "\nВведите координаты НАЧАЛА диагонали (клетка шахматной доски)" << endl;
        cout << "Введите БУКВУ (большая английская, A-H) начала диагонали" << endl;
        letter1 = proverkaletter(massiveletters);
        cout << "Введите ЦИФРУ (1-8) начала диагонали" << endl;
        number1 = (proverkanumber(massivenumbers) - 1); // Минус 1, так как хочу считать от 0 до 7
        cout << "\nВведите координаты КОНЦА диагонали (клетка шахматной доски)" << endl;
        cout << "Введите БУКВУ (большая английская, A-H) конца диагонали" << endl;
        letter2 = proverkaletter(massiveletters);
        cout << "Введите ЦИФРУ (1-8) конца диагонали" << endl;
        number2 = (proverkanumber(massivenumbers) - 1);                                                         // Минус 1, так как хочу считать от 0 до 7
        if ((number1 == number2) && ((massive(massiveletters, letter1)) == (massive(massiveletters, letter2)))) // Проверяем ввод на одну и ту же клетку
        {
            cout << "Вы ввели координаты одной и той же клетки" << endl;
            cout << "Попробуйте ввести координаты ДИАГОНАЛИ"
                 << "\n\n";
        }
        else if ((abs(number1 - number2)) == (abs((massive(massiveletters, letter1)) - (massive(massiveletters, letter2))))) // Проверяем на то, чтобы клетки,
        {                                                                                                                    // введённые пользователем, образовывали диагональ
            break;
        }
        else
        {
            cout << "Вы ввели координаты не диагонали" << endl;
            cout << "Попробуйте ещё раз"
                 << "\n";
        }
    }
    n = (abs(number1 - number2)) + 1; // Длина диагонали, заданной пользователем
    int *massivesortic = new int[n];
    if ((number1 + massive(massiveletters, letter1)) == (number2 + massive(massiveletters, letter2))) // Если сумма координат начала и конца равны,
    {                                                                                                 // то диагональ с левого верхнего угла в правый нижний угол
        x = stroka - 1 - max(number1, number2);
        y = min(massive(massiveletters, letter1), massive(massiveletters, letter2));
        z = 0;
        for (int i = 0; i < stroka; i++) // Ищем в матрице элементы нужной диагонали, остальные зануляем
        {
            for (int j = 0; j < stolb; j++)
            {
                if ((i == x) && (j == y))
                {
                    massivesortic[z] = matrix[i][j];              // Запоминаем элементы нужной диагонали
                    if (x < (stroka - 1 - min(number1, number2))) // Ставим границу, чтобы закончить поиск элементов диагонали.
                    {                                             // Одного условия достаточно, чтобы клетки дальше не смещались
                        x += 1;
                        y += 1;
                        z += 1;
                    }
                }
                else
                {
                    matrix[i][j] = 0;
                }
            }
        }
        z = 0;
        if ((number1 > number2) && (massive(massiveletters, letter1) < massive(massiveletters, letter2))) // Проверка, чтобы начальная клетка было слева сверху, тогда сортировка
        {                                                                                                 // будет по возрастанию с левой верхней клетки в правую нижнюю
            Sortik_up(massivesortic, n);
        }
        else // Иначе сортировка будет по убыванию с левой верхней клетки в правую нижнюю, а значит с правой нижней клетки в левую верхнюю сортировка будет по возрастанию
        {
            Sortik_down(massivesortic, n);
        }
        x = stroka - 1 - max(number1, number2);
        y = min(massive(massiveletters, letter1), massive(massiveletters, letter2));
        z = 0;
        for (int i = 0; i < stroka; i++) // Возвращаем элементы на место, но уже отсортированные
        {
            for (int j = 0; j < stolb; j++)
            {
                if ((i == x) && (j == y))
                {
                    matrix[i][j] = massivesortic[z];
                    if (x < (stroka - 1 - min(number1, number2))) // Ставим границу, чтобы закончить поиск элементов диагонали.
                    {                                             // Одного условия достаточно, чтобы клетки дальше не смещались
                        x += 1;
                        y += 1;
                        z += 1;
                    }
                }
            }
        }
        cout << "\n\n";
        for (int i = 0; i < stroka; i++) // Печатаем готовую матрицу на экран
        {
            cout << 8 - i << '|' << '\t'; // Шахматная разметка строк
            for (int j = 0; j < stolb; j++)
            {
                cout << matrix[i][j] << '\t';
            }
            cout << "\n\n";
        }
        cout << "\n\tA\tB\tC\tD\tE\tF\tG\tH\n"; // Шахматная разметка столбцов
    }
    else // Если сумма координат начала и конца не равны, то диагональ с левого нижнего угла в правый верхний угол
    {
        x = stroka - 1 - max(number1, number2);
        y = max(massive(massiveletters, letter1), massive(massiveletters, letter2));
        z = 0;
        for (int i = 0; i < stroka; i++) // Ищем в матрице элементы нужной диагонали, остальные зануляем
        {
            for (int j = 0; j < stolb; j++)
            {
                if (i == x && j == y)
                {
                    massivesortic[z] = matrix[i][j];              // Запоминаем элементы нужной диагонали
                    if (x < (stroka - 1 - min(number1, number2))) // Ставим границу, чтобы закончить поиск элементов диагонали.
                    {                                             // Одного условия достаточно, чтобы клетки дальше не смещались
                        x += 1;
                        y -= 1;
                        z += 1;
                    }
                }
                else
                {
                    matrix[i][j] = 0;
                }
            }
        }
        z = 0;
        if ((number1 < number2) && (massive(massiveletters, letter1) < massive(massiveletters, letter2))) // Проверка, чтобы начальная клетка было слева снизу, тогда
        {                                                                                                 // сортировка будет по возрастанию с левой нижней клетки в правую верхнюю
            Sortik_down(massivesortic, n);
        }
        else // Иначе сортировка будет по убыванию с левой нижней клетки в правую верхнюю, а значит с правой верхней клетки в левую нижнюю сортировка будет по возрастанию
        {
            Sortik_up(massivesortic, n);
        }
        x = stroka - 1 - max(number1, number2);
        y = max(massive(massiveletters, letter1), massive(massiveletters, letter2));
        z = 0;
        for (int i = 0; i < stroka; i++) // Возвращаем элементы на место, но уже отсортированные
        {
            for (int j = 0; j < stolb; j++)
            {
                if ((i == x) && (j == y))
                {
                    matrix[i][j] = massivesortic[z];
                    if (x < (stroka - 1 - min(number1, number2))) // Ставим границу, чтобы закончить поиск элементов диагонали.
                    {                                             // Одного условия достаточно, чтобы клетки дальше не смещались
                        x += 1;
                        y -= 1;
                        z += 1;
                    }
                }
            }
        }
        cout << "\n\n";
        for (int i = 0; i < stroka; i++) // Печатаем готовую матрицу на экран
        {
            cout << 8 - i << '|' << '\t'; // Шахматная разметка строк
            for (int j = 0; j < stolb; j++)
            {
                cout << matrix[i][j] << '\t';
            }
            cout << "\n\n";
        }
        cout << "\n\tA\tB\tC\tD\tE\tF\tG\tH\n"; // Шахматная разметка столбцов
    }
    delete[] massivesortic;
    return 0;
}