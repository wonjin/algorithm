#include <string>
#include <vector>
#include <stack>

#include <iostream>

using namespace std;

void print_stack(stack<int> s)
{
    int n = s.size();
    for(int i=0;i<n;++i) {  
        cout << i <<"th : " << s.top() << "\n";
        s.pop();
    }
}

bool move_value_to_other_stack(stack<int>& src, stack<int>& dst)
{
    if(src.empty())
        return false;
    
    int v = src.top();
    dst.push(v);
    src.pop();
    return true;
}

bool remove_if_has_same_top(stack<int>& s1, stack<int>& s2)
{
    if(s1.empty() || s2.empty())
        return false;
    int v1 = s1.top();
    int v2 = s2.top();

    if (v1 == v2) {
        s1.pop();
        s2.pop();
        return true;
    }
    return false;
}

int remove_repeated_values(stack<int>& s)
{
    stack<int> t;
    int count = 0;
    
    while(!s.empty()) {
        while (remove_if_has_same_top(s,t))
            count++;
        move_value_to_other_stack(s,t);
        while (remove_if_has_same_top(s,t))
            count++;
    }
    return count;
}

int pop_board(vector<vector<int>>& board, int move)
{
    for(int y=0;y<board.size();++y) {
        int v = board[y][move-1];
        if (v != 0) {
            board[y][move-1] = 0;
            return v;
        }
    }
    
    return -1;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    stack<int> s;
    
    for (auto m : moves) {
        int v = pop_board(board, m);
        if (v == -1)
            continue;
        s.push(v); // 쌓인 값을 넣기
    }
    
    answer = remove_repeated_values(s) * 2;
    return answer;
}

int main()
{
    int answer = solution(
        {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}},
        {1,5,3,5,1,2,1,4}
    );
    cout << answer << "\n";
}