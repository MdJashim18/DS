/**
 *    author:  Mohammad Jashim Uddin
 **/
#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define Y cout << "YES" << endl;
#define yy cout << "Yes" << endl;
#define N cout << "NO" << endl;
#define nn cout << "No" << endl;
#define one cout << "1" << endl;
#define onee cout << "-1" << endl;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


ll partition(ll arr[], ll low, ll high)
{
    ll pivot = arr[high];
    ll i = low - 1;
    for (ll j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


void quickSort(ll arr[], ll low, ll high)
{
    if (low < high)
    {
        ll pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main()
{
    ll n;
    cin >> n;
    ll ar[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    // Sorting
    quickSort(ar, 0, n - 1);
    for (ll i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    return 0;
}



// The time complexity of the Quick Sort algorithm is O(n log n) on average and O(n^2) in the worst case: 
// Best-case time complexity: O(n log n)
// Average-case time complexity: O(n log n)
// Worst-case time complexity: O(n^2)