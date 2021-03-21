#include <stdio.h>
#include <stdlib.h>

const char app_name[] = "readentirefile";

void show_usage()
{
    printf("Usage: ./%s <file name>\n\n", app_name);
}

int main(int argc, char *argv[])
{
    FILE *infile;
    char *buffer;
    long numbytes;

    if (argc == 1)
    {
        show_usage();
        return 0;
    }

    infile = fopen(argv[1], "r");

    // if file exists
    if (infile == NULL)
        return 1;

    // get the number of bytes in the file
    fseek(infile, 0L, SEEK_END);
    numbytes = ftell(infile);

    // start from the beginning
    fseek(infile, 0L, SEEK_SET);

    // memory allocation for a file buffer
    buffer = (char *)calloc(numbytes, sizeof(char));

    /* memory error */
    if (buffer == NULL)
        return 1;

    // copy all the text into the buffer
    fread(buffer, sizeof(char), numbytes, infile);
    fclose(infile);

    // read the file
    printf("The file called %s contains this text\n\n%s", argv[1], buffer);

    /* free the memory we used for the buffer */
    free(buffer);
    return 1;
}
