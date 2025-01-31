#include <stdio.h>

int main()
{
    FILE *file = fopen("shared_file.txt", "w");
    fprintf(file, "Hello from writer!");
    fclose(file);
    return 0;
}