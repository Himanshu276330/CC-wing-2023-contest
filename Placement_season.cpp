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

int maxn = 1e5+10;

void solve(){
    int n; cin>>n;
    vi t(n);
    vi c(n);
    vi l(n);
    int T = 0;
    map<int, pair<int, int> > m;
    rep(i,0,n){
        cin>>t[i]>>c[i]>>l[i];
        m[t[i]] = {c[i], l[i]};
        T = max(T, t[i]);
    }

    int dp[5][maxn];
    rep(i,0,5){
        rep(j,0,maxn) dp[i][j] = -1e18;
    }
    dp[0][0] = 0;
    rep(i,1,T+1){
        rep(j,0,5){
            dp[j][i] = dp[j][i-1];
            if(m[i].first != j){
                continue;
            }
            
            rep(k,0,5){
                if(j == k){
                    dp[j][i] = max(dp[j][i], dp[j][i-1] + m[i].second);
                    continue;
                }
                if(i - abs(j - k) >= 0){
                    dp[j][i] = max(dp[j][i], dp[k][i-abs(j-k)] + m[i].second);
                }
            }
        }
    }
    // rep(i,0,T+1){
    //     cout<<dp[0][i]<<" "<<dp[1][i]<<" "<<dp[2][i]<<" "<<dp[3][i]<<" "<<dp[4][i]<<"\n";
    // }
    int ans = 0;
    rep(i,0,5) ans = max(ans, dp[i][T]);
    cout<<ans<<"\n";
}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
    int t = 1; 
    // cin>>t;
    for(int i = 1; i<=t; i++){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-6 << "ms\n"; 
    return 0;
}