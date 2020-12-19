/* This is stable matching/pairing problem */
// This is implementation of stable marriage problem
#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

#define N 4

//This function return true if woman 'w' prefers man 'm1' over man 'm'
bool wPrefersM1overM(int prefer[2*N][N],int w, int m, int m1)
{
	for(int i=0; i<N; i++){
		if(prefer[w][i]==m1)
			return true;
		if(prefer[w][i]==m)
			return false;
	}
}

//Print stable matching for N boys and N girls
//boys 0 to N-1
//girls N to 2N-1
void stableMarriage(int prefer[2*N][N]){
	int wPartner[N];
	bool mFree[N];

	memset(wPartner,-1,sizeof(wPartner));
	memset(mFree, false, sizeof(mFree));

	int freeCount= N;
	while(freeCount > 0){
		int m;
		for(m=0;m<N;m++)
			if(mFree[m]==false)
				break;
		for(int i=0;i<N && mFree[m]==false;i++){
			int w = prefer[m][i];
			if(wPartner[w-N]==-1){
				wPartner[w-N]=m;
				mFree[m]=true;
				freeCount--;
			}
			else{
				int m1 = wPartner[w-N];
				if(wPrefersM1overM(prefer,w,m,m1)==false){
					wPartner[w-N]=m;
					mFree[m]=true;
					mFree[m1]=false;
				}
			}
		}
	}
	cout << "Woman\tMan" << endl;
	for(int i=0;i<N;i++)
		cout << i+N <<"\t"<< wPartner[i] << endl;
}

int main(){
	int prefer[2*N][N] = {
		{7,5,6,4},
		{5,4,6,7},
		{4,5,6,7},
		{4,5,6,7},
		{0,1,2,3},
		{0,1,2,3},
		{0,1,2,3},
		{0,1,2,3}
	};
	stableMarriage(prefer);
	return 0;
}

