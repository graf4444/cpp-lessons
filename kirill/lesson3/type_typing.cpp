#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n1 = 100500;
    double d1 = n1;
    cout << d1 << '\n';

    double d2 = 1.;
    cout << d2 << '\n';


    double d3 = 5/2.;       // 2.5
    int n3 = d3;
    cout << n3 << '\n';     // 2

    double d4 = 2.9;        // 2.9
    int n4 = d4;
    cout << n4 << '\n';     // 2

    unsigned long long ull5 = 18446744073709551615ULL;       // 18446744073709551615
    cout << ull5 << '\n';
    int n5 = ull5;
    cout << n5 << '\n';                                      // -1


    unsigned long long ull6 = 18446744073709551614ULL;
    cout << ull6 << '\n';
    int n6 = ull6;
    cout << n6 << '\n';  

    double d7 = 12.34;
    cout << d7 << '\n';
    int n7 = static_cast<int>(d7);
    cout << n7 << '\n';  


    cout << -5/2 << endl;   // -2

    return 0;
}


// -1
// 00000001   - 1
// !00000001   -> 11111110+1   -> 11111111  == -1

// -58
// 00111010    - 58
// !00111010   -> 11000101+1   -> 11000110  == -58



// -58+10 = -48
// 11000110 
// +
// 00001010
// = 
// 11010000