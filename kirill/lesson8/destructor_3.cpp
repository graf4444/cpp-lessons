#include <iostream>
 
class Person
{
    public:
        Person(std::string p_name)
        {
            name = p_name;
            std::cout << "Person " << name << " created" << std::endl;
        }
        
        ~Person()
        {
            std::cout << "Person " << name << " deleted" << std::endl;
        }
    private:
        std::string name;
};
 
int main()
{
    // int var = 100500;
    // int* ptr = &var;
    {
        Person* tom = new Person("Tom");
        delete tom;
        Person* bob = new Person("Bob");
        delete bob;
    }

    Person sam("Sam");

    return 0;
}