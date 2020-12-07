#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int d[1000001] = {0};
int p[1000001] = {0};   // 이전 point를 가짐

int main(int argc, char const *argv[])
{
    ifstream ifs("input.txt");
    // istream& is = ifs;
    istream& is = cin;

    int x;
    is >> x;

    for(int i=2;i<=x;++i) {

        int v = d[i-1] + 1;
        p[i] = i-1;
        if (i % 3 == 0) {
            p[i] = v < d[i/3]+1 ? p[i] : i/3;
            v = v < d[i/3]+1 ? v : d[i/3]+1;
        }
        if (i % 2 == 0) {
            p[i] = v < d[i/2]+1 ? p[i] : i/2;
            v = v < d[i/2]+1 ? v : d[i/2]+1;
        }
        d[i] = v;
    }

    cout << d[x] << "\n";
    while(x != 0) {
        cout << x << " ";
        x = p[x];
    }

    return 0;
}