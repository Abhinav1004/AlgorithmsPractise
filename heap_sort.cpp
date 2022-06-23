//implementation of heap sort
#include<bits/stdc++.h>
using namespace std;
void maxheapify(int ar[],int n,int i){
    int large = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && ar[left]>ar[large])
        large = left;
    if(right<n && ar[right]>ar[large])
        large = right;
    if(large!=i){
        swap(ar[large],ar[i]);
        maxheapify(ar,n,large);
    }
}
void buildHeap(int ar[],int n){
    for(int i=(n-1)/2;i>=0;i--){
        maxheapify(ar,n,i);
    }
}

void printArray(int ar[],int n){
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<"\n";
}
void heapSort(int ar[],int n){
    buildHeap(ar,n);
    // printArray(ar,n);
    for(int i=n-1;i>0;i--){
        swap(ar[0],ar[i]);
        maxheapify(ar,i,0);
    }
}
int main(){
    int test;
    cin>>test;
    for(int i=0;i<test;i++){
        int size;
        cin>>size;
        int* ar = new int[size];
        for(int j=0;j<size;j++){
            cin>>ar[j];
        }
        printArray(ar,size);
        heapSort(ar,size);
        printArray(ar,n);

    }
    return 0;
}