#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <immintrin.h>
#include <malloc.h>

#define TEST_W 1024
#define TEST_H 1024

int main(int argc, char *argv[])
{

    int times[32770];
    int passcon = 0;

    int *src1 = (int *) malloc(sizeof(int) * TEST_W * TEST_H);

    memset(times,0,sizeof(times));
    srand(time(NULL));
    for (int i = 0; i < TEST_H; ++i) {
        for (int j = 0; j < TEST_W; ++j) {
            int tmp = rand()%32768;
            src1[i * TEST_W + j] = tmp;
            times[tmp]++;
        }
    }
    double x2 =0;
    double np = 1024*1024/32768;
    for(int i=0; i<32767; i++) {
        x2 += (pow((times[i]-np),2)/np);
    }


    printf("x^2 = %lf \n",x2);


    return 0;
}
