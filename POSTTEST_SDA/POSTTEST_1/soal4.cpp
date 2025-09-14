#include <iostream>
using namespace std;

void swapRef(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;
    cout << "Masukkan nilai x: "; cin >> x;
    cout << "Masukkan nilai y: "; cin >> y;

    cout << "Sebelum ditukar: x = " << x << ", y = " << y << endl;
    swapRef(x, y);
    cout << "Sesudah ditukar: x = " << x << ", y = " << y << endl;
}
