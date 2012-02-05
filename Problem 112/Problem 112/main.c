//
//  main.c
//  Problem 112
//
//  Created by Nikolaus Karpinsky on 2/4/12.
//  Copyright 2012 ISU. All rights reserved.
//

#include <stdio.h>

int isNotIncreasing(int number);
int isNotDecreasing(int number);
int isBouncy(int number);

int isNotIncreasing(int number)
{
  int previousDigit = number%10;
  number /= 10;
  int currentDigit = number%10;
  
  while (number > 0)
  {
    if(previousDigit < currentDigit)
    {
      return 1;
    }
    
    previousDigit = currentDigit;
    number /= 10;
    currentDigit = number%10;
  }
  
  return 0;
}

int isNotDecreasing(int number)
{
  int previousDigit = number%10;
  number /= 10;
  int currentDigit = number%10;
  
  while (number > 0)
  {
    if(previousDigit > currentDigit)
    {
      return 1;
    }
    
    previousDigit = currentDigit;
    number /= 10;
    currentDigit = number%10;
  }
  
  return 0;
}

int isBouncy(int number)
{
  return isNotDecreasing(number) && isNotIncreasing(number);
}

int main (int argc, const char * argv[])
{
  // insert code here...
  printf("Project Euler: Problem 112\n");
  
  int number = 100;
  int bouncyCount = 0;
  const double percentCheck = 99;
  
  for(;number < 100000000; ++number)
  {
    bouncyCount += isBouncy(number) ? 1 : 0;
    
    if((double)bouncyCount/(double)number * 100.0 >= percentCheck)
    {
      break;
    }
  }
  
  printf("Percent Bouncy: %f \nBouncyCount %d \nNumber: %d\n", (double)bouncyCount/(double)number * 100.0f, bouncyCount, number);
  
  return 0;
}

