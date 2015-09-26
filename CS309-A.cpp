#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct node{
	int u,v;
} a[1000][1000];
int main() {
	int cas=0;
	while (true) {
		cas++;
		memset(a,0,sizeof(a));
		int n,cnt,i,j;
		cin>>n;
		if (n==0) return 0;
		char x;
		for (int i=1;i<=n;i++) {
			cin>>x;
			if (x=='U') a[i][1].u=1;
			if (x=='D') a[i][1].u=-1;
			a[i][1].v=i;
		}
		int left=1;
		int right=n;
		for (int i=1;i<=n-2;i++) {
			cin>>x;
			if (x=='L') {
				cnt=0;
				for (int j=1;j<=100;j++) {
					if (a[left][j].u!=0) {
						cnt++;
					}
					else break;
				}
				//cout<<i<<" "<<cnt<<endl;
				for (int j=2;j<=cnt+1;j++) {
					a[left+1][j].v=a[left][cnt-j+2].v;
					a[left+1][j].u=a[left][cnt-j+2].u*(-1);
				}
				left++;
			}
			if (x=='R') {
				cnt=0;
				for (int j=1;j<=100;j++) {
					if (a[right][j].u!=0) {
						cnt++;
					}
					else break;
				}
				//cout<<i<<" "<<cnt<<endl;
				for (int j=2;j<=cnt+1;j++) {
					a[right-1][j].v=a[right][cnt-j+2].v;
					a[right-1][j].u=a[right][cnt-j+2].u*(-1);
				}
				right--;
			}
		}
		int cnt0=1;
		while (a[left][cnt0].v!=0) {
			cnt0++;
		}
		cnt0=cnt0-1;
		int cnt1=1;
		while (a[right][cnt1].v!=0) {
			cnt1++;
		}
		cnt1=cnt1-1;
		//cout<<cnt0<<cnt1<<endl;
		cin>>x;
		int ans;
		if (x=='L') {
			for (int j=cnt1+1;j<=cnt1+cnt0;j++) {
				a[right][j].v=a[left][cnt0-(j-cnt1-1)].v;
				a[right][j].u=a[left][cnt0-(j-cnt1-1)].u*(-1);
			}
			ans=right;
		}
		if (x=='R') {
			for (int j=cnt0+1;j<=cnt1+cnt0;j++) {
				a[left][j].v=a[right][cnt1-(j-cnt0-1)].v;
				a[left][j].u=a[right][cnt1-(j-cnt0-1)].u*(-1);
			}
			ans=left;
		}
		cout<<"Pile "<<cas<<endl;
		int m;
		int y;
		cin>>m;
		for (i=1;i<=m;i++) {
			cin>>y;
			cout<<"Card "<<y<<" is a face ";
			if (a[ans][n-y+1].u==-1) cout<<"down "<<a[ans][n-y+1].v<<"."<<endl;
			if (a[ans][n-y+1].u==1) cout<<"up "<<a[ans][n-y+1].v<<"."<<endl;
		}
	}
	return 0;
}