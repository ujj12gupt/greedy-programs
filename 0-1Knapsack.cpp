#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    return(a>b)?a:b;
}
int knapsack(int W,int wt[],int val[],int n)
{
    // base class
    if(n == 0|| W == 0)
    {
        return 0;
    }
    // If weight of nth item is more

    // then Knapsack capacity W, then
    // this item cannot be included in 
    // optimal solution
    if(wt[n-1]>W)
    {
        // we will call the function again
        return knapsack(W,wt,val,n-1);
        // thus we eliminated that element 
    }
    else
    {
        return max(val[n-1]+knapsack(W-wt[n-1],wt,val,n-1),knapsack(W,wt,val,n-1));
    }
}
int main()
{
    // let us consider 3 objects
    // A B C
    // weight of object A is 10  and value is 60
    // weight of object B is 20 and value is 100
    // weight of object C is 30 and value is 120
    
    // always remember: val[] and wt[] is always in ascending order
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    // weight of bag/Knapsack
    // to calculate size of array
    int n = sizeof(val)/sizeof(val[0]);
    int W = 50;
    cout<< knapsack(W, wt, val, n);
    return 0;
}