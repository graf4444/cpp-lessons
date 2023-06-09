#include <iostream>

using namespace std;

int main()
{
    signed char schar = 'a';            // -128 - 127
    cout << "schar: " << schar << endl;
    schar = -128;
    cout << "schar: " << schar << endl;

    // signed char schar = 'b';    // error: redefinition of 'schar'

    unsigned char uchar = 'b';          // 0 - 255
    cout << "uchar: " << uchar << endl;
    uchar = 97;
    cout << "uchar: " << uchar << endl;

    // 11111111
    uchar = -1;
    cout << "uchar: " << (int)uchar << endl;

    char ch = 'c';
    cout << "ch: " << ch << endl;
    ch = 7;
    cout << "ch: " << ch << endl;
    ch = '7';
    cout << "ch: " << ch << endl;

    cout << "'c' - 'a' == " << ('c' - 'a') + 1 << endl;


    cout << "sizeof(signed char) == " << sizeof(signed char) << endl;
    cout << "sizeof(unsigned char) == " << sizeof(unsigned char) << endl;
    cout << "sizeof(char) == " << sizeof(char) << endl;

    return 0;
}
