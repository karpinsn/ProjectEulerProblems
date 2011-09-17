//
//  main.c
//  Problem 2
//
//  Created by Nikolaus Karpinsky on 9/17/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

/*
 Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
 
 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 
 By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
 */

#include <stdio.h>

int main (int argc, const char * argv[])
{
    //  First numbers of the fibonacci sequence
    int number1 = 1;
    int number2 = 2;
    int number3 = number1 + number2;
    long int sum = 2;   //  Start at 2 since 2 is even but wont get checked
    
    while(number3 <= 4000000)
    {
        //  Can bit shift if this is too slow
        if(number3 % 2 == 0)
        {
            //  Even number
            sum += number3;
        }
        
        number1 = number2;
        number2 = number3;
        number3 = number1 + number2;
    }
    
    // insert code here...
    printf("Final Answer %ld\n", sum);
    return 0;
}

