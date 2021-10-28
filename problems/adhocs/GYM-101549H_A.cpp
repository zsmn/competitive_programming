#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max(a,b) (a>b?a:b) 

int main() {
    int n, i, dmenor=32, dmaior=0, d, mmenor=13, mmaior=0, m, amenor=10000, amaior=0, a;
    char old[20], novo[20], agora[20];
    scanf ("%d", &n);
    for(i=1;i<=n;i++){
        scanf(" %s %d %d %d", agora,&d, &m, &a);
        if(a>amaior){
            strcpy(novo,agora); // novo = agora
            amaior = a;
            dmaior = d;
            mmaior = m;
        }
        if(a<amenor){
            strcpy(old,agora);
            amenor = a;
            dmenor = d;
            mmenor = m;
        }
        if(a==amaior){
            if(m>mmaior){
                strcpy(novo,agora);
                mmaior=m;
                dmaior=d;
            }if(m==mmaior){
                if(d>dmaior){
                    strcpy(novo,agora);
                    dmaior=d;
                }
            }
        }
        if(a==amenor){
            if(m<mmenor){
                strcpy(old,agora);
                mmenor=m;
                dmenor=d;
            }if(m==mmenor){
                if(d<dmenor){
                    strcpy(old,agora);
                    dmenor=d;
                }
            }
        }
    }
    printf("%s\n", novo);
    printf("%s", old);
    
	return 0;
}
