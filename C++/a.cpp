#include <bits/stdc++.h>
using namespace std;

map <string, vector<int>> m;

int main()
{
  string s = "megalusion";
  m.insert(make_pair(s, vector<int>{1, 0})); 
  
  m[s][0]+=1;
  cout << m[s].at(0) << endl;
}