#include <stdio.h>
#include <iostream>

#define tmax 10010
using namespace std;

int mat[tmax][tmax];

int maximo(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

void subseq(int ta, int tb, string l1, string l2){
    int i, j;
    for(i = 0; i<=ta; i++){
        for(j = 0; j<=tb; j++){
            if(j == 0|| i == 0){
                mat[i][j] = 0;
            }else{
                if(l1[(i -1)] == l2[(j-1)]){
                    mat[i][j] = mat[(i -1)][(j -1)] +1;
                }else{
                    mat[i][j] = maximo(mat[i][(j -1)],mat[(i-1)][j]);
                }
            }
        }
    }
}

int main(){
    int ta, tb;
    string l1,l2;
    while(getline(cin,l1)&& getline(cin,l2)){
        ta = l1.size();
        tb = l2.size();
        subseq(ta,tb,l1,l2);
        printf("%d\n", mat[ta][tb]);
    }
}