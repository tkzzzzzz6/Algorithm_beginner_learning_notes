#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int devide();
int  main(){
    int a = 10, b = 2, c;
    if (devide(a,b,&c)){
        printf("%d/%d=%d\n",a,b,c);
    }
    return 0;
}

int devide(int a ,int b ,int *result){
    int ret = 1;
    if (b == 0) ret = 0;
    else{
        *result = a / b;
    }
    return ret;
}
