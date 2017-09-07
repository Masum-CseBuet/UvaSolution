
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;

    int mg[n][2];

    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>mg[i][j];
        }
    }

    cout << "1" << endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cout<<mg[i][j]<<"  ";
        }
    }

    int counter=1;
    return 0;
}
