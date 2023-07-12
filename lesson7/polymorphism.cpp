#include <iostream>
#include <string>

using namespace std;


class Shape {
    public:
        virtual double getArea() {
            return 0.0;
        }
};

class Circle : public Shape {
    private:
        double radius;

    public:
        Circle(double r) {
            radius = r;
        }

        double getArea() override {
            return 3.1416 * radius * radius;
        }
};

class Rectangle : public Shape {
    private:
        double width;
        double height;

    public:
        Rectangle(double width, double height) {
            this->width = width;
            this->height = height;
        }

        double getArea() override {
            return width * height;
        }
};


void print_area(Shape* shape) {
    cout << shape->getArea() << endl;
}


int main()
{
    Circle circle(10);
    Rectangle rectangle(15, 100);

    print_area(&circle);
    print_area(&rectangle);

    cout << circle.getArea() << endl;
    cout << rectangle.getArea() << endl;

    return 0;
}
