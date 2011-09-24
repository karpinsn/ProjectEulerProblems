//
//  main.c
//  Problem 18
//
//  Created by Nikolaus Karpinsky on 9/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

/*
 By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
 
 3
 7 4
 2 4 6
 8 5 9 3
 
 That is, 3 + 7 + 4 + 9 = 23.
 
 Find the maximum total from top to bottom of the triangle below:
 
 75
 95 64
 17 47 82
 18 35 87 10
 20 04 82 47 65
 19 01 23 75 03 34
 88 02 77 73 07 63 67
 99 65 04 28 06 16 70 92
 41 41 26 56 83 40 80 70 33
 41 48 72 33 47 32 37 16 94 29
 53 71 44 65 25 43 91 52 97 51 14
 70 11 33 28 77 73 17 78 39 68 17 57
 91 71 52 38 17 14 91 43 58 50 27 29 48
 63 66 04 68 89 53 67 30 73 16 69 87 40 31
 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
 
 NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
 */

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);

int max(int a, int b) 
{
    return a > b ? a : b;
}

int main (int argc, const char * argv[])
{
    int rows = 100;
    int *numberTriangle = malloc(sizeof(int) * rows * rows);
    
    FILE *fp = fopen("/Users/karpinsn/Workspace/ProjectEulerProblems/Problem 18/Problem 18/Problem67.txt", "r");
    if(NULL == fp)
    {
        printf("Unable to open the file\n");
        return -1;
    }
    
    for(int row = 0; row < rows; ++row)
    {
        for(int col = 0; col <= row; ++col)
        {
            if(EOF == fscanf(fp, "%d", numberTriangle + (row * (rows + 1) + col)))
            {
                break;
            }
        }
    }
    
    // Fill in the array
    
    //	Subtract row since 0 indexed, subtract another one since we want to start at second to last row
    for(int row = rows - 1 - 1; row >= 0; --row)
    {
        for(int col = 0; col <= row; ++col)
        {
            numberTriangle[row * (rows + 1) + col] += max(numberTriangle[(row + 1) * (rows + 1) + col], numberTriangle[(row + 1) * (rows + 1) + col + 1]);
        }
    }
    
    //	Answer is in numberTriangle[0][0]
    printf("Answer is: %d\n", numberTriangle[0]);
    
    return 0;
}

