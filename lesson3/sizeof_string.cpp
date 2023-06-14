#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1 = "abc";
    cout << sizeof(str1) << endl;

    string str2 = "abcdef";
    cout << sizeof(str2) << endl;

    int arr1[] = {1,2,3};
    cout << sizeof(arr1)/sizeof(int) << endl;

    int arr2[] = {1,2,3,4,5,6};
    cout << sizeof(arr2)/sizeof(int) << endl;

    return 0;
}