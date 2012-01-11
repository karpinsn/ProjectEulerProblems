//
//  main.c
//  Problem 16
//
//  Created by Nikolaus Karpinsky on 9/24/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>

long unsigned int ipow(long unsigned int base, int exp);

long unsigned int ipow(long unsigned int base, int exp)
{
    long unsigned int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }
    
    return result;
}

int main (int argc, const char * argv[])
{

    printf("2^16 %ld\n", ipow(2, 64));

    return 0;
}

