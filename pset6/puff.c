#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "forest.h"
#include "huffile.h"
#include "tree.h"


Forest* fp = mkforest();
//prototypes
void buildhtree(Header* header);

int main(int arg c, char* argv[])
{
    //ensure proper usage
    if (argc != 3)
        {
            printf("Usage: %s file to puff output file\n", argv[0]);
            return 1;
        }

    // open input
    Huffile* input = hfopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open %s for reading.\n", argv[1]);
        return 1;
    }
    
    // read in header
    Huffeader header;
    if (hread(&header, input) == false)
    {
        hfclose(input);
        printf("Could not read header.\n");
        return 1;
    }

    // check for magic number
    if (header.magic != MAGIC)
    {
        hfclose(input);
        printf("File was not huffed.\n");
        return 1;
    }

    // check checksum
    int checksum = header.checksum;
    for (int i = 0; i < SYMBOLS; i++)
    {
        checksum -= header.frequencies[i];
    }
    if (checksum != 0)
    {
        hfclose(input);
        printf("File was not huffed.\n");
        return 1;
    }


    //building huffman tree
    for(int i = 0;i < SYMBOLS; i++)
    {
        if(header.frequencies[i] != 0)
        {
            Tree* tr = mktree();
            if (tr == NULL)
            {
                rmforest(fp);
                printf("Could not make tree.\n");
                return 1;
            }
            tr->frequency = header.frequencies[i];
            tr->symbol = (char)i;
            if(!plant(fp, tr))
            {
                rmforest(fp);
                printf("Could not plant tree.\n");
                return 1;
            }
        }       
    }
    while((Tree* pt1 = pick(fp)) != NULL || (Tree* pt2 = pick(fp)) != NULL)
    {
            if(pt2 == NULL)
            {
                if(!plant(fp, pt2))
                {
                    rmforest(fp);
                    printf("Could not plant tree.\n");
                    return 1;
                }
            }
            Tree* top = mktree();
            if (top == NULL)
            {
                rmforest(fp);
                printf("Could not make tree.\n");
                return 1;
            }
            top->left = pt1;
            top->right = pt2;
            top->frequency = pt1->frequency + pt2->frequency;    
            if(!plant(fp, top))
            {
                rmforest(fp);
                printf("Could not plant tree again.\n");
                return 1;
            }
    }
    
    
    
    //reading binary file and puffing to text file    
    FILE* out = fopen(agrv[2], "w");
    bool flag = false;
    Tree* trav = NULL;
    while((int bit = bread(input)) != EOF)
    {
        if(!flag)
        {
            trav = (fp->first)->tree;                
        }
        trav = bit == 0 ? trav->left:trav->right;
        if (trav->left == NULL && trav->right == NULL)
        {
            flag = true;
            if (fputc(trav->symbol, out) == EOF)
                printf("error on writing to %s", argv[2]);
                return 1;
        }
    }
    
    //closing opened file streams
    hfclose(input);
    fclose(out);
}
