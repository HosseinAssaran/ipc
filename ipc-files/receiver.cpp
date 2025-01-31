#include <stdio.h>

int main()
{
    FILE *file = fopen("shared_file.txt", "r");
    char buffer[100];
    fgets(buffer, sizeof(buffer), file);
    printf("Reader read: %s\n", buffer);
    fclose(file);
    return 0;
}