#include <Windows.h>
#include <type_traits>
#include <string>
#include <iostream>
//using namespace std;
//bool vys(int year)
//{
//    bool res = false;
//    if (year % 4 == 0)
//        res = true;
//    if (year % 100 == 0)
//        res = false;
//    if (year % 400 == 0)
//        res = true;
//    return res;
//}
//int date(int d, int m, int y)
//{
//    int k = d;
//    if (vys(y) && (m > 2))
//        k += y * 366;
//    else k += y * 365;
//    switch (m - 1)
//    {
//    case 12: k += 31;
//    case 11: k += 30;
//    case 10: k += 31;
//    case  9: k += 30;
//    case  8: k += 31;
//    case  7: k += 31;
//    case  6: k += 30;
//    case  5: k += 31;
//    case  4: k += 30;
//    case  3: k += 31;
//    case  2: k += 28;
//    case  1: k += 31;
//    }
//    return k;
//}
//int difference(int d1, int d2, int m1, int m2, int y1, int y2)
//{
//    int k = date(d2, m2, y2) - date(d1, m1, y1);
//    return k;
//}
//
//double average(int a[], int n)
//{
//    // Find sum of array element
//    int sum = 0;
//    for (int i = 0; i < n; i++)
//        sum += a[i];
//
//    return (double)sum / n;
//}



std::string login, password, loginInput, passwordInput;
int loginMin = 3, loginMax = 15, passMin = 8, passMax = 30;

bool PassDigit(const std::string& currentPass)
{
    int digitCount = 0;
    for (char c : currentPass)
    {
        if (std::isdigit(c))
        {
            digitCount++;
            if (digitCount >= 3)
                return true;
        }
    }
    return false;
}

bool PassChar(const std::string& currentPass)
{
    int letterCount = 0;
    for (char c : currentPass)
    {
        if (std::isalpha(c))
        {
            letterCount++;
            if (letterCount >= 3)
                return true;
        }
    }
    return false;
}

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    while (true)
    {
        std::cout << "Введите новый логин: ";
        std::getline(std::cin, login, '\n');

        std::cout << "Введите новый пароль: ";
        std::getline(std::cin, password, '\n');

        if (login.size() < loginMin || login.size() > loginMax)
        {
            std::cout << "Недопустимая длина логина. Должно быть от "
                << loginMin << " до " << loginMax << '\n\n';
            Sleep(1500);
            system("cls");
        }
        else if (password.size() < passMin || password.size() > passMax)
        {
            std::cout << "Недопустимая длина пароля. Должно быть от "
                << passMin << " до " << passMax << '\n\n';
            Sleep(1500);
            system("cls");
        }
        else
        {
            if (PassDigit(password) && PassChar(password))
            {
                std::cout << "Регистрация прошла успешно";
                break;
            }
            else
            {
                std::cout << "Ошибка: пароль должен содержать минимум 3 цифры и 3 буквы.\n";
                Sleep(1500);
                system("cls");
            }
        }
    }

    Sleep(1500);
    system("cls");

   
    while (true)
    {
        std::cout << "Введите ваш логин: ";
        std::getline(std::cin, loginInput, '\n');

        std::cout << "Введите ваш пароль: ";
        std::getline(std::cin, passwordInput, '\n');

        if (login == loginInput && password == passwordInput)
        {
            std::cout << "Авторизация прошла успешно! Добро пожаловать! \n\n";
            Sleep(1500);
            system("cls");
            break;
        }
        std::cout << "Ошибка логина или пароля \n";
        Sleep(1500);
        system("cls");
    }

    return 0;
}
