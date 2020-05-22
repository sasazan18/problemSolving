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
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}




#define mxn (ll) 101
ll arr[mxn][mxn];
ll I[mxn][mxn];
ll n;

void  multiply(ll a[][mxn] ,ll b[][mxn])
{

    ll res[n][n];

    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
        {
            res[i][j]=0LL;

            for(ll k=0; k<n; k++)
            {
                res[i][j]=res[i][j]%mod + (((a[i][k]%mod)*(b[k][j])%mod)%mod)%mod;
                res[i][j]%=mod;
            }
        }
    }



   for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
        {
            a[i][j]=res[i][j];
        }
    }

    return ;


}



void power(ll m)
{

    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
        {
            if(i==j)
                I[i][j]=1LL;
            else
                I[i][j]=0LL;
        }
    }

    while(m)
    {
        if(m%2)
        {
            multiply(I,arr);
            m--;
        }
        else multiply(arr,arr),m/=2L;
    }


     for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<n; j++)
                arr[i][j]=I[i][j];
        }
}



int main()
{

    fastio();
    ll t;
    cin>>t;
    while(t--)
    {
        ll m;
        cin>>n>>m;

        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<n; j++)
                cin>>arr[i][j];
        }

        power(m);

         for(ll i=0; i<n; i++)
        {
                for(ll j=0; j<n; j++)
                {
                    cout<<arr[i][j];
                    if(j!=n-1) cout<<" ";
                }
                cout<<endl;

        }

          for(ll i=0; i<n; i++)
        {
                for(ll j=0; j<n; j++)
                   {
                       arr[i][j]=0LL;
                       I[i][j]=0LL;
                   }

        }




    }




    return 0;
}
