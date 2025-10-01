#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, max = 0;
    int players[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int gol;
        cin >> gol;
        if (gol > max)
        {
            max = gol;
            m = 1;
            players[0] = i;
        }
        else if (gol == max)
        {
            players[m++] = i;
        }
    }
    cout << max << "\n"
         << m << "\n";
    for (int i = 0; i < m; i++)
    {
        cout << players[i] + 1 << "\n";
    }
}