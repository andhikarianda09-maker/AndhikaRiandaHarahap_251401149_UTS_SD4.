#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int jumlah;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        jumlah = 0;
    }

    void enqueue(string nama) {
        Node* baru = new Node;
        baru->nama = nama;
        baru->next = nullptr;

        if (front == nullptr) {
            front = rear = baru;
        } else {
            rear->next = baru;
            rear = baru;
        }

        jumlah++;
        cout << nama << " berhasil ditambahkan ke antrian.\n";
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Antrian kosong! Tidak ada pelanggan.\n";
            return;
        }

        Node* hapus = front;

        cout << "Melayani pelanggan: " << front->nama << endl;

        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete hapus;
        jumlah--;
    }

    void tampilFront() {
        if (front == nullptr) {
            cout << "Antrian kosong!\n";
        } else {
            cout << "Pelanggan paling depan: "
                 << front->nama << endl;
        }
    }

    void tampilRear() {
        if (rear == nullptr) {
            cout << "Antrian kosong!\n";
        } else {
            cout << "Pelanggan paling belakang: "
                 << rear->nama << endl;
        }
    }

    void hitungJumlah() {
        cout << "Jumlah pelanggan yang menunggu: "
             << jumlah << endl;
    }

    void tampilAntrian() {
        if (front == nullptr) {
            cout << "Antrian kosong!\n";
            return;
        }

        Node* bantu = front;

        cout << "Isi antrian: ";
        while (bantu != nullptr) {
            cout << bantu->nama;

            if (bantu->next != nullptr) {
                cout << " -> ";
            }

            bantu = bantu->next;
        }

        cout << endl;
    }

    ~Queue() {
        while (front != nullptr) {
            Node* hapus = front;
            front = front->next;
            delete hapus;
        }

        rear = nullptr;
    }
};

int main() {
    Queue antrian;
    int pilihan;
    string nama;

    do {
        cout << "\n===== SISTEM ANTRIAN PELANGGAN =====\n";
        cout << "1. Tambah pelanggan\n";
        cout << "2. Layani pelanggan\n";
        cout << "3. Tampilkan pelanggan paling depan\n";
        cout << "4. Tampilkan pelanggan paling belakang\n";
        cout << "5. Hitung jumlah pelanggan\n";
        cout << "6. Tampilkan seluruh antrian\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama pelanggan: ";
                getline(cin, nama);
                antrian.enqueue(nama);
                break;

            case 2:
                antrian.dequeue();
                break;

            case 3:
                antrian.tampilFront();
                break;

            case 4:
                antrian.tampilRear();
                break;

            case 5:
                antrian.hitungJumlah();
                break;

            case 6:
                antrian.tampilAntrian();
                break;

            case 0:
                cout << "Program selesai. Terima kasih!\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}
