/*
ID: wx_ahu1
PROG: combo
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>

using namespace std;

const string PROG = "combo";

void insert(unordered_set<int> &st, int n, int x)
{
    st.insert((x+2)%n);
    st.insert((x+1)%n);
    st.insert(x);
    st.insert((x+n-1)%n);
    st.insert((x+n-2)%n);
}

int calc(int n, int a, int b)
{
    unordered_set<int> st;
    insert(st, n, a);
    insert(st, n, b);
    return n - st.size();
}

int main()
{
    ofstream fout (PROG + ".out");
    ifstream fin (PROG + ".in");
    int n; fin >> n;
    int a1, a2, a3, b1, b2, b3; fin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    fout << (calc(n, a1, b1) * calc(n, a2, b2) * calc(n, a3, b3)) << endl;
    return 0;
}
