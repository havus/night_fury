#include <stdio.h>  //tugas kelompok ke-1
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[50];
    int quantity;
    struct node* next;
    struct node* prev;
} Node;

Node* head = NULL;
Node* tail = NULL;

void addNode(char* name, int quantity) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->next = NULL;
    newNode->prev = tail;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

Node* findNode(char* name) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deleteNode(char* name) {
    Node* current = findNode(name);
    if (current == NULL) {
        printf("Barang tidak ditemukan.\n");
        return;
    }

    if (current == head) {
        head = current->next;
    }
    if (current == tail) {
        tail = current->prev;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
}

void updateQuantity(char* name, int delta) {
    Node* current = findNode(name);
    if (current == NULL) {
        printf("Barang tidak ditemukan.\n");
        return;
    }

    current->quantity += delta;

    if (current->quantity < 1) {
        deleteNode(name);
        printf("Barang %s telah habis.\n", name);
    } else if (current->quantity < 5) {
        printf("Peringatan: barang %s hampir habis.\n", name);
    }
}

void displayInventory() {
    Node* current = head;
    printf("%-20s %-10s\n", "Nama Barang", "Stok");
    while (current != NULL) {
        printf("%-20s %-10d\n", current->name, current->quantity);
        current = current->next;
    }
}

void displayTransactions() {
    // implementasi riwayat transaksi belum dibuat
    printf("Belum ada riwayat transaksi.\n");
}

int main() {
    int choice, quantity;
    char name[50];

    do {
        printf("\n== Toko Sembako Pak Andi ==\n");
        printf("1. Tambah Barang\n");
        printf("2. Hapus Barang\n");
        printf("3. Update Stok Barang\n");
        printf("4. Tampilkan Stok Barang\n");
        printf("5. Riwayat Transaksi\n");
        printf("0. Keluar\n");
        printf("============================\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
            switch (choice) {
        case 1:
            printf("Nama barang: ");
            scanf("%s", name);
            printf("Jumlah stok: ");
            scanf("%d", &quantity);
            addNode(name, quantity);
            printf("Barang %s telah ditambahkan.\n", name);
            break;
        case 2:
            printf("Nama barang: ");
            scanf("%s", name);
            deleteNode(name);
            break;
        case 3:
            printf("Nama barang: ");
            scanf("%s", name);
            printf("Jumlah perubahan ('+' untuk penambahan, '-' untuk pengurangan): ");
            scanf("%d", &quantity);
            updateQuantity(name, quantity);
            break;
        case 4:
            displayInventory();
            break;
        case 5:
            displayTransactions();
            break;
        case 0:
            printf("Terima kasih telah menggunakan program ini.\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
    }
} while (choice != 0);

return 0;}

