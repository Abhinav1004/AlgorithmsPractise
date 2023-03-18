//implementation of kth largest element
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
int extractMax(int ar[],int* n){
    if(*n>=1){
        int val = ar[0];
        swap(ar[0],ar[*n-1]);
        maxheapify(ar,*n,0);
        *n = *n-1;
        return val;
    }
    else
    return INT_MAX;
}
int kthLargest(int ar[],int n,int k){
    buildHeap(ar,n);
    int val = INT_MAX;
    if(k>n)
    return INT_MAX;
    else{
        for(int i=0;i<k;i++){
            val = extractMax(ar,&n);
        }
        return val;
    }
}
// void heapSort(int ar[],int n){
//     buildHeap(ar,n);
//     // printArray(ar,n);
//     for(int i=n-1;i>0;i--){
//         swap(ar[0],ar[i]);
//         maxheapify(ar,i,0);
//     }
// }
int main(){
    int test;
    cin>>test;
    for(int i=0;i<test;i++){
        int size,k;
        cin>>size;
        int* ar = new int[size];
        for(int j=0;j<size;j++){
            cin>>ar[j];
        }
        cin>>k;
        int val = kthLargest(ar,n,k);
        cout<<val<<"\n";

    }
    return 0;
}