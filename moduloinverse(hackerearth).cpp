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
#define mod 1000000007
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define bug cout<<"Here"<<endl
void fastio(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
ll powmod(ll a, ll b){ll ans = 1;while(b){if(b&1) ans = ans*a%mod;a = a*a%mod;b >>= 1;}return ans;}



ll power(ll n,ll p)
{
    ll res=1;

    while(p){
        if(p%2)
        {
            res= (res*n)%mod;
            p--;
        }
        else
        {
            n=(n*n);
            n%=mod;
            p/=2;
        }
    }
    return res;

}


vector<int> primeFactorize( int n )
{
    vector<int>List;
    int sqrtN = int( sqrt(n) );
    for( int i = 2; i <= sqrtN; i++ )
    {
        if( n % i == 0 )
        {

            while( n % i == 0 )
            {
                n /= i;
                List.pb(i);

            }

        }
    }
    if( n > 1 )
    {

        List.pb(n) ;

    }

    return List;

}

bool isprime(ll x)
{
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0) return false;
    }
    return true;
}


ll coprime(ll x)
{
    if(isprime(x))
    {
        return x-1;
    }
    else
    {
        vector<int>v=primeFactorize(x);

         map<int,int>mp;

         for(auto u:v)
         {
             mp[u]++;
         }

         ll ans=1;

         for(auto u:mp)
         {
             ans*= POW(u.first,u.second-1)*(u.first-1);
         }

         return ans;
    }
}



int main(){

    fastio();
    ll n,MOD;

    cin>>n>>MOD;


    ll phi=coprime(MOD);

    cout<<power(n,phi-1)<<endl;





return 0;
}
