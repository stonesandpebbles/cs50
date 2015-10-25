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
    
    string key = argv[1];
    for(int i = 0;i < strlen(key);i++)
    {
        if (!((key[i] >= 'A' && key[i] <= 'Z') || (key[i] >= 'a' && key[i] <= 'z')))
        {
            printf("Key error");
            return 1;
        }
        
    
    }
    string text = GetString();    
         
    
    int keylen = strlen(key);
    int j;
    for(int i = 0, count = 0;i < strlen(text); i++)
    {
        
        j = (count) % keylen;
        int shift;
        shift = (key[j] < 'a') ? key[j]-'A': key[j]-'a';
        //printf("shift = %d\n", shift);
        if(text[i] >= 'A' && text[i] <= 'Z') 
        {
            text[i] = 'A' + (text[i] - 'A'+ shift) % 26 ;
            count++; 
        
        }
        
        else if((text[i] >= 'a' && text[i] <= 'z'))
        {
            text[i] = 'a' + (text[i] - 'a'+ shift) % 26 ;
            count++;
        }
        
        
            
    }
    
    printf("%s\n", text);
    
    
    return 0;
}
