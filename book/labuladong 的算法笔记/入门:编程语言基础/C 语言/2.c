#include <stdio.h>

void read_continuously(){
    int x;
    while(scanf("%d",&x) != EOF){
        printf("%d\n",x);
    }
}

void switch_c(){
    int day;
    scanf("%d",&day);
    char *week[] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    char *s;
    switch(day){
        case 1:
            s = week[0];
            break;
        case 2:
            s = week[1];
            break;
        case 3:
            s = week[2];
            break;
        case 4:
            s = week[3];
            break;
        case 5:
            s = week[4];
            break;
        case 6:
            s = week[5];
            break;
        case 7:
            s = week[6];
            break;
        default:
            s = "Invalid day";
            break;
    }

    printf("%s\n",s);
}

int main(){
    // read_continuously();
    switch_c();
    return 0;
}
