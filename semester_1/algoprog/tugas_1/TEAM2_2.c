#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void printCombS (char sentence1[], char sentence2[]) {
	printf("Gabungan 2 buah inputan kalimat = %s %s \n", sentence1, sentence2);
}

char* combS(char kata1[], char kata2[], int useSpace) {
	char *combinedS = malloc(256);

	strcat(combinedS, kata1);

	if (useSpace) {
		strcat(combinedS, " ");   
	}
	strcat(combinedS, kata2);

	return combinedS;
}

void reverseS (char sentence1[], char sentence2[]) {
	char result[256];
	char *combinedS = combS(sentence1, sentence2, 1);

	// strcat(combinedS, sentence1);
	// strcat(combinedS, sentence2);
	// strcat(sentence1, sentence2); // CombinedS dipakai untuk reference/penampung (passby reference) //

	// indexing combinedS = sinubayas
	//                      012345678
	// printf("%ld", strlen(combinedS));
	for (int n = strlen(combinedS) - 1; n >= 0; n--) {
		// printf("%c", combinedS[n]);
		// printf("\n");
		strncat(result, &combinedS[n], 1);
	}
	printf("Hasil membalik kalimat gabungan = %s \n", result);
}

void countS (char addT[], char sentence[]) {
	int result = 0;

	printf("Jumlah Huruf kalimat %s = %ld \n", addT, strlen(sentence));
}

void main() {
	char sentence1[256], sentence2[256];
	printf("silahkan masukan kalimat pertama: ");
	scanf("%s", sentence1);
	printf("silahkan masukan kalimat kedua: ");
	scanf("%s", sentence2);

	printCombS(sentence1, sentence2);
	reverseS(sentence1, sentence2);
	countS("pertama", sentence1);
	countS("kedua", sentence2);

	char *gabunganKata = combS(sentence1, sentence2, 0);
	printf("Total Jumlah huruf = %ld \n", strlen(gabunganKata));

	int jumlahK1=strlen(sentence1);
	int jumlahK2=strlen(sentence2);
	printf("Total Perkalian kalimat = %d", jumlahK1 * jumlahK2);
}
