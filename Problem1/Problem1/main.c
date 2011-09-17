//
//  main.c
//  Problem1
//
//  Created by Nikolaus Karpinsky on 9/17/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

/*
 If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 
 Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <stdio.h>

int main (int argc, const char * argv[])
{
    int maxNumber = 1000;
    long int sum = 0;
    
    for(int number = 1; number < maxNumber; number++)
    {
        if(number % 3 == 0 || number % 5 == 0)
        {
            //  multiple of 3 or 5
            sum += number;
        }
    }
    
    printf("Final sum is: %ld\n", sum);
    return 0;
}

