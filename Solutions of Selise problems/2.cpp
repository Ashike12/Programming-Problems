#include<bits/stdc++.h>

using namespace std;

int depth;

struct node{
    node *ch1,*ch2;
    int val;
    node(){
        ch1=NULL;
        ch2=NULL;
    }

}*root;

int cnt;

int main()
{
    cin>>depth;
    root = new node();
    cnt = 1;
    root->val = cnt++;
    node *cur;
    cur=root;
    for(int i=1;i<=depth;i++)
    {
        node *tmp;
        for(int j=0;j<2*i;j++)
        {
            node *left_child = new node();
            node *right_child = new node();
        }
    }
    return 0;
}
