#include <iostream>
using namespace std;

int main()
{
    int n, arr[100], key;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at position " << i + 1;
            return 0;
        }
    }

    cout << "Element not found";
    return 0;
}
