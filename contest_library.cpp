/* GCD function */
int GCD(int a,int b){
    
    while(b>0){
         a  = a%b ;
         a ^=b ;   b^=a ; a^=b ; 
    }
    
    return a ;
}

/* qsort */

qsort(<arrayname,<size>,sizeof(<elements_size>),compare) ;

int compare(const void *a,const void *b){

    /*This will sort in increasing oder */
    
    int *x = (int *)a ;
    int *y = (int *)b ;
    return *x-*y ;


}
