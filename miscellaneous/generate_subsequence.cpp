#include<iostream>
#include<math.h>
using namespace std;
void printSubsequence(int ar[],int n){
	for(int i=1;i<=pow(2,n);i++){
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				cout<<ar[j]<<" ";
			}
		}
		cout<<"\n";
	}
}
int main(int argc, char const *argv[])
{
	int test;
	cin>>test;
	for(int i=0;i<test;i++){
		int n;
		cin>>n;
		int ar[n];
		for(int j=0;j<n;j++){
			cin>>ar[j];
		}
		printSubsequence(ar,n);
	}
	return 0;
}
