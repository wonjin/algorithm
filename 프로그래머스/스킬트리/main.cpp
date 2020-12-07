#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isSorted(vector<int> index)
{
    int temp = -1;
    for(int i=0;i<index.size(); ++i) {
        if (temp > index[i])
            return false;
        temp = index[i];
    }
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (auto ref : skill_trees) {
        
        vector<int> index(skill.size(), 27);
        for(int i=0;i<skill.size();++i) {
            for(int j=0;j<ref.size();++j) {
                if (skill[i] == ref[j]) {
                    index[i] = j;
                }
            }
        }
        
        if (isSorted(index))
            answer++;
    }
    
    return answer;
}