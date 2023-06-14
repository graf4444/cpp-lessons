#include <iostream>

// Определение класса
class MyClass {
private:
    int myNumber;

public:
    // Конструктор класса
    MyClass(int number) {
        myNumber = number;
    }

    // Метод класса
    void printNumber() const {
        // myNumber = 100500;
        std::cout << "My number is: " << myNumber << std::endl;
    }
};

// Функция main
int main() {
    // Создание объекта класса
    const MyClass obj(42);

    // Вызов метода класса
    obj.printNumber();

    return 0;
}
