//
//  main.c
//  Problem 4
//
//  Created by Nikolaus Karpinsky on 9/24/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

/*
 A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 99.
 
 Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

//  Largest possible product is 6 digits (999 * 999 = 998001)
int digits[6];

void digitizer(int number);
int isPalindrome(void);
int isPalindromeR(int left, int right);
int iPow(int num, int pow);
int max(int a, int b);

int max(int a, int b) 
{
    return a > b ? a : b;
}

int iPow(int num, int pow)
{
    if(pow == 0)
    {
        return 1;
    }
    else if(pow == -1)
    {
        return 0;
    }
    
    int power = num;
    for(int i = 0; i < pow - 1; ++i)
    {
        power *= num;
    }
    
    return power;
}

//  Take the product and digitize it into the digits array
void digitizer(int number)
{
    for(int i = 0; i < 6; i++)
    digits[i] = -1;
    
    int currentNumber = number;
    for(int place = 5; place >= 0; --place)
    {
        while(currentNumber >= 0)
        {
            digits[place]++;
            currentNumber -= iPow(10, place);
        }
        currentNumber += iPow(10, place);
    }
}

int isPalindrome(void)
{
    int right = 0;
    int left = 5;
    while(0 == digits[left] && left >= 0)
    {
        --left;
    }
    
    return isPalindromeR(left, right);
}

int isPalindromeR(int left, int right)
{
    if (left <= right) 
    {
        //  We are good
        return 1;
    }
    
    if(digits[left] != digits[right])
    {
        return 0;
    }
    
    return isPalindromeR(--left, ++right);
}

int main (int argc, const char * argv[])
{
    int num = 69896;
    digitizer(num);
    printf(" %d ", isPalindrome());    
    
    int maxP = 0;
    for(int i = 100; i <= 999; ++i)
    {
        for(int i2 = 100; i2 <= 999; ++i2)
        {
            digitizer(i * i2);
            if(isPalindrome())
            {
                maxP = max(maxP, i * i2);
                printf("Max Palindrome: %d\n", maxP);
            }
        }
    }
    
    return 0;
}

