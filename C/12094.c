#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
int n, max;
int hi[11]={0,};

void back(int d,int t[][25])
{
	int i,j,k;
    int tmp_hi;
	int tmp[25][25],chk[25][25];
	if(d==10)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(max<t[i][j]) max=t[i][j];
        
        if (hi[d]<max) {
            hi[d] = max<<1;
            for(int i=d-1; i>=0; i--){
                hi[i] = hi[i+1]>>1;
            }
        }

		return;
	}
	
	memset(tmp,0,sizeof(tmp)); 
	memset(chk,0,sizeof(chk));
    tmp_hi=0;
	for(i=1;i<=n;i++)
	{
		k=0;
		for(j=1;j<=n;j++)
		{
			if(t[i][j]!=0)
			{
				if(chk[i][k]==0 && tmp[i][k]==t[i][j])
				{
					chk[i][k]=1; tmp[i][k]+=t[i][j];
                    tmp_hi= tmp_hi>tmp[i][k]? tmp_hi:tmp[i][k];
				}
				else
					tmp[i][++k]=t[i][j];
                    tmp_hi= tmp_hi>tmp[i][k]? tmp_hi:tmp[i][k];
			}
		}
	}
	if(tmp_hi>hi[d]) back(d+1,tmp);

	memset(tmp,0,sizeof(tmp));
	memset(chk,0,sizeof(chk));
    tmp_hi=0;
	for(i=1;i<=n;i++)
	{
		k=n+1;
		for(j=n;j>=1;j--)
		{
			if(t[i][j]!=0)
			{
				if(chk[i][k]==0 && tmp[i][k]==t[i][j])
				{
					chk[i][k]=1; tmp[i][k]+=t[i][j];
                    tmp_hi= tmp_hi>tmp[i][k]? tmp_hi:tmp[i][k];
				}
				else
					tmp[i][--k]=t[i][j];
                    tmp_hi= tmp_hi>tmp[i][k]? tmp_hi:tmp[i][k];
			}
		}
	}
	if(tmp_hi>hi[d]) back(d+1,tmp);

	memset(tmp,0,sizeof(tmp)); 
	memset(chk,0,sizeof(chk));
    tmp_hi=0;
	for(i=1;i<=n;i++)
	{
		k=0;
		for(j=1;j<=n;j++)
		{
			if(t[j][i]!=0)
			{
				if(chk[k][i]==0 && tmp[k][i]==t[j][i])
				{
					chk[k][i]=1; tmp[k][i]+=t[j][i];
                    tmp_hi= tmp_hi>tmp[k][i]? tmp_hi:tmp[k][i];
				}
				else
					tmp[++k][i]=t[j][i];
                    tmp_hi= tmp_hi>tmp[k][i]? tmp_hi:tmp[k][i];
			}
		}
	}
	if(tmp_hi>hi[d]) back(d+1,tmp);

	memset(tmp,0,sizeof(tmp));  
	memset(chk,0,sizeof(chk));
    tmp_hi=0;
	for(i=1;i<=n;i++)
	{
		k=n+1;
		for(j=n;j>=1;j--)
		{
			if(t[j][i]!=0)
			{
				if(chk[k][i]==0 && tmp[k][i]==t[j][i])
				{
					chk[k][i]=1; tmp[k][i]+=t[j][i];
                    tmp_hi= tmp_hi>tmp[k][i]? tmp_hi:tmp[k][i];
				}
				else
					tmp[--k][i]=t[j][i];
                    tmp_hi= tmp_hi>tmp[k][i]? tmp_hi:tmp[k][i];
			}
		}
	}
	if(tmp_hi>hi[d]) back(d+1,tmp);

}

int main(){
    int map[25][25]={0,};
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) scanf("%d", &map[i][j]);
    }
    back(0, map);

    printf("%d\n",max);
}