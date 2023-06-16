#include <iostream>

using namespace std;

bool func(int i) {
    return i*i == i+i;
}

int main()
{
    int i = 0;
    while(i < 10)
    {
        if (i == 5) {
            break;
        }
        cout << "i: " << i << '\n';
        i++;
    }
    cout << "\n";

    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            continue;
        }
        cout << "i: " << i << '\n';
    }
    cout << "\n";

    for (int i = 0; i < 10; i++) {
        if (!func(i)) {
            continue;
        }
        cout << "i: " << i << '\n';
    }
    cout << "\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 1) {
                break;
            }
            cout << i << " " << j << endl;
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 1) {
                continue;
            }
            cout << i << " " << j << endl;
        }
        cout << endl;
    }

    return 0;
}