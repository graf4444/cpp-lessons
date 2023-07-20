#include <iostream>

using namespace std;


class Circle {
    private:
        double radius;

    public:
        double getRadius() {
            return radius;
        }

        void setRadius(double radius) {
            if (radius >= 0) {
                this->radius = radius;
            }
            throw "Radius must be greater than 0!";
        }

        double getArea() {
            return 3.1416 * radius * radius;
        }

};

int main()
{
    Circle* circle1 = new Circle();
    Circle* circle2 = new Circle();
    try {
        circle1->setRadius(10);
        circle2->setRadius(-1);
    }
    catch (const char* error_message) {
        cout << "const char*: " << error_message << endl;
    }
    catch (const string error_message) {
        cout << "string: " << error_message << endl;
    }
    catch (...) {
        cout << "exception!" << endl;
    }

    cout << circle1->getArea() << endl;
    cout << circle2->getArea() << endl;
    return 0;
}
