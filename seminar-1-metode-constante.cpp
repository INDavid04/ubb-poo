#include <iostream>
using namespace std;

class Point {
private:
    int x = -3, y = -5;
public:
    Point(int a = 0, int b = 0) {
        x = a;
        y = b;
    }
    void show() const {
        cout << "x: " << x << ' ' << "y: " << y << endl;
    }
};

int main() {
    Point p(52);

    p.show();
    return 0;
}
