#include <iostream>
#include <vector>

using namespace std;


int main()
{

    int size = 10;
    int arr[size];
    
    for (int i = 0; i < size; i++) {
        arr[i] = i+1;
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 6; i < size; i++) {
        arr[i-1] = arr[i];
    }
    size -= 1;

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
