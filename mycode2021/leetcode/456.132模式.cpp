#define maxsize 150001
#include<stdio.h>
#include<stdlib.h>

bool find132pattern(int* nums, int numsSize){
    if(numsSize<3||!nums)
    {
        return false;
    }
    int *fmin=(int*)malloc(sizeof(int*)*maxsize);
    int *stack=(int*)malloc(sizeof(int*)*maxsize);
    int top=-1;
    fmin[0]=nums[0];
    for(int i=1;i<numsSize-1;i++)
    {
        if(fmin[i-1]>nums[i])
        {
            fmin[i]=nums[i];
        }
        else
            fmin[i]=fmin[i-1];
    }
    for(int i=numsSize-1;i>0;i--)
    {
        if(nums[i]>fmin[i])
        {
            while(top!=-1&&stack[top]<=fmin[i])
            top--;
            if(top!=-1&&stack[top]<nums[i])
            {
                free(fmin);
                free(stack);
                return true;
            }
            stack[++top]=nums[i];
        }
    } 
}