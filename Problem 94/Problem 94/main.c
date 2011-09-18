//
//  main.c
//  Problem 94
//
//  Created by Nikolaus Karpinsky on 9/17/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

/*
 It is easily proved that no equilateral triangle exists with integral length sides and integral area. However, the almost equilateral triangle 5-5-6 has an area of 12 square units.
 
 We shall define an almost equilateral triangle to be a triangle for which two sides are equal and the third differs by no more than one unit.
 
 Find the sum of the perimeters of all almost equilateral triangles with integral side lengths and area and whose perimeters do not exceed one billion (1,000,000,000).
 */

#include <stdio.h>

unsigned long int arearator(unsigned long int a, unsigned long int c);
unsigned long int rooter(unsigned long int number, unsigned long int lowerBound, unsigned long int upperBound);
unsigned long int quickRooter(unsigned long int number, unsigned long int lowerBound, unsigned long int upperBound);

int main (int argc, const char * argv[])
{

    unsigned long int perimSum = 0;
    
    //(1000000000 / 3)
    
    //  Since the equalatoral sides must be odd (can prove this) index should always be odd.
    for(unsigned long int i = 1; i < (1000000000 / 3); i += 2)
    {
        if(arearator(i, i+1))
        {
            printf("Found triangle: %ld, %ld, %ld\n", i, i, i+1);
            
            //  Even area, sum the permimator
            perimSum += 3 * i + 1;
        }
        
        if(arearator(i, i-1))
        {
            printf("Found triangle: %ld, %ld, %ld\n", i, i, i-1);
            
            //  Even area, sum the permimator
            perimSum += 3 * i - 1;
        }
    }
    
    printf("Final permimator sum: %ld\n", perimSum);
    return 0;
}

unsigned long int arearator(unsigned long int a, unsigned long int c)
{
    //  Calculate h2 which is the height squared
    unsigned long int h2 = (a * a) - ((c/2) * (c/2));
    unsigned long int h = quickRooter(h2, c/2, a);
    
    //  If there is no integer root, rooter returns 0 thus arearator returns 0
    return (c/2) * h;
}

unsigned long int rooter(unsigned long int number, unsigned long int lowerBound, unsigned long int upperBound)
{
    //  Could develop a better root search if this is slow
    for(unsigned long int possibleRoot = lowerBound; possibleRoot < upperBound; possibleRoot++)
    {
        if(possibleRoot * possibleRoot == number)
        {
            return possibleRoot;
        }
    }
    
    return 0;
}

unsigned long int quickRooter(unsigned long int number, unsigned long int lowerBound, unsigned long int upperBound)
{
    //  Go half way
    unsigned long int possibleRoot = (upperBound - lowerBound)/2 + lowerBound;
    if(possibleRoot == lowerBound || possibleRoot == upperBound)
    {
        return 0;
    }
    
    unsigned long int square = possibleRoot * possibleRoot;
    
    if(square == number)
    {
        // Found our root
        return possibleRoot;
    }
    
    // trim the bounds
    return square < number ? quickRooter(number, possibleRoot, upperBound) : quickRooter(number, lowerBound, possibleRoot);
    
    //return possibleRoot * possibleRoot == number ? possibleRoot : quickRooter(number, ,)
}