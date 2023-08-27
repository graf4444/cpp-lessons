#include <iostream>

using namespace std;

int main()
{
    bool flag;
    cout << "flag is: " << flag << endl;
    flag = true;
    cout << "flag is: " << flag << endl;
    flag = false;
    cout << "flag is: " << flag << endl;
    flag = 1;
    cout << "flag is: " << flag << endl;
    if (flag == 1) 
    {
        cout << "flag is true" << endl;
    }
    if (flag == false) 
    {
        cout << "flag is false" << endl;
    }
    int int_flag = 1;
    flag = true;
    if (flag == int_flag) 
    {
        cout << "int_flag and flag are true" << endl;
    }

    cout << "sizeof(flag): " << sizeof(flag) << endl;
    cout << "sizeof(bool): " << sizeof(bool) << endl;

    return 0;
}
