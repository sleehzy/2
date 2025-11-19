#include <iostream>





void findRoots(int a, int b, int c)
{
    setlocale(LC_ALL, "ru");

    if (a == 0) 
    {
        std::cout << "неверно";
        return;
    }

    int d = b * b - 4 * a * c;
    double sqrt_val = sqrt(abs(d));

    if (d > 0) 
    {
        std::cout << "Корни реальны и отличаются друг от друга ";
        std::cout << (double)(-b + sqrt_val) / (2 * a) << " "
            << (double)(-b - sqrt_val) / (2 * a);
    }
    else if (d == 0) 
    {
        std::cout << "Корни реальны и одинаковы ";
        std::cout << -(double)b / (2 * a);
    }

   
    else 
    {
        std::cout << "Корни сложные ";
        std::cout << -(double)b / (2 * a) << " + i"
            << sqrt_val / (2 * a) << " "
            << -(double)b / (2 * a) << " - i"
            << sqrt_val / (2 * a);
    }
}


int main()
{
    int a = 1, b = -7, c = 12;

    
    findRoots(a, b, c);
    return 0;
}