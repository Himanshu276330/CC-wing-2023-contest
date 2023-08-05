#include <bits/stdc++.h>
#define ll __int128
using namespace std;
int a, b;
int largestSegment(vector<ll> &divPermutation, int a, int b)
{
    int n = divPermutation.size();
    ll number = a * 1ll * b;
    int i = 0, j = 0;
    ll curr = 1;
    int ans = 0;
    while (j < n)
    {
        curr *= divPermutation[j];
        while (number % curr)
        {
            curr /= divPermutation[i];
            i++;
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    vector<int> divA, divB;
    for (int i = 1; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            divA.push_back(i);
            divA.push_back(a / i);
        }
    }
    for (int i = 1; i * i <= b; i++)
    {
        if (b % i == 0)
        {
            divB.push_back(i);
            divB.push_back(b / i);
        }
    }
    set<ll> div;
    for (int it : divA)
    {
        for (int itr : divB)
        {
            div.insert(it * 1ll * itr);
        }
    }
    vector<ll> divisors(div.begin(), div.end());
    ;
    int size = divisors.size();
    vector<int> permutation(size);
    for (int i = 0; i < size; i++)
        cin >> permutation[i];
    vector<ll> divPermutation(size);
    for (int i = 0; i < size; i++)
    {
        divPermutation[i] = divisors[permutation[i] - 1];
    }
    cout << largestSegment(divPermutation, a, b) << '\n';
}