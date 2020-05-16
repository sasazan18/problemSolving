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


#define mxn 100005

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}




vector<pii>arr;
vector<int>seg[4*mxn];

void build(int node,int b,int e)
{
    if(b==e)
    {
        seg[node].pb(arr[b].second);
        return ;
    }

    int mid=(b+e)>>1;

    build(2*node,b,mid);
    build(2*node+1,mid+1,e);

    merge(seg[2*node].begin() , seg[2*node].end(), seg[2*node+1].begin(), seg[2*node+1].end(),back_inserter(seg[node]));




}


int query(int node,int b,int e,int l,int r,int k)
{

     if(b==e)
     {

         return seg[node][0];

     }

     int mid=(b+e)>>1;

     int total=upper_bound(seg[2*node].begin(),seg[2*node].end(),r)-lower_bound(seg[2*node].begin(),seg[2*node].end(),l);

     if(total>=k)
     {
         return query(2*node,b,mid,l,r,k);
     }
     else
        {return query(2*node+1,mid+1,e,l,r,k-total);}

}







int main()
{
    fastio();


     int n,q;
     cin>>n>>q;

     unordered_map<int,int>mp;

     for(int i=0;i<n;i++)
     {

        int x;
        cin>>x;
        arr.pb({x,i});
        mp[i]=x;
      }
     sor(arr);

     build(1,0,n-1);



     while(q--)
     {
         int l,r,k;
         cin>>l>>r>>k;
         --l;
         --r;

         int temp=query(1,0,n-1,l,r,k);
         cout<<mp[temp]<<endl;



     }











    return 0;
}

