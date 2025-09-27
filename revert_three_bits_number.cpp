#include <stdio.h>
#include <math.h>

using namespace std;

int number;
int main()
{
    int bit;
    scanf("%d", &number);
    for(int i=0; i<3; i++)
    {
        bit = number % 10;
        number /= 10;
        printf("%d", bit);
    }
    printf("\n");
    return 0;
}