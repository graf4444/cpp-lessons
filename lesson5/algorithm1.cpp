#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsOdd (int i) {
  return ((i%2)==1);
}

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
    string str = "abcdefaa";
    vector<int> vec = {1,2,3,4,5,1,2,3,1,1};

    cout << "Count 'a' in str: " << count(str.begin(), str.end(), 'a') << endl;
    cout << "Count 1 in vec: " << count(vec.begin(), vec.end(), 1) << endl;

    cout << endl;

    vector<int>::iterator it = find_if(vec.begin(), vec.end(), IsOdd);
    while(it != vec.end()) {
        cout << *it << ' ';
        it = find_if(++it, vec.end(), IsOdd);
    }

    cout << endl;

    print_vector("before: ", vec);
    swap(vec[0], vec[1]);
    print_vector("after: ", vec);
    
    cout << endl;

    print_vector("before: ", vec);
    // random_shuffle(vec.begin(), vec.end());
    print_vector("after: ", vec);
    
    return 0;
}
