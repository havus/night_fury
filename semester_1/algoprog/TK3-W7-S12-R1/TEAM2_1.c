#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *assignHoroscope(char fullDate[]) { // date format DD-MM-YYYY
  char *strDate = malloc(2);
  strDate[0]    = fullDate[0];
  strDate[1]    = fullDate[1];

  char *strMonth  = malloc(2);
  strMonth[0]     = fullDate[3];
  strMonth[1]     = fullDate[4];

  int date  = atoi(strDate);
  int month = atoi(strMonth);

  switch (month) {
  // Aries	    21 Maret      – 19 April 
  // Taurus	    20 April      – 20 Mei
  // Gemini	    21 Mei        – 20 Juni 
  // Cancer	    21 Juni       – 22 Juli
  // Leo	      23 juli       – 22 Agustus
  // Virgo	    23 Agustus    – 22 September
  // Libra	    23 September  – 22 Oktober
  // Scorpio	  23 Oktober    – 21 November
  // Sagitarius	22 November   – 21 Desember
  // Capricorn  22 Desember   - 19 januari
  // Aquarius	  20 januari    – 18 Februari
  // Pisces	    19 Februari   – 20 Maret
  case 1: {
    if (date >= 20) {
      return "Aquarius";
    } else {
      return "Capricorn";
    }
  }
  case 2: {
    if (date >= 19) {
      return "Pisces";
    } else {
      return "Aquarius";
    }
  }
  case 3: {
    if (date >= 21) {
      return "Aries";
    } else {
      return "Pisces";
    }
  }
  case 4: {
    if (date >= 20) {
      return "Taurus";
    } else {
      return "Aries";
    }
  }
  case 5: {
    if (date >= 21) {
      return "Gemini";
    } else {
      return "Taurus";
    }
  }
  case 6: {
    if (date >= 21) {
      return "Cancer";
    } else {
      return "Gemini";
    }
  }
  case 7: {
    if (date >= 23) {
      return "Leo";
    } else {
      return "Cancer";
    }
  }
  case 8: {
    if (date >= 23) {
      return "Virgo";
    } else {
      return "Leo";
    }
  }
  case 9: {
    if (date >= 23) {
      return "Libra";
    } else {
      return "Virgo";
    }
  }
  case 10: {
    if (date >= 23) {
      return "Scorpio";
    } else {
      return "Libra";
    }
  }
  case 11: {
    if (date >= 22) {
      return "Sagitarius";
    } else {
      return "Scorpio";
    }
  }
  case 12: {
    if (date >= 22) {
      return "Capricorn";
    } else {
      return "Sagitarius";
    }
  }
  }

  return "undefined";
}

int main() {
  char name[256];
  char date[11];
  char horoscope[20];

  printf("Masukkan Nama: ");                        scanf("%s", name);
  printf("Masukkan Tanggal Lahir (DD-MM-YYYY): ");  scanf("%s", date);

  strcpy(horoscope, assignHoroscope(date));

  printf("Nama: %s\n", name);
  printf("Bintang: %s\n", horoscope);
  printf("Tanggal Lahir: %s\n", date);

  return 0;
}
