//program to print the distinct string permutations
#include<iostream>
#include<vector>
#include<set>
using namespace std;
void swap(char* a,char* b){
    int t = *a;
    *a = *b;
    *b = t;
}
void print_string_permutations_util(string s,int start,int end,vector<string>& v){
    set<char> s1;
    if(start==end)
    v.push_back(s);
    else{
        if(start<end){
            for(int i=start;i<=end;i++){
                if(s1.find(s[i])!=s1.end())
                continue;
                s1.insert(s[i]);
                swap(s[i],s[start]);
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
    print_string_permutations(s);
    return 0;
}