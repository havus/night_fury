#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


void sayHi(char name[], int age) {
  printf("Hi %s! you are %d \n", name, age);
}

double calc(char operator, double num1, double num2) {
  // printf("calculating...");

  switch(operator) {
  case '+':
    return num1 + num2;
  case '-':
    return num1 - num2;
  case ':':
    return num1 / num2;
  case '/':
    return num1 / num2;
  case 'x':
    return num1 * num2;
  case '*':
    return num1 * num2;
  }

  return 0;
}

void calculatorFunc() {
  char stillCalculateAnswer = 'y';
  double result;

  printf("Enter a number: ");
  scanf("%lf", &result);

  // store initial number to variable
  char question[256];
  snprintf(question, sizeof(question), "%g", result);

  while (stillCalculateAnswer == 'y') {
    char    operator;
    double  nextNum;

    printf("Enter operator: ");
    scanf("%s", &operator);

    printf("Enter a number: ");
    scanf("%lf", &nextNum);

    snprintf(question, sizeof(question), "%s %s", question, &operator);
    snprintf(question, sizeof(question), "%s %g", question, nextNum);

    result = calc(operator, result, nextNum);
    printf("question: %s \n", question);
    printf("result: %g \n", result);

    printf("continue? (Y/n) : ");
    getchar(); // to remove '\n' from end of -> scanf("%lf", &nextNum);

    stillCalculateAnswer = tolower(getchar());

    if (stillCalculateAnswer == '\n') {
      stillCalculateAnswer = 'y';
    }
  }
}

// char *returnStr() {
void returnStr() {
  char coba[] = "Hello";
  // printf("%s", coba);

  // return &(coba);
}

char* createStr() {
  char *str = malloc(30);
  strcpy(str, " test");
  strcat(str, " char");

  return str;
}

int testSwitch(char contohCh) {
  // printf("Output: %p", &(contohCh));

  switch (contohCh) { // switch(0x11111) {
    case 'a': // case: 0x123123
      printf("case a: %c", contohCh);
    default:
      printf("masuk default");
  }

  return 0;
}

void learnParamChar(char param0, char param1[], char *param2, const char *param3) {
  printf("param0 = %c\n", param0);
  printf("param1 = %s\n", param1);
  printf("param2 = %s\n", param2);
  printf("param3 = %s\n", param3);
}

int main() {
  // int luckyNumber[] = {2, 3, 4, 10, 13, 18, 78};
  // printf("%d \n", luckyNumber[0]);
  // returnStr();
  // char *returned_str = createStr();
  // printf("%s", createStr());
  // printf("%s", *returnStr());

  // sayHi("John", 24);
  // calculatorFunc();

  // char strEx[] = "hello"; // /x123123
  // testSwitch(strEx);

  // char ch = 'A';
  char sentence[] = "Hello world";
  // learnParamChar('A', sentence, sentence, sentence);
  learnParamChar('A', "Hello world", "hello wo", "Hello w");

  return 0;
}
