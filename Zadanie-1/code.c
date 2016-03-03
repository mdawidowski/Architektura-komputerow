#include <stdio.h>
#include <stdlib.h>
int lessthan0(decimal){  //obliczanie kodu dla liczby ujemnej
  int number, i = 1, j = 32, a = 32;
  int binary[32];
  //wypelnianie tablicy zerami
  while (i != 32) {
    binary[i] = 0;
    i += 1;
  }
 //jeśli liczba jest mniejsza od 0 to zapisuje binarnie, neguje i dodaje do tego 1
    decimal *= -1;
    i = 1;
    while(decimal != 0){
      binary[i++] = decimal % 2;
      decimal = decimal / 2;
    }
    // negacja zapisu binarnego
    i = 1;
    for (i = 1; i <= 32; i++){
      if (binary[i] = 1){
        binary[i] = 0;
      }
      else binary[i] = 1;
    }
    //dodanie do tablicy liczby 1, dopóki napotyka na 1 zamienia na je 0 i przechodzi dalej, jeśli w tablicy będzie 0 to wychodzi z pętli i dodaje to tego elementu 1
    while(j > 1){
      if(binary[j] == 1){
        binary[j] = 0;
      }
      else{
        binary[j] = 1;
      }
      j -= 1;
    }
    // wypisywanie wyniku
    printf("Liczba %d w U2: ",decimal);
    for(a = 32 ;a > 0;a--){
      printf("%d",binary[a]);
    }
  }


  int morethan0(decimal){
    int number, i = 1, a = 32;
    int binary[32];
    //wypelnianie tablicy zerami
    while (i != 32) {
      binary[i] = 0;
      i += 1;
    }
    // obliczanie kodu u2 dla liczby dodatniej i dla 0
    i = 1;
    while(decimal != 0){
      binary[i++] = decimal % 2;
      decimal = decimal / 2;
    }
    // wypisywanie wyniku
    printf("Liczba %d w U2: ",decimal);
      for(a = 32 ;a > 0;a--){
        printf("%d",binary[a]);
    }
  }

int main(){
  int decimal;
  FILE *plik = fopen("liczby.txt","r");
  if (plik == NULL){
      printf("Brak pliku liczby.txt");
  }
  while (fscanf(plik, "%d", &decimal) != EOF){
    if (decimal<0) {
      morethan0(decimal);
    }
    else if(decimal>=0){
      lessthan0(decimal);
    }
  }
  return 0;
}
