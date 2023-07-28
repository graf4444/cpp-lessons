#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// int add(int a, int b);
// double add(double a, double b);
// string add(string a, string b);

template<typename T> T add(T, T);


int main() {
    cout << add(1, 2) << endl;
    cout << add(1.1, 2.1) << endl;
    cout << add(string("1"), string("2")) << endl;

    return 0;
}

// int add(int a, int b) {
//     return a + b;
// }

// double add(double a, double b) {
//     return a + b;
// }

// string add(string a, string b) {
//     return a + b;
// }

template<typename T> T add(T a, T b) {
    return a + b;
}