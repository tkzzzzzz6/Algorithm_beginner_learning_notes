#include <stdio.h>
int main(void)
{
    /*********Begin*********/
    printf("the number of students:");
    float n;
    scanf("%f",&n);
    
    if (n <= 0){
        printf("the scores:");
        printf("average=%.2f", 0);
    }
    else{
        float sum = 0;
        printf("the scores:");
        for (int i = 0; i < n; i++)
        {
            float score;
            scanf("%f", &score);
            sum += score;
        }
        printf("average=%.2f", sum / n);
    }
    
    /*********End**********/
    return 0;
}
