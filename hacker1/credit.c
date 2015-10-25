# include <stdio.h>
# include <cs50.h>

int main(void) {
    long long number;
    do {
        printf("Number:");
        number = GetLongLong();
        }
        while (number < 0);
    if (number/1000000000000 == 0) {
        printf("INVALID\n");
        return 0;
        }    
    long long copy = number;
    int count = 0;
    int sum = 0;
    int digit = 0;
    while (number > 0) {
        digit = number - ((number/10)*10);
        //printf("digit = %d\n", digit);
        if (count % 2 != 0)
            digit *= 2;
        int digit1 = 0, digit2 = 0;    
        if (digit > 9) {
            digit1 = digit - (digit/10)*10;
            digit2 = digit/10;
            digit = 0;
            //printf("d1= %d", digit1);
            //printf("d2=%d", digit2);
            }
        sum += digit1 + digit2 + digit;
        //printf("sum= %d\n", sum);
        number /= 10;
        count++;
        }
    //printf("%d\n", sum);    
    if (sum % 10 == 0) {
        if (copy / 10000000000000 == 34 || copy / 10000000000000 == 37)
            printf("AMEX\n");
        if (copy / 100000000000000 > 50 && copy / 100000000000000 < 56)
            printf("MASTERCARD\n");
        if (copy / 1000000000000 == 4 || copy / 1000000000000000 == 4)
            printf("VISA\n");
        }                    
    return 0;
}

