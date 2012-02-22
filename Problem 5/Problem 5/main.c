#include <stdio.h>

int main(int argc, char* argv)
{
  unsigned long int divisible = 22;
  int divisor = 2;

  while(1)
  {
	//	Only check 11 - 20 since 1 - 10 are all factors of the others
	for(divisor = 11; divisor < 21; ++divisor)
	{
	  if(divisible % divisor != 0)
		break; // This isn't it
	}

	if(21 == divisor)
	  break; // We found it!
	else
	  divisible+= 2; // Increment by two since odd is not divisible by 2
  }

  printf("Divisible: %ld\n", divisible);

  return 0;
}