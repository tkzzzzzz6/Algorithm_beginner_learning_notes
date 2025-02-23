#include<stdio.h>
#include<math.h>
	int main(void)
	{  
	  /*********Begin*********/
      for (int i = 100;i<1000;i++){
          int a;
          a = pow(i%10,3) + pow(i/10%10,3) + pow(i/100,3);
          if (a == i)
          printf("%d ",i);
      }

          /*********End**********/
    return 0;
}
