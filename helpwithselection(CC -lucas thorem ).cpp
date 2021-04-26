#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define si(n) scanf("%d",&n);
#define PI acos(-1.0)
#define sl(n) scanf("%lld",&n);
#define sf(n) scanf("%lf",&n);
#define ss(n) scanf("%s",n);
#define for0(i,n) for(ll i=0;i<n;i++)
#define for1(i,n) for(ll i=1;i<=n;i++)
#define forc(i,j,n) for(ll i=j;i<n;i++)
#define pb push_back
#define sor(n) sort(n.begin(),n.end())
#define sorcmp(n) sort(n.begin(),n.end(),cmp)
#define rev(n) reverse(n.begin(),n.end())
#define pi(x)  printf("%d",x);
#define pl(x)  printf("%lld",x);
#define pf(x)  printf("%.10lf",x);
#define ps(x)  printf("%s",x);
#define en() printf("\n");
#define random_shuffle(r...)random_shuffle(r,[](int _){return rand()%_;})
#define SQR(a) (a)*(a)
#define sp(x) fixed<<setprecision(x)
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define bug cout<<"Here"<<endl
void fastio(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
ll powmod(ll a, ll b,ll mod){ll ans = 1;while(b){if(b&1) ans = ans*a%mod;a = a*a%mod;b >>= 1;}return ans;}


ll fact[100005];
ll inv[100005];

ll mul(ll a,ll b,ll mxn)
{

    return ( (a%mxn) * (b%mxn) ) % mxn;
}

inline ll bigmod(ll n,ll p,ll MOD)   //bigmod
{
    ll res=1;

    while(p){
        if(p%2)
        {
            res= ((res%MOD) *(n%MOD))%MOD;
            p--;
        }
        else
        {
            n= (n%MOD)*(n%MOD);
            n%=MOD;
            p/=2;
        }
    }
    return res;



}

void process(ll p)
{
    fact[0] = inv[0] = 1;

    ll mxn=p;

    for(int i=1; i<mxn; i++) fact[i] = mul(fact[i-1], i,mxn);
    inv[mxn - 1] = bigmod(fact[mxn - 1], mxn - 2,mxn);
    for(int i=mxn-2; i>=1; i--) inv[i] = mul(inv[i+1], (i + 1),mxn);
}


ll nCr_Lucas(ll n, ll r,ll p)
{
        vector<int>v1,v2;
        ll mxn=p;

        while(n)
        {
            v1.pb(n%mxn);
            n/=mxn;
        }

        while(r)
        {
            v2.pb(r%mxn);
            r/=mxn;
        }



        int l1=v1.size();
        int l2=v2.size();
        int need=l1-l2;


        while(need--)
        {
            v2.pb(0);

        }




        ll ans=1;

        for(int i=0;i<v1.size();i++)
        {
            if(v2[i]==0) continue;

            if(v2[i]>v1[i])
            {
                ans=0;
                break;
            }

            ll temp =mul(mul (fact[ v1[i] ] , inv[ v2[i] ],mxn) , inv[ v1[i]-v2[i] ],mxn);

            ans=mul(ans,temp,mxn);

        }

        return ans;
}

int main()
{
    fastio();
	int t;
	cin>>t;
	while(t--)
    {
        ll n,r,p;
        cin>>n>>r>>p;

        process(p);


        cout<<nCr_Lucas(n,r,p)<<endl;


    }






	return 0;
}


