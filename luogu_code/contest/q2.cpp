#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, k, d;
        cin >> n >> k >> d;

        //n为正整数序列的长度,k为首项,d为公差

        // 求出序列中满足字串中的元素是平均值是整数的个数

        // 采用滑动窗口的方法

        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];

        }

        int count = 0;
        for (int i = 0; i < n; i++){
            int sum = 0;
            for (int j = i; j < n; j++){
                sum += a[j];
                if (sum % d == 0){
                    count++;
                }
            }
        }

        cout << count << endl;
        
        

    }
}