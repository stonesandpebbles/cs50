/****************************************************************************
 * math3.c
 *
 * David J. Malan
 * malan@harvard.edu
 *
 * Computes and prints a floating-point total.
 *
 * Demonstrates loss of precision.
 ***************************************************************************/

#include <stdio.h>

int main(void)
{
    float answer = 1 / 10;
    printf("%.2f\n", answer);
    return 0;
}
