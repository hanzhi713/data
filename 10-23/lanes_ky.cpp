/**
 * To compile and run:
 * clang++ -o d d.cpp && ./d
 */
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int mem[250][250];
int len[250];
int ss[250];
int cs[250];

int main(){
    int n, m, k, r;
    cin>>n>>m>>k>>r;

    for(int i = 0; i < n; i++){
        cin>>len[i];
    }

    for(int i = 0; i < n - 1; i++){
        cin>>ss[i]>>cs[i];
    }

    for(int j = 0; j < m; j++){
        if(len[0] >= j * k){
            mem[0][j] = j * r + len[0];
        }else{
            mem[0][j] = -1;
        }
    }

    

    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){ // change to lane j + 1
            int min = INT_MAX;
            for(int l = 0; l < m; l++){ // from lane l + 1
                int a = mem[i - 1][l];

                if(a == -1){
                    continue;
                }
                
                a += ss[i - 1] + cs[i - 1] * (l + 1);

                if(len[i] >= abs(l - j) * k){
                    a += len[i] + r * abs(l - j);
                }else{
                    // a += len[i];
                    continue;
                }
                if(a < min){
                    min = a;
                }
            }
            if(min == INT_MAX){
                mem[i][j] = -1;
            }else{
                mem[i][j] = min;
            }
        }
    }

    // int min = INT_MAX;

    // for(int i = 0; i < m; i++){
    //     int temp = mem[n - 1][i];
    //     if(temp == -1){
    //         continue;
    //     }
    //     if(temp < min){
    //         min = temp;
    //     }
    // }

    cout<<mem[n - 1][0]<<endl;
    return 0;
}