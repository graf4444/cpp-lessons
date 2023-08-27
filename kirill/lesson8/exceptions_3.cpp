#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    int a, b, res;

    while (true)
    {
        try {
            cout << "введите a: ";
            cin >> a;

            cout << "введите b: ";
            cin >> b;

            if (b == 0) {
                throw invalid_argument("На 0 дельить нельзя!");
            }

            res = a / b;
            cout << "результат: " << res << endl;
        }
        catch(const invalid_argument& ex) {
            cout << ex.what() << endl;
        }
    }

    return 0;
}