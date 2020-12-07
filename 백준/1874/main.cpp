#include <fstream>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void algorithm(istream& is)
{
    int n;
    scanf("%d",&n);

    vector<int> data;
    for(int i=0;i<n;++i)
    {
        int d;
        scanf("%d",&d);
        data.push_back(d);
    }

    stack<int> s;
    vector<char> ans;
    int count = 0;
    for (int i=1;i<=n;++i)
    {
        s.push(i);
        ans.emplace_back('+');

        // same
        while(!s.empty() && s.top() == data[count])
        {
            s.pop();
            ans.emplace_back('-');
            count++;
        }
    }

    if(!s.empty())
        printf("NO\n");
    else {
        for(auto& v : ans)
            printf("%c\n", v);
    }
}

int main(int argc, char const *argv[])
{
    // ifstream ifs("input.txt");
    // if (ifs.is_open())
    //     algorithm(ifs);
    algorithm(cin);

    return 0;
}
