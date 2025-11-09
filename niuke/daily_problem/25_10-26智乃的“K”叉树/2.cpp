#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> degree(n + 1, 0);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    int max_deg = 0,second_max_deg = 0;
    int max_count = 0;

    for (int i = 1; i <= n;++i){
        if(degree[i] > max_deg){
            second_max_deg = max_deg;
            max_deg = degree[i];
            max_count = 1;
        }else if(degree[i] == max_deg)
            max_count++;
        else if(degree[i] > second_max_deg)
            second_max_deg = degree[i];
    }

    int min_k = INT_MAX;
    int best_root = 1;

    for (int r = 1;r<=n;r++){
        int k_r;
        if(degree[r] < max_deg){
            k_r = max(degree[r],max_deg - 1);
        }else{
            if(max_count == 1)
                k_r = max(max_deg,second_max_deg - 1);
            else
                k_r = max_deg;
        }

        if(k_r < min_k || (k_r == min_k && r < best_root)){
            min_k = k_r;
            best_root = r;
        }
    }
    cout << min_k << " " << best_root << endl;
    return 0;
}