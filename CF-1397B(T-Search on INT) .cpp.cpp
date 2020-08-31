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





vector<ll>arr;
int n;

ll cost(ll mid)
{



    ll tot=0;
    ll temp=1;

    tot+= (arr[0]-temp);

    for(int i=1;i<n;i++)
    {
        if((1e18/temp)<mid) return 1e18;
        temp*=mid;
        tot+= abs(arr[i]-temp);
    }

    return tot;
}




//binary search on Integer


int main()
{


    fastio();


    cin>>n;

    for(int i=0;i<n;i++) {
        ll x;
        cin>>x;
        arr.pb(x);
    }

    sor(arr);


    ll lo=1,hi=1e18;
    ll ans=1e18+10;


    while(hi-lo>1)
    {
      ll mid1=lo+(hi-lo)/3;
      ll mid2=hi-(hi-lo)/3;

      ll cost1=cost(mid1);
      ll cost2=cost(mid2);



      if(cost1>cost2)
      {

          lo=mid1+1;
          if(cost2<ans) ans=cost2;

      }
      else
      {
          hi=mid2-1;
          if(cost1<ans )  ans=cost1;
      }


    }


    cout<<ans<<endl;




	return 0;
}

