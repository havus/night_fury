#include <stdio.h>
#include <string.h>

// -------------------------------------------------------
// | mode | description
// -------------------------------------------------------
// | r    | opening a file to be read
// | w    | creating a file to be written
// | a    | opening a file for data append
// | r+   | opening a file for read/write
// | w+   | creating a file for read/write
// | a+   | opening a file for read/append
// | rb   | opening a file (binary) to be read
// | wb   | creating a file (binary) for write operation
// -------------------------------------------------------

// fgetc
// fgets
// fputc
// fputs
// fscanf
// fprintf
// fopen
// fwrite
// fread
// feof

void example1() {
  char ch;
  FILE *myfile = fopen("semester_1/algoprog/sample_read.txt", "r");

  if (myfile == NULL) {
    printf("file does NOT exist!\n");
    return;
  }

  while(!feof(myfile)) {
    ch = fgetc(myfile);
    printf("%c", ch);
  }

  printf("\n");

  fclose(myfile);
}

void example2() {
  char sentence[] = "this text will be saved in sample_write.txt using fputc :)";
  // FILE *myfile = fopen("semester_1/algoprog/sample_write.txt", "w");
  FILE *myfile = fopen("semester_1/algoprog/sample_write.txt", "a");

  if (myfile == NULL) {
    // will create file automatically!
  }

  // for new line
  fputc('\n', myfile);

  for (int i = 0; i < strlen(sentence); i++) {
    fputc(sentence[i], myfile);
  }

  fclose(myfile);
}

void example3() {
  FILE *myfile = fopen("semester_1/algoprog/sample_read.txt", "r");
  char sentence[3] = "oke"; // should define the size, example in this case is 3

  if (myfile == NULL) {
    printf("file does NOT exist!\n");
    return;
  }

  while(fgets(sentence, 3, myfile)) {
    printf("%s\n", sentence);
  }

  fclose(myfile);
}

void example4() {
  FILE *myfile = fopen("semester_1/algoprog/sample_write.txt", "a");

  fputs("\nthis is new again", myfile);

  fclose(myfile);
}


int main() {
  // example1();
  // example2();
  // example3();
  example4();

  return 0;
}
