#include <stdio.h>
#include <stdlib.h>

/*
  Soal Case 2:

  Buatlah queue yang memiliki isi elemen berupa data konsumen,
  lalu buat program utamanya beserta prosedur dan fungsi yang dibutuhkan,
  buat simulasi Ketika ada konsumen yang masuk antrian dan ada konsumen yang keluar antrian.

  How to play:
  $ gcc -o printer exam.c && ./printer && rm ./printer
*/

#define MAX_SIZE 100

struct Motor {
  int level_perbaikan;
  char nama[20];
  char merk[20];
};

struct PriorityQueue {
  struct Motor data[MAX_SIZE];
  int size;
};

void swap(struct Motor *a, struct Motor *b) {
  struct Motor temp = *a;
  *a = *b;
  *b = temp;
}

void insert(struct PriorityQueue *pq, struct Motor motor) {
  // Step 1: [Add the new value and set its POS]
  //      SET N = N + 1, POS = N
  // Step 2: SET HEAP[N] = VAL
  // Step 3: [Find appropriate location of VAL]
  //            Repeat Steps 4 and 5 while POS > 1
  // Step 4: SET PAR = POS/2
  // Step 5:IF HEAP[POS] <= HEAP[PAR],
  //        then Goto Step 6.
  //        ELSE
  //           SWAP HEAP[POS], HEAP[PAR]
  //           POS = PAR
  //        [END OF IF]
  //           [END OF LOOP]
  // Step 6: RETURN

  if (pq->size == MAX_SIZE) {
    printf("queue is full\n");
    return;
  }

  // STEP 1:
  int n = pq->size;
  int position = n;

  // STEP 2:
  pq->data[n] = motor;
  pq->size++;

  // HEAPIFY
  while (position > 0) {
    int parent_index = position / 2;
    // printf("merk %s: parent_index=%i, position=%i, n=%i\n", motor.merk, parent_index, position, n); // Suzuki: 1, 2, 2
    // printf("level_perbaikan[pos]%i, level_perbaikan[parent]%i\n", pq->data[position].level_perbaikan, pq->data[parent_index].level_perbaikan); // 4, 2

    if (pq->data[position].level_perbaikan < pq->data[parent_index].level_perbaikan) {
      swap(&pq->data[position], &pq->data[parent_index]);
      position = parent_index;
    } else {
      return;
    }
  }
}

void deleteLastNode(struct PriorityQueue *pq) {
  // Step 1: [Remove the last node from the heap] SET LAST = HEAP[N], SET N = N - 1
  // Step 2: [Initialization]
  //        SET PTR = 1, LEFT = 2, RIGHT = 3
  // Step 3: SET HEAP[PTR] = LAST
  // Step 4: Repeat Steps 5 to 7 while LEFT <= n
  // Step 5: IF HEAP[PTR] >= HEAP[LEFT] AND
  //         HEAP[PTR] >= HEAP[RIGHT]
  //             Go to Step 8
  // [END OF IF]
  // Step 6: IF HEAP[RIGHT] <= HEAP[LEFT]
  //             SWAP HEAP[PTR], HEAP[LEFT]
  //             SET PTR = LEFT
  //         ELSE
  //             SWAP HEAP[PTR], HEAP[RIGHT]
  //             SET PTR = RIGHT
  //         [END OF IF]
  // Step 7: SET LEFT = 2 * PTR and RIGHT = LEFT + 1 [END OF LOOP]
  // Step 8: RETURN
  if (pq->size == 0) {
    printf("queue is empty\n");
    return;
  }

  // STEP 1
  int n = pq->size -1;
  struct Motor lastNode = pq->data[n];
  struct Motor null_motor = { .level_perbaikan = 99999, .nama = "Null", .merk = "Null" };
  pq->data[n] = null_motor;
  return;

  // free(&pq->data[n]);
  // printf("merk %s %i\n", pq->data[n].merk, n); // Suzuki: 1, 2, 2
  n--;

  // STEP 2
  int ptr = 0;
  int left = 1;
  int right = 2;

  // STEP 3
  pq->data[ptr] = pq->data[n];
  pq->size--;

  // STEP 4
  while (left > n) {
    // Step 5: IF HEAP[PTR] >= HEAP[LEFT] AND
    //  HEAP[PTR] >= HEAP[RIGHT]
    //      Go to Step 8
    if (pq->data[ptr].level_perbaikan < pq->data[left].level_perbaikan && pq->data[ptr].level_perbaikan < pq->data[right].level_perbaikan) {
      return;
    }

    // Step 6: IF HEAP[RIGHT] <= HEAP[LEFT]
    //           SWAP HEAP[PTR], HEAP[LEFT]
    //           SET PTR = LEFT
    //       ELSE
    //           SWAP HEAP[PTR], HEAP[RIGHT]
    //           SET PTR = RIGHT
    //       [END OF IF]
    if (pq->data[right].level_perbaikan > pq->data[left].level_perbaikan) {
      swap(&pq->data[ptr], &pq->data[left]);
      ptr = left;
    } else {
      swap(&pq->data[ptr], &pq->data[right]);
      ptr = right;
    }
  }
}

void display_top_priority(struct PriorityQueue *pq) {
  // printf("okeoke: %i\n", pq->size);
  if (pq->size == 0) {
    printf("Queue is empty!\n");
    return;
  }

  printf("----------------- LIST --------------\n");
  for (int i = 0; i < pq->size; i++) {
    printf("Skala level_perbaikan: %d\n", pq->data[i].level_perbaikan);
    printf("Nama pemilik: %s\n", pq->data[i].nama);
    printf("Merk motor: %s\n", pq->data[i].merk);
    printf("------------------\n");
  }
}

int main() {
  struct PriorityQueue pq = { .size = 0 };

  struct Motor motor1 = { .level_perbaikan = 2, .nama = "John", .merk = "Honda" };
  struct Motor motor2 = { .level_perbaikan = 1, .nama = "Jane", .merk = "Yamaha" };
  struct Motor motor3 = { .level_perbaikan = 4, .nama = "Bob", .merk = "Suzuki" };
  struct Motor motor4 = { .level_perbaikan = 5, .nama = "Alice", .merk = "Kawasaki" };
  struct Motor motor5 = { .level_perbaikan = 3, .nama = "Eve", .merk = "Benelli" };

  insert(&pq, motor1);
  insert(&pq, motor2);
  insert(&pq, motor3);
  insert(&pq, motor4);
  insert(&pq, motor5);

  display_top_priority(&pq);

  deleteLastNode(&pq);
  display_top_priority(&pq);

  deleteLastNode(&pq);
  display_top_priority(&pq);
}
