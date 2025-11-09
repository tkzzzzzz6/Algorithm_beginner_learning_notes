
//»¹ÊÇ³¬Ê±
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int minFlips(vector<int> arr) {
    int n = arr.size();

    vector<int> target = arr;
    sort(target.begin(), target.end());

    if (arr == target)return 0;

    queue<pair<vector<int>, int>>q;
    map<vector<int>, bool>visited;

    q.push({arr,0});
    visited[arr] = true;

    while (!q.empty()) {
        auto [curr, steps] = q.front();
        q.pop();
        
        for (int k = 2; k <= n; ++k) {
            vector<int> next = curr;
            reverse(next.begin(), next.begin() + k);

            if (next == target)return steps + 1;

            if (!visited[next]) {
                visited[next] = true;
                q.push({ next,steps + 1 });
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;

    vector<int> redius(n);

    for (int i = 0; i < n; ++i)cin >> redius[i];

    cout << minFlips(redius) << '\n';


    return 0;
}