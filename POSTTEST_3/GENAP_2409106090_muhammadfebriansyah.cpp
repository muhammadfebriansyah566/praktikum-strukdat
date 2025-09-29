#include <iostream>
#include <string>
using namespace std;

struct Jadwal {
string kodePenerbangan;
string tujuan;
string status;
Jadwal* next;
Jadwal* prev;  // tambahan untuk double linked list
};

Jadwal* head = nullptr;
Jadwal* tail = nullptr; // pointer ke node terakhir
int jumlahJadwal = 0;

// Generate kode penerbangan otomatis
string generateKode(int urutan) {
return "JT-090" + (urutan == 0 ? string("") : "-" + to_string(urutan));
}

// Tambah Jadwal di akhir
void tambahJadwal() {
string tujuan;
cout << "Masukkan tujuan penerbangan: ";
cin.ignore();
getline(cin, tujuan);

Jadwal* baru = new Jadwal;
baru->kodePenerbangan = generateKode(jumlahJadwal);
baru->tujuan = tujuan;
baru->status = "Tepat Waktu";
baru->next = nullptr;
baru->prev = nullptr;

if (!head) {
    head = tail = baru;
} else {
    tail->next = baru;
    baru->prev = tail;
    tail = baru;
}

jumlahJadwal++;
cout << "Jadwal penerbangan berhasil ditambahkan dengan kode: " << baru->kodePenerbangan << endl;


}

// Sisipkan Jadwal sesuai posisi (digit terakhir NIM = 0 -> posisi 2)
void sisipJadwal() {
string tujuan;
cout << "Masukkan tujuan penerbangan: ";
cin.ignore();
getline(cin, tujuan);

int posisi = 0 + 2; // digit terakhir nim = 0 → 0+2=2
Jadwal* baru = new Jadwal;
baru->kodePenerbangan = generateKode(jumlahJadwal);
baru->tujuan = tujuan;
baru->status = "Tepat Waktu";
baru->next = nullptr;
baru->prev = nullptr;

if (!head) {
    head = tail = baru;
} else {
    if (posisi <= 1) {
        baru->next = head;
        head->prev = baru;
        head = baru;
    } else {
        Jadwal* temp = head;
        for (int i = 1; i < posisi - 1 && temp->next; i++) {
            temp = temp->next;
        }
        baru->next = temp->next;
        if (temp->next) temp->next->prev = baru;
        temp->next = baru;
        baru->prev = temp;
        if (baru->next == nullptr) tail = baru; // update tail jika disisipkan di akhir
    }
}
jumlahJadwal++;
cout << "Jadwal berhasil disisipkan di posisi ke-" << posisi << endl;

}

// Hapus jadwal paling awal
void hapusAwal() {
if (!head) {
cout << "Tidak ada jadwal untuk dihapus.\n";
return;
}
Jadwal* temp = head;
head = head->next;
if (head) head->prev = nullptr;
else tail = nullptr; // kalau list kosong
cout << "Jadwal " << temp->kodePenerbangan << " berhasil dihapus.\n";
delete temp;
jumlahJadwal--;
}

// Update status penerbangan
void updateStatus() {
if (!head) {
cout << "Belum ada jadwal.\n";
return;
}

string kode;
cout << "Masukkan kode penerbangan yang ingin diupdate: ";
cin >> kode;

Jadwal* temp = head;
while (temp && temp->kodePenerbangan != kode) {
    temp = temp->next;
}

if (!temp) {
    cout << "Jadwal tidak ditemukan.\n";
} else {
    cout << "Status saat ini: " << temp->status << endl;
    cout << "Masukkan status baru: ";
    cin.ignore();
    getline(cin, temp->status);
    cout << "Status penerbangan " << kode << " berhasil diperbarui.\n";
}

}

// Tampilkan semua jadwal dari depan
void tampilkanJadwal() {
if (!head) {
cout << "Tidak ada jadwal.\n";
return;
}

Jadwal* temp = head;
cout << "\n=== Daftar Jadwal Penerbangan (Dari Depan) ===\n";
while (temp) {
    cout << "Kode   : " << temp->kodePenerbangan << endl;
    cout << "Tujuan : " << temp->tujuan << endl;
    cout << "Status : " << temp->status << endl;
    cout << "-------------------------------\n";
    temp = temp->next;
}

}

// Traversal dari belakang
void tampilkanJadwalBelakang() {
if (!tail) {
cout << "Tidak ada jadwal.\n";
return;
}

Jadwal* temp = tail;
cout << "\n=== Daftar Jadwal Penerbangan (Dari Belakang) ===\n";
while (temp) {
    cout << "Kode   : " << temp->kodePenerbangan << endl;
    cout << "Tujuan : " << temp->tujuan << endl;
    cout << "Status : " << temp->status << endl;
    cout << "-------------------------------\n";
    temp = temp->prev;
}

}

// Cari jadwal berdasarkan kode atau tujuan
void cariJadwal() {
if (!head) {
cout << "Belum ada jadwal.\n";
return;
}

string input;
cout << "Masukkan kode penerbangan atau tujuan: ";
cin.ignore();
getline(cin, input);

Jadwal* temp = head;
bool ditemukan = false;
while (temp) {
    if (temp->kodePenerbangan == input || temp->tujuan == input) {
        cout << "\n=== Detail Jadwal Ditemukan ===\n";
        cout << "Kode   : " << temp->kodePenerbangan << endl;
        cout << "Tujuan : " << temp->tujuan << endl;
        cout << "Status : " << temp->status << endl;
        cout << "-------------------------------\n";
        ditemukan = true;
        break;
    }
    temp = temp->next;
}

if (!ditemukan) cout << "Data tidak ditemukan.\n";

}

int main() {
int pilihan;
do {
cout << "\n+------------------------------------------------------------+\n";
cout << "|         FLIGHT SCHEDULE SYSTEM                             |\n";
cout << "|      [ FEB RIAN - 2409106090 ]                             |\n";
cout << "+------------------------------------------------------------+\n";
cout << "| 1. Tambah Jadwal Penerbangan                               |\n";
cout << "| 2. Sisipkan Jadwal Penerbangan                             |\n";
cout << "| 3. Hapus Jadwal Paling Awal                                |\n";
cout << "| 4. Update Status Penerbangan                               |\n";
cout << "| 5. Tampilkan Semua Jadwal (Dari Depan)                     |\n";
cout << "| 6. Tampilkan Semua Jadwal (Dari Belakang)                  |\n";
cout << "| 7. Cari Jadwal (Berdasarkan Kode / Tujuan)                 |\n";
cout << "| 0. Keluar                                                  |\n";
cout << "+------------------------------------------------------------+\n";
cout << "Pilih menu: ";
cin >> pilihan;

    switch (pilihan) {
        case 1: tambahJadwal(); break;
        case 2: sisipJadwal(); break;
        case 3: hapusAwal(); break;
        case 4: updateStatus(); break;
        case 5: tampilkanJadwal(); break;
        case 6: tampilkanJadwalBelakang(); break;
        case 7: cariJadwal(); break;
        case 0: cout << "Terima kasih!\n"; break;
        default: cout << "Pilihan tidak valid!\n";
    }
} while (pilihan != 0);

return 0;

}
