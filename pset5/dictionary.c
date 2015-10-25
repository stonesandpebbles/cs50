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

#define CSIZE 27
#define in {false, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}}
typedef struct node
{
    bool is_word;
    struct node* children[CSIZE];

}node;

node* root = NULL;
node* np = NULL;
int ind = 0;
static unsigned int hsize = 0;
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
        }
        
        else
        {
            tword[i] = word[i];
        }
    }
    tword[len] = '\0';
    node* p = root;
    int count = 0;
    while (p != NULL && count <= len)
    {
        if (p->is_word && count == len)
        {
            return true;
        }
        
        if (count == len) break;
        int index = tword[count] - 'a';
        p = (tword[count] == '\'')? p->children[CSIZE - 1]: p->children[index];
        
        count++;
    }    
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("could not open/n");
        return false;
    }
        
    char st[LENGTH + 1];
    
    node* q = malloc(sizeof(node));
    node* r = q;
    root = r;
    *r = (struct node)in;
    while (fscanf(fp, "%s", &st) != EOF)
    {
        int len = strlen(st);
        int index;
        r = root;
        for(int i = 0;i < len;i++)
        {
            index = (st[i] == '\'')? CSIZE - 1:st[i] - 'a';    
            if (r->children[index] == NULL)
            {
                r->children[index] = malloc(sizeof(node));
                *(r->children[index]) = (struct node) in;
            }
            r = r->children[index];
        }
        r->is_word = true;
        hsize++;      
    }
    fclose(fp);
    np = root;
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
 
void uhelper(node* t)
{
for(int i = 0; i < CSIZE ; i++)
{
    if (t->children[i] != NULL)
    {
        uhelper(t->children[i]);
    }
}
free(t);
}

 
bool unload(void)
{
    // TODO
    node* p = root;
    uhelper(p);
    return true;
}




