# include <stdio.h>
# include <cs50.h>

int main(void) {

    printf("Height: ");
    int height = GetInt();
    
    while (height > 23 || height < 0) {
        printf("Height: ");
        height = GetInt(); 
    }
    
    for (int i = 0;i < height;i++) {
        
        for(int j = height+1;j > 0;j--) {
            
            
            if (j <= i+2) {
                printf("#");
            } 
               
            else {
                printf(" ");    
            }
         }
         printf("\n");
    }    
    
    return 0;           
}
