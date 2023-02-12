#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
#define ll long long int
 
int diff(string& A, string& B) {
    int d = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != B[i]) d++;
    }
    return d;
}

int flipsRequired(string& A, string& B) {
    // Base case
    if (A == B) return 0;
    if (A.size()%2 == 1) {
        int d = diff(A, B);
        B = A; return d;
    }
 
    int mid = A.size()/2;
    string A1 = A.substr(0, mid);
    string A2 = A.substr(mid, mid);
    string Bl1 = B.substr(0, mid);
    string Br1 = B.substr(0, mid);
    string Bl2 = B.substr(mid, mid);
    string Br2 = B.substr(mid, mid);

    int m1 = flipsRequired(A1, Bl1) + flipsRequired(A2, Bl2);
    int m2 = flipsRequired(A1, Br2) + flipsRequired(A2, Br1);
    
    if (m1 <= m2) {
        B = Bl1 + Bl2;
        return m1;
    } else {
        B = Br1 + Br2;
        return m2;
    }
}
 
void solve() {
    int n; cin >> n;
    string A, B;
    cin >> A >> B;
    
    cout << flipsRequired(A, B) << '\n';
    for (char i : B) cout << i;
    cout << '\n';
}
 
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
