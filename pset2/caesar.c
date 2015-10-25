# include <stdio.h>
# include <cs50.h>
# include <string.h>
# include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Key error");
        return 1;    
    }
    
    string text = GetString();    
         
    int key = atoi(argv[1]);
    
    for(int i = 0;i < strlen(text); i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z') 
        {
            text[i] = 'A' + (text[i] - 'A'+ key) % 26 ;
             
        
        }
        
        else if((text[i] >= 'a' && text[i] <= 'z'))
        {
            text[i] = 'a' + (text[i] - 'a'+ key) % 26 ;
        }
        
        
            
    }
    
    printf("%s\n", text);
    
    
    return 0;
}
