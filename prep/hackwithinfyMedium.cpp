#include<bits/stdc++.h>

using namespace std;

int getMaximumValue(int n , vector<int>& values){
    int momentum = 0;
    int count = 0;
    // checking if the value in the values are strictly decreasing 
    bool isDecreasing = true;
    for(int i = 1; i < n;i++){
        if(values[i] > values[i - 1]){
            isDecreasing  = false;
            break;
        }
    }
    if(values.size() == 1) return 1;
    if(isDecreasing) return 2;
    for(int i = 0; i < n;i++){
        if(values[i] >= momentum){
            count++;
            momentum = values[i];
        }
        if(values[i] < momentum){
            momentum = 0;
        }
    }
    return count;
}

int countAccepted(
    const vector<int>& values,
    int start,
    int end
){
    int momentum = 0;
    int accepted = 0;

    for(int i = start; i <= end; i++){
        if(values[i] >= momentum){
            accepted++;
            momentum = values[i];
        }
    }

    return accepted;
}

int getMaximumValue(int n, vector<int>& values)
{
    if(n==0) return 0;
    if(n==1) return 1;

    int answer = 0;

    // try using the one reset at every possible index
    for(int split=0; split<n; split++)
    {
        int leftAccepted=0;
        int rightAccepted=0;

        if(split>0)
            leftAccepted =
                countAccepted(values,0,split-1);

        // reset happens here, fresh momentum=0
        rightAccepted =
            countAccepted(values,split,n-1);

        answer=max(
            answer,
            leftAccepted+rightAccepted
        );
    }

    return answer;
}