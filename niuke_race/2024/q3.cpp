#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> x_coords(m), y_coords(m);
    
    unordered_map<int, vector<int>> x_map, y_map;
    int max_distance = 0;
    
    for (int i = 0; i < m; i++) {
        cin >> x_coords[i] >> y_coords[i];
        
        // 同时处理x和y坐标
        x_map[x_coords[i]].push_back(y_coords[i]);
        y_map[y_coords[i]].push_back(x_coords[i]);
    }
    
    // 处理x坐标相同的情况
    for (auto& pair : x_map) {
        if (pair.second.size() >= 2) {
            auto& vec = pair.second;
            max_distance = max(max_distance, *max_element(vec.begin(), vec.end()) - *min_element(vec.begin(), vec.end()));
        }
    }
    
    // 处理y坐标相同的情况
    for (auto& pair : y_map) {
        if (pair.second.size() >= 2) {
            auto& vec = pair.second;
            max_distance = max(max_distance, *max_element(vec.begin(), vec.end()) - *min_element(vec.begin(), vec.end()));
        }
    }
    
    cout << max_distance << endl;
    return 0;
}