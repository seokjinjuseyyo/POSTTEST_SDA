#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*Tugas nya Syarifah Anargya Rizky dengan Nim 2509106007
dengan penugasan nomor ganjil tema pawcare petshop dan juga dokter hewan*/

#define MAX 100 // kapasitas maksimum array

struct Hewan { //untuk nyimpan data hewannya
    int id; // id hewannya
    string nama; // nama hewannya
    string jenis; // jenis hewannya
    string dokter; // ini nama dokter hewannya nanti
    int harga; // harga buat perawatan hewannya
};

Hewan dataHewan[MAX]; // array buat nyimpen semua data hewan
int jumlah = 5; // jumlah data awal

Hewan queueAntrian[MAX]; // array queue nya
int frontQ = -1, rearQ = -1; // penanda depan dan belakang antrian

Hewan stackRiwayat[MAX]; // array stack nya
int topS = -1; // penanda elemen teratas stack

void swapData(Hewan *a, Hewan *b) { // Fungsinya kita swap pakai pointer
    Hewan temp = *a; // buat nyimpan data a
    *a = *b;         // a nya isi dengan b
    *b = temp;       // b nya isi dengan temp
}

void tampilHeader() { // Buat nampilin header tabel
    cout << "\n===========================================================================" << endl;
    cout << "| " << left << setw(5)  << "ID"
         << "| " << setw(12) << "Nama"
         << "| " << setw(12) << "Jenis"
         << "| " << setw(20) << "Dokter Hewan"
         << "| " << setw(14) << "Harga (Rp)" << " |" << endl;
    cout << "===========================================================================" << endl;
}

void tampilBaris(Hewan* h) { // nampilin 1 baris data hewan
    cout << "| " << left << setw(5)  << h->id
         << "| " << setw(12) << h->nama
         << "| " << setw(12) << h->jenis
         << "| " << setw(20) << h->dokter
         << "| " << setw(14) << h->harga << " |" << endl;
}

void tampilSemua(Hewan* arr, int n) { // buat nampilin semua datanya
    if (n == 0) {
        cout << "\nBelum ada data hewan." << endl;
        return;
    }

    tampilHeader();

    for (int i = 0; i < n; i++) {
        tampilBaris(arr + i); // kita akses pakai pointer
    }

    cout << "===========================================================================" << endl;
}

void tambahData(Hewan* arr, int &n) { // buat nambah data baru
    int idBaru;
    bool idAda;

    do { // kita validasi ID nya biar ga double
        idAda = false;
        cout << "ID Hewan     : "; cin >> idBaru;

        for (int i = 0; i < n; i++) {
            if (arr[i].id == idBaru) {
                idAda = true;
                break;
            }
        }

        if (idAda) cout << "ID sudah ada, coba lagi!\n";

    } while (idAda);

    arr[n].id = idBaru; // buat input data
    cout << "Nama Hewan   : "; cin.ignore(); getline(cin, arr[n].nama);
    cout << "Jenis Hewan  : "; getline(cin, arr[n].jenis);
    cout << "Dokter Hewan : "; getline(cin, arr[n].dokter);
    cout << "Harga (Rp)   : "; cin >> arr[n].harga;

    n++; // jumlah datanya bertambah

    cout << "\nData berhasil ditambahkan.\n";
}

void linearSearch(Hewan* arr, int n, string cari) { // bagian linear search dan iterasinya
    bool ketemu = false;
    for (int i = 0; i < n; i++) { // loop buat kita cek satu-satu dari depan

        cout << "Iterasi ke-" << i  // buat nampilin proses tiap iterasinya
             << " -> cek: " << (arr + i)->nama << endl;

        if ((arr + i)->nama == cari) { // kita cek apakah namanya itu sama

            cout << "\n>> Data ketemu di index ke-" << i << "!\n";

            tampilHeader();
            tampilBaris(arr + i);

            cout << "===========================================================================" << endl;

            ketemu = true;
            break; // dan kita berhenti kalau sudah ketemu
        }
    }

    if (!ketemu) { // kita kasih output kalau ga ketemu
        cout << "\nNama '" << cari << "' tidak ditemukan.\n";
    }
}

int fibonacciSearch(Hewan* arr, int n, int target) { // bagian fibonacci search

    int fib2 = 0; // F(k-2)
    int fib1 = 1; // F(k-1)
    int fib  = 1; // F(k)

    while (fib < n) { // kita cari fibonacci >= n
        fib2 = fib1;
        fib1 = fib;
        fib  = fib1 + fib2;
    }

    int offset = -1;

    while (fib > 1) {
        int i = offset + fib2;

        if (i >= n) i = n - 1;

        if ((arr + i)->id == target) {
            return i; // ketemu
        }
        else if ((arr + i)->id < target) {
            fib  = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else {
            fib  = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
    }

    if (fib1 && (arr + offset + 1)->id == target)
        return offset + 1;

    return -1;
}

void bubbleSort(Hewan* arr, int n) { // ini proses bubble Sort buat nama a-z
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j].nama > arr[j + 1].nama) { // kita bandingkan namanya
                swapData(&arr[j], &arr[j + 1]);
            }
        }
    }

    cout << "\nData sudah diurutkan berdasarkan nama.\n";
    tampilSemua(arr, n);
}

void selectionSort(Hewan* arr, int n) { // ini proses selection sortnya
    for (int i = 0; i < n - 1; i++) {

        int idxMin = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j].harga < arr[idxMin].harga) {
                idxMin = j;
            }
        }

        if (idxMin != i) {
            swapData(&arr[i], &arr[idxMin]);
        }
    }

    cout << "\nData sudah diurutkan berdasarkan harga.\n";
    tampilSemua(arr, n);
}

bool isQueueFull() { // cek apakah antrian sudah penuh
    return rearQ == MAX - 1;
}

bool isQueueEmpty() { // cek apakah antrian kosong
    return frontQ == -1 || frontQ > rearQ;
}

void enqueue(Hewan* h) { // buat nambahin hewan ke antrian
    if (isQueueFull()) { // kalau antrian penuh ya overflow
        cout << "\n[OVERFLOW] Antrian sudah penuh!\n";
        return;
    }

    if (frontQ == -1) frontQ = 0; // kalau elemen pertama masuk kita set front nya ke 0

    rearQ++; // geser rear ke kanan buat tempat elemen baru
    *(queueAntrian + rearQ) = *h; // kita salin data hewan pakai dereferensi pointer

    cout << "\nHewan '" << h->nama << "' (ID: " << h->id << ") berhasil didaftarkan ke antrian.\n";
}

void dequeue() { // buat manggil hewan terdepan dari antrian
    if (isQueueEmpty()) { // kalau antrian kosong
        cout << "\n Antrian kosong, tidak ada hewan yang bisa dipanggil!\n";
        return;
    }

    Hewan* dipanggil = queueAntrian + frontQ; // ambil hewan paling depan pakai pointer

    cout << "\n>> Memanggil pasien: " << dipanggil->nama << " (ID: " << dipanggil->id << ")" << endl;
    cout << "   Jenis  : " << dipanggil->jenis << endl;
    cout << "   Dokter : " << dipanggil->dokter << endl;

    frontQ++; // geser front ke kanan karena sudah dipanggil

    if (isQueueEmpty()) frontQ = rearQ = -1; // reset kalau antrian jadi kosong
}

void tampilAntrian() { // buat nampilin semua isi antrian
    if (isQueueEmpty()) {
        cout << "\nAntrian pemeriksaan kosong.\n";
        return;
    }

    cout << "\n===== ANTRIAN PEMERIKSAAN HEWAN =====\n";
    tampilHeader();

    for (int i = frontQ; i <= rearQ; i++) { // iterasi pakai pointer 
        tampilBaris(queueAntrian + i);
    }

    cout << "===========================================================================" << endl;
    cout << "Total antrian: " << (rearQ - frontQ + 1) << " hewan\n";
}

bool isStackFull() { // cek apakah stack sudah penuh
    return topS == MAX - 1;
}

bool isStackEmpty() { // cek apakah stack kosong
    return topS < 0;
}

void pushRiwayat(Hewan* h) { // buat nyimpen tindakan ke riwayat
    if (isStackFull()) { // kalau stack penuh 
        cout << "\nRiwayat sudah penuh!\n";
        return;
    }

    topS++; // naikan top dulu
    *(stackRiwayat + topS) = *h; // salin data hewan pakai  pointer

    cout << "\nTindakan untuk '" << h->nama << "' (ID: " << h->id << ") berhasil dicatat ke riwayat.\n";
}

void popRiwayat() { // buat hapus tindakan terakhir dari riwayat
    if (isStackEmpty()) { // kalau stack kosong 
        cout << "\nRiwayat kosong, tidak ada tindakan yang bisa dibatalkan!\n";
        return;
    }

    Hewan* terakhir = stackRiwayat + topS; // ambil elemen teratas pakai pointer

    cout << "\n>> Tindakan terakhir dibatalkan: " << terakhir->nama << " (ID: " << terakhir->id << ")\n";

    topS--; // turunkan top, data kita anggap sudah dihapus
}

void peekQueueStack() { // buat lihat terdepan antrian dan teratas riwayat tanpa hapus
    cout << "\n=====   ANTRIAN & RIWAYAT    =====\n";

    if (!isQueueEmpty()) { // cek dulu apakah antrian ada isinya
        cout << "\n[QUEUE - Pasien Terdepan]:\n";
        tampilHeader();
        tampilBaris(queueAntrian + frontQ); // lihat frontnya aja tanpa hapus
        cout << "===========================================================================" << endl;
    } else {
        cout << "\n Antrian kosong.\n";
    }

    if (!isStackEmpty()) { // cek dulu apakah riwayat ada isinya
        cout << "\n Tindakan Terakhir]:\n";
        tampilHeader();
        tampilBaris(stackRiwayat + topS); // lihat topnya aja tanpa hapus
        cout << "===========================================================================" << endl;
    } else {
        cout << "\n Riwayat masih kosong.\n";
    }
}

void tampilRiwayat() { // buat nampilin semua isi riwayat tindakan
    if (isStackEmpty()) {
        cout << "\nRiwayat tindakan kosong.\n";
        return;
    }

    cout << "\n=====          RIWAYAT TINDAKAN MEDIS          =====\n";
    tampilHeader();

    for (int i = topS; i >= 0; i--) { // iterasi dari top ke bawah pakai pointer 
        tampilBaris(stackRiwayat + i);
    }

    cout << "===========================================================================" << endl;
    cout << "Total riwayat: " << (topS + 1) << " tindakan\n";
}

void daftarAntrian(Hewan* arr, int n) { // buat milih hewan dari data lalu didaftarkan ke antrian
    if (n == 0) {
        cout << "\nBelum ada data hewan.\n";
        return;
    }

    tampilSemua(arr, n); // tampil dulu semua data biar bisa pilih

    int idCari;
    cout << "Masukkan ID hewan yang ingin didaftarkan ke antrian: ";
    cin >> idCari;

    bool ketemu = false;
    for (int i = 0; i < n; i++) {
        if ((arr + i)->id == idCari) { // cek ID nya cocok ga
            enqueue(arr + i); // kalau cocok langsung enqueue
            ketemu = true;
            break;
        }
    }

    if (!ketemu) cout << "\nID tidak ditemukan.\n";
}

void catatRiwayat(Hewan* arr, int n) { // buat milih hewan dari data lalu dicatat ke riwayat
    if (n == 0) {
        cout << "\nBelum ada data hewan.\n";
        return;
    }

    tampilSemua(arr, n); // tampil dulu semua data biar bisa pilih

    int idCari;
    cout << "Masukkan ID hewan yang ingin dicatat tindakannya: ";
    cin >> idCari;

    bool ketemu = false;
    for (int i = 0; i < n; i++) {
        if ((arr + i)->id == idCari) { // cek ID nya cocok ga
            pushRiwayat(arr + i); // kalau cocok langsung push aja
            ketemu = true;
            break;
        }
    }

    if (!ketemu) cout << "\nID tidak ditemukan.\n";
}

int main() { // ini main nya
    int pilihan;

    // data awalnya gini
    dataHewan[0] = {21, "Megatron", "Kucing",  "drh. Seokjin",  150000};
    dataHewan[1] = {22, "Willy",    "Anjing",  "drh. Jungkook", 200000};
    dataHewan[2] = {23, "Molly",    "Burung",  "drh. Yoongi",    80000};
    dataHewan[3] = {24, "Whinky",   "Kelinci", "drh. Seokjin",  120000};
    dataHewan[4] = {25, "Mujair",   "Anjing",  "drh. Jungkook", 250000};

    do {
        cout << "\n================================================" << endl;
        cout << "||       MANAGEMENT PAWCARE PETSHOP          ||" << endl;
        cout << "================================================" << endl;
        cout << "||               DATA HEWAN                  ||" << endl;
        cout << "|| 1.  Tampil Semua Data Hewan               ||" << endl;
        cout << "|| 2.  Tambah Data Hewan Baru                ||" << endl;
        cout << "|| 3.  Cari Berdasarkan Nama                 ||" << endl;
        cout << "|| 4.  Cari Berdasarkan ID                   ||" << endl;
        cout << "|| 5.  Urutkan Berdasarkan Nama              ||" << endl;
        cout << "|| 6.  Urutkan Berdasarkan Harga             ||" << endl;
        cout << "||            ANTRIAN & RIWAYAT              ||" << endl;
        cout << "|| 7.  Daftarkan Hewan ke Antrian            ||" << endl;
        cout << "|| 8.  Panggil Pasien Terdepan               ||" << endl;
        cout << "|| 9.  Tampil Semua Antrian                  ||" << endl;
        cout << "|| 10. Catat Tindakan ke Riwayat             ||" << endl;
        cout << "|| 11. Batalkan Tindakan Terakhir            ||" << endl;
        cout << "|| 12. Tampil Semua Riwayat                  ||" << endl;
        cout << "|| 13. Peek Antrian & Riwayat                ||" << endl;
        cout << "|| 14. Keluar                                ||" << endl;
        cout << "================================================" << endl;
        cout << "Pilihan: "; cin >> pilihan;

        if (pilihan == 1) {
            tampilSemua(dataHewan, jumlah);
        }
        else if (pilihan == 2) {
            tambahData(dataHewan, jumlah);
        }
        else if (pilihan == 3) {
            string cari;
            cout << "Nama yang dicari: ";
            cin.ignore(); getline(cin, cari);
            linearSearch(dataHewan, jumlah, cari);
        }
        else if (pilihan == 4) {

            for (int i = 0; i < jumlah - 1; i++) // kita urutkan dulu berdasarkan ID
                for (int j = 0; j < jumlah - i - 1; j++)
                    if (dataHewan[j].id > dataHewan[j + 1].id)
                        swapData(&dataHewan[j], &dataHewan[j + 1]);

            int idCari;
            cout << "ID yang dicari: "; cin >> idCari;

            int hasil = fibonacciSearch(dataHewan, jumlah, idCari);

            if (hasil != -1) {
                cout << "\nData ketemu!\n";
                tampilHeader();
                tampilBaris(&dataHewan[hasil]);
                cout << "===============================================================================" << endl;
            } else {
                cout << "\nID tidak ditemukan.\n";
            }
        }
        else if (pilihan == 5) {
            bubbleSort(dataHewan, jumlah);
        }
        else if (pilihan == 6) {
            selectionSort(dataHewan, jumlah);
        }
        else if (pilihan == 7) {
            daftarAntrian(dataHewan, jumlah); // panggil fungsi daftar antrian
        }
        else if (pilihan == 8) {
            dequeue(); // panggil pasien terdepan
        }
        else if (pilihan == 9) {
            tampilAntrian(); // tampil semua antrian
        }
        else if (pilihan == 10) {
            catatRiwayat(dataHewan, jumlah); // panggil fungsi catat riwayat
        }
        else if (pilihan == 11) {
            popRiwayat(); // batalkan tindakan terakhir
        }
        else if (pilihan == 12) {
            tampilRiwayat(); // tampil semua riwayat
        }
        else if (pilihan == 13) {
            peekQueueStack(); // peek antrian dan riwayat
        }
        else if (pilihan == 14) {
            cout << "\nTerima kasih sudah mengunjungi petshop Whingky.\n";
        }
        else {
            cout << "\nPilihan tidak valid.\n";
        }

    } while (pilihan != 14);

    return 0;
}