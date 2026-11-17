#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* buatNode(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->left = nullptr;
    baru->right = nullptr;
    return baru;
}

Node* insert(Node* root, int nilai) {
    if (root == nullptr) {
        return buatNode(nilai);
    }

    if (nilai < root->data) {
        root->left = insert(root->left, nilai);
    }
    else if (nilai > root->data) {
        root->right = insert(root->right, nilai);
    }

    return root;
}

void tampilRentang(Node* root, int bawah, int atas) {
    if (root == nullptr) {
        return;
    }

    if (root->data > bawah) {
        tampilRentang(root->left, bawah, atas);
    }

    if (root->data >= bawah && root->data <= atas) {
        cout << root->data << " ";
    }

    if (root->data < atas) {
        tampilRentang(root->right, bawah, atas);
    }
}

bool search(Node* root, int cari) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == cari) {
        return true;
    }

    if (cari < root->data) {
        return search(root->left, cari);
    }

    return search(root->right, cari);
}
void hapusBST(Node* root) {
    if (root == nullptr) {
        return;
    }

    hapusBST(root->left);
    hapusBST(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;
    int nilai, bawah, atas, cari;

    cout << "===== PROGRAM BINARY SEARCH TREE =====\n";

    cout << "\nMasukkan bilangan bulat (-1 untuk berhenti):\n";

    while (true) {
        cout << "Masukkan nilai: ";
        cin >> nilai;

        if (nilai == -1) {
            break;
        }

        root = insert(root, nilai);
    }

    if (root == nullptr) {
        cout << "\nBST masih kosong!\n";
        return 0;
    }

    cout << "\nMasukkan batas bawah: ";
    cin >> bawah;

    cout << "Masukkan batas atas: ";
    cin >> atas;

    cout << "\nNilai BST dalam rentang "
         << bawah << " sampai " << atas << ":\n";

    if (bawah > atas) {
        cout << "Batas bawah tidak boleh lebih besar dari batas atas.\n";
    } else {
        tampilRentang(root, bawah, atas);
        cout << endl;
    }

    cout << "\nMasukkan nilai yang ingin dicari: ";
    cin >> cari;

    if (search(root, cari)) {
        cout << "Nilai " << cari << " ditemukan dalam BST.\n";
    } else {
        cout << "Nilai " << cari << " tidak ditemukan dalam BST.\n";
    }

    hapusBST(root);

    return 0;
}
