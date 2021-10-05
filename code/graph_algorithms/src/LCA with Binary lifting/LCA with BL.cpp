li n,l;
vector<vi> graph;

li timer;
vi in,out;

vector<vi> up;

void dfs(li u,li p)
{
	in[u]=++timer;

	up[u][0]=p;

	f(i,1,l)
	{
		up[u][i]=up[up[u][i-1]][i-1];
	}

	for(li v:graph[u])
	{	
		if(v!=p)
		{
			dfs(v,u);
		}
	}

	out[u]=++timer;
}

bool is_ancestor(li u,li v)
{
	return in[u]<=in[v] && out[v]<=out[u];
}

li lca(li u,li v)
{
	if(is_ancestor(u,v))
		return u;

	if(is_ancestor(v,u))
		return v;

	fr(i,l,0)
	{
		if(!is_ancestor(up[u][i],v))
			u=up[u][i];
	}

	return up[u][0];
}

void init(li root)
{
	in.resize(n+1);
	out.resize(n+1);

	timer=0;

	l=ceil(log2(n+1));

	up.assign(n+1,vi(l+1));

	dfs(root,root);
}