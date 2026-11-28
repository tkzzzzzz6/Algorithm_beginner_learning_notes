#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1010;
typedef long long ll ;
int n,m,q;
ll mat[N][N];
/**
 * @brief Entry point for the 2D prefix sum solver.
 *
 * Reads matrix dimensions, constructs the cumulative sum table `mat`
 * using inclusion-exclusion, then answers `q` submatrix sum queries by
 * outputting the range sum for the requested coordinates.
 *
 * @return Exit status code.
 */
int main() {
    scanf("%d%d%d", &n,&m,&q);
    int tmp;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%d", &tmp);
            mat[i][j] = mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1]+tmp;
            
        }
    }
    int x1, y1, x2, y2;
    for(int i = 1; i <= q; i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%lld\n", mat[x2][y2]-mat[x2][y1-1]-mat[x1-1][y2]+mat[x1-1][y1-1]);
    }


    return 0;
}
// 64 位输出请用 printf("%lld")
