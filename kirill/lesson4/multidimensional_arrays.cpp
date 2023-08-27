#include <iostream>

using namespace std;

int main()
{
    int numbers1[3] = {1,2,3};

    cout << numbers1 << "\n";
    for (int i = 0; i < 3; i++) {
        cout << numbers1[i] << " ";
    }
    cout << "\n\n";


    int numbers2[3][2] = { {1, 2}, {4, 5}, {7, 8} };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << numbers2[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    int numbers3[3][3][2] = { 
        {
            {1, 2}, {4, 5}, {7, 8}
        },
        {
            {1, 2}, {4, 5}, {7, 8}
        },
        {
            {1, 2},
            {4, 5},
            {7, 8}
        }
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                cout << numbers3[i][j][k] << " ";
            }
            cout << "\n-----\n";
        }
        cout << "\n";
    }


    char str[] = {"hello"};
    cout << str << "\n";

    return 0;
}