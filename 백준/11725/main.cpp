#include <fstream>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<tuple<int,int>> v;

int dfs(int x)
{
    auto [l, r] = v[x-1];   // index -1
    if(x == 1)
        return 1;
    if(x==0)
        return 0;

    dfs(l);
    dfs(r);
    
    return 0;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ifstream ifs("input.txt");
    istream& is = ifs;
    // istream& is = cin;

    int N;
    is >> N;
    v.resize(N+1);
    for(int i=0;i<N;++i) {
        int l,r;
        is >> l >> r;
        if(get<0>(v[l]) == 0)
            get<0>(v[l]) = r;
        else
            get<1>(v[l]) = r;
        if(get<0>(v[r]) == 0)
            get<0>(v[r]) = l;
        else
            get<1>(v[r]) = l;
    }


    // find 1 with parent
    // for(int i=2;i<N;++i) {
    //     dfs(i);
    // }

    return 0;
}