#include <iostream>
#include <vector>

using namespace std;

// double divide(int a, int b) {
//     return (double)a / b;
// }

int main()
{
    // double a, b;
    // cin >> a >> b;
    // cout << divide(a, b) << endl;

    int indx;
    cin >> indx;

    while (indx != 100500) {
        vector<int> vec;
        for (int i = 0; i < 10; i++) {
            vec.push_back((i+1)*100);
        }
        cout << vec[indx] << endl;
        cin >> indx;
    }

    return 0;
}
