#include <iostream>

using namespace std;


int main()
{
    unsigned int my_bool = 0b10011101;
    unsigned int mask_1 = 0b00010000;

    cout << (my_bool & mask_1) << endl;

    unsigned int mask_2 = 1 << 4;

    cout << (my_bool & mask_2) << endl;

    return 0;
}
