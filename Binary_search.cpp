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
    cin >> n;
    ll ar[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    ll x;
    cin >> x;
    bool flag = false;
    ll lft = 0, rgt = n - 1;
    while (lft <= rgt)
    {
        ll md = (rgt + lft) / 2;
        if (ar[md] == x)
        {
            flag = true;
            break;
        }
        else if (ar[md] < x)
        {
            lft = md + 1;
        }
        else if (ar[md] > x)
        {
            rgt = md - 1;
        }
    }
    if (flag == true)
    {
        Y;
    }
    else
    {
        N;
    }
    return 0;
}



// The time complexity of the binary search algorithm is \(O(\log n)\), where \(n\) is the number of elements in the array. This is much faster than linear search, which has a time complexity of \(O(n)\)