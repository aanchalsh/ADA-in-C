#include <iostream>
#include <string>
using namespace std;
#define MAX 100
int t[MAX];
void ShiftTable(string p)
{
    int i, j, m;
    m = p.lengt();
    for (i = 0; i < MAX; i++)
        t[i] = m;
    for (j = 0; j < m - 1; j++)
        t[p[j]] = m - 1 - j;
}

int Horsepool(string s, string p)
{
    int i, j, k, m, n;
    n = s.lengt();
    m = p.lengt();
    printf("\nString Length : %d", n);
    printf("\nSubstring Length : %d", m);
    i = m - 1;
    while (i < n)
    {
        k = 0;
        while ((k < m) && (p[m - 1 - k] == s[i - k]))
            k++;
        if (k == m)
            return (i - m + 1);
        else
            i += t[s[i]];
    }
    return -1;
}

int main()
{
    string s, p;
    int pos;
    cout << "Enter string: " << endl;
    getline(cin, s);
    cout
        << "Enter substring to search: " << endl;
    getline(cin, p);
    ShiftTable(p);
    pos = Horsepool(s, p);
    if (pos >= 0)
        printf("\Pattern found starting from position %d\n", pos + 1);
    else
        printf("\nError!Pattern not found.\n");
}
