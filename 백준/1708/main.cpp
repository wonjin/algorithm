#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
#include <algorithm>
#include <deque>

typedef long long ll;

using namespace std;

tuple<ll,ll> operator-(const tuple<ll,ll>& t1, const tuple<ll,ll>& t2) {
    auto [x1,y1] = t1;
    auto [x2,y2] = t2;
    return make_tuple(x1-x2, y1-y2);
}

// t1 -> t2
ll ccw(const tuple<ll,ll>& t1, const tuple<ll,ll>& t2) {
    auto [x1,y1] = t1;
    auto [x2,y2] = t2;
    return x1*y2 - x2*y1;
}

int main(ll argc, char const *argv[])
{
    ifstream ifs("input.txt");
    // istream& is = ifs;
    istream& is = cin;

    ll N;
    is >> N;
    deque<tuple<ll,ll>> vec;
    for(auto i=0;i<N;++i) {
        ll x, y;
        is >> x >> y;
        vec.push_back({x,y});
    }

    // find minimum y point
    auto it_pts = std::min_element(vec.begin(), vec.end(), 
        [](tuple<ll,ll> v1, tuple<ll,ll> v2){
            auto [x1,y1] = v1;
            auto [x2,y2] = v2;
            return y1 < y2;
        });
    auto min_pts = *it_pts;
    vec.erase(it_pts);

    std::sort(vec.begin(), vec.end(), 
        [min_pts](tuple<ll,ll> v1, tuple<ll,ll> v2){
            auto vec1 = v1 - min_pts;
            auto vec2 = v2 - min_pts;

            // 여기가 중요!
            if (ccw(vec1, vec2) == 0) {
                auto [x1,y1] = vec1;
                auto [x2,y2] = vec2;
                return x1*x1+y1*y1 < x2*x2+y2*y2;
            }
            return ccw(vec1, vec2) > 0;
        });

    vec.push_front(min_pts);

    stack<tuple<ll,ll>> s;
    s.push(vec[0]);
    s.push(vec[1]);

    for(ll i=2;i<vec.size();++i) {
        while(s.size() >= 2) {
            auto second = s.top(); s.pop();
            auto first = s.top();
            auto third = vec[i];

            auto v1 = second - first;
            auto v2 = third - first;

            if(ccw(v1, v2) > 0) {
                s.push(second);
                break;
            }
        }
        s.push(vec[i]);
    }

    cout << s.size();
    return 0;
}
