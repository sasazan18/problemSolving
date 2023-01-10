#include<bits/stdc++.h>
using namespace std;

// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#define ll long long
#define PI acos(-1.0)
#define for0(i,n) for(ll i=0;i<n;i++)
#define for1(i,n) for(ll i=1;i<=n;i++)
#define forc(i,j,n) for(ll i=j;i<n;i++)
#define pb push_back
#define sor(n) sort(n.begin(),n.end())
#define sorcmp(n) sort(n.begin(),n.end(),cmp)
#define rev(n) reverse(n.begin(),n.end())
#define random_shuffle(r...)random_shuffle(r,[](int _){return rand()%_;})
#define SQR(a) (a)*(a)
#define sp(x) fixed<<setprecision(x)
#define mod 1000000007
#define pii pair<int,int>
#define pll pair<ll,ll>
#define togglebit(mask,bit) (mask ^ (1<<bit))
#define SetBit(x, k) (x | (1LL << k))
#define ClearBit(x, k) (x & ~(1LL << k))
#define CheckBit(x, k) ((x>>k)&1)
#define YES cout << "YES"<<endl
#define NO cout << "NO"<<endl
void fastio(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
ll powmod(ll a, ll b){ll ans = 1;while(b){if(b&1) ans = ans*a%mod;a = a*a%mod;b >>= 1;}return ans;}
#define mxn 30005


void solve(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)
      cin>>arr[i];
    int left_min[mxn];
    int right_min[mxn];
    memset(left_min,0,sizeof left_min);
    memset(right_min,0,sizeof right_min);

    stack<pii>s;

    for(int i=1;i<=n;i++){
        if(s.empty()){
            s.push({arr[i],i});
            left_min[i]=0;
        }
        else{
            int x = arr[i];
            while(s.size()>0 &&  s.top().first>=x){
                 s.pop();
            }

            if(s.empty()){
                left_min[i]=0;
            }
            else{
                left_min[i]=s.top().second;
            }
            s.push({x,i});
        }
    }

    stack<pii>s2;

    for(int i=n;i>=1;i--){
        if(s2.empty()){
            s2.push({arr[i],i});
            right_min[i]=n+1;
        }
        else{
            int x = arr[i];
            while(s2.size()>0 &&  s2.top().first>=x){
                 s2.pop();
            }

            if(s2.empty()){
                right_min[i]=n+1;
            }
            else{
                right_min[i]=s2.top().second;
            }
            s2.push({x,i});
        }
    }

    int ans = 1;
    for(int i=1;i<=n;i++){
        int temp = right_min[i]-left_min[i]-1;
        ans = max(ans,temp*arr[i]);
    }
    cout<<ans<<endl;








    


return;
}


int main(){
    int t;
    cin>>t;
    int tc = 1;
    while(t--){

        cout<<"Case "<<tc<<": ";
     
        solve();

        ++tc;

    }
    return 0;
}
