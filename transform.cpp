#include <iostream>
#include<cstdio>
using namespace std;
void exchange(int b[],int x) {
    int t[81];

    switch(x) {

    case 1:

        for(int i=0,j=72; i<81; i=i+9,j=j-9) {

            for(int k=i,r=j; k<i+9; k++,r++) {

                t[r]=b[k];

            }

        }
        break;

    case 0:

        for(int i=0,j=8; i<9; i++,j--) {

            for(int k=i,r=j; k<i+81; k=k+9,r=r+9) {

                t[r]=b[k];

            }

        }
        break;

    }
    for(int i=0; i<81; i++) {

        b[i]=t[i];

    }

}

void Rotate(int b[]) {

    int t[81];

    for(int k=0,r=8; r>=0; k=k+9,r--) {

        for(int i=k,j=r; i<k+9; i++,j=j+9) {

            t[j]=b[i];

        }

    }

    for(int i=0; i<81; i++) {

        b[i]=t[i];

    }
}

void changeCol(int b[],int x,int y) {

    int temp;

    for(int k=0; k<3; k++) {

        for(int i=(k+(x*3)),j=(k+(y*3)); i<(k+(x*3))+81; i=i+9,j=j+9) {

            temp=b[i];

            b[i]=b[j];

            b[j]=temp;

        }

    }

}

void changeRow(int b[],int x,int y) {

    int temp;

    for(int i=(x*27),j=(y*27); i<((x*27)+27); i++,j++) {

        temp=b[i];

        b[i]=b[j];

        b[j]=temp;

    }

}

void changeNum(int b[],int X,int Y) {

    for(int i=0; i<81; i++) {

        if(b[i]==X) {

            b[i]=Y;

            continue;

        }

        if(b[i]==Y) {

            b[i]=X;

            continue;

        }

    }

}

int main(int argc, const char * argv[]) {



    int a[81];

    int x,y,c;

    for(int i=0; i<81; i++) {

        cin>>a[i];

    }

    while(1) {

        cin>>c;

        if(c==0) {

            break;

        }

        switch(c) {

        case 1:

            cin>>x>>y;

            changeNum(a,x,y);

            break;

        case 2:

            cin>>x>>y;

            changeRow(a,x,y);

            break;

        case 3:

            cin>>x>>y;

            changeCol(a,x,y);

            break;

        case 4:

            cin>>x;

            for(int i=0; i<x; i++) {

                Rotate(a);
            }

            break;

        case 5:

            cin>>x;

            exchange(a,x);

            break;

        }
    }
    for(int i=0; i<81; i++) {
        if((i+1)%9==0) {
            cout<<a[i]<<"\n";
        } else {
            cout<<a[i]<<" ";
        }

    }

    return 0;

}


