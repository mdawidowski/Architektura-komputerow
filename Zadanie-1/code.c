// Program zamieniający liczby dziesiętne podane w pliku na U2
// Autor: Marcin Dawidowski
#include <stdio.h>
#include <stdlib.h>
int tou2(int decimal){
  int number;
  int i=1 ,j = 1, binary[32];
  number = decimal;
//wypełnianie tabeli zerami
  while (i != 32) {
    i += 1;
    binary[i] = 0;
  }
//sprawdzanie czy liczba jest dodatnia, czy ujemna
  while(number!=0){
    if(number<0){       //jeśli liczba jest mniejsza od 0 to zapisuje binarnie, neguje i dodaje do tego 1
      number *= -1;
      binary[i++] = number % 2;
      number = number / 2;
      for (i = 1; i <= 32; i++){       // negacja zapisu binarnego
        if (binary[i] = 1){
          binary[i] = 0;
        }
        else binary[i] = 1;

      }
      while(binary[j] != 0){          //dodanie do tablicy liczby 1 dopóki napotyka na 1 to przechodzi dalej, jeśli w tablicy będzie 0 to wychodzi z pętli i dodaje to tego elementu 1
        binary[j] = 0;
        j += 1;
      }
        binary[j] = 1;
    }
    else {                            // obliczanie kodu u2 dla liczby dodatniej
      binary[i++] = number % 2;
      number = number / 2;
    }

}
  // wypisywanie wyniku
    printf("Liczba %d w U2: ",decimal);
    for(j = 32 ;j > 0;j--){
      printf("%d",binary[j]);
  }

}
int main(){
   int decimal;
   FILE *plik = fopen("liczby.txt","r");
   if (plik == NULL){
       printf("Brak pliku liczby.txt");
   }
   while (fscanf(plik, "%d", &decimal) != EOF){
    if (decimal < -2147483648 || decimal > 2147483647){
      printf("Liczba przekracza zakres \n");
    }
    else{
      tou2(decimal);
      printf("\n");
    return 0;
  }
   }
   fclose(plik);
 }
