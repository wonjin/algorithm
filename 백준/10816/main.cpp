#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


int main(int argc, char const *argv[])
{
    ifstream ifs("input.txt");
    istream& is = ifs;
    // istream& is = cin;

    int N, M;
    is >> N;
    vector<int> n, m;
    for(int i=0;i<N;++i) {
        int d;
        is >> d;
        n.push_back(d);
    }

    is >> M;
    for(int i=0;i<M;++i) {
        int d;
        is >> d;
        m.push_back(d);
    }

    sort(n.begin(), n.end());

    for(auto v:m) {
        auto ub = upper_bound(n.begin(), n.end(), v);
        auto lb = lower_bound(n.begin(), n.end(), v);
        cout << ub - lb << " ";
    }

    return 0;
}
