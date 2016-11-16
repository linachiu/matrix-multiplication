#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <immintrin.h>
#include <malloc.h>

int testfun(int *src1,int src_w,int src_h)
{
    int times[32770];
    int passcon = 0;
    int faildcon = 0;

    while(passcon == 0 ) {

        int runs=0;
        int cmp= -1;
        int upp = 0;
        int failflag =0;

        memset(times,0,sizeof(times));
        srand(time(NULL));

        for (int i = 0; i < src_h; ++i) {
            for (int j = 0; j < src_w; ++j) {
                int tmp = rand()%32768;
                src1[i * src_w + j] = tmp;
                times[tmp]++;
                if(upp == 1 && tmp < cmp) {
                    runs++;
                    upp = 0;
                } else if(upp == 0 && tmp > cmp) {
                    runs++;
                    upp = 1;
                }
                cmp = tmp;
            }
        }

        double y = src_w * src_h;
        double m = (2 * y - 1) / 3;
        double a2 = (16 * y - 29) / 90;
        double a = pow( a2, 0.5);
        double z = 1.96;
        double min = m - z * a;
        double max = m + z * a;

        if(runs > max || runs < min) {
            failflag = 1;
            //printf("runsfail!");
        }
        printf("runs = %d \n",runs);
        min = 32550 ;
        max = 32980;

        if(failflag == 0) {
            double x2 =0;
            double np = 1024*1024/32768;
            for(int i=0; i<32767; i++) {
                x2 += (pow((times[i]-np),2)/np);
            }
            if(x2<min || x2>max)
                failflag =1;

            printf("x^2 = %lf \n",x2);
        }
        if(failflag == 0) {
            passcon++;
            printf("pass!!\n");
        } else {

            faildcon++;
        }
    }
    printf("faild %d times !!\n", faildcon);
    return 0;
}