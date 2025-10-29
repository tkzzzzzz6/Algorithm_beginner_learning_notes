#include <stdio.h>
// void func(int x[5])
// {
//     int i;
//     for (i = 0; i < 5; i++)
//         x[i] = i + 6;
// }
void func(int x[])
{
    int i;
    for (i = 0; i < 5; i++)
        x[i] = i + 6;
}

int main()
{
    int i, a[5] = {1, 2, 3, 4, 5};
    func(a);
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);
}
