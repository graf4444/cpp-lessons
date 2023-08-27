#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template<typename T, typename K> T add(T, K);

int main() {
    cout << add(1.2, 2) << endl; // 3.2
    cout << add(1, 2.2) << endl; // 3

    return 0;
}

template<typename T, typename K> T add(T a, K b) {
    return a + b;
}