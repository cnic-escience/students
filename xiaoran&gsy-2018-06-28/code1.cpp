/**
 * Author: xiaoran
 * Time: 2018-06-27 
 */ 
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

class Minmatch{
public:
    Minmatch(){
        init();
    }
    void init();
    pair<int,int> minmatch(string s,string p);
    bool judge();

private:
    int *a; // 默认128个
    int *b; //
    int begin,len;
};

void Minmatch::init(){
    a = new int[128];
    b = new int[128];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    begin = -1;
    len = 0;
}

bool Minmatch::judge(){
    for(int i=0;i<128;i++){
        if(a[i]<b[i]) return false;
    }
    return true;
}

pair<int,int> Minmatch::minmatch(string s,string p){
    init();
    // cout<<s<<endl;
    // cout<<p<<endl;
    for(int i=0;i<p.size();i++){
        b[p[i]-'a'] ++;
    }
    cout<<b[0]<<endl;
    int start, end;
    start = end = 0;
    a[s[end]-'a'] ++;
    while(start<=end && end<s.size()){
        if(judge()){ // True
            if(len > end-start+1 || len == 0){
                len = end-start+1;
                begin = start;
            }
            a[s[start++]-'a'] --;
        }
        else a[s[++end]-'a'] ++;
    }
    if (len > 0){
        cout<< "start: "<< begin << ", length: " << len << ", substr: "<<s.substr(begin,len)<<endl;
    }
    else{
        cout<<"Do not match."<<endl;
    }
    // cout<<s.substr(begin,len)<<endl;
    return pair<int, int>(begin, len);
}

int main(int argc, char* argv[])
{   
    Minmatch match;
    string s,p;
    while(cin>>s>>p){
        match.minmatch(s,p);
    }
    return 0;
}