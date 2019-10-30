/**
 * To compile and run:
 * clang++ -o h h.cpp && ./h
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll x1, y_1, x2, y2;

bool cut(ll x, ll y){
    if(x >= x1 && x <= x2 && y >= y_1 && y <= y2){
        return true;
    }
    return false;
}

int main(){
    ll xb, yb;
    cin>>xb>>yb>>x1>>y_1>>x2>>y2;
    
    ll gcd = __gcd(xb, yb);

    ll unit_x = xb / gcd;
    ll unit_y = yb / gcd;

    bool flag = false;

    if(gcd == 1){
        cout<<"Yes"<<endl;
    }else if(!cut(unit_x, unit_y)){
        cout<<"No"<<endl;
        cout<<unit_x<<" "<<unit_y<<endl;
    }else{
        if(cut(xb, yb) || cut(xb - unit_x, yb - unit_y)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
            double y_intercept = ((double)x2 / (double)unit_x) * unit_y;
            double x_intercept = ((double)y2 / (double)unit_y) * unit_x;
            if(y_intercept > y_1 && y_intercept < y2){
                ll n = x2 / unit_x;
                cout<<(n + 1) * unit_x <<" "<<(n + 1) * unit_y<<endl;
            }else{
                ll n = y2 / unit_y;
                cout<<(n + 1) * unit_x <<" "<<(n + 1) * unit_y<<endl;
            }
        }
    }

    // for(ll i = 1; i < gcd; i++){
    //     ll tx = i * unit_x;
    //     ll ty = i * unit_y;
    //     if(!cut(tx, ty)){
    //         cout<<"No"<<endl;
    //         cout<<tx<<" "<<ty<<endl;
    //         flag = true;
    //         break;
    //     }
    // }

    // cout<<gcd<<endl;

    // if(!flag){
    //     cout<<"Yes"<<endl;
    // }

    return 0;
}