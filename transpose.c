/*****************************************************************************/
/**                        Transpose MATRIX                                 **/
/**                                                                         **/
/*****************************************************************************/

#include <stdio.h>
#include <math.h>

#define Kdiv  8
#define NCOL  8

main()
{


/*declaration*/


  FILE    *fp, *fp1;
  double a[Kdiv][Kdiv]; 
  int i,j;
  char st[130];

/*reading input file*/


  fp=fopen("MatrixGenerated2.txt", "r");
  for(i=0;i<Kdiv;i++){
   for(j=0;j<NCOL;j++){
  fscanf(fp,"%lf ",&a[i][j]);
  }
  }
  fclose(fp);
  


/*making matrix*/

  	  sprintf(st,"TRANSPOSED");
          fp1 = fopen(st,"w");
           for(j=0;j<NCOL;j++){         
            for(i=0;i<Kdiv;i++){
	    fprintf(fp1,"%17.17e ",a[i][j]);
	    }
            fprintf(fp1,"\n");
           } 
          fclose(fp1);
}
