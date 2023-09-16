#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define N1 16
#define N2 16
#define N  (N1*N2) 
#define PI 3.1415926535897932

typedef struct cplxFloat_
{
    float real;
    float imag;
} cplxFloat;


/* get parial FFT weight vector */
void getWeight(cplxFloat *w, int16_t M, int16_t N)
{
    int16_t i;
    for (i = 0; i < M; i++)
    {
        w[i].real =  cos(2*PI*i/N);
        w[i].imag = -sin(2*PI*i/N);
    }
}

/* complex-valued multiplication */
cplxFloat cplxMul(cplxFloat x, cplxFloat y)
{
    cplxFloat z;

    z.real = x.real*y.real - x.imag*y.imag;
    z.imag = x.real*y.imag + x.imag*y.real;

    return z;
}


int main(void)
{   
    int16_t n, k, n1, n2;
    int16_t freqMinIdx, freqMaxIdx;
    int16_t coarseFreqIdx, fineFreqIdx;
    int16_t coarseIdxMask = N1-1;
    int16_t fineIdxMask = N2-1;
    cplxFloat weight, temp;
    cplxFloat partialFFTout;

    /* 40 ~ 70 번째 주파수 인덱스를 관찰하겠다. */
    specMinIdx = 40;
    specMaxIdx = 70;         

    cplxFloat wCoarse[N1];
    cplxFloat wFine[N2];
    getWeight(wCoarse, (int16_t)N1, (int16_t)N1);
    getWeight(wFine, (int16_t)N2, (int16_t)N);

    /* loop w.r.t. frequency index */
    for (k = freqMinIdx; k <= freqMaxIdx; k++)
    {
        coarseFreqIdx = (int16_t)(k/N2); 
        fineFreqIdx = k - coarseFreqIdx*N2; 

        /* loop w.r.t. input sample index */
        partialFFTout.real = partialFFTout.imag = 0;
        for (n = 0; n < N; n++)
        {   
            n2 = n*fineFreqIdx;         
            n1 = n*coarseFreqIdx + n2/N2;

            /* bit mask for modulo operation */    
            n1 &= coaseIdxMask;
            n2 &= fineIdxMask;

            /* w^{kn} in DFT matrix */
            weight = cplxMul(wCoarse[n1], wFine[n2]);

            /* partial FFT output */
            temp = cplxMul(weight, x[n]); // x가 있다고 가정
            partialFFTout.real += temp.real;
            partialFFTout.imag += temp.imag;
        }
        /* 
        partialFFTout 어딘가에 복사 혹은 배열로 잡으면 됨. 이하 생략
        */
    }

    return 0;
}