#include<bits/stdc++.h>
using  namespace std;
#define pii pair<int,int>
#define pb push_back
#define inf INT_MAX
#define mxn 10005
vector<pii>g[mxn];

int vis[mxn];
int dis[mxn];
int  n;
void dijkstra(int source)
{

    priority_queue<pii>p;
    p.push({0,source});

    while(!p.empty())
    {

        pii x=p.top();
        p.pop();
        int node=x.second;
        int cost=(-1)*x.first;


        if(vis[node]) continue;

        vis[node]=1;
        dis[node]=cost;

        for(auto u:g[node])
        {
            if(vis[u.first]) continue;
            int temp;
            temp=cost+u.second;
            temp*=-1;
            p.push({temp,u.first});

        }

    }

    return ;

}


void init()
{
    for(int i=0; i<=n+2; i++) dis[i]=inf,vis[i]=0;
}


int main()
{

    int t;
    cin>>t;
    while(t--)
    {



        cin>>n;
        string str;

        int k=1;
        map<string,int>mp;
        for(int i=0; i<n; i++)
        {
            cin>>str;
            mp[str]=k;
            int m;
            cin>>m;
            while(m--)
            {
                int a,b;
                cin>>a>>b;

                g[k].pb({a,b});

            }

            k++;
        }



        int q;
        cin>>q;

        while(q--)
        {
            init();
            string str,ptr;
            cin>>str>>ptr;

            dijkstra(mp[str]);

            cout<<dis[mp[ptr]]<<endl;

        }



        for(int i=1; i<=n; i++)
        {
            g[i].clear();
        }



    }



}
