#include <iostream>
#include <string>

using namespace std;

class Circle {
    private:
        string AVAILABLE_COLORS[3] = {"black", "white", "green"};

        double radius;
        string color = "black";

    public:
        double getRadius() {
            return radius;
        }

        string getColor() {
            return color;
        }

        void setRadius(double radius) {
            if (radius > 0) {
                this->radius = radius;
            }
        }

        void setColor(string color) {
            string* fcolor = find(begin(AVAILABLE_COLORS), end(AVAILABLE_COLORS), color);
            if (fcolor != end(AVAILABLE_COLORS)) {
                this->color = color;
            }
        }

        double getArea() {
            return 3.1416 * radius * radius;
        }

};


int main()
{
    Circle circle1;
    Circle circle2;

    circle1.setRadius(1.0);
    circle2.setRadius(3.5);

    circle1.setColor("1");
    circle2.setColor("white");

    cout << circle1.getRadius() << " " << circle1.getColor() << endl;
    cout << circle2.getRadius() << " " << circle2.getColor() << endl;

    cout << "Area circle 1: " << circle1.getArea() << endl;
    cout << "Area circle 2: " << circle2.getArea() << endl;

    return 0;
}
