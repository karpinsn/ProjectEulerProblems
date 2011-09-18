//
//  main.c
//  Problem 10
//
//  Created by Nikolaus Karpinsky on 9/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

/*
 The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 
 Find the sum of all the primes below two million.
 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, const char * argv[])
{
    unsigned int n = 2000000;
    
    //  Create the list
    unsigned int* primes = malloc(sizeof(unsigned int) * n);
    primes[0] = 0;
    primes[1] = 0;
    
    for(int i = 2; i < n; i++)
    {
        primes[i] = i;
    }
    
    //  Sieve it
    unsigned int p = 2;
    while(p < n)
    {
        for(unsigned int c = 2 * p; c < n; c+= p)
        {
            primes[c] = 0;
        }
        p++;
        while(primes[p] == 0 && p < n)
        {
            p++;
        }
    }
    
    //  Sum it
    unsigned long int sum = 0;
    for(unsigned int i = 2; i < n; i++)
    {
        sum += primes[i];
    }
    
    //  Release it
    free(primes);
    
    // insert code here...
    printf("Final sum: %ld\n", sum);
    return 0;
}

