#include <iostream>
#include <vector>

using namespace std;

class User
{
 public:
    int get_age() {
        return age;
    }

   void set_age(int a) {
        if (a >= 0 && a <= 120) {
            age = a;
        }
        // error
   }
   
 private:
   int age;
};

int main()
{
    User u1;

    cout << u1.get_age() << endl;

    u1.set_age(1);

    cout << u1.get_age() << endl;

    return 0;
}
