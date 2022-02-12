/* Poisson's equation */

#include <stdio.h>
#define _USE_MATH_DEFINES

#include <math.h>
#define N 5
int main(void){
    int i,j,m;
    float u[N+1][N+1],U,er,d,h;
    d=1.0;
    h=d/N;
    for(i=0;i<=N;i++){
        for(j=0;j<=N;j++)
            u[i][j]=0.0;
        u[i][N]=sin(M_PI*h*i);
    }
        

    m=0;
    do {
        er=0.0;
        for(i=1;i<N;i++) {
            for(j=1;j<N;j++) {
                U=(u[i-1][j]+u[i][j-1]+u[i+1][j]+u[i][j+1])/4.0;
                if(i==j)U+=2.135/8.85418782*100/4.0*h*h;
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

/*
    26
   0.00   0.59   0.95   0.95   0.59  -0.00
   0.00   0.41   0.71   0.80   0.70   0.00
   0.00   0.36   0.66   0.85   0.46   0.00
   0.00   0.38   0.72   0.53   0.28   0.00
   0.00   0.42   0.35   0.25   0.13   0.00
   0.00   0.00   0.00   0.00   0.00   0.00
*/