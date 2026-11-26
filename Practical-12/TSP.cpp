#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 20

int cost[MAX][MAX];
int path[MAX];
int minCost = 99999;
int bestPath[MAX];
int n;

int main()
{
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    // Initialize path
    for (int i = 0; i < n; i++)
        path[i] = i;

    // Fix starting city as 0
    do
    {
        int totalCost = 0;

        // Calculate cost of the tour
        for (int i = 0; i < n - 1; i++)
        {
            totalCost += cost[path[i]][path[i + 1]];
        }

        // Return to starting city
        totalCost += cost[path[n - 1]][path[0]];

        // Update minimum cost
        if (totalCost < minCost)
        {
            minCost = totalCost;

            for (int i = 0; i < n; i++)
                bestPath[i] = path[i];
        }

    } while (next_permutation(path + 1, path + n));

    cout << "\nMinimum Cost = " << minCost << endl;

    cout << "Optimal Tour: ";
    for (int i = 0; i < n; i++)
        cout << bestPath[i] << " --> ";

    cout << bestPath[0] << endl;

    return 0;
}
