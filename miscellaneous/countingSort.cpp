#include<iostream>
using namespace std;
void printArray(int ar[],int n){
	for(int i=0;i<n;i++){
		cout<<ar[i]<<" ";
	}
}
void countingSort(int ar[],int n){
	int output[n];
	int min_ele = ar[0];int max_ele = ar[0];
	for(int i=1;i<n;i++){
		min_ele = min(min_ele,ar[i]);
		max_ele = max(max_ele,ar[i]);
	}
	int range = max_ele-min_ele+1;
	// cout<<range<<"\n";
	int count[range];
	for(int i=0;i<range;i++){
		count[i] = 0;
	}
	// printArray(count,range);
	// cout<<"\n";
	for(int i=0;i<n;i++){
		count[ar[i]-min_ele]++;
	}
	// printArray(count,range);
	// cout<<"\n";
	for(int i=1;i<range;i++){
		count[i] = count[i-1]+count[i];
	}
	// printArray(count,range);
	// cout<<"\n";
	for(int i=n-1;i>=0;i--){
		output[count[ar[i]-min_ele]-1] = ar[i];
		count[ar[i]-min_ele]--;
	}
	for(int i=0;i<n;i++){
		ar[i] = output[i];
	}
	printArray(ar,n);
}
int main(int argc, char const *argv[])
{
	int test;
	cin>>test;
	for(int i=0;i<test;i++){
		int size;
		cin>>size;
		int ar[size];
		// cout<<size<<"\n";
		for(int j=0;j<size;j++)
			cin>>ar[j];
		// printArray(ar,size);
	countingSort(ar,size);
	}
	return 0;
}
