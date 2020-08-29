//
//  LargeProdSeries.c
//  
//
//  Created by ramo17 on 8/19/20.
//

/*
 The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char *sieve;
  size_t i;
  unsigned count = 0;
  size_t n = 1000000;
  const unsigned target = 10001;

  sieve = calloc(n, sizeof *sieve);
  for (i = 2; i < n; i++) {
    if (!sieve[i]) {
      size_t j;

      count++;
      if (count == target) {
        printf("%lu\n", i);
        break;
      }
      for (j = i*2; j < n; j += i) {
        sieve[j] = 1;
      }
    }
  }
  free(sieve);

  return 0;
}
