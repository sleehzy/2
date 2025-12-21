#include <iostream>
using namespace std;
bool vys(int year)
{
    bool res = false;
    if (year % 4 == 0)
        res = true;
    if (year % 100 == 0)
        res = false;
    if (year % 400 == 0)
        res = true;
    return res;
}
int date(int d, int m, int y)
{
    int k = d;
    if (vys(y) && (m > 2))
        k += y * 366;
    else k += y * 365;
    switch (m - 1)
    {
    case 12: k += 31;
    case 11: k += 30;
    case 10: k += 31;
    case  9: k += 30;
    case  8: k += 31;
    case  7: k += 31;
    case  6: k += 30;
    case  5: k += 31;
    case  4: k += 30;
    case  3: k += 31;
    case  2: k += 28;
    case  1: k += 31;
    }
    return k;
}
int difference(int d1, int d2, int m1, int m2, int y1, int y2)
{
    int k = date(d2, m2, y2) - date(d1, m1, y1);
    return k;
}

double average(int a[], int n)
{
    // Find sum of array element
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    return (double)sum / n;
}



int main()
{
    setlocale(LC_ALL,"ru");
    std::cout << "\t\t\t\tпервое задание: \n\n\n\n\n";
    int d1, d2, m1, m2, y1, y2;
    cout << "1 день: ";
    cin >> d2;
    cout << "1 мес€ц: ";
    cin >> m2;
    cout << "1 год: ";
    cin >> y2;
    cout << "2 день: ";
    cin >> d1;
    cout << "2 мес€ц: ";
    cin >> m1;
    cout << "2 год: ";
    cin >> y1;
    cout << "различи€ между этими двум€ датами " << difference(d1, d2, m1, m2, y1, y2) << " дней\n";
    system("PAUSE");

    std::cout << "\t\t\t\tвторое задание: \n\n\n\n\n";
    int arr[] = { 10, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << average(arr, n);

    return 0;
}