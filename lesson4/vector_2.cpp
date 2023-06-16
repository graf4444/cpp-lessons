#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> v) {
    for(int el : v) {
        cout << el << " ";
    }
    cout << endl;
}

void print_vector(string str, vector<int> v) {
    cout << str;
    for(int el : v) {
        cout << el << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> myVector = {1, 2, 3, 4, 5};

    print_vector(myVector);

    myVector.push_back(6);
    print_vector(myVector);

    myVector.pop_back();
    print_vector(myVector);

    cout << "myVector.empty(): " << myVector.empty() << endl;

    print_vector("before: ", myVector);
    myVector.clear();
    print_vector("after: ", myVector);

    myVector = {1, 2, 3, 4, 5};
    cout << myVector[10] << endl;
    // cout << myVector.at(10) << endl;
    cout << myVector.at(1) << endl;

    myVector = {1, 2, 3, 4, 5};
    print_vector("before: ", myVector);
    myVector.insert(myVector.begin() + 2, {7, 8});
    print_vector("after: ", myVector);

    myVector = {1, 2, 3, 4, 5};
    print_vector("before: ", myVector);
    myVector.erase(myVector.begin() + 2);
    print_vector("after: ", myVector);

    myVector = {1, 2, 3, 4, 5};
    print_vector("before: ", myVector);
    myVector.erase(myVector.begin() + 2, myVector.begin() + 4);
    print_vector("after: ", myVector);

    myVector = {1, 2, 3, 4, 5};
    print_vector("before: ", myVector);
    myVector.erase(myVector.begin() + 2, myVector.end() - 1);
    print_vector("after: ", myVector);

    myVector = {5, 3, 4, 2, 1};
    print_vector("before: ", myVector);
    sort(myVector.begin(), myVector.end());
    print_vector("after: ", myVector);

    // vector<int> myVector2;
    // cout << "myVector2.front(): " << myVector2.front() << endl;

    myVector = {1, 2, 3, 4, 5};
    print_vector("before: ", myVector);
    myVector.assign({9, 8, 7});
    print_vector("after: ", myVector);

    vector<int> myVector3;
    myVector3.push_back(1);
    myVector3.push_back(2);
    myVector3.push_back(3);
    myVector3.push_back(4);
    myVector3.push_back(5);
    myVector3.resize(100);
    cout << "myVector3.size() " << myVector3.size() << endl;
    cout << "myVector3.capacity() " << myVector3.capacity() << endl;

    return 0;
}