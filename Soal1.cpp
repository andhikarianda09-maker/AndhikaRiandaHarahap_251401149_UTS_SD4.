#include <iostream>
using namespace std;

int main() {
    int nilai[5][4];
    double rataRata[5];
    double total;

    for (int i = 0; i < 5; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;

        for (int j = 0; j < 4; j++) {
            cout << "Masukkan nilai komponen ke-" << j + 1 << ": ";
            cin >> nilai[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        total = 0;

        for (int j = 0; j < 4; j++) {
            total += nilai[i][j];
        }

        rataRata[i] = total / 4;
        cout << "\nRata-rata mahasiswa ke-" << i + 1 << ": " << rataRata[i];
    }

    int tertinggi = 0;
    int terendah = 0;
    int jumlah = 0;

    for (int i = 0; i < 5; i++) {
        if (rataRata[i] > rataRata[tertinggi]) {
            tertinggi = i;
        }

        if (rataRata[i] < rataRata[terendah]) {
            terendah = i;
        }

        if (rataRata[i] >= 75) {
            jumlah++;
        }
    }

    cout << "\n\nRata-rata tertinggi: Mahasiswa ke-" << tertinggi + 1;
    cout << " (" << rataRata[tertinggi] << ")";

    cout << "\nRata-rata terendah: Mahasiswa ke-" << terendah + 1;
    cout << " (" << rataRata[terendah] << ")";

    cout << "\nJumlah mahasiswa dengan rata-rata minimal 75: " << jumlah;

    return 0;
}