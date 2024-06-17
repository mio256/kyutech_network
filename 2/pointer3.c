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
    char s[30], s1[] = "Oishi", s2[] = "Reiya";
    slink(s, s1, s2);
    printf("%s\n", s);

    return 0;
}
