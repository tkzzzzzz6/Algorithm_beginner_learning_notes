#include <iostream>
#include <vector>

using namespace std;

int main(){
    int cnt = 0;
    for (int i = 11; i <= 100000000; i++)
    {
        int x = i;
        vector<int> weishu;
        while(x){
            weishu.push_back(x % 10);
            x /= 10;
        }
        if(weishu.size() % 2 == 1)
            continue;
        int sum1 = 0;
        int sum2 = 0;
        int front = 0;
        int back = weishu.size() - 1;
        while(front < back){
            sum1 += weishu[front];
            sum2 += weishu[back];
            front++;
            back--;
        }
        if(sum1 == sum2)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}