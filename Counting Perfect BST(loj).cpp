//problems on catalan number

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
#define mod 100000007
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define bug cout<<"Here"<<endl
void fastio(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
ll powmod(ll a, ll b){ll ans = 1;while(b){if(b&1) ans = ans*a%mod;a = a*a%mod;b >>= 1;}return ans;}

#define mxn 2000005
ll fact[mxn];
vector<ll>v;


void cal_fact()
{
    fact[0]=1;
    fact[1]=1;

    for(int i=2;i<mxn;i++)
    {
        fact[i]=(i%mod)*(fact[i-1]%mod);
        fact[i]%=mod;
    }
}
;

void cal_num()
{

    unordered_map<ll,ll>mp;

    for(ll i=2;i<=100001;i++)
    {
        for(ll j=2;;j++)
        {
            ll temp=POW(i,j);
            if(temp>10000000000)
                break;

           if(mp[temp]==0)
           {
               v.pb(temp);
               mp[temp]++;
           }

        }
    }


    sor(v);




}





int main()
{
     fastio();

	 cal_fact();

	 cal_num();




	 int t;
	 cin>>t;





	 for(int tc=1;tc<=t;tc++)
     {
         ll a,b;
         cin>>a>>b;

         cout<<"Case "<<tc<<": ";


         int pos1=upper_bound(v.begin(),v.end(),a-1)-v.begin();
         int pos2=upper_bound(v.begin(),v.end(),b)-v.begin();

         if(pos1==pos2)
         {
             cout<<0<<endl;
             continue;
         }

         int n=pos2-pos1;

         // finding catalan number
         // 2n c n / (n+1)


         ll ans=fact[2*n] * powmod(fact[n],mod-2);
         ans%=mod;

         ans=ans * powmod(fact[n],mod-2);
         ans%=mod;

         ans=ans* powmod(n+1,mod-2);
         ans%=mod;

         cout<<ans<<endl;






     }







	return 0;
}

