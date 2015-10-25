 /****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

#define BSIZE 300
#define TSIZE 50

typedef struct node
{
    char st[LENGTH + 1];
    struct node* next;

}node;

node* hasht[TSIZE];


static unsigned int hsize = 0;
static int ind = 0;
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    int len = strlen(word);
    char tword[len + 1];
    for(int i = 0; i < len; i++)
    {
        if( word[i] >= 'A' && word[i] <= 'Z')
        {
            tword[i] = word[i] + 32;
            //printf("%c", tword[i]);
        }
        
        else
        {
            tword[i] = word[i];
        
        }
    }
    
    tword[len] = '\0';
    //char* ptword = tword;
    int j = 0;
    
    while (j < ind && !(strcmp(hasht[j+1]->st, tword) > 0))
    {
         j++;
    }
    
    node* p = hasht[j];
    
    while (p != NULL)
    {
        if (strcmp(p->st, tword) == 0) 
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    //printf("CP1/n");
    //char word[LENGTH +1];
    // TODO
    ind = 0;
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("could not open/n");
        return false;
    }
    int count = 0;
    
    
    node* q = malloc(sizeof(node));
    node* p = q;
    hasht[0] = p;
    
    while (fscanf(fp, "%s", p->st) != EOF)
    {
        count++;
        q = malloc(sizeof(node));
        if (count == BSIZE)
        {
            p->next = NULL;
            hsize += count;
            count = 0;
            ind++;
            p = q;
            hasht[ind] = p;
        }
        
        else
        {
            p->next = q;
            p = p->next;
        }
           
    }
    
    p->next = NULL;
    hsize += count;
    fclose(fp);
    return true;
    
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return hsize;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    node* p;
    for(int i = 0; i <= ind;i++)
    {
        p = hasht[i];
        while (p != NULL)
        {
            node* q = p;
            p = p->next;
            free(q);
        }
    }
    
    return true;
}


