#include <stdio.h>

int soalNomor1() {
	int input1, input2;

	printf("Input 1: ");
	scanf("%d", &input1);

	printf("Input 2: ");
	scanf("%d", &input2);

	if (input1 % 2 != 1) {
		printf("validasi: input 1 harus ganjil\n");
		return 1;
	}

	if (input2 % 2 != 0) {
		printf("validasi: input 2 harus genap\n");
		return 1;
	}

	int sumValue      = input1 + input2;
	double meanValue	= (input1 + input2) / 2;
	int squareValue1  = input1 * input1;
	int squareValue2  = input2 * input2;

	// jumlah, rata-rata, dan kuadrat dari kedua bilangan yang dimasukkan. 
	printf("Jumlah %d \n", sumValue);
	printf("Rata-rata %lf \n", meanValue);
	printf("Kuadrat dari %d adalah %d \n", input1, squareValue1);
	printf("Kuadrat dari %d adalah %d \n", input2, squareValue2);

	return 0;
}

int main() {
	int loopAgain = 1;

	while (loopAgain) {
		loopAgain = soalNomor1();
	}

	return 0;
}