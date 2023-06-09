#include <iostream>

using namespace std;

void print()
{
    cout << "print() 1" << endl;
}

void print()
{
    cout << "print() 2" << endl;
}

int main()
{
    print();

    return 0;
}
