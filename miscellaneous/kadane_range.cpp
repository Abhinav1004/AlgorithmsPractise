#include<iostream>
using namespace std;
void printArray(int ar[],int n){
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
}
void find_kadane_range(int ar[],int n){
    int start = 0;int end = 0;
    int s = 0;
    int max_cur = ar[0];
    int max_end = ar[0];
    for(int i=1;i<n;i++){
        if(max_cur+ar[i]>ar[i]){
            max_cur = max_cur+ar[i];
        }
        else{
            max_cur = ar[i];
            s = i;
        }
        if(max_cur>max_end){
            max_end = max_cur;
            start = s;
            end = i;
        }
    }
    cout<<"maximum subarray lies between "<<start<<" "<<end;
    cout<<"\n";
}
int main(){
    int test;
    cin>>test;
    for(int i=0;i<test;i++){
        int n;
        cin>>n;
        int ar[n];
        for(int j=0;j<n;j++)
        cin>>ar[j];
        find_kadane_range(ar,n);
        // printArray(ar,n);
        cout<<"\n";
    }
    return 0;
}