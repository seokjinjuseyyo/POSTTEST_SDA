//SOAL 2 - Tugas Struct dan Array Data Mahasiswa

#include <iostream>
#include <iomanip> // buat baikin tabel sajaa
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    int jumlah = 5;
    Mahasiswa mhs[5];

    for (int i = 0; i < jumlah; i++) {
        cout << "--- Isi Data Mahasiswa ke-" << (i + 1) << " ---" << endl;
        cout << "Nama : ";
        getline(cin, mhs[i].nama);
        cout << "NIM  : ";
        getline(cin, mhs[i].nim);
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cin.ignore();
        cout << endl;
    }

    cout << "===== Daftar Semua Data Mahasiswa =====" << endl;
    cout << string(4+15+15+6, '-') << endl; 
    cout << left << setw(4) << "No" \
        << setw(15) << "Nama" \
        << setw(15) << "NIM" \
        << setw(6) << "IPK" << endl;
    cout << string(4+15+15+6, '-') << endl; 
    for (int i = 0; i < jumlah; i++) {
        cout << left << setw(4) << (i+1)
            << setw(15) << mhs[i].nama
            << setw(15) << mhs[i].nim
            << setw(6) << fixed << setprecision(2) << mhs[i].ipk << endl;
    cout << string(4+15+15+6, '-') << endl; 
    }

    // Kita cari IPK tertingginya
    int idxTertinggi = 0;
    for (int i = 1; i < jumlah; i++) {
        if (mhs[i].ipk > mhs[idxTertinggi].ipk) {
            idxTertinggi = i;
        }
    }

    cout << endl;
    cout << "=== Mahasiswa IPK Tertinggi ===" << endl;
    cout << "Nama : " << mhs[idxTertinggi].nama << endl;
    cout << "NIM  : " << mhs[idxTertinggi].nim << endl;
    cout << "IPK  : " << mhs[idxTertinggi].ipk << endl;

    return 0;
}
