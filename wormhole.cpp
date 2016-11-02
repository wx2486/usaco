
/*
ID: wx_ahu1
PROG: wormhole
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string PROG = "wormhole";
ofstream fout(PROG + ".out");
ifstream fin(PROG + ".in");

int n;
vector<int> jmp;
vector<int> wjmp;

void whjmp(vector<int> pairs)
{
    wjmp.clear();
    wjmp.assign(n, 0);
    for (int i=0; i<n; i+=2)
    {
        int a=pairs[i], b=pairs[i+1];
        wjmp[a] = b;
        wjmp[b] = a;
    }
}

bool check()
{
    vector<bool> checked(n, false);
    for (int i=0; i<n; i++)
        if (!checked[i])
        {
            int id = i;
            while (jmp[id] >= 0)
            {
                id = wjmp[jmp[id]];
                if (id == i) return false;
                checked[id] = true;
            }
        }
    return true;
}

int dig(vector<bool> picked, vector<int> pairs)
{
    int a = 0;
    while (picked[a]) a++;
    picked[a] = true;
    
    int sum = 0;
    for (int b=a+1; b<n; b++)
        if (!picked[b])
        {
            picked[b] = true;
            pairs.push_back(a);
            pairs.push_back(b);
            
            if (pairs.size() == n)
            {
                whjmp(pairs);
                sum += !check();
            }
            else
                sum += dig(picked, pairs);
            
            picked[b] = false;
            pairs.pop_back();
            pairs.pop_back();
        }
    return sum;
}

int main()
{
    fin >> n;
    vector<int> x(n), y(n);
    jmp.clear();
    jmp.assign(n, 0);
    for (int i=0; i<n; i++) fin >> x[i] >> y[i];
    for (int i=0; i<n; i++)
    {
        int jid = -1;
        for (int j=0; j<n; j++)
            if (y[i] == y[j] && x[i] < x[j] && (jid < 0 || x[jid] > x[j]))
                jid = j;
        jmp[i] = jid;
    }
    
    vector<bool> picked(n, false);
    vector<int> pairs;
    fout << dig(picked, pairs) << endl;
    
    return 0;
}
