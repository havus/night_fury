#include <stdio.h>
#include <time.h>

void learn_goto() {
  printf("It's time to learn goto!\n");

  // goto exit;
  goto edge_case;
  printf("this is will not run\n");

edge_case:
  printf("this is edge case, avoid using goto to improve code readability\n");

exit:
  printf("exit!\n");
}

// Compile-Time Error
//   caused by syntax error
// Link-Time Error
//   success fully compiled, but cause link error
//   caused by no object code at link time
// Run-Time Error
//   successfully compiled, but error at runtime. Usually caused by numerical operation
//   such as: overflow, floating point underflow, division by zero, etc.
// Logical Error
//   wrong result caused by incorrect logical flow/algorithm

// struct tm {
//   int tm_sec;   /* seconds,  range 0 to 59          */
//   int tm_min;   /* minutes, range 0 to 59           */
//   int tm_hour;  /* hours, range 0 to 23             */
//   int tm_mday;  /* day of the month, range 1 to 31  */
//   int tm_mon;   /* month, range 0 to 11             */
//   int tm_year;  /* The number of years since 1900   */
//   int tm_wday;  /* day of the week, range 0 to 6    */
//   int tm_yday;  /* day in the year, range 0 to 365  */
//   int tm_isdst; /* daylight saving time             */	
// };

void learnTime() {
  time_t epochTime;
  time(&epochTime);

  printf("Epoch time: %ld\n", epochTime);

  // struct tm *localtime(const time_t *timer)
  struct tm *info;
  info = localtime(&epochTime);
  printf("now: %d/%.2d/%d ", info->tm_year + 1900, info->tm_mon + 1, info->tm_mday);
  printf("%d:%d:%.2d\n", info->tm_hour, info->tm_min + 1, info->tm_sec);

  printf("Current local time and date: %s", asctime(info));
}


// gcc -o printer semester_1/algoprog/learn_additional_1.c && ./printer && rm ./printer
int main() {
  // learn_goto();
  learnTime();

  return 0;
}
