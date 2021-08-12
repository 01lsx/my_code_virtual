int formula(int a){
    int n=0,comp=a;
    while(comp/2>=2)
    n++;
    comp/=2;
    return n;
}
int p,q，m;
q=formula(x);
p=formula(y);
m=abs(q-p);

