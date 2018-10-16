#include <bits/stdc++.h>

using namespace std;

int main()
{
    int numberOfCases;
    cin>>numberOfCases;

    for(int cases=1; cases<=numberOfCases; cases++){
       int lengthOfSequence, sequence[105];
       cin>>lengthOfSequence;
       for(int i=0;i<lengthOfSequence;i++){
        cin>>sequence[i];
       }
       int Start = 0, End = 0;
       for(int subSeqLen=1;subSeqLen<=lengthOfSequence;subSeqLen++){
            int slidingSize = lengthOfSequence-subSeqLen;
            for(int i=0; i<=slidingSize; i++){
                int localStart = i, localEnd = i+subSeqLen, sum=0, mul=1;
                for(int j=localStart; j<localEnd; j++){
                    sum+=sequence[j];
                    mul*=sequence[j];
                }
                if(sum==mul){
                    Start = localStart;
                    End = localEnd;
                }
            }
       }
       printf("Case %d#\n%d\n", cases, End-Start);
       for(int i=Start;i<End;i++)
            printf("%d ", sequence[i]);
       printf("\n");
    }

    return 0;
}
