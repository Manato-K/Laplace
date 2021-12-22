/* laplace */
#include <stdio.h>
#include <math.h>
#define N 3
int main(void){
    int i,j,m;
    float u[N+1][N+1],U,er,d,h;
    d=12.0;
    h=d/N;
    for(i=0;i<=N;i++)
        for(j=0;j<=N;j++) u[i][j]=0.0;
    for(i=0;i<=N;i++) {
        u[i][0]=100.0;
        u[0][i]=100.0;
        u[N][i]=100.0;
    }
    m=0;
    do {
        er=0.0;
        for(i=1;i<N;i++) {
            for(j=1;j<N;j++) {
                U=(u[i-1][j]+u[i][j-1]
                +u[i+1][j]+u[i][j+1])/4.0;
                er+=fabs(U-u[i][j]);
                u[i][j]=U;
            }
        }
        m++;
    } while(er>1.0e-4);
    printf("%d\n",m);
    for(j=N;j>=0;j--) {
        for(i=0;i<=N;i++) printf("%7.2f",u[i][j]);
        printf("\n");
    }
}