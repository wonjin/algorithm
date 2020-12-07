#include <fstream>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int,int,int,int> Rect;

int arr[1025][1025] = {0};
int d[1025][1025] = {0};

void printd(int X, int Y) {
    for(int y=1;y<=Y;++y) {
        for(int x=1;x<=X;++x) {
            cout << d[y][x] << " ";
        }
        cout << "\n";
    }
}

void print(int X, int Y) {
    for(int y=1;y<=Y;++y) {
        for(int x=1;x<=X;++x) {
            cout << arr[y][x] << " ";
        }
        cout << "\n";
    }
}

int main(int argc, char const *argv[])
{
    ifstream ifs("input.txt");
    // istream& is = ifs;
    istream& is = cin;

    int N, M;
    is >> N >> M;

    for(int y=1;y<=N;++y)
        for(int x=1;x<=N;++x)
            is >> arr[y][x];

    vector<Rect> rects;
    for(int i=0;i<M;++i) {
        int x1,y1,x2,y2;
        is >> x1 >> y1 >> x2 >> y2;
        rects.push_back({x1,y1,x2,y2});
    }

    for(int y=1;y<=N;++y) {
        for(int x=1;x<=N;++x) {
            d[y][x] = d[y-1][x] + d[y][x-1] - d[y-1][x-1] + arr[y][x];
        }
    }

    for(auto [x1,y1,x2,y2] : rects) {
        cout << d[x2][y2] - d[x2][y1-1] - d[x1-1][y2] + d[x1-1][y1-1] << "\n";
    }

    return 0;
}