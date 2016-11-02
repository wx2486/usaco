/*
ID: wx_ahu1
PROG: skidesign
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>

using namespace std;

const string PROG = "skidesign";
ofstream fout(PROG + ".out");
ifstream fin(PROG + ".in");

int calc(vector<int> &v, int minH, int maxH)
{
    int cost = 0;
    for (int n : v)
        if (n < minH)
            cost += (minH-n)*(minH-n);
        else if (n > maxH)
            cost += (n-maxH)*(n-maxH);
    return cost;
}

int main()
{
    int n; fin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) fin >> v[i];
    
    int minCost = INT_MAX;
    for (int i=0; i+17<=100; i++)
    {
        int cost = calc(v, i, i+17);
        minCost = min(minCost, cost);
    }
    
    fout << minCost << endl;
    
    return 0;
}
