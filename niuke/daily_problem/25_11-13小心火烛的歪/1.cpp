#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<string> grass;
vector<vector<string>> plans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int i, j, k, n, m, q, mask;
    cin >> n >> m >> q;

    grass.resize(n);
    plans.resize(q, vector<string>(n));

    for (i = 0; i < n; ++i)
        cin >> grass[i];

    for (k = 0; k < q; ++k)
        for (i = 0; i < n; ++i)
            cin >> plans[k][i];

    int min_cnt = 1000;

    int best_mask = -1;

    for (mask = 0; mask < (1 << q); ++mask)
    {
        vector<vector<int>> res(n, vector<int>(m, 0));

        for (k = 0; k < q; ++k)
        {
            if (mask & (1 << k))
            {
                for (i = 0; i < n; ++i)
                {
                    for (j = 0; j < m; ++j)
                        if (plans[k][i][j] == '1')
                            res[i][j] = 1;
                }
            }
        }
    }

    int vaild = 1;
    for (i = 0; i < n && valid; ++i)

        return 0;
}
