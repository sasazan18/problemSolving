#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pb push_back
#define sor(n) sort(n.begin(),n.end())
#define pii pair<int,int>
#define YES cout << "YES"<<endl
#define NO cout << "NO"<<endl
#define mod 1000000007
#define SQR(a) (a)*(a)
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
ll powmod(ll a, ll b){ll ans = 1;while(b){if(b&1) ans = ans*a%mod;a = a*a%mod;b >>= 1;}return ans;}
#define mxn 200005

void solve()
{
    cout<<"Learning git!"<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test=1;
    //cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
