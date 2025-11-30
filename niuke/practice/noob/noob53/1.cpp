#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c = 0;
    char *str = (char *)malloc(1);
    if(NULL == str)
    {
        return -1;
    }
    int iLen = 0;
    while(1)
    {
        c = getchar();
        if(c == '\n')
        {
            break;
        }
        else if(c == '5')        
        {
            c = '*';
        }
        str[iLen++] = c;
        char *temp = (char *)realloc(str,iLen+2);
        if(temp == NULL)
        {
            return -1;
        }
        str = temp;
    }
    str[iLen] = '\0';
    printf("%s",str);
    free(str);
    return 0;
}
