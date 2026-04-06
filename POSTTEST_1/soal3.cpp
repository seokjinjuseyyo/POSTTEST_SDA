//Soal 3 : Array dan pointer untuk operasi dasar

#include <iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    int* depan = arr;
    int* belakang = arr + n - 1;

    while (depan < belakang) {
        int temp = *depan;
        *depan = *belakang;
        *belakang = temp;
        depan++;
        belakang--;
    }
}

int main() {
    int prima[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;
    int* p;

    // tampilkan arraynya yang sebelum dibalik
    cout << "Array sebelum dibalik:" << endl;
    p = prima;
    for (int i = 0; i < n; i++) {
        cout << "nilai: " << *p << "  alamat: " << p << endl;
        p++;
    }

    reverseArray(prima, n);

    // tampilkan arraynya yang sudah dibalik
    cout << "\nArray sesudah dibalik:" << endl;
    p = prima;
    for (int i = 0; i < n; i++) {
        cout << "nilai: " << *p << "  alamat: " << p << endl;
        p++;
    }

    return 0;
}
