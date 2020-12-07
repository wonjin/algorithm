#include <fstream>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int v[200001] = {0};

int bfs(int _x, int t) {

    queue<tuple<int,int>> q;
    q.push({_x,0});

    while(!q.empty()) {
        auto [x,d] = q.front();
        q.pop();
        v[x] = true;

        if(x == t) {
            return d;
        }

        if (!v[x*2] && x*2 >= 0 && x*2 <= 100000)
            q.push({x*2,d});
        if (!v[x-1] && x-1 >= 0 && x-1 <= 100000)
            q.push({x-1,d+1});
        if (!v[x+1] && x+1 >= 0 && x+1 <= 100000)
            q.push({x+1,d+1});
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    ifstream ifs("input.txt");
    // istream& is = ifs;
    istream& is = cin;

    int N,M;
    is >> N >> M;

    cout << bfs(N, M);

    return 0;
}