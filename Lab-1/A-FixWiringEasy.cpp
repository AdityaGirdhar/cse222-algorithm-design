#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define ll long long int

int mergeAndCount(vector<int>& nums, int l, int mid, int r) {
    vector<int> v1, v2;
    for (int i=l; i<=mid; i++) v1.push_back(nums[i]);
    for (int i=mid+1; i<=r; i++) v2.push_back(nums[i]);

    int i=l; int j=mid+1; int ptr = l;
    int count = 0;
    while (i < mid+1 && j < r+1 && ptr < nums.size()) {
        if (v1[i-l] <= v2[j-(mid+1)]) {
            nums[ptr] = v1[i-l]; i++;
        } else {
            nums[ptr] = v2[j-(mid+1)];
            count += (mid+1-i);
            j++;
        }
        ptr++;
    }
    while (i < mid+1 && ptr < nums.size()) {
        nums[ptr] = v1[i-l]; i++; ptr++;
    }
    while (j < r+1 && ptr < nums.size()) {
        nums[ptr] = v2[j-(mid+1)]; j++; ptr++;
    }
    return count;
}

int countInversion(vector<int>& nums, int i, int j) {
    if (i >= j) return 0;
    int mid = i + (j-i)/2;
    int l = countInversion(nums, i, mid);
    int r = countInversion(nums, mid+1, j);
    int m = mergeAndCount(nums, i, mid, j);
    return l+m+r;
}

int main() {
    int n, p, q; cin >> n;
    map<int, multiset<int>> map;
    // vector<multiset<int>> v(n);
    // for (int i = 0; i < n; i++) {
    //     multiset<int> st; v[i] = st;
    // }
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        int q; cin >> q;
        if (map.find(p) == map.end()) {
            multiset<int> st;
            map[p] = st;
        }
        map[p].insert(q);
    }

    vector<int> in;
    for (auto el : map) {
        for (int i : el.second) in.push_back(i);
    }
    // for (int i : in) cout << i << ' ';
    // cout << '\n';
    cout << countInversion(in, 0, n-1);
}
