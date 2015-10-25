# include <stdio.h>
# include <cs50.h>

int main(void) {
    int num, denom;
    
    do{
    
        printf("non-negative numerator: ");
        num = GetInt();
    
    } while (num < 0);
    
    do{
    
        printf("positive denominator: ");
    
        denom = GetInt();
        
    } while (denom <= 0);
    
    float perc = num*100.0/denom;
    printf("%.2f%%\n",perc); 
   
       
} 
