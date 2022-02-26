#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
signed main() 
{
    (*cin.tie(0)).sync_with_stdio(0);
    int t; 
    cin >> t;
    while(t--)
    {
        int n;
        int64_t x;
        cin >> n >> x;
        vector<int64_t> ar(n);
        for(auto &it : ar)
        {
            cin >> it;
        }
        sort(ar.begin(), ar.end());
        vector<bool> vis(n);
        int j = 0, q = 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(vis[i])
            {
                continue;
            }
            if(ar[i] * x > ar[j])
            {
                while(ar[j] <= ar[i] * x && j < n)
                {
                    j++;
                }
                j--;
                q = j;
            }
            if(i < q && ar[i] * x == ar[q])
            {
                vis[q--] = true;
            }
            else{
                ans++;
            }
        }
        cout << ans << endl;
    }
}