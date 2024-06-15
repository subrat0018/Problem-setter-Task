#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Map to store the count of differences arr[i] - i
    unordered_map<long long, long long> countMap;
    
    // Calculate the differences arr[i] - i and store their counts in countMap
    for (int i = 0; i < n; ++i) {
        long long diff = arr[i] - i;
        countMap[diff]++;
    }
    
    long long beautifulTriplets = 0;
    
    // Iterate over the countMap to calculate the number of beautiful triplets
    for (auto& it : countMap) {
        long long count = it.second;
        
        // If there are at least 3 elements with the same difference, calculate combinations C(count, 3)
        if (count >= 3) {
            beautifulTriplets += (count * (count - 1) * (count - 2)) / 6;
        }
    }
    
    // Output the total number of beautiful triplets for the current test case
    cout << beautifulTriplets << "\n";
}

int main() {
    solve();
    
    return 0;
}

