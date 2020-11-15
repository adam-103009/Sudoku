#include <iostream>
#include<vector>
using namespace std;
bool Checking(int (*board)[9], int x, int y);
bool solve(int (*sudo)[9]);
bool solve(int (*sudo)[9]) {
    for (int row = 0; row < 9; row++)
        for (int col = 0; col < 9; col++) {
            if (sudo[row][col] == 0) {
                for (int i = 1; i < 10; i++) {
                    sudo[row][col] = i;
                    if (Checking(sudo,row,col) && solve(sudo))
                        return true;
                    sudo[row][col] = 0;
                }
                return false;
            }
        }
    return true;
}
bool Checking(int (*board)[9], int x, int y) {
    for (int row = 0; row < 9; row++) {
        if (row != x && board[row][y] == board[x][y])
            return false;
    }
    for (int col = 0; col < 9; col++) {
        if (col != y && board[x][col] == board[x][y])
            return false;
    }
    for (int row = 3 * (x / 3); row < 3 * (x / 3 + 1); row++)
        for (int col = 3 * (y / 3); col < 3 * (y / 3 + 1); col++)
            if ((row != x || col != y) && board[row][col] == board[x][y])
                return false;
    return true;
}
int main() {
    int a[9][9],c=0;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin>>a[i][j];
        }
    }
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(a[i][j]==0) {
                c++;
            }
        }
    }
    if(c>64) {
        cout<<2<<"\n";
        return 0;
    }

    if(solve(a)) {
        cout<<1<<"\n";
        solve(a);
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if((j+1)%9==0) {
                    cout<<a[i][j]<<"\n";
                } else {
                    cout<<a[i][j]<<" ";
                }
            }
        }
    } else {
        cout<<0<<"\n";
    }



    return 0;
}

