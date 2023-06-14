#include <iostream>

using namespace std;

int main()
{
    const double pi = 3.14;

    // pi = 100500.0; //  error: cannot assign to variable 'pi' with const-qualified type 'const double'

    cout << pi << endl;


    const char ch = 'a';
    // ch = 'b';

    const string str = "abc";
    // str = "cba";

    cout << str << endl;
    
    return 0;
}