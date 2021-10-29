#include <bits/stdc++.h>

using namespace std;
#define M 6
#define N 7490

int main() {
  int coins[] = {0, 1, 5, 10, 25, 50};
  int mtr[M][N]; // row as the number of coins and columns as the possibilities of change 

  for(int i = 0; i < M; ++i){
    for(int j = 0; j < N; ++j){
      if(i == 0 and i != j){
        mtr[i][j] = 0;
      } else if(j == 0){
        mtr[i][j] = 1;
      } else{
        mtr[i][j] = (j >= coins[i] ? mtr[i][j - coins[i]] : 0) + mtr[i-1][j];
      }
    }
  }
  
  int n;
  while(cin >> n){
    cout << mtr[M - 1][n] << "\n";
  }

  return 0;
}