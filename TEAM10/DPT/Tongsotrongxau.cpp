#include<bits/stdc++.h>
#include<string.h>
#include"../../_src/Log.h"
#include"../../_src/Utils.h"
#define Test
using namespace std;
string s, temp;
int ans = 0;
void Nhap()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen(Test".inp","r",stdin);
        freopen(Test".out","w",stdout);
        #endif
        getline(cin,s);
        s += ' ';
}
void Solve()
{
    for(auto &ch: s)
    {
        if(isdigit(ch)) temp += ch;
        else{
            if(temp != "") ans += atoi(temp.c_str());
            temp = "";
        }
    }
    cout << ans;
}
int main()
{
    LOG_WT("Bai: Tong so trong xau\n");
    LOG_IT("Ten: Do Phu Thanh\n");
    LOG_IT("Msv: 21T1020710\n");
    LOG_DT("-----\n");
    LOG_DT("Nhap chuoi: ");
    Nhap();
    LOG_WT("\nTong so: ");
    Solve();
}