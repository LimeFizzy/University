#include <stdio.h>
#include <stdlib.h>
 
#define SIZE 10          // data size
#define FREQ_SIZE 1000   // upper bound for values
 
// input: 
//    user enters 10 non-negative integers
// output: 
//    report how many times each unique value occured,
//    display values and occurence times in ascending order
 
int main() {
   
   int inputArray[SIZE] = { 0 };
   int frequency[FREQ_SIZE] = { 0 };
   int diffNums[SIZE] = { 0 };
   int num, counter = 0;
 
   // report what the program does
   printf("Programa nuskaito 10 vartotojo ivestu skaiciu, skaiciuoja kiek kartu kiekvienas is ju pasikartojo ir isveda skaiciavimu rezultatus.\n\n");
   // ask to enter 10 numbers 
   printf("Iveskite seka is 10 nariu(-io). Reziai kiekvienam skaiciui: [0;999]\n\n");
 
   while(counter < SIZE){
      // ask to enter the following number
      printf("Iveskite %d-aji sekos elementa.\n", counter+1);
      if((scanf("%d", &num) == 1) && (getchar() == '\n')){
         if ((num >= 0) && (num < FREQ_SIZE)){
            inputArray[counter++] = num;
            // report that number entered successfully
            printf("Skaicius atitinka rezius ir yra sekmingai irasytas.\n");
         } else {
            // report that value exceeds bounds and has to belong to [0; FREQ-SIZE]
            printf("Netinkama ivestis! Skaicius virsyja masyvo rezius [0;999].\n");
         }
      } else {
         // report invalid input, ask to enter whole non-negative number again
         printf("Netinkama ivestis! Iveskite sveika, neneigiama skaiciu, atitinkanti rezius [0;999]!\n");
         while(getchar() != '\n')
            ;
      }
   }
   
   // report that data has been entered correctly
   printf("Visi skaiciai buvo ivesti sekmingai!\n\n");
   // proceeding to computations...
   
   for(int i=0; i<SIZE; i++){
        frequency[ inputArray[i] ]++;
   }
 
   int flag;
   int diffNumsCounter = 0;
 
   for(int i=0; i<SIZE; i++){
      flag=1;
      for(int j=0; j<i; j++){
         if(inputArray[i] == inputArray[j]){
            flag=0;
         }        
      }       
      if(flag){
         diffNums[diffNumsCounter] = inputArray[i];
         diffNumsCounter++;
      }
   }
 
   int temp;
 
   for(int j=0; j<diffNumsCounter-1; j++){
      for(int i=0; i<diffNumsCounter-j-1; i++){
         if(diffNums[i] > diffNums[i+1]){
            temp = diffNums[i];
            diffNums[i] = diffNums[i+1];
            diffNums[i+1] = temp;
         }
      }
   }
 
   // report that results will be reported
   printf("Skaiciavimu rezultatai:\n");
   printf("Skaicius          Pasikartojimu daznis\n");
   for(int i=0; i<diffNumsCounter; i++){
      if( frequency[ diffNums[i] ] != 0 ){
         // report the value of diffNums[i] and the value of frequency[diffNums[i]]
         printf("%8d...........................%3d\n", diffNums[i], frequency[diffNums[i]]);
      }
   }
 
   return 0;
}