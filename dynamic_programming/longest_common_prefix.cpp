#include<iostream>
#include<string>
#include<vector>
using namespace std;
string find_common_prefix_util(string s1,string s2){
  int i=0;int j=0;
  string common_str = "";
  while(i<s1.size() && j<s2.size()){
    if(s1[i]==s2[j])
      {common_str+=s1[i];
      i++;j++;}
      else
      break;
  }
  return common_str;
}
string find_prefix(vector<string> strs){
  int n = strs.size();
  string common_prefix = "";
  if(n==0)
  return "";
  else if(n==1)
  return strs[0];
  else{
    common_prefix = find_common_prefix_util(strs[0],strs[1]);
    for(int i=2;i<n;i++){
      common_prefix = find_common_prefix_util(common_prefix,strs[i]);
    }
  }
  return common_prefix;
}
int main(){
  int test;
  cin>>test;
  for(int i=0;i<test;i++){
    int n;
    cin>>n;
    vector<string> strs;
    cin.ignore();
    for(int j=0;j<n;j++){
      string s;
      getline(cin,s);
      strs.push_back(s);
    }
    string common_prefix = find_prefix(strs);
    cout<<common_prefix<<"\n";
  }
  return 0;
}
