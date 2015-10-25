# include <stdio.h>
# include <cs50.h>

int main (void) {
    int i;
    i = GetInt();
    int numBits = sizeof(int) * 8;
    bool start = false;
    for( int j = numBits - 1;j >= 0;j--) {
        if ((i & (1 << j))) 
            start = true;
        if (start)
            printf("%s", i & (1 << j)? "1":"0");
        }   
    printf("\n");
    return 0;
    } 
    
