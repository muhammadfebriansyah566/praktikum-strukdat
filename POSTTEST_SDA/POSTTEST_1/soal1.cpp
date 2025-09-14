#include <iostream>
using namespace std;

bool isPrima(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

void balikArray(int *arr, int n) {
    int *awal = arr;
    int *akhir = arr + n - 1;
    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

int main() {
    const int N = 7;
    int arr[N];
    int count = 0, num = 2;

    // isi array dengan bilangan prima
    while (count < N) {
        if (isPrima(num)) {
            arr[count++] = num;
        }
        num++;
    }

    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < N; i++) cout << arr[i] << " ";
    cout << endl;

    balikArray(arr, N);

    cout << "Array sesudah dibalik: ";
    for (int i = 0; i < N; i++) cout << arr[i] << " ";
    cout << endl;
}
