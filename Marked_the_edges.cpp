#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define inf 1e18
#define f first
#define s second
#define pi pair<int, int>
#define vi vector<int>
#define vs vector<string>
#define vpi vector<pi>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vvpi vector<vpi>
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repr(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n" // for interactive comment it.
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// cout<<fixed<<setprecision(12)
// memset(dp,-1,sizeof(dp));

void debug(string ty,int val){ cerr<<ty<<":"<<val<<" ";}
void debug(string ty,string val){cerr<<ty<<":"<<val<<" ";}
void debug(int ty,string val){cerr<<ty<<":"<<val<<" ";}
void debug(int ty,int val){cerr<<ty<<":"<<val<<" ";}
void debug(int ty,vi &arr){
	cerr<<ty<<": ";
	for(auto it:arr){
		cerr<<it<<" ";
	}cerr<<endl;
}
void debug_endl(){cerr<<endl;}
 
int _ceil(int a, int b){
	if (a % b == 0) return a / b;
	return a / b + 1;
}

int _gcd(int a,int b){
	if(a==0) return b;
	return _gcd(b%a,a);
}

int mod = 1e9+7;
int _pow(int a, int p){
	int res = 1;
	while (p > 0){
		if (p & 1){
			res = (res * a)%mod;
		}
		p = p >> 1;
		a = (a * a) % mod;
	}
	return res;
}

// bool _large_mod(string &str,int n){
//     int cur=0;
//     for(char ch:str){
//         cur=cur*10+(ch-'0');
//         cur%=n;
//     }
//     return cur==0;
// }

int _find(int cur, vi &par){
	if (par[cur] == -1) return cur;
	return par[cur] = _find(par[cur], par);
}

// const int N=2e5;
// int fact[N+1];

// int ncr(int n,int r){
// 	int res=fact[n];
// 	res=(res*_pow(fact[n-r]))%mod;
// 	res=(res*_pow(fact[r]))%mod;
// 	return res;
// }

int findRoot(vector<int>& treeArr, int node) {
    if (treeArr[node] == node)
        return node;
    int temp = findRoot(treeArr, treeArr[node]);
    treeArr[node] = temp;
    return temp;
}

void solve(int A, vector<vector<int>>& B) {
    vector<int> kings(A + 1);
    for (int i = 0; i <= A; i++) {
        kings[i] = i;
    }

    for (int i = 0; i < B.size(); i++) {
        // Adding fourth parameter as index
        B[i].push_back(i);
    }

    sort(B.begin(), B.end(), [](const vector<int>& o1, const vector<int>& o2) {
        // Sort on weight
        return o1[2] < o2[2];
    });

    vector<int> ans(B.size(), 0);

    for (int i=0;i<B.size();i++) {
        
        int p1 = findRoot(kings, B[i][0]);
        int p2 = findRoot(kings, B[i][1]);

        if (p1 != p2) {
            int j=i;
            while(j<B.size() && B[j][2]==B[i][2]){
                // Marked 1 with same weight.
                //must not connected yet.
                if(findRoot(kings, B[j][0])!=findRoot(kings, B[j][1])) ans[B[j][3]]=1;
                j++;
            }
            j=i;
            while(j<B.size() && B[j][2]==B[i][2]){
                int pp1 = findRoot(kings, B[j][0]);
                int pp2 = findRoot(kings, B[j][1]);
                
                if(pp1!=pp2){
                    kings[pp2] = pp1;
                }
                j++;
            }
            i=j-1;
        }
    }
    for(int i=0;i<B.size();i++){
		cout<<ans[i]<<" ";
	}cout<<endl;
}


void solve(){
	int n,m;
	cin>>n>>m;

	vvi egdes;
	rep(i,0,m){
		int a,b,c;
		cin>>a>>b>>c;
		egdes.push_back({a,b,c});
	}
	solve(n,egdes);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("/Users/shekharh433/Desktop/Code/input.txt", "r", stdin);
    freopen("/Users/shekharh433/Desktop/Code/output.txt", "w", stdout);
    #endif

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i) {
		solve();
    }

    return 0;
}


 
// implementation
// greedy
// prefix suffix
// math
// binary
// dp
// randomisation

// g++ -std=c++17 AA.cpp -o AA; ./AA
// "/Users/shekharh433/Desktop/Code/AAAAAAA/" && g++ -std=c++17  AA.cpp -o AA && "/Users/shekharh433/Desktop/Code/AAAAAAA/"AA