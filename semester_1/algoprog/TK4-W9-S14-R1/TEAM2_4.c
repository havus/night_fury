#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Order {
  char  name[50];         // Kopi, Teh, Coklat atau Soda.
  char  size[50];         // Small, Medium dan Largest.
  char  temperature[50];  // Dingin, panas atau hangat.
  int   price;
  // Harga = size x panjang karakter nama minuman x pjg karakter Penyajian x 100 
  // Nama Minuman:  Kopi    => 4
  // Size :         Small   => 5
  // Penyajian :    Dingin  => 6
  // Harga :        12000   => 4 x 5 x 6 x 100 = 12000
};

// ------- GLOBAL VARIABLE - start -------
int ORDER_COUNT = 0;
struct Order DATABASE[100];
// ------- GLOBAL VARIABLE - end -------


void printHelp() {
  printf("\n");
  printf("---------------------- GUIDE ----------------------\n");
  printf("1: Input data.\n");
  printf("2: View History.\n");
  printf("3: Delete History\n");
  printf("4: Exit\n");
  printf("---------------------------------------------------\n");
  printf("\n");
}

void inputOrder() {
  struct Order newOrder;

  int isValidInput = 0;

  // ---------------------------- input name - start ----------------------------
  do {
    isValidInput = 0; // default false

    printf("Nama Minuman (Kopi, Teh, Coklat atau Soda): "); scanf("%s", newOrder.name);

    char lowercaseInput[50];
    for (int i = 0; i <= strlen(newOrder.name); i++) {
      lowercaseInput[i] = tolower(newOrder.name[i]);
      if (i == strlen(newOrder.name)) {
        lowercaseInput[i] = '\0';
      }
    }

    char *validNames[4] = { "kopi", "teh", "coklat", "soda" };
    for (int i = 0; i < 4; i++) {
      if (strcmp(lowercaseInput, validNames[i]) == 0) {
        isValidInput = 1;
      }
      // debug: printf("%s - %s - %d\n", lowercaseInput, validNames[i], strcmp(lowercaseInput, validNames[i]));
    }
    if (!isValidInput) {
      printf("Invalid input, pilihan: Kopi, Teh, Coklat atau Soda\n");
    }
  } while (!isValidInput);
  // ---------------------------- input name - end ----------------------------

  // ---------------------------- input size - start ----------------------------
  do {
    isValidInput = 0; // default false

    printf("Size Minuman (Small, Medium dan Largest): "); scanf("%s", newOrder.size);

    char lowercaseInput[50];
    for (int i = 0; i <= strlen(newOrder.size); i++) {
      lowercaseInput[i] = tolower(newOrder.size[i]);
      if (i == strlen(newOrder.size)) {
        lowercaseInput[i] = '\0';
      }
    }

    char *validNames[3] = { "small", "medium", "largest" };
    for (int i = 0; i < 3; i++) {
      if (strcmp(lowercaseInput, validNames[i]) == 0) {
        isValidInput = 1;
      }
    }

    if (!isValidInput) {
      printf("Invalid input, pilihan: Small, Medium dan Largest\n");
    }
  } while (!isValidInput);
  // ---------------------------- input size - end ----------------------------

  // ---------------------------- input temperature - start ----------------------------
  do {
    isValidInput = 0; // default false

    printf("Penyajian Minuman (Dingin, panas atau hangat): "); scanf("%s", newOrder.temperature);

    char lowercaseInput[50];
    for (int i = 0; i <= strlen(newOrder.temperature); i++) {
      lowercaseInput[i] = tolower(newOrder.temperature[i]);
      if (i == strlen(newOrder.temperature)) {
        lowercaseInput[i] = '\0';
      }
    }

    char *validNames[3] = { "dingin", "panas", "hangat" };
    for (int i = 0; i < 3; i++) {
      if (strcmp(lowercaseInput, validNames[i]) == 0) {
        isValidInput = 1;
      }
    }

    if (!isValidInput) {
      printf("Invalid input, pilihan: Dingin, panas atau hangat\n");
    }
  } while (!isValidInput);
  // ---------------------------- input temperature - end ----------------------------

  newOrder.price = strlen(newOrder.name) * strlen(newOrder.size) * strlen(newOrder.temperature) * 100;

  // ---------------------------- confirm order - start ----------------------------
  printf("------------- Orderan -------------\n");
  printf("Nama Minuman: %s\n", newOrder.name);
  printf("Size:         %s\n", newOrder.size);
  printf("Penyajian:    %s\n", newOrder.temperature);
  printf("Harga:        %d\n", newOrder.price);

  char confirmed;
  getchar();
  printf("Konfirmasi orderan (Y/n): "); scanf("%c", &confirmed);
  // ---------------------------- confirm order - end ----------------------------

  if (confirmed == tolower('n')) {
    printf("Order cancelled!\n");
    return;
  }

  DATABASE[ORDER_COUNT] = newOrder;
  ORDER_COUNT++;
}

void deleteAndReorderDatabase(int indexTarget) {
  for (int i = 0; i < ORDER_COUNT; i++) {
    if (i >= indexTarget - 1) {
      // swipe current with next element
      DATABASE[i] = DATABASE[i + 1];
    }
  }

  ORDER_COUNT--;
}

void deleteOrder() {
  int indexWillBedeleted  = 0;
  int validIndex          = 0; // default false

  do {
    printf("Hapus data no: "); scanf("%d", &indexWillBedeleted);

    validIndex = (indexWillBedeleted > 0) && (indexWillBedeleted <= ORDER_COUNT);

    if (!validIndex) {
      printf("invalid data no %d - not found\n", indexWillBedeleted);
    }
  } while (!validIndex);

  deleteAndReorderDatabase(validIndex);

  printf("Data %d Successfully deleted..\n", indexWillBedeleted);
}

int main() {
  int continueLoop = 1;
  int selectedOption;

  do {
    printHelp();
    printf("Masukkan input anda: "); scanf("%d", &selectedOption);

    switch (selectedOption) {
    case 1: {
      inputOrder();
      // printf("order count: %d\n", ORDER_COUNT);
      break;
    }
    case 2: {
      for (int i = 0; i < ORDER_COUNT; i++) {
        // No, Nama pesanan, Size, Penyajian dan Harga.
        printf("%d, %s, %s, %s, %d\n", i+1, DATABASE[i].name, DATABASE[i].size, DATABASE[i].temperature, DATABASE[i].price);
      }
      break;
    }
    case 3: {
      deleteOrder();
      break;
    }
    case 4: {
      continueLoop = 0;
      printf("Saving file to dataminuman.txt...\n");

      FILE *result = fopen("dataminuman.txt", "w");
      for (int i = 0; i < ORDER_COUNT; i++) {
        char tempText[256];
        snprintf(
          tempText,
          sizeof(tempText),
          "%d,%s,%s,%s,%d\n",
          i+1, DATABASE[i].name, DATABASE[i].size, DATABASE[i].temperature, DATABASE[i].price
        );
        fputs(tempText, result);
      }
      fclose(result);

      printf("Goodbye...\n");
      break;
    }
    default: {
      continueLoop = 0;
      printf("Invalid input\n");
      printHelp();
      break;
    }}

    // set default selectedOption
    selectedOption = 0;
  } while (continueLoop);

  return 0;
}
