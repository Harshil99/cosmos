li N = 3e6-10;

vi BIT1(3e6);
vi BIT2(3e6);

void add(vector<li> &b,li x,li v)
{
    for(;x<=N;x+=(x&(-x)))
        b[x]+=v;
}

li range_add(li l,li r,li x)
{
    add(BIT1,l,x);
    add(BIT1,r+1,-x);
    add(BIT2,l,x*(l-1));
    add(BIT2,r+1,-x*r);
}

li query(vector<li> &b,li x)
{
    li ans=0;

    for(;x>0;x-=(x&(-x)))
    {
        ans+=b[x];
    }

    return ans;
}

li pre_sum(li x)
{
    return query(BIT1,x)*x - query(BIT2,x);
}

li range_sum(li l,li r)
{
    return pre_sum(r)-pre_sum(l-1);
}