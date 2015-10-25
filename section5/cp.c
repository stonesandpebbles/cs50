#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Usage: cp source destination\n");
        return 1;
    }
    
    FILE* fpr = fopen(argv[1], "r");
    FILE* fpw = fopen(argv[2], "w"); 
    // TODO: copy the contents of argv[1] to argv[2]
    char buffer[256];
    for (int n = fscanf(fpr, "%s", buffer);n != EOF;n = fscanf(fpr, "%s", buffer))
        fprintf(fpw, "%s\n", buffer);     
    
    fclose(fpr);
    fclose(fpw);

    return 0;
}

