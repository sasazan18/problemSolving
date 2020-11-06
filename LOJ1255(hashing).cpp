
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

#define mxn 1000005
#define MOD (ll) 2000000063
ll base1=000000021 ,base2=1000000181;

char s[mxn],pat[mxn];

ll pw1[mxn],pw2[mxn];
ll h1[mxn],h2[mxn];


void pw_calc() //calculating power of base
{
    pw1[0]=1;
    pw2[0]=1;

    for(int i=1;i<mxn;i++)
    {
        pw1[i]= (pw1[i-1]* base1)%MOD;
        pw2[i]= (pw2[i-1]* base2)%MOD;
    }

    return ;
}

void init1() //calculating hash of the text cumilatively
{
    int slen=strlen(s);
    for(ll i=1;i<=slen;i++)
    {
        h1[i]= ( h1[i-1]* base1+  s[i-1] )%MOD ;
        h2[i]=  ( h2[i-1]* base2+ s[i-1] )%MOD;
    }

    return ;
}
ll init2() //will return the merged hash value of pattern
{
     int len=strlen(pat);
     ll hsh1=0,hsh2=0;
     for(int i=1;i<=len;i++)
    {

        hsh1= ( hsh1*base1+ pat[i-1] )%MOD;
        hsh2=  ( hsh2*base2+ pat[i-1])%MOD;
    }



    return (hsh1<<32)| hsh2;

}


ll hashVal(int l,int r)  //will return merges double hash value
{
    ll hsh1=(h1[r]-h1[l-1]* pw1[r-l+1] )%MOD;
    if(hsh1<0) hsh1+=MOD;

    ll hsh2=(h2[r]-h2[l-1]* pw2[r-l+1] )%MOD;
    if(hsh2<0) hsh2+=MOD;



    return (hsh1<<32)| hsh2;
}



int main()
{
    pw_calc();
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++)
    {

        scanf("%s%s",s,pat);


	init1();
	ll pat_hash=init2();

	int n,m;
	n=strlen(s);
	m=strlen(pat);

    int cnt=0;

	for(int i=m;i<=n;i++)
    {

        ll s_hash=hashVal(i-m+1,i);


        if(s_hash==pat_hash) cnt++;
    }

    printf("Case %d: %d\n",tc,cnt);






    }








	return 0;
}

