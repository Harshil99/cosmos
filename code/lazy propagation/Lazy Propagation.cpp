vi seg(3e6);
vi lazy(3e6);
vi a;
 
void build(li i,li start,li end)
{
    if(start==end)
    {
        seg[i]=a[start];
        return;
    }
    else
    {
        li mid=(start+end)/2;
 
        build(2*i,start,mid);
        build(2*i+1,mid+1,end);
 
        seg[i]=seg[i<<1]+seg[i<<1 | 1];   // Change this acc to logic
    }
}
void updateLazy(li i,li start,li end,li l,li r)
{
    if(start>end)return;

    if(lazy[i])
    {
        seg[i]= (end-start+1) - seg[i];  // Change this acc to logic

        if(start!=end)
        {
            lazy[i<<1]=lazy[i<<1]^1;
            lazy[(i<<1)+1]=lazy[(i<<1)+1]^1;
        }

        lazy[i]=0;
    }

    if(start>r || end<l)return;

    if(l<=start && end<=r)
    {
        seg[i]= (end-start+1) - seg[i];   // Change this acc to logic

        if(start!=end)
        {
            lazy[i<<1]=lazy[i<<1]^1;
            lazy[(i<<1)+1]=lazy[(i<<1)+1]^1;
        }

        return;
    }

        li mid=(start+end)/2;
 
        updateLazy(2*i,start,mid,l,r);
        updateLazy(2*i+1,mid+1,end,l,r);
 
        seg[i]=seg[i<<1]+seg[i<<1 | 1];   // Change this acc to logic
}
 
li queryLazy(li i,li start,li end,li l,li r)
{
    if(start>end)return 0;

    if(lazy[i])
    {
        seg[i]= (end-start+1) - seg[i];  // Change this acc to logic

        if(start!=end)
        {
            lazy[i<<1]=lazy[i<<1]^1;
            lazy[(i<<1)+1]=lazy[(i<<1)+1]^1;
        }

        lazy[i]=0;
    }

    if(start>r || end<l)return 0;

    if(l<=start && end<=r)
    {
        return seg[i];
    }
 
    li mid=(start+end)/2;
 
    li left=queryLazy(i<<1,start,mid,l,r);
    li right=queryLazy((i<<1)+1,mid+1,end,l,r);
 
    return left+right;  // Change this acc to logic
}