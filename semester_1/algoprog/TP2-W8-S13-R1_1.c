#include <stdio.h>
#include <string.h>

void printHelp() {
  printf("Menu 1 untuk Input data mahasiswa.\n");
  printf("Menu 2 untuk Input nilai.\n");
  printf("Menu 3 untuk melihat nilai mahasiswa dan status\n");
  printf("Menu 4 keluar dari program\n\n");
}

typedef struct Student {
  // ----- score.start -----
  int     attendanceScore;
  int     taskScore;
  int     quizScore;
  int     activenessScore;
  int     examScore;
  double  overallScore; // Nilai Hadir 10% +Nilai Tugas 20% + Nilai Quiz 10% + Nilai keaktifan forum 10% dan Nilai UAS 50%.
  // ----- score.end -----

  // ----- indentity.start -----
  char nim[30];
  char name[20];
  char learningSubject[20];
  // ----- indentity.end -----
} Mahasiswa;

Mahasiswa createNewStudent(Mahasiswa database[], int totalStudent) {
  Mahasiswa newStudent;

  int isValidNim; // flaging

  do {
    isValidNim = 1; // default true

    printf("Masukkan NIM: "); scanf("%s", newStudent.nim);


    // NIM validation
    for (int i = 0; i < totalStudent; i++) {
      printf("debug: %s, %s\n", database[i].nim, newStudent.nim);

      if (strcmp(database[i].nim, newStudent.nim) == 0) { // strcmp, same will return 0, NOT same will return -49
        printf("nim already used, please retry again!\n");

        isValidNim = 0;
        break; // break the for loop
      }
    }
  } while (!isValidNim);

  printf("Masukkan Nama: ");        scanf("%s", newStudent.name);
  printf("Masukkan Mata Kuliah: "); scanf("%s", newStudent.learningSubject);

  return newStudent;
}

int main() {
  printHelp();

  Mahasiswa database[100];

  int currentIdxStudent = 0;
  int continueLoop      = 1;
  int selectedOption;

  do {
    printf("Masukkan input anda: "); scanf("%d", &selectedOption);

    switch (selectedOption) {
    case 1: {
      database[currentIdxStudent] = createNewStudent(database, currentIdxStudent +1);
      printf("debug: currentIdxStudent = %d\n", currentIdxStudent);
      currentIdxStudent++;

      break;
    }
    case 4:
      continueLoop = 0;
      break;
    }
  } while (continueLoop);

  return 0;
}