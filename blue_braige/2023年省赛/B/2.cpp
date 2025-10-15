#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<long,long> pii;
#define int ll
const int dx[9]={-1, 0, 1, 0, 1, -1, 1, -1,0};
const int dy[9]={0, 1, 0, -1, -1, 1, 1, -1,0};
#define INF 0x3f3f3f3f
const int N=2e5+10;
int ans=0;
void dfs(int grade,int index)
{
	if(grade==70) ans++;
	if(grade==100) return;
	if(index==30) return;
	dfs(grade+10,index+1);
	dfs(0,index+1);
}
void solve()
{
	dfs(0,0);
    cout << ans << endl;
	return;
}
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}