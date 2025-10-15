#include <iostream>
#include <vector>

using namespace std;

// 初始化平0,输-1,赢1
int R[5][5] = {
    0, -1, 1, 1, -1,
    1, 0, -1, 1, -1,
    -1, 1, 0, -1, 1,
    -1, -1, 1, 0, 1,
    1, 1, -1, -1, 0};

int main()
{
    int N, NA, NB;
    cin >> N >> NA >> NB;
    vector<int> A(NA), B(NB);
    for (int i = 0; i < NA; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < NB; i++)
    {
        cin >> B[i];
    }

    int scoreA = 0, scoreB = 0;
    int i = 0, j = 0;
    while (N--)
    {
        if (i == NA)
        {
            i = 0;
        }
        if (j == NB)
        {
            j = 0;
        }
        int result = R[A[i]][B[j]];
        if (result == 1)
        {
            scoreA++;
        }
        else if (result == -1)
        {
            scoreB++;
        }
        i++;
        j++;
    }

    cout << scoreA << " " << scoreB << endl;

    return 0;
}
