#include <iostream>

using namespace std;

int main()
{
    long double ld = 1.79769e+308;
    cout << "sizeof(long double): " << sizeof(long double) << endl;
    cout << "sizeof(ld): " << sizeof(ld) << endl;
    
    return 0;
}
