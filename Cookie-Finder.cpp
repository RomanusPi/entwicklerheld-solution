#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char **cookieFinder(char **input) {
    
   static char **tab;
   int N = 6;  //max_columns
   int M = 6;  //max_rows  
   int cookies = 0;
   if ((tab  = (char **)malloc(sizeof(char *)*N)) == NULL) printf(">error1 >" );
   for ( int i = 0; i < N; i++ )
      {
       if (( tab[i] = malloc(sizeof(char)*M )) == NULL ) printf(">error2 >%d",i );
      }
 
   for ( int k = 0; k < M; k++ )
      {

      if (input[k] == NULL)
         { 
            tab[k] = NULL;
            return tab;
         }
      for ( int r = 0; r < M; r++ )
         {
             
         if  (input[k][r] == NULL) { tab[k][r] = NULL; continue;}
         if  (input[k][r] == '*')  { tab[k][r] = '*'; continue; } 
         if  (input[k][r] == ' ') 
            {
            cookies = 0;
            if ( r > 0 ) { 
               if (input[k][r - 1] == '*') cookies++;   
               if ( k > 0 )  if (input[k-1][r-1] == '*') cookies++;   
            } 
            if ( k > 0 ) { 
               if (input[k - 1][r] == '*') cookies++;   
               if (( r + 1 != NULL ) && (input[k-1][r+1] == '*')) cookies++;   
            }   
            if ( r + 1 != NULL ) { 
               if (input[k][r + 1] == '*') cookies++;   
               if ((input[k+1] != NULL) &&  (input[k+1][r+1] == '*')) cookies++;   
            } 

            if (input[k + 1] != NULL) { 
               if (input[k + 1][r] == '*') cookies++;   
               if (( r > 0 )  && (input[k + 1][r - 1] == '*')) cookies++;   
            }
                      
            if ( cookies == 0)  tab[k][r] = ' '; 
            else tab[k][r] = 48 + cookies;  

            }        
         
         }
    
   }
 return tab ;
}
