#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define ll              long long int
#define fo(i,a,n)       for(ll i=a;i<n;i++)
#define rfo(i,a,n)      for(ll i=n-1;i>=a;i--)
#define all(a)          a.begin(),a.end()
#define pb              push_back
#define mp              make_pair
#define vll             vector<ll>
#define pll             pair<ll,ll>
#define mll             map<ll,ll>
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define ri              reverse_iterator
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define MOD             1000000007
#define inf             1e18
#define ite(a)          for(auto &x : a)
#define read(a)         ite(a) cin>>x;
#define fast            ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define what_is(x)      cerr << #x << " is " << x << endl;
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


//function
// ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
// void google(int t) {cout << "Case #" << t << ": ";}
// vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
// ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
// ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
// ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
// ll ceiling(ll n,ll m) {if(n%m==0)return n/m; else return n/m+1;}
// ll fact(ll n){ll res = 1;for (ll i = 2; i <= n; i++)res = res * i;return res;}
// ll nCr(ll n, ll r){return fact(n) / (fact(r) * fact(n - r));}
// bool isprime(ll n){for(ll i = 2; i * i <= n; i++){if(n % i == 0){return 0;}}return 1;}
void r_p_p()
{
    #ifndef ONLINE_JUDGE
        freopen("in1f.txt", "r", stdin);
        freopen("output3f.txt", "w", stdout);
    #endif
} 
void solve()
{
	ll n,m;
	cin>>n>>m;
	ll a[n];
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
    int dp[n+2][m+2];
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++){
    	for(int j=1; j<=m; j++){
    		if(i==1){
    			if(a[i]==0 || a[i]==j){
    				dp[i][j] = 1;
    			}
    			else{
    				dp[i][j] = 0;
    			}
    		}
    		else{
    			if(a[i]==0 || a[i]==j){
    				dp[i][j] = ((dp[i-1][j-1] + dp[i-1][j])%MOD + dp[i-1][j+1])%MOD;
    			}
    			else{
    				dp[i][j] = 0;
    			}
    		}
    	}
    }
    int ans = 0;
    for(int i=1; i<=m; i++){
    	ans = (ans + dp[n][i])%MOD;
    }
    cout<<ans<<endl;
}
int32_t main()
{
    r_p_p();
    fast;
    ll TC=1;
    // cin>>TC;
    for(ll i=1; i<=TC; i++)
    {
        solve();
    }
    return 0;
}