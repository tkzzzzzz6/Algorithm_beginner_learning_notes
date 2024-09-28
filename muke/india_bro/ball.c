#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int main(){
    initgraph(640,480);
    fillcircle(320, 240, 50);
    _getch();
    return 0;
}