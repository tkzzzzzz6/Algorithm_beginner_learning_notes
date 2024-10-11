#include <stdio.h>

int main(){
    int x;
    int cnt = 0;
    double sum = 0;
    int number[100];
    scanf("%d", &x);
    while (x != -1){
        number[cnt] = x;
        sum += x;
        cnt++;
        scanf("%d", &x);  // 添加这行以读取下一个输入
    }
    if (cnt > 0){
        printf("%f\n", sum / cnt);
        for (int i = 0; i < cnt;i++){
            if (number[i] > sum / cnt){
                printf("%d\n", number[i]);
            }
        }
    }
    return 0;
}
