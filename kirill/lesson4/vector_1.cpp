#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> myVector1;

    myVector1.push_back(1);
    myVector1.push_back(2);
    myVector1.push_back(3);

    for (int i = 0; i < myVector1.size(); i++) {
        cout << myVector1[i] << " ";
    }
    cout << endl;


    vector<int> myVector2(5, 10);
    for (int i = 0; i < myVector2.size(); i++) {
        cout << myVector2[i] << " ";
    }
    cout << endl;


    vector<int> myVector3({ 10, 20, 30 });
    for (int el : myVector3) {
        cout << el << " ";
    }
    cout << endl;


    // int arr[] = {1,2,3};
    // for (int el : arr) {
    //     cout << el << " ";
    // }
    // cout << endl;


    // string str = "abcdrf";
    // for (char el : str) {
    //     cout << el << " ";
    // }
    // cout << endl;

    return 0;
}