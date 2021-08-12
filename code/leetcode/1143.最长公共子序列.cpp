 int i=0,j=0,a=0,b=0,count=0;
    char text1[1000],text2[1000];
    char t;
    scanf("%s",text1);
    t=getchar();
    scanf("%s",text2);
    t=getchar();
    a=strlen(text1);
    b=strlen(text2);
    if(a!=0&&b!=0){
        while(text1[i]!='\0'&&text2[j]!='\0'){
            if(text1[i]==text2[j])
            {
                count++;
                i++;
                j++;
            }           
            else   {
                j++;
                    }
           }
    }
    printf("%d",count);