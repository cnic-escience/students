/**
 * Author: xiaoran
 * Time: 2018-06-28
 */ 

#include<iostream>
#include<cstring>
using namespace std;
int a[105][105],sum[105],b[105];
const int MIN_VALUE = -10000000;
int main()
{
    int n;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j<=i) cin>>a[i][j];
                else a[i][j] = MIN_VALUE;
            }
        }
        memset(sum,0,sizeof(sum));
        int max=MIN_VALUE;
        for(int i=1;i<=n;i++){
            memset(sum,0,sizeof(sum));
            memset(b,0,sizeof(b));
            for(int k=i;k<=n;k++){
                for(int j=1;j<=n;j++){
                    b[j]+=a[k][j];
                    if(sum[j-1]>=0){
                        sum[j]=sum[j-1]+b[j];
                    }
                    else sum[j]=b[j];
                    if(max<sum[j]) max=sum[j];
                }
            }
        }
        cout<<max<<endl;
 
    }
    return 0;
}
