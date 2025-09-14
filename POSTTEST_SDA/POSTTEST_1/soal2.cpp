#include <iostream>
using namespace std;

int main() {
    const int N = 3;
    int matriks[N][N];
    int val = 1;

    // isi matriks dengan angka 1..9
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriks[i][j] = val++;
        }
    }

    // hitung jumlah elemen baris genap (index 1)
    int jumlah = 0;
    for (int j = 0; j < N; j++) {
        jumlah += matriks[1][j];
    }

    // cetak matriks
    cout << "Matriks 3x3:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Jumlah elemen baris genap (baris ke-2): " << jumlah << endl;
}
