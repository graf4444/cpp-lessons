#include <iostream>
#include <string>

using namespace std;


class Shape {
    protected:
        double area;

    public:
        double getArea() {
            return area;
        }
};

class Circle : public Shape {
    private:
        double radius;

    public:
        Circle(double r) {
            radius = r;
            area = 3.1416 * radius * radius;
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
            area = width * height;
        }

};


int main()
{
    Circle circle(10);
    Rectangle rectangle(15, 100);

    cout << circle.getArea() << endl;
    cout << rectangle.getArea() << endl;

    return 0;
}
