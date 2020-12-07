#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

int X = 100000;

vector<int> path;

void print_vector() {
    for(auto v : path) {
        cout << v << " ";
    }
    cout << "\n";
}

// x : 현재 위치
// t : 목표 위치
// d : 깊이
void dfs(int x, int t, int d) {

    int prev = path.empty() ? -1000 : path.back();
    path.push_back(x);
    if(x == t) {
        X = std::min(X, d);
        // 모든 방법
        // cout << d << ": \n";
        // print_vector();
    }
    else if(x > t) {
        dfs(x-1, t, d+1);
    }
    else {
        if(prev != x-1 && 2 * (x-1) > t)
            dfs(x-1, t, d+1);
        if(prev != x+1)
            dfs(x+1, t, d+1);
        if(prev != x*2)
            dfs(x*2, t, d+1);
    }
    path.pop_back();
}

int main(int argc, char const *argv[])
{
    ifstream ifs("input.txt");
    // istream& is = ifs;
    istream& is = cin;

    int N, K;
    is >> N >> K;

    dfs(N, K, 0);
    cout << X;

    return 0;
}
