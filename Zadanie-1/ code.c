// Program zamieniający liczby dziesiętne podane w pliku na U2
// Autor: Marcin Dawidowski
#include <stdio.h>
#include <stdlib.h>
int tou2(long long int decimal){
  long long int number;
  int i=1 ,j, binary[32];
  number = decimal;
//wypełnianie tabeli zerami
  while (i != 32) {
    i += 1;
    binary[i] = 0;
  }
//sprawdzanie czy liczba jest dodatnia, czy ujemna
  while(number!=0){
    if(number<0){
      binary[32] = 1;
    }
    else binary[32] = 0;
    binary[i++] = number % 2;
    number = number / 2;

    }
    printf("Liczba %lld w U2: ",decimal);
    for(j = 32 ;j > 0;j--){
      printf("%d",binary[j]);
  }

}
int main(){
   long long int decimal;
   FILE *plik = fopen("liczby.txt","r");
   if (plik == NULL){
       printf("Brak pliku liczby.txt");
   }
   while (fscanf(plik, "%lld", &decimal) != EOF){
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
