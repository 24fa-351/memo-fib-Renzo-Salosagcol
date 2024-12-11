#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef unsigned long long int fib_type;

int can_add(fib_type a, fib_type b) {
    return a <= ULLONG_MAX - b;
}

fib_type recursiveFibWrapper (
   fib_type target_fib_index, 
   fib_type fib_series[], int max_index) {

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

fib_type iterativeFibWrapper (
   fib_type target_fib_index, 
   fib_type fib_series[], int max_index) {

   while (max_index != target_fib_index) {
      fib_series[max_index + 1] = 
      fib_series[max_index - 1] + fib_series[max_index];
      max_index++;
   }

   return fib_series[max_index - 1];
}

fib_type fib_r(
   fib_type target_fib_index, 
   fib_type fib_series[]) {

      if (fib_series[target_fib_index - 1] != 0 ||
         target_fib_index - 1 == 0 ||
         target_fib_index - 1 == 1) {
            return fib_series[target_fib_index - 1];
         }
      
      return recursiveFibWrapper(target_fib_index, fib_series, 1);
}

fib_type fib_i(
   fib_type target_fib_index, 
   fib_type fib_series[]) {

      if (fib_series[target_fib_index - 1] != 0 ||
         target_fib_index - 1 == 0 ||
         target_fib_index - 1 == 1) {
            return fib_series[target_fib_index - 1];
         }
      
      return iterativeFibWrapper(target_fib_index, fib_series, 1);
}

int main (int argc, char *argv[]) {
   if (argc != 3) {
      fprintf(stderr, "Usage: %s <number> <type>\n", argv[0]);
      return 1;
   }

   const fib_type INFORMATION_NUMBER = atoi(argv[1]);
   const char INFORMATION_TYPE = argv[2][0];

   fib_type fib_series[INFORMATION_NUMBER + 1];
   for (fib_type index = 0; index < INFORMATION_NUMBER + 1; index++) {
      fib_series[index] = 0;
   }
   fib_series[1] = 1;
   fib_type result = 0;

   if (INFORMATION_TYPE == 'r') {
      result = fib_r(INFORMATION_NUMBER, fib_series);
   }
   else if (INFORMATION_TYPE == 'i') {
      result = fib_i(INFORMATION_NUMBER, fib_series);
   }

   printf("%llu\n", result);
   
   return 0;
}