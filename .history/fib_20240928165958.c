#include <stdio.h>
#include <stdlib.h>

unsigned long long int recursiveFibWrapper (
   unsigned long long int target_fib_index, 
   unsigned long long int fib_series[], int max_index) {

   if (max_index == target_fib_index) {
      return fib_series[max_index - 1];
   } else {
      fib_series[max_index + 1] = 
      fib_series[max_index] + fib_series[max_index - 1];
      return recursiveFibWrapper(
         target_fib_index, 
         fib_series, 
         max_index + 1);
   }

   return 0;
}

unsigned long long int iterativeFibWrapper (
   unsigned long long int target_fib_index, 
   unsigned long long int fib_series[], int max_index) {

   while (max_index != target_fib_index) {
      fib_series[max_index + 1] = 
      fib_series[max_index - 1] + fib_series[max_index];
      max_index++;
   }

   return fib_series[max_index - 1];
}

unsigned long long int fib_r(
   unsigned long long int target_fib_index, 
   unsigned long long int fib_series[]) {

      if (fib_series[target_fib_index - 1] != 0 ||
         target_fib_index - 1 == 0 ||
         target_fib_index - 1 == 1) {
            return fib_series[target_fib_index - 1];
         }
      
      return recursiveFibWrapper(target_fib_index, fib_series, 1);
}

unsigned long long int fib_i(
   unsigned long long int target_fib_index, 
   unsigned long long int fib_series[]) {

      if (fib_series[target_fib_index - 1] != 0 ||
         target_fib_index - 1 == 0 ||
         target_fib_index - 1 == 1) {
            return fib_series[target_fib_index - 1];
         }
      
      return iterativeFibWrapper(target_fib_index, fib_series, 1);
}

int main (int argc, char *argv[]) {

   const unsigned long long int INFORMATION_NUMBER = atoi(argv[1]);
   const char INFORMATION_TYPE = argv[2][0];
   const char *FILE_NAME = argv[3];

   FILE *file_pointer = fopen(FILE_NAME, "r");
   char file_text[256];
   fgets(file_text, sizeof(file_text), file_pointer);
   const int FILE_NUMBER = atoi(file_text);

   const unsigned long long int TARGET_FIB_INDEX = INFORMATION_NUMBER + FILE_NUMBER;

   unsigned long long int fib_series[TARGET_FIB_INDEX + 1];
   for (unsigned long long int index = 0; index < TARGET_FIB_INDEX + 1; index++) {
      fib_series[index] = 0;
   }
   fib_series[1] = 1;
   unsigned long long int result = 0;

   if (INFORMATION_TYPE == 'r') {
      result = fib_r(TARGET_FIB_INDEX, fib_series);
   }
   else if (INFORMATION_TYPE == 'i') {
      result = fib_i(TARGET_FIB_INDEX, fib_series);
   }

   printf("%llu\n", result);
   
   fclose(file_pointer);
   return 0;
}