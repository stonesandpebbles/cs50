# include <stdio.h>
# include <cs50.h>

int main(void) {
    char c;
    c = GetChar();
    printf("%c\n",c - 'a' + 'A');
    return 0;
    }
