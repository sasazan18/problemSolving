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
#define pi(x)  prllf("%d",x);
#define pl(x)  prllf("%lld",x);
#define pf(x)  prllf("%.10lf",x);
#define ps(x)  prllf("%s",x);
#define en() prllf("\n");
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


#define mxn 200005
ll seg[4 * mxn];
vector<ll> adj[4 * mxn];
vector<ll>t1,t2;
ll n;

void mergeSort(int node, int l, int h)
{
	if(l == h)
	{
		adj[node].pb(t2[l]);
		return ;
	}
	int m = (l + h) >> 1;

	mergeSort(node * 2, l, m);
	mergeSort(node * 2 + 1, m + 1, h);

	for(int i = 0, j = 0, curr = l; curr <= h; curr++)
	{
		if(i >= adj[node * 2].size())
			adj [node].pb(adj [node * 2 + 1][j++]);
		else if(j >= adj[node * 2 + 1].size())
			adj [node].pb( adj [node * 2][i++]);
		else if(adj [node * 2][i] < adj [node* 2 + 1][j])
			adj [node].pb ( adj [node * 2][i++]);
		else
			adj [node].pb ( adj [node * 2 + 1][j++] );
	}
}





ll query(int node,int b,int e,int l,int r,ll x){

        if(b > r || e < l) return 0;
        if(b >= l && e <= r){

               int lo = 0 , hi = adj[node].size() - 1,res = -1;

               while(lo <= hi){
                int mid = (lo + hi)  /2;

                if(adj[node][mid] >= x){
                    hi = mid - 1;
                }else {
                   res = mid;
                   lo = mid + 1;
                }



               }

           res++;
           if(res < 0) res = 0;
           return res;
        }

        int mid = b + e >> 1;
        int xx = query(node << 1,b,mid,l,r,x);
        int y = query(node << 1 | 1, mid + 1 , e,l,r,x);
        return xx + y;

}



int main(){
fastio();



cin>>n;
int arr[n];
int brr[n];
for(int i=0;i<n;i++) cin>>arr[i];
for(int i=0;i<n;i++) cin>>brr[i];

for(int i=0;i<n;i++)
{
    t1.pb(arr[i]-brr[i]);
    t2.pb(brr[i]-arr[i]);
}
ll ans=0;
mergeSort(1,0,n-1);
for(int i=0;i<n;i++)
{

     ll res=query(1,0,n-1,i+1,n-1,t1[i]);
    ans+=res;
}

cout<<ans<<endl;


//cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';









return 0;
}
