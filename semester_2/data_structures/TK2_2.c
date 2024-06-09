#include <stdio.h>

/*
  Soal Case 2:

  Buatlah queue yang memiliki isi elemen berupa data konsumen,
  lalu buat program utamanya beserta prosedur dan fungsi yang dibutuhkan,
  buat simulasi Ketika ada konsumen yang masuk antrian dan ada konsumen yang keluar antrian.

  How to play:
  $ gcc -o printer TK2_2.c && ./printer && rm ./printer
*/


struct Customer { // structure data type
  char name[32];
};

struct Queue { // structure data type
  int front, rear;
  struct Customer data;
};

struct Customer queue[20];

int main() {
  struct Queue queue;

  printf("Hello\n");
}
