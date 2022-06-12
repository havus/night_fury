#include <stdio.h>
#include <ctype.h>
#include <string.h>


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

int main() {
  // int luckyNumber[] = {2, 3, 4, 10, 13, 18, 78};
  // printf("%d \n", luckyNumber[0]);

  sayHi("John", 24);
  calculatorFunc();

  return 0;
}
