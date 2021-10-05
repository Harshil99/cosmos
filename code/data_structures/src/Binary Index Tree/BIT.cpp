li n;
vi BIT(3e6);

void update(li x,li v)
{
    for(;x<=n;x+=(x&(-x)))
        BIT[x]+=v;
}

li query(li x)
{
    li ans=0;

    for(;x>0;x-=(x&(-x)))
    {
        ans+=BIT[x];
    }

    return ans;
}