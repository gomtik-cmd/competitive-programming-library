#include <bits/stdc++.h>

using namespace std;

/*
 * Input: types c.size() types of coins and value of coins for each time.
 * Output: No. of ways to make changes for n value using given coins
 */
template <typename templateType>
templateType getWays(templateType n, vector<templateType> c){
	templateType** a = (templateType**)malloc((n+1)*sizeof(templateType*));
	for(int i=0;i<n+1;i++)a[i] = (templateType*)calloc(c.size(), sizeof(templateType));

	/* Assumption: Coins of all types are in infintr quantity. */
	for(int i=0;i<c.size();i++)a[0][i]=1;
	for(templateType i=1;i<n+1;i++){
		for(templateType j=0;j<c.size();j++){
			templateType x = ((i-c[j])>=0)? a[i-c[j]][j]:0;
			templateType y = (j>0)? a[i][j-1]:0;
			a[i][j] = x+y;
		}
	}

	return a[n][c.size()-1];
}


//test drivers function
int main() {
	int n;
	int m;
	cin >> n >> m;
	vector<long> c(m);
	for(int c_i = 0; c_i < m; c_i++){
		cin >> c[c_i];
	}
	// Print the number of ways of making change for 'n' units using coins having the values given by 'c'
	long ways = getWays<long>(n, c);
	cout<<ways<<endl;
	return 0;
}
