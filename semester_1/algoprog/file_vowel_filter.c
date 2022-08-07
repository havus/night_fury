#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*
1) Buatlah sebuah file teks dengan nama "sumber.txt". Isilah file tersebut dengan kalimat:
  Bina Nusantara
  Algorithm and Programming
2) Buatlah sebuah program sederhana untuk membaca file tersebut,
  lalu tampilkanlah hasilnya di layar dengan menghilangkan huruf vokalnya.
  Sehingga tampilannya sebagai berikut:
  Bn Nsntr
  lgrthm nd Prgrmmng

  $ gcc -o printer file_vowel_filter.c && ./printer && rm ./printer
*/

int main() {
  FILE *myfile = fopen("sumber.txt", "w");
  char sentence[] = "Bina Nusantara\nAlgorithm and Programming\n";
  char sentence2[] = "1\n";

  fputs(sentence, myfile);
  fclose(myfile);

  for (int i = 0; i < strlen(sentence); i++) {
    bool isVowelChar = (
      tolower(sentence[i]) == 'a' ||
      tolower(sentence[i]) == 'i' ||
      tolower(sentence[i]) == 'u' ||
      tolower(sentence[i]) == 'e' ||
      tolower(sentence[i]) == 'o'
    );

    if (!isVowelChar) {
      printf("%c", sentence[i]);
    }
  }

  printf("\n");

  return 0;
}
