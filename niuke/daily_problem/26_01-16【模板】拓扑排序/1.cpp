#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

struct node
{
  int du = 0;
  vector<int> zi;
};

int main()
{
  int n,m;
  cin >> n >> m;
  vector<node> dd(n+1);

  for(int i = 0;i<m;++i)
  {
    int f,z;
    cin >> f >> z;
    dd[f].zi.push_back(z);
    dd[z].du++;
  }
  queue<int> lie;
  for(int i = 1;i<=n;++i)
  {
    if(dd[i].du == 0)
    {
     lie.push(i);
    }
  }
  vector<int> ans;

  while(!lie.empty())
  {
    int now = lie.front();
    lie.pop();
    ans.push_back(now);

    for(int k:dd[now].zi){
      dd[k].du--;
      if(dd[k].du==0)lie.push(k);
    }
  }
  if(ans.size()!=n)cout << -1;
  else{
    for(int i = 0;i<n;++i)
    {
      cout << ans[i];
      if(i!=n-1)cout << ' ';
    }
  }
}
