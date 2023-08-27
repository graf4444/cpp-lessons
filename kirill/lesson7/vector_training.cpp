#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    vector<int>::iterator it = vec.end();

    cout << *(--it) << endl;

    return 0;
}
