#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template<typename T>
class Person {
public:

    Person() {
    }

    Person(T id, string name) {
        this->id = id;
        this->name = name;
    }

    void setId(T id) {
        this->id = id;
    }

    void print() {
        cout << id << " " << name << endl;
    }

private:
    T id;
    string name;
};


int main() {
    Person<int>* p = new Person<int>();
    p->setId(12);
    
    Person<int>* person1 = new Person<int>(1, "Ivan");
    Person<string>* person2 = new Person<string>("abc", "Roman");

    (*person1).print();
    (*person2).print();
    
    return 0;
}
