#include <fstream>
#include <iostream>

using namespace std;

int D[17][17] = {0};
int N;
int ans = 0;

bool cross(int y, int x) {
    for(int i=1;i<=N;++i) {
        if(y-i<1 || x-i<1)
            break;
        if(D[y-i][x-i]) // --
            return true;
    }
    for(int i=1;i<=N;++i) {
        if( y+i>N || x+i>N)
            break;
        if(D[y+i][x+i]) // ++
            return true;
    }
    for(int i=1;i<=N;++i) {
        if(x-i<1 || y+i>N)
            break;
        if(D[y+i][x-i]) // +-
            return true;
    }
    for(int i=1;i<=N;++i) {
        if(y-i<1 || x+i>N)
            break;
        if(D[y-i][x+i]) // -+
            return true;
    }
    return false;
}

bool col(int x) {
    for(int y=1;y<=N;++y)
        if(D[y][x])
            return true;
    return false;
}

bool row(int y) {
    for(int x=1;x<=N;++x)
        if(D[y][x])
            return true;
    return false;
}

void s(int y)
{
    if(y > N) {
        ans++;
        return;
    }

    for(int x=1;x<=N;++x) {
        if(D[y][x] || row(y) || col(x) || cross(y,x))
            continue;
        D[y][x] = true;
        s(y+1);            
        D[y][x] = false;
    }
}

int main(int argc, char const *argv[])
{
    ifstream ifs("input.txt");
    // istream& is = ifs;
    istream& is = cin;

    is >> N;

    s(1);

    cout << ans << "\n";
    return 0;
}

// #include <cstdio>
// using namespace std;
// int n, ans = 0;
// bool a[14], b[27], c[27];

// void solve_dfs(int i) {
// 	if (i == n) {
// 		ans++;
// 		return;
// 	}
// 	for (int j = 0; j < n; j++) {
// 		if (!a[j] && !b[i + j] && !c[i - j + n - 1]) {
// 			a[j] = b[i + j] = c[i - j + n - 1] = true;
// 			solve_dfs(i + 1);
// 			a[j] = b[i + j] = c[i - j + n - 1] = false;
// 		}
// 	}
// }

// int main() {
// 	n = 15;
// 	solve_dfs(0);
// 	printf("%d\n", ans);
// 	return 0;
// }