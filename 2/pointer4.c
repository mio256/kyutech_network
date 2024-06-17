#include <stdio.h>
#include <string.h>

void slink(char *s, char *s1, char *s2)
{
    strcpy(s, s1);
    strcat(s, "_");
    strcat(s, s2);
}

int main(int argc, char *argv[])
{
    char s[30];
    if (argc < 3)
    {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }
    slink(s, argv[1], argv[2]);
    printf("%s\n", s);

    return 0;
}
