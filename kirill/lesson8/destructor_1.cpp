#include <iostream>

using namespace std;

class MyClass {
    public:
        MyClass() {
            cout << "Constructor run!!!" << endl;
        }

        ~MyClass() {
            cout << "Destructor run!!!" << endl;
        }
};

int main()
{
    MyClass myClass; // constructor

    return 0;

    //destructor
}
