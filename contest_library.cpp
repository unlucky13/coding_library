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
