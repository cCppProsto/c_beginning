#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *pstr = NULL;
    // ...
    int  l = 5;
    int i = 0;
    int n_s = 0;

    pstr = calloc(l + 1, sizeof(char));

    strcpy(pstr, "Hello");
    n_s = (l + strlen(" world!") + 1);

    printf("%p - \n", pstr);
    pstr = realloc(pstr, 1024);
    printf("%p - \n", pstr);

    strcat(pstr, " world!");

    pstr[n_s] = '\0';
    printf("%s", pstr);

    printf("\n");

    if(pstr != NULL)
        free(pstr);
    pstr = NULL;


    //malloc();
    //calloc();
    //realloc();
    //free();

    return 0;
}
