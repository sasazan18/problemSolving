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



long double a,b,c,d;

long double func(long double x)
{
     long double temp=a*powl(x,3.0)+b*powl(x,2.0)+c*x+d;
     return temp;
}


long double df(long double x)   // derivative value of the equation
{
    long double temp=3*a*x*x+2*b*x+c;
    return temp;
}




void newtonRaphson(long double x)
{
    long double h ;
    long double err=1;
    while (err >= 0.00000000001)    // X(n+1)=Xn-(f(x) / f'(x))  ///Xn+1= new root and Xn=previous root

    {
        h = func(x)/df(x);
        long double nx = x - h;

        err= abs(nx-x)/abs(x);    // check the relative error between the two roots .
        x=nx;                     //if the relative error is less than eps than it will break ;


    }
    cout<<sp(6)<<x<<endl;
}



int main(){


     //ax3 + bx2 + cx + d = 0 (a ≠ 0).
     //find the real root

     cin>>a>>b>>c>>d;

     newtonRaphson(-1000);   //guessed root will be passed to the function














return 0;
}

