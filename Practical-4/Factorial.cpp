#include <iostream>
using namespace std;

// Iterative method
int iterativeFactorial(int n)
{
    int fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

// Recursive method
int recursiveFactorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return n * recursiveFactorial(n - 1);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Factorial (Iterative) = " << iterativeFactorial(n) << endl;
    cout << "Factorial (Recursive) = " << recursiveFactorial(n) << endl;

    return 0;
}
