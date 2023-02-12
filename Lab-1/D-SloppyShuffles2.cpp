#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define ll long long int

bool isShuffle(string A, string B) {
    if (A.size() == 1) {
        if (A[0] == B[0]) return true;
        return false;
    }
    if (A.size()%2 == 1) {
        return false;
    }
    if (A == B) return true;
 
    int mid = A.size()/2;
    string A1 = A.substr(0, mid);
    string A2 = A.substr(mid, mid);
    string B1 = B.substr(0, mid);
    string B2 = B.substr(mid, mid);
 
    return (
        (isShuffle(A1, B1) && isShuffle(A2, B2)) ||
        (isShuffle(A1, B2) && isShuffle(A2, B1))
        );
}
 
void solve() {
    int n; cin >> n;
    string A, B;
    cin >> A >> B;
    
    cout << ((isShuffle(A, B)) ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
