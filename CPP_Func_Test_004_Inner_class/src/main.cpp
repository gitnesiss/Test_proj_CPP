#include <iostream>
#include <ctime>

using namespace std;

class Image {

public:

    void getImageInfo() {
        for (int i = 0; i < LENGTH; i++) {
            cout << "#" << i << "   " << pixel[i].getInfo() << endl;
        }
    }

private:

    class Pixel {
    public:
        Pixel(int r, int g, int b) {
            this->r = r;
            this->g = g;
            this->b = b;
        }
        
        string getInfo() {
            return "Pixel: r = " + to_string(r) + " g = " + to_string(g) + " b = " + to_string(b);
        }

    private:
        int r;
        int g;
        int b;
    };

    static const int LENGTH = 5;

    Pixel pixel[LENGTH] {
        Pixel(0,4,64),
        Pixel(4,14,10),
        Pixel(111,4,24),
        Pixel(244,244,14),
        Pixel(111,179,64)
    };

};

int main() {
    setlocale(LC_ALL, "ru");

    Image img;
    img.getImageInfo();

    return 0;
}
