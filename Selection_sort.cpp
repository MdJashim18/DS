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

    // Sorting 
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

    for(ll i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
    return 0;
}