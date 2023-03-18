//program to print the string permutations in lexicographical order
#include<iostream>
#include<vector>
using namespace std;
void swap(char* a,char* b){
    int t = *a;
    *a = *b;
    *b = t;
}
void print_string_permutations_util(string s,int start,int end,vector<string>& v){
    if(start==end)
    v.push_back(s);
    else{
        if(start<end){
            for(int i=start;i<=end;i++){
                swap(s[i],s[start]);
                sort(s.begin()+start+1,s.end());
                print_string_permutations_util(s,start+1,end,v);
                swap(s[i],s[start]);
            }
        }
    }
}
void print_string_permutations(string s){
    vector<string> v;
    print_string_permutations_util(s,0,s.size()-1,v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"\n";
    }
}
int main(){
    string s;
    getline(cin,s);
    cout<<"Permutations are \n";
    sort(s.begin(),s.end());
    print_string_permutations(s);
    return 0;
}