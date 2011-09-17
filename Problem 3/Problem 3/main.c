//
//  main.c
//  Problem 3
//
//  Created by Nikolaus Karpinsky on 9/17/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

/*
 The prime factors of 13195 are 5, 7, 13 and 29.
 
 What is the largest prime factor of the number 600851475143 ?
 */

#include <stdio.h>

long unsigned int factorize(long unsigned int numberToFactor, long unsigned int currentFactor);

int main (int argc, const char * argv[])
{
    long unsigned int numberToFactor = 600851475143;
    long unsigned int currentFactor = 2;
    
    //  Factorize
    while(currentFactor <= numberToFactor)
    {
        //  If this needs to be faster it could use a incrementor to skip even numbers
        currentFactor = factorize(numberToFactor, currentFactor);
        
        if(0 == currentFactor)
        {
            break;
        }

        printf("Here is a factor: %ld", currentFactor);
        numberToFactor /= currentFactor;

        //  Check if the factor is prime with the factorizor!
        unsigned long int factorsFactor = factorize(currentFactor, 3);
        if(factorsFactor == 0 || factorsFactor == currentFactor)
        {
            //  We have a prime Factor!
            printf(" and its Prime!");
        }
        
        printf("\n");
    }
    
    
    return 0;
}

long unsigned int factorize(long unsigned int numberToFactor, long unsigned int currentFactor)
{
    while(currentFactor <= numberToFactor)
    {
        if(numberToFactor % currentFactor == 0)
        {
            return currentFactor;
        }
        
        currentFactor++;
    } 
    return 0;
}