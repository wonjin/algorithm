#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


int main(int argc, char const *argv[])
{
    ifstream ifs("input.txt");
    // istream& is = ifs;
    istream& is = cin;

    int N, M;
    is >> N;
    map<int,int> n;
    vector<int> m;
    for(int i=0;i<N;++i) {
        int d;
        is >> d;
        auto it_b = n.insert({d, 1});
        if(!it_b.second)
            n[d] += 1;
    }

    is >> M;
    for(int i=0;i<M;++i) {
        int d;
        is >> d;
        m.push_back(d);
    }

    for(auto v:m) {
        cout << n[v] << " ";
    }

    return 0;
}
