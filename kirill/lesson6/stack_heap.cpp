#include <iostream>
#include <vector>

using namespace std;


void func1(int& a) {
    a = 100500;
}

void func3(int* b) {
    *b = 100500;
}

void func2(vector<int>& vec) {
    vec[1] = 100500;
}

void print_vector(vector<int> vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a = 10;
    int* b = new int;
    *b = 5;

    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    cout << "a: " << a << endl;
    cout << "b: "  << *b << endl;
    print_vector(vec);

    func1(a);
    func3(b);
    func2(vec);

    cout << "a: " << a << endl;
    cout << "b: "  << *b << endl;
    print_vector(vec);

    return 0;
}
