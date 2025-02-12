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

    for(ll i=1;i<n;i++)
    {
        ll tmp = ar[i];
        ll j = i-1;
        while(j>=0 && ar[j]>tmp)
        {
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = tmp;
    }

    for(ll i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
    return 0;
}






// Best case (O(n)):
// This occurs when the input array is already sorted, where only a single comparison is needed for each element. 
// Average case (O(n^2)):
// In most scenarios, the algorithm will need to compare each element with a significant number of previous elements, leading to a quadratic time complexity. 
// Worst case (O(n^2)):
// This happens when the input array is in reverse order, requiring the maximum number of comparisons for each element. 