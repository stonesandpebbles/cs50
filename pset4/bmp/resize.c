/****************************************************************************
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 ***************************************************************************/
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: copy infile outfile\n");
        return 1;
    }

    // remember filenames
    int factor = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    bi.biWidth *= factor;
    bi.biHeight *= factor;
    
    bf.bfSize -= bi.biSizeImage;
    bi.biSizeImage = (((bi.biWidth) * (bi.biBitCount/8)) + (4 - ((bi.biWidth) * sizeof(RGBTRIPLE)) % 4) % 4) * abs(bi.biHeight) ;
    bf.bfSize += bi.biSizeImage;
    
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int inpadding =  (4 - ((bi.biWidth/factor) * sizeof(RGBTRIPLE)) % 4) % 4;
    int outpadding = (4 - ((bi.biWidth) * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight/factor; i++)
    {
        
       
        RGBTRIPLE tripleline[bi.biWidth/factor]; 
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth/factor; j++)
        {
                // temporary storage
            RGBTRIPLE triple;    

            
            
            
          // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            tripleline[j] = triple;
        } 
        
        for(int x = 0; x < factor; x++)
        {
            
            for(int y = 0; y < bi.biWidth/factor; y++)
            {
                RGBTRIPLE triple;
                triple = tripleline[y];
                
                for (int k = 0; k < factor; k++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
               
            }
           

            // then add it back (to demonstrate how)
            for (int l = 0; l < outpadding; l++)
                fputc(0x00, outptr);
            
        
        }//inptr -= 3;
    
         // skip over padding, if any
        fseek(inptr, inpadding, SEEK_CUR);
        
        
        //inptr += 3;
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
