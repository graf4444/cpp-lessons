#include <iostream>

using namespace std;

// class MyClass2 {};

class MyClass {
    // private:
    //     MyClass2
    public:
        MyClass() {
            cout << "Constructor run!!!" << endl;
        }

        ~MyClass() {
            // delete MyClass2
            cout << "Destructor run!!!" << endl;
        }
};

int main()
{
    {
        MyClass myClass1;
        MyClass myClass2;
    }

    MyClass myClass3;

    return 0;
}
