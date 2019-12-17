#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidDist(vector< pair<int,int> > points, int Dist) {
    int n = points.size();
    int p = -1, minY = 1000000, maxY = -1000000;
    for(int j = 0; j < n; j++) {
        while(p + 1 < j && points[j].first - points[p + 1].first >= Dist) {
            p++;
            minY = min(minY, points[p].second);
            maxY = max(maxY, points[p].second);
        }
        if(p != -1 && abs(minY - points[j].second) >= Dist)
            return true;
        if(p != -1 && abs(maxY - points[j].second) >= Dist)
            return true;
    }
    return false;
}

int bSearch(vector< pair<int, int> > points) {
    int Left = 0, Right = 1000000, ans;
    sort(points.begin(), points.end());
    while(Left <= Right) {
        int Mid = (Left + Right) / 2;
        if(isValidDist(points, Mid)) {
            ans = Mid;
            Left = Mid + 1;
        }
        else
            Right = Mid - 1;
    }
    return ans;
}

int main()
{
    int n;
    vector< pair<int,int> > points;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }
    cout << bSearch(points);
    return 0;
}
