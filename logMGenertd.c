/*****************************************************************************/
/**                        FORMING MATRIX                                   **/
/**                                                                         **/
/*****************************************************************************/

#include <stdio.h>
#include <math.h>


#define Kdiv  8
#define NCOL  11

main()
{


/*declaration*/


  FILE    *fp, *fp1;
  double a[Kdiv][NCOL]; 
  int i,j;
  char st[130];

/*reading input file*/


  fp=fopen("MatrixGenerated.txt" , "r");
  for(i=0;i<Kdiv;i++){
   for(j=0;j<NCOL;j++){
  fscanf(fp,"%lf ",&a[i][j]);
  }
  }
  fclose(fp);
  
  for(i=0;i<Kdiv;i++){
   for(j=0;j<NCOL;j++){
   a[i][j]= log(a[i][j]);
  }
  }


/*making matrix*/

  	  sprintf(st,"ln/MatrixGenerated2.txt");
          fp1 = fopen(st,"w");     
           for(i=0;i<Kdiv;i++){
            for(j=0;j<NCOL;j++){    
	    fprintf(fp1,"%17.17e ",a[i][j]);
	    }
            fprintf(fp1,"\n");
           } 
          fclose(fp1);
}
