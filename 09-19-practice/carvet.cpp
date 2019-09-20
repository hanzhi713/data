/**
 * To compile and run:
 * clang++ -o c c.cpp && ./c
 */
#include <iostream>
#include <vector>
using namespace std;

int lot[250][250];

int main(){
    int r, c;
    int x, y;
    int ept_x, ept_y;
    while(cin>>r>>c){
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                int temp;
                cin>>temp;
                lot[i][j] = temp;
                if(temp == -1){
                    ept_x = i;
                    ept_y = j;
                }
            }
        }
        cin>>x>>y;
        x--;
        y--;
        int car = lot[x][y];
        int ax = x, ay = y;
        int bx, by;
        for(int i = -1; i <=1; i++){
            for(int j = -1; j <= 1; j++){
                if((i != 0 && j != 0) || i == j) continue;
                if(ax + i < 0 || ax + i >= r || ay + j < 0 || ay + j >= c) continue;
                if(lot[ax + i][ay + j] == car){
                    bx = ax + i;
                    by = ay + j;
                }
            }
        }
        vector<int> v;
        int original = car;
        while(true){
            int tempX;
            int tempY;
            if(ax == bx){
                tempX = ax;
                if(ay > by){
                    tempY = by - 1;
                }else{
                    tempY = by + 1;
                }
            }else{
                tempY = ay;
                if(ax > bx){
                    tempX = bx - 1;
                }else{
                    tempX = bx + 1;
                }
            }

            if(tempX < 0 || tempX >= r || tempY < 0 || tempY >= c){
                cout<<"impossible"<<endl;
                break;
            }

            car = lot[tempX][tempY];


            if(car == -2){
                cout<<"impossible"<<endl;
                break;
            }

            if(car == -1){
                for(int i = 0; i < v.size(); i++){
                    cout<<v[i]<<" ";
                }
                cout<<original<<endl;
                break;
            }

            bool flag = false;
            for(int i = 0; i < v.size(); i++){
                if(v[i] == car){
                    cout<<"impossible"<<endl;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            
            v.insert(v.begin(), car);
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    if((i != 0 && j != 0) || i == j) continue;
                    if(ax + i < 0 || ax + i >= r || ay + j < 0 || ay + j >= c) continue;
                    if(lot[tempX + i][tempY + j] == car){
                        ax = tempX;
                        ay = tempY;
                        bx = tempX + i;
                        by = tempY + j;
                    }
                }
            }
        }
    }
    return 0;
}