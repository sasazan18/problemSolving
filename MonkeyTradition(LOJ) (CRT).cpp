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
#define pb push_back
#define sor(n) sort(n.begin(),n.end())
#define sorcmp(n) sort(n.begin(),n.end(),cmp)
#define rev(n) reverse(n.begin(),n.end())
#define en() printf("\n");
#define random_shuffle(r...)random_shuffle(r,[](int _){return rand()%_;})
#define sp(x) fixed<<setprecision(x)
#define mod 1000000007
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define bug cout<<"Here"<<endl
void fastio(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
ll powmod(ll a, ll b){ll ans = 1;while(b){if(b&1) ans = ans*a%mod;a = a*a%mod;b >>= 1;}return ans;}

vector< pair<ll,ll> > equation ;  /// this will contain the value of ai and mi



ll egcd(ll a, ll b , ll &x ,ll &y)
{

    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }

    ll x1,y1;

    ll d= egcd( b,a%b,x1,y1 ) ;

    x=y1;

    y=x1 - y1 * (a/b);

    return d;


}


pair<ll,ll> CRT()  /// it will return a  {x, N} pair, where x is the unique solution modulo N.
{

    if(equation.size()==0)  return {-1,-1}; ///No equations to solve

    ll a1= equation[0].first;
    ll m1= equation[0].second;

    a1%=m1;

     /** Initially x = a1 (mod m1)**/

    /** merging the solution with the remaining equatuions **/


   for(int i=1;i<equation.size();i++)
   {

       ll a2= equation[i].first;
       ll m2= equation[i].second;

       ll g= __gcd(m1,m2);

       if(a1%g!=a2%g) return {-1,-1} ; // conflict in equation

       /** Merge the two equations **/

       ll p,q;

       ll gcd=egcd(m1/g, m2/g, p, q);

       ll MOD= m1/g * m2 ; /// lcm(m1,m2)

       ll x = ( (__int128)a1 * (m2/g) % MOD *q % MOD + (__int128)a2 * (m1/g) % MOD * p % MOD ) % MOD;

       ///Merged equation

       a1=x;

       if(a1<0) a1+=MOD;

       m1=MOD;


   }


   return {a1,m1};




}

int main()
{

    fastio();

	int t;
	cin>>t;
	int tc=1;
	while(t--)
	{

	    int n;
	    cin>>n;

	    for(int i=0;i<n;i++){

            ll x,y;
            cin>>x>>y;

            equation.pb({y,x});

	    }

	    pll p = CRT();

	   cout<<"Case "<<tc<<": ";

	   if(p.first==-1) cout<<"Impossible"<<endl;
	   else cout<<p.first<<endl;





	    equation.clear();
	    ++tc;

	}







	return 0;
}


/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/

