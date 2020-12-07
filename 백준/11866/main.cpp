#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream ifs("input.txt");
    // istream& is = ifs;
    istream& is = cin;

    int N, K;
    is >> N >> K;

    queue<int> q;
    for(int i=1;i<=N;++i)
        q.push(i);

    vector<int> ans;
    while(!q.empty()) {
        for(int i=1;i<K;++i) {
            int x = q.front();
            q.pop();
            q.push(x);
        }
        ans.push_back(q.front());
        q.pop();
    }

    cout << "<";
    for(int i=0;i<ans.size()-1;++i) {
        cout << ans[i] << ", ";
    }
    cout << ans.back();
    cout << ">";

    return 0;
}
