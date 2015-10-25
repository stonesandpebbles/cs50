/****************************************************************************
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 ***************************************************************************/
 # include <stdio.h>
 # include <stdlib.h>
 # include <stdint.h>
 
 int main(void)
 {
    FILE* inptr = fopen("card.raw", "r");    
    if (inptr == NULL)
    {
        printf("could not open file");
        return  2;
    }
    
    uint8_t type[512];
    int nit = 1;
    int i = 1;
    int flag = 0;
    while ((nit!=0))
    {
        if ((type[0]== 0xff) && (type[1] == 0xd8) && (type[2] == 0xff) && (type[3] == 0xe1 || type[3] == 0xe0)) 
        {
            char fname[8];
            sprintf(fname, "%03d.jpg", i);
            i++;
            //printf("%03d.jpg", i);
            FILE* outptr = fopen(fname, "w");
            fwrite(&type, 512, 1, outptr);

            nit = fread(&type, 512, 1, inptr);
        
            while (!((type[0]== 0xff) && (type[1] == 0xd8) && (type[2] == 0xff) && (type[3] == 0xe1 || type[3] == 0xe0)) && nit != 0) 
        
            {
                
                
                fwrite(&type, 512, 1, outptr);

                nit = fread(&type, 512, 1, inptr);    
            }
            //printf("%d\n", i);
            fclose(outptr);
            //printf("%s",
            flag = 1;    
        }
        //printf("here\n");
        if (flag == 0)
        {
            nit = fread(&type, 512, 1, inptr);
        } 
    }
    fclose(inptr);
    return 0;
 }
 
