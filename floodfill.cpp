#include<bits/stdc++.h>
#define iterate_forloop(i,n) for(int i=0;i<n;i++)
#define fors(i,init,n,step) for(int i=init;i<n;i+=step)

using namespace std;

typedef int nd;

/* Floofill algorithm
 * Input : 2D matrix in form of vector<vector>
 * startx, starty : x-coord of starting point
 * fillvalue : values to be filled on empty cells
 * border : value to stop filling colors through the boundary area.
 * xoffset, yoffset : move to be taken to fill each cell from the previous one.
 * allDirection : true means apply xoffset in all 8 directions otherwise not.
 * Example : To run Knight of Chess, pick xoffset=1 and yofset=2.
 * 	     To fill colors in four sides only, use xoffset=1, yoffset=0
	     To fill color in diagonal,use xoffset=1, yoffset=1.
	     To fill colors in all eight directions of radius one, use xoffset=yoffset=1 and allDirection=true.
 */
//Copy code from here till....
#ifndef floodfill_rec_func
#define floodfill_rec_func \
	if(i>=0 && i<n && j>=0 && j<n && g[i][j]!=border && g[i][j]!=fillvalue)floodfill(g,i,j,fillvalue,border,xoffset,yoffset,alldirection);
#endif
#ifndef iterate_forloop
#define iterate_forloop(i,n) for(int i=0;i<n;i++)
#endif
template <typename t>
void floodfill(vector<vector<t> >&g, int startx, int starty, t fillvalue, t border, int xoffset, int yoffset, bool alldirection=false){
	int n = g.size();
	g[startx][starty]=fillvalue;
	iterate_forloop(l,2){
		iterate_forloop(k,2){
			int i=startx+pow(-1,l)*xoffset, j=starty+ pow(-1,k)*yoffset;
	if(startx==3 && starty==2)cout<<i<<":"<<j<<endl;
			floodfill_rec_func
			if(xoffset!=yoffset){
				int i=startx+pow(-1,l)*yoffset, j=starty+ pow(-1,k)*xoffset;
	if(startx==3 && starty==2)cout<<i<<":"<<j<<endl;
				floodfill_rec_func
			}
			if(alldirection==true){
				i=startx+pow(-1,k)*xoffset;j=starty;
	if(startx==3 && starty==2)cout<<i<<"::"<<j<<endl;
				floodfill_rec_func
				if(xoffset!=yoffset){
					j=starty+pow(-1,k)*xoffset;i=startx;
	if(startx==3 && starty==2)cout<<i<<"::"<<j<<endl;
					floodfill_rec_func
				}
			}
		}
	}
return;
}
#undef floodfill_rec_func
//... till here to floodfill

int main(){
	nd n;
	cin>>n;
	vector<vector<int> >g(n,vector<int>(n,-1));
	iterate_forloop(i,n)iterate_forloop(j,n)cin>>g[i][j];
	floodfill(g,0,0,2,-1,1,1,true);
	iterate_forloop(i,n) {
		iterate_forloop(j,n)cout<<g[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
