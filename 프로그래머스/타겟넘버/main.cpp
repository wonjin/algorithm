
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void dfs(const vector<int>& numbers, int depth, int target, int value, int& answer)
{
    if (depth == numbers.size()) {
        if (target == value)
            answer++;
        return;
    }
    dfs(numbers, depth+1, target, value + numbers[depth], answer);
    dfs(numbers, depth+1, target, value - numbers[depth], answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, 0, target, 0, answer);
    return answer;
}

int main()
{
    int answer = solution(
        {1,1,1,1,1},
        3
    );

    cout << answer << "\n";
}