#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<double, double>>v(n),ans;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    ans.push_back({ v[0].first, v[0].second });
    pair<int,int>start = ans[0];
    pair<int, int> l(v[1]),temp;
    int j = 0;
    double anser = 0;
    while (l != start) {
        l = v[(j+1)%n];
        for (int i = 0; i < n; i++) {
            temp = v[i];
            double x3 = temp.first;
            double x1 = ans[0].first;
            double x2 = l.first;
            double y3 = temp.second;
            double y1 = ans[0].second;
            double y2 = l.second;
            if (((x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1)) > 0) {
                l = temp;
            }
        }
        //cout << l.first<<' '<<l.second <<' '<<j<< endl;
         
        anser += sqrt(pow(l.first*1.0 - ans[0].first*1.0, 2) + pow(-ans[0].second*1.0 + l.second*1.0, 2));
        ans.pop_back();
        ans.push_back(l);
        j++;
         
        //cout << anser << endl;;
         
    }
    ans.pop_back();
    cout << fixed<< setprecision(1) <<anser  ;
 
 
 
}
