#include <fstream>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

bool visit[200000] = {0};

// x : 현재 위치
// t : 목표 위치
// d : 깊이
int bfs(int _x, int t) {

    queue<tuple<int,int>> q;
    q.push({_x,0});
    visit[_x] = true;
    
    while(!q.empty()) {
        auto p = q.front();
        int x = get<0>(p);
        int d = get<1>(p);
        q.pop();

        if (x == t) {
            return d;
        }
    
        // case x-1
        if( x-1 >= 0 && visit[x-1] == false) {
            visit[x-1] = true;
            q.push(make_tuple(x-1, d+1));
        }
        // case x*2
        if (x < t && visit[x*2] == false) {
            visit[x*2] = true;
            q.push(make_tuple(x*2, d+1));
        }
        // case x+1
        if( x < t && visit[x+1] == false) {
            visit[x+1] = true;
            q.push(make_tuple(x+1, d+1));
        }

    }
}

int main(int argc, char const *argv[])
{
    ifstream ifs("input.txt");
    // istream& is = ifs;
    istream& is = cin;

    int N, K;
    is >> N >> K;

    cout << bfs(N, K);

    return 0;
}
