#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

int n;                      //
vector<int> target_state;   // Ŀ״̬ʵδʹãΪĿ [1,2,3,...,n]
int max_depth;              // IDA* ǰ

/**
 * ʽƴӵǰ״̬Ŀ״̬Ҫٲ
 *
 * ԭ"ϵ"
 * - ϵ㣺̵ıŲ 1˵Ŀ״̬вڣ
 * - ÿηת 2 ϵ
 * - ˣ貽  ceil(ϵ / 2)
 *
 * 磺[3, 1, 2, 4]
 *   - 3  1 ֮䣺|3-1|=2  1  ϵ
 *   - 1  2 ֮䣺|1-2|=1 = 1  Ƕϵ
 *   - 2  4 ֮䣺|2-4|=2  1  ϵ
 *   - 4 λ(Ӧ)  ϵ
 *   ܹ 3 ϵ㣬Ҫ ceil(3/2) = 2
 */
int heuristic(const vector<int>& state) {
    int breakpoints = 0;

    // ֵ nǷײĩβ
    // ڣ˵ֵҪƶһϵ
    if (state.back() != n) {
        breakpoints++;
    }

    // ԪأǵıǷ
    for (int i = 0; i < n - 1; ++i) {
        // ԪرŲ 1˵Ŀ״̬в
        // Ҫͨתһϵ
        if (abs(state[i] - state[i + 1]) != 1) {
            breakpoints++;
        }
    }

    return breakpoints;
}

/**
 * תתǰ k Ԫ
 *
 * @param arr Ҫת飨ֵݣ޸ԭ飩
 * @param k תǰ k Ԫ
 * @return ת
 *
 * 磺flip([3, 1, 2, 4], 3)  [2, 1, 3, 4]
 */
vector<int> flip(vector<int> arr, int k) {
    reverse(arr.begin(), arr.begin() + k);
    return arr;
}

/**
 * DFS+ ֦
 *
 * IDA* ģ޶
 * ֦g + h(state) > max_depth"ò + ʣಽ > "
 *
 * @param state ǰ״̬У
 * @param g 㵽ǰ״̬Ѿ˶ٲʵʴۣ
 * @param prev_flip һηתλ kظת k  k  صԭ״̬
 * @return Ƿڵǰҵ
 */
bool dfs(const vector<int>& state, int g, int prev_flip) {
    // ʽֵƻҪٲ
    int h = heuristic(state);

    // ֦"ò + Ʋ"ƣ·
    //  IDA* ĺģʽ֦
    if (g + h > max_depth) {
        return false;
    }

    // Ŀ⣺ʽֵΪ 0˵ѾﵽĿ״̬ [1,2,3,...,n]
    // ûжϵ = Ԫض =
    if (h == 0) {
        return true;  // ҵ⣡
    }

    // пܵķת
    // k=2: תǰ 2 Ԫ
    // k=3: תǰ 3 Ԫ
    // ...
    // k=n: ת
    for (int k = 2; k <= n; ++k) {
        // ֦Żηתͬһλ
        // Ϊ flip(k)  flip(k) صԭ״̬Ч
        if (k == prev_flip) continue;

        // ״ִ̬зת
        vector<int> next_state = flip(state, k);

        // ݹ״̬
        // g+1:  1
        // k: ¼ηתλã´αظת
        if (dfs(next_state, g + 1, k)) {
            return true;  // ҵ⣬Ϸ
        }
    }

    // пܶԹˣûҵ
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // ȡ
    cin >> n;
    vector<int> start_state_raw(n);    // ԭʼ루ʵʰ뾶ֵ
    vector<int> sorted_unique(n);      // ɢ

    for (int i = 0; i < n; ++i) {
        cin >> start_state_raw[i];
        sorted_unique[i] = start_state_raw[i];
    }

    // ========== ɢ ==========
    // ΪʲôҪɢ
    // ԭʼǣ[87, 75, 19, 49, 46, ...]ʵʰ뾶ֵ
    // ֻԴСϵľֵ
    // ɢ󣺽ӳΪ 1, 2, 3, ..., n
    // Ŀ״̬ǹ̶ [1, 2, 3, ..., n]жϺ

    // һ򣬵õС˳
    sort(sorted_unique.begin(), sorted_unique.end());
    // 磺[87, 75, 19, ...]    [1, 5, 11, 19, ...]

    // ڶӳԭʼֵ
    map<int, int> val_to_rank;
    for (int i = 0; i < n; ++i) {
        val_to_rank[sorted_unique[i]] = i + 1;
        // Сֵ   1
        // Сֵ   2
        // ...
        // ֵ   n
    }

    // ԭʼ״̬תΪʾ
    vector<int> start_state(n);
    for (int i = 0; i < n; ++i) {
        start_state[i] = val_to_rank[start_state_raw[i]];
    }
    // 磺[87, 75, 19, ...]  [14, 13, 3, ...] (ݴС)

    // ========== IDA*  ==========
    // ʲô IDA*
    // - ˵ID A*
    // -  d=0 ʼҲ⣬ӵ d=1, d=2, ...
    // - ÿڣ DFS + ʽ֦
    // - ŵ㣺ռ临ӶȵͣDFSʱʽ

    // ʽֵʼ
    // ʼ max_depth = h(start_state)Ҫôಽ
    for (max_depth = heuristic(start_state); ; ++max_depth) {
        //  max_depth
        // ʼ״̬ò 0һηתλ 0ʾûУ
        if (dfs(start_state, 0, 0)) {
            // ҵ⣡ȣٷת
            cout << max_depth << endl;
            break;
        }
        // ڵǰҲȼ
        // max_depth++ һѭִ
    }

    return 0;
}
