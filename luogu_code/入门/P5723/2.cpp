#include<iostream>
using namespace std;
bool isprime(int x){ //判断质数的函数，应该不用我多解释
	if(x<2)return false;
	if(x==2)return true;
	for(int i=2;i*i<=x;i++){
		if(x%i==0)return false;
	}
	return true;
}
int l,r,x,y; //l,r是题目范围，x,y是他们的长度
int a[10];  //储存创造出来的数
bool b=true;  //用来作为是否跳出的判断

void go(int x,int k){  //k是总位数，x是目前枚举到的位置
	if(x==(k+1)/2){  //(k+1)/2是k位的中间数，可以自己算一下
		for(int i=k;i>x;i--){  //把剩下的位数完善
			a[i]=a[k-i+1];
		}
		int shu=0;  //将数组转化成数
		for(int i=1;i<=k;i++){
			shu=shu*10+a[i];
		}
		if(shu<l)return; //小于l就跳过
		if(shu>r){ //大于r就跳出
			b=false;
			return;
		}
		if(isprime(shu))cout<<shu<<endl; //是质数就输出
		return; //这个一定不能漏，要不然会一直搜下去（本人是亲身体验过的受害者）
	}
	int i;
	if(x)i=0;
	else i=1; //最高位不能是0
	for(i=i;i<=9;i++){ //dfs(深度优先搜索)下一位，没学过可以去看下P1706
		if(b==false)return; //如果已经出现大于r的数，就跳出函数
		a[x+1]=i;
		go(x+1,k);
	}
	return;
}
int weishu(int j){ //计算一个数的长度
	int b=j,count=0;
	while(b>0){
		b/=10;
		count++;
	}
	return count;
}
int main(){
	cin>>l>>r;
	x=weishu(l);
	y=weishu(r);
	for(int i=x;i<=y;i++){
		if(i==1){ //一位数特判
			if(l<=5&&r>=5)cout<<5<<endl;
			if(l<=7&&r>=7)cout<<7<<endl;
			continue;
		}
		if(i==2){ //两位数特判
			if(l<=11&&r>=11)cout<<11<<endl;
			continue;
		}
		if(i%2==0)continue; //偶数位就跳过
		if(i==9)break; //九位直接跳出
		b=true; //每次搜索要先重置这个变量
		go(0,i); //从第0位开始搜
	}
	return 0;
}