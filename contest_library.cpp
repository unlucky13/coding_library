/*                                                       GCD function 
=======================================================================================================================*/

int GCD(int a,int b){
    
    while(b>0){
         a  = a%b ;
         a ^=b ;   b^=a ; a^=b ; 
    }
    
    return a ;
}



/*                                                          qsort
=====================================================================================================================*/

qsort(<arrayname,<size>,sizeof(<elements_size>),compare) ;

int compare(const void *a,const void *b){

    /*This will sort in increasing oder */
    
    int *x = (int *)a ;
    int *y = (int *)b ;
    return *x-*y ;


}


/*                                        Binary Indexed tree From Topcoder 
 ================================================================================================================= */
int read(int idx){
    /* this will return single value of the idx-th index */

    int sum = 0 ;
	while(idx>0){
		sum+=tree[idx] ;
		idx -= (idx &(-idx)) ;
	}

	return sum ;

}


void update(int idx,int val){

    while(idx<=n){
		tree[idx]+=val ;
		idx += (idx &(-idx)) ; ;
	}

}

int readSingle(int idx){

    int sum = tree[idx];
	if (idx > 0){
		int z = idx - (idx & -idx);
	    idx--;
        while (idx != z){
        	sum -= tree[idx];
		    idx -= (idx & -idx);
        }
	}

return sum;

}


/*                                        BIT -masking  From http://www.shafaetsplanet.com
=======================================================================================================================*/


int Set(int N,int pos){return N=N | (1<<pos);}          /* this will set the bit of the number N at pos to 1 */
int reset(int N,int pos){return N= N & ~(1<<pos);}      /* this will set the bit of the number N at pos to 0 */
bool check(int N,int pos){return (bool)(N & (1<<pos));} /* this will return the bit of the number N at pos */





/*                     MST_Kruskal - From http://www.shafaetsplanet.com
========================================================================================================================*/

struct edge
{
    int u,v,w;
    bool operator < ( const edge& p ) const
    {      
        return w < p.w;   
    }
};
int par[MAXN];
vector<edge>e;
int find(int r)
{
   return (par[r]==r) ? r:  find(par[r]);
}
int mst(int n)
{
    sort(e.begin(),e.end());
    for(int i=1;i<=n;i++)par[i]=i;
     
    int count=0,s=0;
    for(int i=0;i<(int)e.size();i++)
    {
        int u=find(e[i].u);
        int v=find(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            count++;
            s+=e[i].w;
            if(count==n-1) break;
        }
    }
    return s;
}

/*                           Dijkstra-from https://sites.google.com/site/smilitude
=======================================================================================================================*/


vector<int> edge[100], cost[100];
const int infinity = 1000000000;

edge[i][j] = jth node connected with i 
cost[i][j] = cost of that edge

struct data {
    int city, dist;
    bool operator < ( const data& p ) const {
        return dist > p.dist;
    }
};

int dijkstra(int source, int destination) {
    
    int d[100];
    for(int i=0; i<100; i++) d[i] = infinity;

    priority_queue<data> q;
    data u, v;
    u.city = source, u.dist = 0;
    q.push( u );
    d[ source ] = 0;

    while( !q.empty() ) {
        u = q.top(); q.pop();
        int ucost = d[ u.city ];

        for(int i=0; i<edge[u.city].size(); i++) {
            v.city = edge[u.city][i], v.dist = cost[u.city][i] + ucost;
            // relaxing :)
            if( d[v.city] > v.dist ) {
                d[v.city] = v.dist;
                q.push( v );
            }
        }
    }
    
    return d[ destination ];
}

/*                                                   Strongly Connected Components(Tarjan) frome Topcoder:
=========================================================================================================================================*/
int idx[maxn],tim,lowlink[maxn],scc[maxn],components;
stack<int>s ;
vector<int>adj[maxn] ;
void reset()
{
     
     memset(scc,-1,sizeof(scc)) ;
     memset(idx,-1,sizeof(idx)) ;
     for(int i=0;i<=maxn;i++) adj[i].clear() ;
     while(!s.empty()) s.pop() ;
     components = 0 ;
}
void dfs(int here,int par) {

    idx[here] = lowlink[here] = tim++;
    s.push(here);
    for(int i = 0; i <(int)adj[here].size(); i++)  {
      int there = adj[here][i];
      if(idx[there] == -1) {
      	dfs(there,here) ;
        lowlink[here] = min(lowlink[here],lowlink[there] );
      }
      else if(scc[there]==-1){

      	/* This line is really trciky .) is means The lowlink[here] is defined as the lowest-numbered vertex reachable from the subtree rooted at here via a single edge in the same component as here.*/

        lowlink[here] = min(lowlink[here], idx[there]);
      }
    }
    if(lowlink[here] == idx[here]) {

    	int elem ;
    	do{
      	elem = s.top() ;
      	s.pop() ;
      	scc[elem]=components ;
      } while(elem!=here) ;
    }

  }


