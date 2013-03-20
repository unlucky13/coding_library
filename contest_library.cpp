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


/*                                          BIT -masking 
=======================================================================================================================*/


int Set(int N,int pos){return N=N | (1<<pos);}          /* this will set the bit of the number N at pos to 1 */
int reset(int N,int pos){return N= N & ~(1<<pos);}      /* this will set the bit of the number N at pos to 0 */
bool check(int N,int pos){return (bool)(N & (1<<pos));} /*/* this will return the bit of the number N at pos */

