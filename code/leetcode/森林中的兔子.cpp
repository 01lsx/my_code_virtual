int numRabbits(int* answers, int answersSize){
int a[1000];
int count=0;
int i,x,y;
for(i=0;i<1000;i++)
{
    a[i]=0;
}
for(i=0;i<answersSize;i++)
{
    a[answers[i]]++;
}
for(i=0;i<1000;i++)
{
    if(a[i]!=0)
    {
        if(a[i]<=i+1)
        count=count+i+1;
        else if(a[i]>i+1)
        {
            x=a[i]%(i+1);
            y=a[i]/(i+1);
            if(x==0)
            count= count+(i+1)*y;
            else
            count=count+(i+1)*(y+1);
        }
    }
}
return count;
}