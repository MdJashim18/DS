
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

int main()
{
    ll n;
    cin>>n;
    ll ar[n];
    for(ll i=0;i<n;i++)
    {
        cin>>ar[i];
    }

    for(ll i=0;i<n-1;i++)
    {
        ll mn = i;
        for(ll j=i+1;j<n;j++)
        {
            if(ar[j]<ar[mn])
            {
                mn = j;
            }
        }
        if(mn!=i)
        {
            swap(ar[i],ar[mn]);
        }
    }

    for(auto x:ar)
    {
        cout<<x<<" ";
    }
    return 0;
}






// Key points about Selection Sort time complexity:
// Best case:
// O(n^2) - Even if the array is already sorted, the algorithm still needs to perform the same number of comparisons.
// Average case:
// O(n^2) - The average case is also O(n^2) as the number of comparisons remains roughly the same regardless of the initial array order.
// Worst case:
// O(n^2) - The worst case occurs when the array is in reverse order and needs to perform the maximum number of comparisons