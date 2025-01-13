#include<cstdio>
#include<algorithm>
#include<cmath>
double M=log10(18446744073709551615.0);
using namespace std;
int e[45]={4,6,8,9,10,12,14,15,16,18,20,21,22,24,25,26,27,28,30,32,33,34,35,36,38,39,40,42,44,45,46,48,49,50,51,52,54,55,56,57,58,60,62,63,64};
unsigned long long Pow(unsigned long long x,int k)
{
    if(k==1) return x;
    unsigned long long y=Pow(x,k/2);
    y*=y;
    if(k%2) y*=x;
    return y;
}

unsigned long long ans[100000];
int main()
{
    int N=1;
    for(int i=2;i<65536;i++)
    {
        int flag=1;
        for(int j=0;j<45;j++)
        {
            if((double)(e[j]*1.0)*log10(i)>M) break;
            unsigned long long temp=Pow(i,e[j]);
            ans[N++]=temp;
            flag=0;
        }
        if(flag) break;
    }
    printf("1\n");
    sort(ans+1,ans+N);
    for(int i=1;i<N;i++)
    if(ans[i]!=ans[i-1]) printf("%llu\n",ans[i]);
    return 0;
}