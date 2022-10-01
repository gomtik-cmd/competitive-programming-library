#include<bits/stdc++.h>
#define fori(i,n) for(int i=0;i<n;i++)

using namespace std;

#ifndef fori
#define fori(i,n) for(int i=0;i<n;i++)
#endif

vector<int> dijkstrasAlgo(vector<vector<int> >g, int start)
{
	int n = g.size();
	vector<int> dist(n,INT_MAX);
	vector<int> Q(n); // Q->unvisited nodes
	fori(i,n)Q[i]=i;
	dist[start] = 0;
	int u=start;

	while(!Q.empty())
	{
		int min = 0;
		fori(j,Q.size())
			if(dist[Q[j]]<dist[Q[min]]) min = j;

		u = Q[min];
		Q.erase(Q.begin()+min);

		fori(i,n)
			if(u!=i && g[u][i]!=-1){
				int alt = dist[u]+g[u][i];
				if(alt<dist[i]) dist[i]= alt;
			}
	}
	return dist;
}


int main()
{
	int input_n;
	cout << "Enter value of n: "<< endl;
	cin>>input_n;
	vector<vector<int> >g(input_n, vector<int>(input_n));
	fori(i,input_n){
		fori(j,input_n){
			cin>>g[i][j];
		}
	}
	vector<int> t = dijkstrasAlgo(g,0);
	fori(i,input_n)cout<<t[i]<<" ";
}
