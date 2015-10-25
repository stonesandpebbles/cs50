# include <stdio.h>
# include <cs50.h>
# include <math.h>

int main (void) {
    
  printf("O hai!  How much change is owed?\n");
  float change = GetFloat();
  
  while (change < 0){
    printf("How much change is owed?\n");
    change = GetFloat();
  
  } 
  int count = 0;
  change = round(change * 100);
  
  while (change >= 5) {   
    if (change >= 25) {
        change -= 25;
        count++;
    }    
    else if (change >= 10 && change < 25) {
        change -= 10;
        count++;
    }    
        
    else if (change >= 5 && change < 10) {
        change -= 5;
        count++;
    }    
    
                
  }
  printf("%d\n",count+(int)change); 
  return 0;
}


