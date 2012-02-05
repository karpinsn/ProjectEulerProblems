//
//  main.c
//  Problem 55
//
//  Created by Nikolaus Karpinsky on 2/4/12.
//  Copyright 2012 ISU. All rights reserved.
//

#include <stdio.h>

#define CUTOFF_DEPTH 50

int       isPalindrome(long int number);
long int  reverseDigits(long int number);
int       isLychrel(short int depth, long int number);

int isPalindrome(long int number)
{
  return number == reverseDigits(number);
}

long int reverseDigits(long int number)
{
  //  Store the first digit in the number
  long int reversedNumber = number%10;
  number /= 10;
  
  while(number > 0)
  {
    //  Shift decimal over 1 place
    reversedNumber *= 10;
    //  Take a digit and place it in reverse
    reversedNumber += number%10;
    //  Shift the number back 1 place
    number /= 10;
  }
  
  return reversedNumber;
}

int isLychrel(short int depth, long int number)
{
  if(depth > CUTOFF_DEPTH)
  {
    return 1;
  }
  
  long int newNumber = number + reverseDigits(number);
  
  return isPalindrome(newNumber) ? 0 : isLychrel(++depth, newNumber);
}

int main (int argc, const char * argv[])
{
  printf("Problem 55 - Checking for Lychrel numbers!\n");
  
  int lychrelCount = 0;
  int num = 1;
  for(num = 1; num < 10000; ++num)
  {
    lychrelCount += isLychrel(0, num) ? 1 : 0;
  }
  
  printf("Lychrel number count: %d\n", lychrelCount);
  
  return 0;
}

