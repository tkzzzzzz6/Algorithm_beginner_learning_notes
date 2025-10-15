#include <string>
#include <vector>
#include <iostream>
#include <queue>


using namespace std;

class Solution
{
public:
    // 创建队列，用于存储当前需要推倒的多米诺
    string pushDominoes(string dominoes)
    {
        int n = dominoes.size();
        queue<int> q;
        vector<int> time(n, -1); //-1表示未被推倒
        vector<string> force(n); //记录每个位置受到的力

        for(int i = 0;i < n;++i){
            if(dominoes[i] != '.'){
                q.emplace(i);
                time[i] = 0;
                force[i].push_back(dominoes[i]);
            }
        }

        string res(n,'.');

        while(!q.empty()){
            int i = q.front();
            q.pop();

            if(force[i].size() == 1){
                char f = force[i][0];
                res[i] = f;
                int t = time[i];
                int ni = (f == 'L') ? i - 1 : i + 1;
                if(ni >= 0 && ni < n){
                    if(time[ni] == -1){
                        q.emplace(ni);
                        time[ni] = t + 1;
                        force[ni].push_back(f);
                    }else if(time[ni] == t + 1){
                        if(force[ni].size() == 1)
                            force[ni].push_back(f);
                    }
                }
            }
            
        }
        return res;
    }
};

int main()
{
    Solution s;
    string dominoes = ".L.R...LR..L..";
    cout << s.pushDominoes(dominoes) << endl;
    return 0;
}