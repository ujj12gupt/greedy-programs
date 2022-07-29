#include<bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
    return(a>b)?a:b;
}
// here n is size of array
// W is the load of knapsnack
int knapsnack(int W,int wt[],int val[],int n)
{
    // creating a function whose datatype is a vector
    // creating 2-D vector
    /*
    Create a vector containing "n+1"vectors/rows 
    each of size vector<int>(W+1) .
    */ 
    vector<vector<int>>K(n+1,vector<int>(W+1));
    // here we have created a function of vector of vector
    // and passed two parameteres
    // n+1 is first parameter which is indicating number of rows of table
    // vector<int>(W+1) is second parameter where (W+1) indicating size of vector
    // W+1 is telling number of columns
    // vector<int>(W+1) is telling size of the each row.

    int w;// here w is column_name
    int i;//here i is row_name
    for(i = 0; i <=n;i++)
    {
        for(w = 0; w<= W; w++) 
        {
            if(i == 0||w == 0)
            {
                K[i][w] = 0;
            }
            else if(wt[i-1]<=w)
            {
                K[i][w] = max(val[i-1]+ K[i-1][w-wt[i-1]],K[i-1][w]);
            }
            else
            {
                K[i][w] = K[i-1][w];
            }
        }
    }
    return K[n][W];
}
int main()
{
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapsnack(W,wt,val,n);
    return 0;
}