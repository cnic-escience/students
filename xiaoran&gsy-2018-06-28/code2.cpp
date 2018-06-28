/**
 * Author: xiaoran
 * Time: 2018-06-28
 */ 
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
bool val[101][101] = {0};
    
bool isInterleave(string s1,string s2,string s3){
    int s1len=s1.size(),s2len=s2.size(),s3len=s3.size();
    if(s1len+s2len!=s3len)return false;
    memset(val,0,sizeof(val));

    val[0][0]=true;
    for(int i=1;i<=s1len;i++){
        val[i][0]=val[i-1][0]&&s1[i-1]==s3[i-1];
    }
    for(int i=1;i<=s2len;i++){
        val[0][i]=val[0][i-1]&&s2[i-1]==s3[i-1];
    }
    for(int i=1;i<=s1len;i++){
        for(int j=1;j<=s2len;j++){
            val[i][j]=(val[i][j-1]&&s2[j-1]==s3[i+j-1])||(val[i-1][j]&&s1[i-1]==s3[i+j-1]);
        }
    }

    return val[s1len][s2len];
}


int main()
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    string s4 = "aadbbbaccc";
    
    cout<<isInterleave(s1,s2,s3)<<endl;

    cout<<isInterleave(s1,s2,s4)<<endl;

    return 0;
}