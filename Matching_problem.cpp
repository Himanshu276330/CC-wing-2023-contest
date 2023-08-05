#include <bits/stdc++.h>
using namespace std;
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define int long long
#define pb push_back
#define rep(i,a,b) for(int i = a; i < b; i++)
#define all(x) x.begin(),x.end()
#define in(a) for(int i = 0; i<a.size(); i++) cin>>a[i];
#define out(a) for(int i = 0; i<a.size(); i++) cout<<a[i]<<" ";
typedef vector<int> vi;
#define sqrt(x) sqrtl(x)
#define ret(a) cout<<a<<"\n"; return

void solve(){
    int n; cin>>n;
    vi a(n);
    in(a);
    vi b(n);
    in(b);
    map<int,int> m;
    rep(i,0,n) m[a[i]] = i;
    map<int,int> rots;
    int ans = 0;
    rep(i,0,n){
        if(m.find(b[i]) == m.end()) continue;
        int req = i - m[b[i]] + n;
        req %= n;
        rots[req]++;
    } 
    int final = 1e9;
    rep(i,0,n){
        final = min(final, n - rots[i] + i);
    }
    ret(final);
}   
 
int32_t main() {    
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
    int t = 1; 
    cin>>t;
    for(int i = 1; i<=t; i++){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-6 << "ms\n"; 
    return 0;
}