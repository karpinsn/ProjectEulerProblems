#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Project Euler 7

  By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

  What is the 10 001st prime number?
*/

int main(int argc, char* argv[])
{
  //  Prime-counting function = n / ln(n) says that we should have enough primes
  const int n = 200000;
  int* primes = (int*)malloc(sizeof(int) * n);
  memset(primes, 1, n * sizeof(int));

  int p = 2;
  primes[0] = 0;
  primes[1] = 0;
  while(p * 2 < n)
  {
	for(int c = 2 * p; c < n; c += p)
	{
	  primes[c] = 0;
	}
	do
	  p++; while(p < n && !primes[p]);
  }

  int primeCount = 0;
  int primeIndex = 0;

  int primeToFind = 10001;

  while(primeIndex < n && primeCount < primeToFind)
  {
	if(primes[primeIndex])
	  primeCount++;
	primeIndex++;
  }
  primeIndex--;

  printf("PrimeCount: %d Prime: %d\n", primeCount, primeIndex);

  free(primes);
  return 0;
}