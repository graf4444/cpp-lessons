#include <iostream>

using namespace std;

int main()
{
    int var = 17;
    int *ptr = &var;
    int **ptr2 = &ptr;

    cout << ptr2 << endl;
    cout << ptr << endl;
    cout << &var << endl;

    cout << endl;

    cout << *ptr2 << endl;
    cout << *ptr << endl;
    cout << var << endl;

    cout << endl;

    cout << **ptr2 << endl;
    cout << *ptr << endl;
    cout << var << endl;

    cout << endl;
    *ptr = 10;

    cout << *ptr << endl;
    cout << var << endl;

    return 0;
}
