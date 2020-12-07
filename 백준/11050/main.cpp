#include <fstream>
#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    ifstream ifs("input.txt");
    // istream& is = ifs;
    istream& is = cin;

    int n,k;
    cin >> n >> k;

    long nume = 1;
    long denom = 1;

    for(int i=1;i<=k;++i)
        nume *= n--;
    for(int i=1;i<=k;++i)
        denom *= i;
    
    cout << nume / denom << "\n";

    return 0;
}
