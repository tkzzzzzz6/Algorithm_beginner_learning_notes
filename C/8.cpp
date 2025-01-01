#include <stdio.h>

int main()
{
    char str[100];
    scanf("%s", str);
    int i = 0, cnt = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            cnt++;
        i++;
    }
    printf("%d", cnt);
}