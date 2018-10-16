#include<bits/stdc++.h>

using namespace std;

string number(int n){
    string str="";
    while(n>0)
    {
        str+= (n%10 + '0');
        n/=10;
    }
    string f="";

    int len = str.length();

    for(int i=len-1;i>=0;i--)
        f+=str[i];
    return f;
}

int main()
{
    int num,div;
    //cout<<number(20);
    while(cin>>num>>div){

    int cnt=0;
    string str="";

        if(num%div==0)
        {
            int ans = 0;
            while(num){
                num-=div;
                ans++;
            }
            str+= number(ans);
        }
        else{
            bool  flag = false;
            int i=0;
            while(i<3)
            {
                while(num<div) {
                    int k = 1,tmp=0;
                    while(k<=num){
                        tmp+=10;
                        k++;
                    }
                    num=tmp;
                    if(num<div) str+='0';
                    if(!flag) str+='.';

                    flag = true;
                }

                int ans = 0;
                if(num%div==0){
                    while(num){
                    num-=div;
                    ans++;
                    }
                    str+= number(ans);
                    break;
                }
                else
                    while(num>=div){
                        num-=div;
                        ans++;
                    }

                str+= number(ans);
                i++;
            }
        }

        cout<<str;
    }

    return 0;
}
