#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXVAL 100001

int v[2][MAXVAL] = {0};
int d[2][MAXVAL] = {0};

void printv(int N) {
    for(int i=1;i<=N;++i) 
        cout << v[0][i] << " ";
    cout << "\n";
    for(int i=1;i<=N;++i) 
        cout << v[1][i] << " ";
    cout << "\n=====================\n";
}

void print(int N) {
    for(int i=1;i<=N;++i) 
        cout << d[0][i] << " ";
    cout << "\n";
    for(int i=1;i<=N;++i) 
        cout << d[1][i] << " ";
    cout << "\n";
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ifstream ifs("input.txt");
    // istream& is = ifs;
    istream& is = cin;

    int T, N;
    is >> T;

    while(T--) {
        is >> N;
        memset(v, 0, sizeof(int) * MAXVAL * 2);
        memset(d, 0, sizeof(int) * MAXVAL * 2);
        
        for(int i=1;i<=N;++i)
            is >> v[0][i];
        for(int i=1;i<=N;++i)
            is >> v[1][i];

        // printv(N);

        d[0][1] = v[0][1];
        d[1][1] = v[1][1];

        for(int i=2;i<=N;++i) {
            d[0][i] = v[0][i] + max(max(d[1][i-1], d[1][i-2]), d[0][i-2]);
            d[1][i] = v[1][i] + max(max(d[0][i-1], d[0][i-2]), d[1][i-2]);
        }

        cout << max(d[0][N], d[1][N]) << "\n";
    }

    return 0;
}