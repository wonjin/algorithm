#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char const *argv[])
{
    ifstream ifs("input.txt");
    // istream& is = ifs;
    istream& is = cin;

    while(true) {
        string str;
        is >> str;
        if (str.compare("0") == 0)
            break;
        
        auto it_s = str.begin();
        auto it_e = str.end() - 1;
        bool ans = true;

        for(int i=0;i<str.size()/2;++i) {
            if (*it_s != *it_e) {
                ans = false;
                break;
            }
            it_s++;
            it_e--;
        }
        
        cout << (ans ? "yes" : "no") << "\n";
    }

    return 0;
}
