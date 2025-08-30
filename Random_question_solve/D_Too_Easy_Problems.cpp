#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, t;
    cin >> n >> t;
    
    vector<int> skill(n), time(n), result;
    
    for (int i = 0; i < n; i++) {
        cin >> skill[i] >> time[i];
    }
    
    int low = 0, high = n;
    
    while (low < high) {
        int mid = (low + high + 1) / 2;
        
        vector<pii> candidates;
        
        for (int i = 0; i < n; i++) {
            if (skill[i] >= mid) {
                candidates.emplace_back(time[i], i);
            }
        }
        
        sort(candidates.begin(), candidates.end());
        
        bool isValid = false;
        
        if ((int)candidates.size() >= mid) {
            int totalTime = 0;
            
            for (int i = 0; i < mid; i++) {
                totalTime += candidates[i].first;
            }
            
            if (totalTime <= t) {
                isValid = true;
                result.resize(mid);
                
                for (int i = 0; i < mid; i++) {
                    result[i] = candidates[i].second + 1; // Convert to 1-based index
                }
            }
        }
        
        if (isValid) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    
    int finalSize = (int)result.size();
    
    cout << finalSize << "\n" << finalSize << "\n";
    
    for (int idx : result) {
        cout << idx << " ";
    }
    
    cout << "\n";
    
    return 0;
}
