#include <stdio.h>



void compute(int data[], int n, int target)
{

  // 创建一个结构体数组来保存数值和原始索引
  struct NumIndex
  {
    int num;
    int index;
  } nums[100];

  // 初始化结构体数组
  for (int i = 0; i < n; i++)
  {
    nums[i].num = data[i];
    nums[i].index = i;
  }

  // 对结构体数组按数值排序
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (nums[j].num > nums[j + 1].num)
      {
        NumIndex temp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = temp;
      }
    }
  }

  // 使用双指针查找
  int left = 0,right = n-1;
  while(left < right){
    if (nums[left].num + nums[right].num == target){
      printf("%d,%d\n",nums[left].index,nums[right].index);
      return;
    }
    else if(nums[left].num + nums[right].num < target){
      left++;
    }
    else{
      right--;
    }
  }
  printf("-1,-1\n");// 没找到答案
}

int main(void)
{
    int a[]={-3,2,5,9,15,32};
    int x ;
    scanf("%d",&x);
    compute(a,6,x);





	
}