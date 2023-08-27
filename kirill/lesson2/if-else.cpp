#include <iostream> 
 
int main()
{
    int a = 0;
    if(a == 8) 
    {
        std::cout << "a == 8" << std::endl;
        a = 100500;
    }
 
    std::cout << "a == " << a << std::endl;
    std::cout << "End of program" <<  std::endl;
}