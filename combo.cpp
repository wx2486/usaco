/*
ID: wx_ahu1
PROG: combo
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

const string PROG = "combo";
ofstream fout(PROG + ".out");
ifstream fin(PROG + ".in");

void calc(unordered_set<string> &st, int n)
{
    int a, b, c; fin >> a >> b >> c;
    for (int i=-2; i<=2; i++)
        for (int j=-2; j<=2; j++)
            for (int k=-2; k<=2; k++)
            {
                int aa, bb, cc;
                aa = (a + i + 2*n) % n;
                bb = (b + j + 2*n) % n;
                cc = (c + k + 2*n) % n;
                string s = to_string(aa) + ' ' + to_string(bb) + ' ' + to_string(cc);
                st.insert(s);
                cout << s << endl;
            }
}

int main()
{
    int n; fin >> n;
    unordered_set<string> st;
    
    calc(st, n);
    calc(st, n);
    
    fout << st.size() << endl;

    return 0;
}
