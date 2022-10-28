#include "bits/stdc++.h"
#include <vector>
#define batas 447
using namespace std;

vector<unsigned long long int> total(batas + 1);
int coord1[batas + 1];
int coord2[batas + 1];
char direction;

void nextDirection() {
    if (direction == 'T') { direction = 'U'; }
    else if (direction == 'U') { direction = 'B'; }
    else if (direction == 'B') { direction = 'S'; }
    else { direction = 'T'; }
}

void init_() {
    unsigned long long int sum = 0;
    direction = 'S';
    coord1[0] = 0;
    coord2[0] = 0;
    for(int i=1; i<=batas; i++) {
        sum += i;
        total[i] = sum;
        nextDirection();
        if (direction == 'T') {
            coord1[i] = coord1[i-1] + i;
            coord2[i] = coord2[i-1];
        } else if (direction == 'U') {
            coord1[i] = coord1[i-1];
            coord2[i] = coord2[i-1] + i;
        } else if (direction == 'B') {
            coord1[i] = coord1[i-1] - i;
            coord2[i] = coord2[i-1];
        } else {
            coord1[i] = coord1[i-1];
            coord2[i] = coord2[i-1] - i;
        }
    }
}

void checkDirection(int idx) {
    if(idx % 4 == 0) {
        direction = 'S';
    } else if (idx % 4 == 1) {
        direction = 'T';
    } else if (idx % 4 == 2) {
        direction = 'U';
    } else {
        direction = 'B';
    }
} 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;
    
    init_();

    for(int i=0; i<n; i++) {
        int m;
        cin>>m;
        vector<unsigned long long int>::iterator lb = lower_bound(total.begin(), total.end(), m);
        int idx = lb - total.begin();
        checkDirection(idx);
        if (total[idx] != m) {
            idx -= 1;
        }
        int lbval = total[idx];
        int stepleft = m - lbval;
        pair<int, int> coord;
        if (direction == 'T') {
            coord.first = coord1[idx] + stepleft;
            coord.second = coord2[idx];
        } else if (direction == 'U') {
            coord.first = coord1[idx];
            coord.second = coord2[idx] + stepleft;
        } else if (direction == 'B') {
            coord.first = coord1[idx] - stepleft;
            coord.second = coord2[idx];
        } else {
            coord.first = coord1[idx];
            coord.second = coord2[idx] - stepleft;
        }
        cout<<coord.first<<" "<<coord.second<<endl;
    }

    // for (int i=0; i<20; i++) {
    //     cout<<total[i]<<" pair: "<<coord1[i]<<", "<<coord2[i]<<endl;
    // }
}