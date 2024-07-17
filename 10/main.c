#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buf[100] = "\0";
    printf("Content-type: text/html \n\n");
    printf("<pre>\n");
    char *method = getenv("REQUEST_METHOD");
    if (strcmp(method, "GET") == 0)
    {
        strcpy(buf, getenv("QUERY_STRING"));
        strtok(buf, "=");
        printf("%s\n", strtok(NULL, "="));
    }
    else if (strcmp(method, "POST") == 0)
    {
        scanf("%s", buf);
        strtok(buf, "=");
        printf("%s\n", strtok(NULL, "="));
    }
    else
    {
        return 1;
    }
    printf("</pre>\n");
}
