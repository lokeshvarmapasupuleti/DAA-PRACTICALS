#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int coins(int N, vector<int> &d)
{
    int n = d.size();
    const int INF = INT_MAX / 2;

    vector<vector<int>> c(n, vector<int>(N + 1, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == 0 && j < d[i])
                c[i][j] = INF;
            else if (i == 0)
                c[i][j] = 1 + c[i][j - d[i]];
            else if (j < d[i])
                c[i][j] = c[i - 1][j];
            else
                c[i][j] = min(c[i - 1][j],
                              1 + c[i][j - d[i]]);
        }
    }

    return c[n - 1][N];
}

int main()
{
    int n, N;

    cout << "Enter number of denominations: ";
    cin >> n;

    vector<int> d(n);

    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++)
        cin >> d[i];

    cout << "Enter amount: ";
    cin >> N;

    int result = coins(N, d);

    if (result >= INT_MAX / 2)
        cout << "Change cannot be made." << endl;
    else
        cout << "Minimum number of coins: " << result << endl;

    return 0;
}
