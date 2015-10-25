#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: cat filename [filename ...]\n");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        // TODO: open argv[i] and print its contents to stdout
        FILE* fp = fopen(argv[i], "r");
        //char buffer[256];
        /*while (fscanf(fp, "%s", buffer) != EOF)
        {
            printf("%s\n", buffer);
        }
        */
        for (int ch = fgetc(fp); ch!= EOF; ch = fgetc(fp))
            fputc(ch, stdout); 
        
        fclose(fp);
    }

    return 0;
}

