# include <stdio.h>
# include <cs50.h>

int main(void) {
    int height;
    //int gapSize = 2;
    do{
        printf("Height:");
        height = GetInt();
    
    }
    while(height < 0 || height > 23);
    
    for(int i = 1;i <= height; i++) {
        
        for(int j = 0; j < height - i; j++)
            printf(" ");
        
        for(int k = 0; k < i;k++)
            printf("#");
        printf(" ");
        printf(" ");
        for(int l = 0; l< i;l++)
            printf("#");
                
        printf("\n");
    }    

    return 0;
}
