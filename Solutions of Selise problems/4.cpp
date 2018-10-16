#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,row,col,cnt=1;
    cin>>n;
    int arr[100][100];
    row = n, col=1;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            row = n-i-1;
            col = 0;
            for(int j=0;j<=i;j++)
            {
                arr[row][col] = cnt++;
                row++,col++;
            }
        }
        else
        {
            row=n-1;
            col=i;
            for(int j=0;j<=i;j++)
            {
                arr[row][col] = cnt++;
                row--,col--;
            }
        }
    }
    if(n%2==1){
    for(int i=0;i<n-1;i++)
    {
        if(i%2==0)
        {
            col = n-1;
            row = n-i-2;
            for(int j=0;j<=n-i-2;j++)
            {
                arr[row][col] = cnt++;
                row--,col--;
            }
        }
        else
        {
            row=0;
            col=i+1;
            for(int j=0;j<=n-i-2;j++)
            {
                //cout<<row<<" "<<col<<"\n";
                arr[row][col] = cnt++;
                row++,col++;
            }
        }
    }
    }
    else{
        for(int i=0;i<n-1;i++)
    {
        if(i%2==1)
        {
            col = n-1;
            row = n-i-2;
            for(int j=0;j<=n-i-2;j++)
            {
                arr[row][col] = cnt++;
                row--,col--;
            }
        }
        else
        {
            row=0;
            col=i+1;
            for(int j=0;j<=n-i-2;j++)
            {
                //cout<<row<<" "<<col<<"\n";
                arr[row][col] = cnt++;
                row++,col++;
            }
        }
    }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<"\t";

        cout<<"\n";
    }

    return 0;
}
