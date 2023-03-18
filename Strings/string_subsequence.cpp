//program to print the string subsequences
#include<iostream>
#include<math.h>
using namespace std;
void printSubsequencePower(string s){
    for(int i=1;i<pow(2,s.size());i++){
        for(int j=0;j<s.size();j++){
            if((1<<j)&i)
            cout<<s[j];
        }
        cout<<"\n";
    }
}
void printSubsequence(string s){
    for(int k=1;k<=s.size();k++){
        for(int i=0;i<=s.size()-k;i++){
            int j = i+k-1;
            for(int m=i;m<=j;m++){
                cout<<s[m];
            }
            cout<<"\n";
        }
    }
}
int main(){
    string s;
    int test;
    cin>>test;
    cin.ignore();
    for(int i=0;i<test;i++){
        getline(cin,s);
        // printSubsequence(s);
        printSubsequencePower(s);
    }
    return 0;
}