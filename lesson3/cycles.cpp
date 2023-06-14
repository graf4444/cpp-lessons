#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    while(i < 10)
    {
        cout << "i: " << i << '\n';
        i++;
    }

    cout << '\n';
    // for (int i = 0, b = 0; i < 10; i += 3, b--) {
    //     cout << "i: " << i << " b: " << b << '\n';
    // }

    for (int i = 0; i < 10; ++i) {
        cout << "i: " << i << '\n';
    }

    cout << '\n';

    i = 6;
    do
    {
        cout << "i: " << i << '\n';
        i--;
    }
    while(i > 100);

    return 0;
}