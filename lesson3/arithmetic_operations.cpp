#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    cout << ++a << '\n'; // 11
    cout << a++ << '\n'; // 11 -> 12
    cout << a << '\n';   // 12

    int i = 0;
    bool b = i++ == 0;
    cout << b << '\n';
    i = 0;
    b = ++i == 0;
    cout << b << '\n';

    b = 4945623856827346;
    cout << b << '\n';

    int n1 = 5, n2 = 2;
    cout << "1 n1/n2(5/2) == " << n1/n2 << '\n'; // 2

    double d1 = 5, d2 = 2;
    cout << "2 d1/d2(5/2) == " << d1/d2 << '\n'; // 2.5

    cout << "3 n1/d2(5/2) == " << n1/d2 << '\n';  // 2.5

    cout << "4 d1/n2(5/2) == " << d1/n2 << '\n';  // 2.5


    return 0;
}