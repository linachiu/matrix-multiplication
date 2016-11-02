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

int main()
{

    int times[32770],times2[32770];
    memset(times,0,sizeof(times));
    memset(times2,0,sizeof(times2));
    int *src1 = (int *) malloc(sizeof(int) * TEST_W * TEST_H);
    int *src2 = (int *) malloc(sizeof(int) * TEST_W * TEST_H);

    srand(time(NULL));
    for (int i = 0; i < TEST_H; ++i) {
        for (int j = 0; j < TEST_W; ++j) {
            int tmp = rand()%32768;
            src1[i * TEST_W + j] = tmp;
            times[tmp]+=1;
            tmp   = rand()%32768;
            src2[i * TEST_W + j]=tmp;
            times2[tmp]+=1;
        }
    }

    printf("%d\n",RAND_MAX);

    FILE *fp;
    fp = fopen("detail.txt","w");

    for ( int i = 0; i < 32768; i++ )
        fprintf(fp,"%d %d %d\n",i,times[i],times2[i]);

    fclose(fp);

    return 0;
}
