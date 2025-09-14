#include <iostream>
#include <algorithm>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

bool compareIPK(Mahasiswa a, Mahasiswa b) {
    return a.ipk < b.ipk;
}

int main() {
    const int N = 4;
    Mahasiswa mhs[N];

    cout << "Input data 4 mahasiswa:\n";
    for (int i = 0; i < N; i++) {
        cout << "Mahasiswa " << i + 1 << ":\n";
        cout << "Nama: "; cin >> mhs[i].nama;
        cout << "NIM: "; cin >> mhs[i].nim;
        cout << "IPK: "; cin >> mhs[i].ipk;
    }

    sort(mhs, mhs + N, compareIPK);

    cout << "\nData mahasiswa setelah diurutkan berdasarkan IPK ascending:\n";
    for (int i = 0; i < N; i++) {
        cout << mhs[i].nama << " (" << mhs[i].nim << ") - IPK: " << mhs[i].ipk << endl;
    }
}
