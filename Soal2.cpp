#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = nullptr;
    int n, nilai, cari;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Node* baru = new Node();

        cout << "Masukkan bilangan: ";
        cin >> baru->data;

        baru->next = nullptr;

        if (head == nullptr) {
            head = baru;
        } else {
            Node* bantu = head;

            while (bantu->next != nullptr) {
                bantu = bantu->next;
            }

            bantu->next = baru;
        }
    }

    cout << "\nData Linked List: ";
    Node* bantu = head;

    while (bantu != nullptr) {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }

    cout << "\n\nMasukkan nilai yang dicari: ";
    cin >> cari;

    bantu = head;

    while (bantu != nullptr && bantu->data != cari) {
        bantu = bantu->next;
    }

    if (bantu == nullptr) {
        cout << "Nilai tidak ditemukan.";
    } else if (bantu->next == nullptr) {
        cout << "Tidak ada node setelah nilai tersebut.";
    } else {
        Node* hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;

        cout << "Node setelah nilai " << cari << " berhasil dihapus.";
    }

    Node* sebelumnya = nullptr;
    Node* sekarang = head;
    Node* berikutnya = nullptr;

    while (sekarang != nullptr) {
        berikutnya = sekarang->next;
        sekarang->next = sebelumnya;
        sebelumnya = sekarang;
        sekarang = berikutnya;
    }

    head = sebelumnya;

    cout << "\n\nLinked List setelah dibalik: ";

    bantu = head;

    while (bantu != nullptr) {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }

    while (head != nullptr) {
        bantu = head;
        head = head->next;
        delete bantu;
    }

    return 0;
}