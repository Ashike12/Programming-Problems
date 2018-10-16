#include<bits/stdc++.h>

using namespace std;

int main()
{
    double FV=312.5,VV=156.25,SV=125,cf=0,cv=0,cs=0,dis=54000000;
    int i=0;

    bool cff=false,cvv=false,css=false;

    for(int i=0;i<2592000;i++)
    {
        if(!cff){
            cf+=FV;
            if(cf>dis) cf=dis-(cf-dis),cff=true;
        }
        else
        {
            cf-=FV;
            if(cf<0) cf = cf*-1.0,cff=false;
        }

        if(!cvv){
            cv+=VV;
            if(cv>dis) cv=dis-(cv-dis),cvv=true;
        }
        else
        {
            cv-=VV;
            if(cv<0) cv = cv*-1.0,cvv=false;
        }

        if(!css){
            cs+=SV;
            if(cs>dis) cs=dis-(cs-dis),css=true;
        }
        else
        {
            cs-=SV;
            if(cs<0) cs = cs*-1.0,css=false;
        }


        if(cf==cv==cs)
        {
            printf("%dsec %.1lf \n",i,cf);
            //break;
        }

        //cout<<cf<<" "<<cv<<" "<<cs<<endl;

    }

    return 0;
}
