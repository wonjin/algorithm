#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

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

    for(int i=0;i<M;++i) {
        cout << (find(n.begin(), n.end(), m[i]) == n.end() ? 0 : 1) << "\n";
    }

    return 0;
}
