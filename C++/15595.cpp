#include <bits/stdc++.h>
using namespace std;

map <string, vector<int>> m;

void add(char *s, int c){
    if(m.find(s) == m.end()){
        if(c == 4)
            m.insert(make_pair(s, vector<int>{1, 0}));
        else
            m.insert(make_pair(s, vector<int>{0, 1}));
    }
    
    if(c == 4) m[s][0]++;
    else m[s][1]++;
}

int main(){
    int n, no, c, mem, t, lang, len;
    char id[21];

    int ac=0, wa=0;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> no >> id >> c >> mem >> t >> lang >> len;
        if(strcmp(id, "megalusion") == 0) continue;
        add(id, c);
    }

    cout << m.  
    // vector<int> v;
    // for(; it != m.end(); it++){
    //     v = it->second;
    //     if(v[0] != 0){
    //         ac++;
    //         wa += v[1];
    //     }
    // }

    // if(ac == 0) cout << "0.000000";
    // else cout << (double)ac / (ac + wa) * 100;


}