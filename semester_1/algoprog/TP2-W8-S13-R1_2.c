#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

// ------- GLOBAL VARIABLE - start -------
int STUDENT_COUNT = 0;
Mahasiswa DATABASE[100];
// ------- GLOBAL VARIABLE - end -------


/* ---------------------------------------------------------------------------------------------- */
/* ------------------------------------ made with love ------------------------------------------ */
/* ---------------------------------------------------------------------------------------------- */

void printHelp() {
  printf("\n");
  printf("---------------------- GUIDE ----------------------\n");
  printf("Menu 1 untuk Input data mahasiswa.\n");
  printf("Menu 2 untuk Input nilai.\n");
  printf("Menu 3 untuk melihat nilai mahasiswa dan status\n");
  printf("Menu 4 keluar dari program\n");
  printf("Menu 5 clear\n");
  printf("---------------------------------------------------\n");
  printf("\n");
}

int findByNim(char nim[]) {
  Mahasiswa blankStudent;
  blankStudent.nim[0] = '\0'; // blank identifier

  for (int i = 0; i < STUDENT_COUNT; i++) {
    if (strcmp(DATABASE[i].nim, nim) == 0) { // strcmp, when 'same' will return 0, 'NOT same' will return -49
      return i;
    }
  }

  return -1;
}

Mahasiswa createNewStudent() {
  Mahasiswa newStudent;

  int isNimExist; // flaging

  do {
    isNimExist = 0; // default false

    printf("Masukkan NIM: "); scanf("%s", newStudent.nim);

    // -------------- NIM validation - start --------------
    int indexStudent = findByNim(newStudent.nim);

    if (indexStudent >= 0) {
      printf("nim already used, please retry again!\n");
      isNimExist = 1;
    }
    // -------------- NIM validation - end --------------
  } while (isNimExist);

  printf("Masukkan Nama: ");        scanf("%s", newStudent.name);
  printf("Masukkan Mata Kuliah: "); scanf("%s", newStudent.learningSubject);

  return newStudent;
}

void inputScore() {
  char nimTarget[30];

  printf("Masukkan NIM: "); scanf("%s", nimTarget);

  int indexStudent = findByNim(nimTarget);

  if (indexStudent < 0) {
    printf("NIM tidak ditemukan\n");
    return;
  }

  printf("Masukkan Nilai Hadir: ");           scanf("%d", &DATABASE[indexStudent].attendanceScore);
  printf("Masukkan Nilai Tugas: ");           scanf("%d", &DATABASE[indexStudent].taskScore);
  printf("Masukkan Nilai Quiz: ");            scanf("%d", &DATABASE[indexStudent].quizScore);
  printf("Masukkan Nilai Keaktifan Forum: "); scanf("%d", &DATABASE[indexStudent].activenessScore);
  printf("Masukkan Nilai UAS: ");             scanf("%d", &DATABASE[indexStudent].examScore);

  DATABASE[indexStudent].overallScore = (
    (DATABASE[indexStudent].attendanceScore * 0.1) +
    (DATABASE[indexStudent].taskScore       * 0.2) +
    (DATABASE[indexStudent].quizScore       * 0.1) +
    (DATABASE[indexStudent].activenessScore * 0.1) +
    (DATABASE[indexStudent].examScore       * 0.5)
  );
}

void showGradeStatus() {
  char nimTarget[30];

  printf("Masukkan NIM: "); scanf("%s", nimTarget);

  int indexStudent = findByNim(nimTarget);

  if (indexStudent < 0) {
    printf("NIM tidak ditemukan\n");
    return;
  }

  char    grade;
  double  overallScore = DATABASE[indexStudent].overallScore;

  if (overallScore >= 90) { // A
    grade = 'A';
  } else if (overallScore >= 80 && overallScore < 90) {
    grade = 'B';
  } else if (overallScore >= 70 && overallScore < 80) {
    grade = 'C';
  } else if (overallScore >= 60 && overallScore < 70) {
    grade = 'D';
  } else if (overallScore < 60) {
    grade = 'E';
  }

  printf("Status grade = %c (%s)\n",        grade, grade == 'E' ? "Tidak Lulus" : "Lulus");
  printf("dengan nilai rata-rata = %.2f\n", overallScore);
}

int main() {
  int continueLoop = 1;
  int selectedOption;

  do {
    printHelp();
    printf("Masukkan input anda: "); scanf("%d", &selectedOption);

    switch (selectedOption) {
    case 1: {
      DATABASE[STUDENT_COUNT] = createNewStudent();
      STUDENT_COUNT++;

      // always give a feedback to user after a process
      printf("Jumlah mahasiswa = %d\n", STUDENT_COUNT);
      break;
    }
    case 2: {
      inputScore();
      break;
    }
    case 3: {
      showGradeStatus();
      break;
    }
    case 4: {
      continueLoop = 0;
      printf("Goodbye...\n");
      break;
    }
    case 5: {
      system("clear");
      break;
    }
    default: {
      printf("Invalid input\n");
      printHelp();
    }}

    selectedOption = 0;
  } while (continueLoop);

  return 0;
}

// @todo
// report bug;
//  when "Masukkan input anda: " -> if we input alphabet, infinite loop
