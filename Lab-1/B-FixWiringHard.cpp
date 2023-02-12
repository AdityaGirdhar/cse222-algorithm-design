#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define ll long long int

ll mergeAndCount(vector<ll>& nums, ll l, ll mid, ll r) {
    vector<ll> v1, v2;
    for (ll i=l; i<=mid; i++) v1.push_back(nums[i]);
    for (ll i=mid+1; i<=r; i++) v2.push_back(nums[i]);

    ll i=l; ll j=mid+1; ll ptr = l;
    ll count = 0;
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

ll countInversion(vector<ll>& nums, ll i, ll j) {
    if (i >= j) return 0;
    ll mid = i + (j-i)/2;
    ll l = countInversion(nums, i, mid);
    ll r = countInversion(nums, mid+1, j);
    ll m = mergeAndCount(nums, i, mid, j);
    return l+m+r;
}

int main() {
    ll n, p, q; cin >> n;
    map<ll, multiset<ll>> map;
    // vector<multiset<ll>> v(n);
    // for (ll i = 0; i < n; i++) {
    //     multiset<ll> st; v[i] = st;
    // }
    for (ll i = 0; i < n; i++) {
        ll p; cin >> p;
        ll q; cin >> q;
        if (map.find(p) == map.end()) {
            multiset<ll> st;
            map[p] = st;
        }
        map[p].insert(q);
    }

    vector<ll> in;
    for (auto el : map) {
        for (ll i : el.second) in.push_back(i);
    }
    // for (ll i : in) cout << i << ' ';
    // cout << '\n';
    cout << countInversion(in, 0, n-1);
}
