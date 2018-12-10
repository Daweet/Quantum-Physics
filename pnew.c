/*****************************************************************************/
/**              PRODUCT OF MATRIX   vvT                                    **/
/**                                                                         **/
/*****************************************************************************/

#include <stdio.h>
#include <math.h>


#define Kdiv  8
#define NCOL  8

main()
{


/*declaration*/


  FILE    *fp, *fp1, *fp2;
  double a[Kdiv][Kdiv]; 
  double b[Kdiv][Kdiv]; 
  double p[Kdiv][Kdiv];
  int i,j,k;
  char st[130];

/*reading input file*/


  fp=fopen("MatrixGenerated2.txt" , "r");
  for(i=0;i<Kdiv;i++){
   for(k=0;k<NCOL;k++){
  fscanf(fp,"%lf ",&a[i][k]);
   }
  }
  fclose(fp);

  fp1=fopen("TRANSPOSED" , "r");
  for(i=0;i<NCOL;i++){
   for(k=0;k<Kdiv;k++){
  fscanf(fp1,"%lf ",&b[i][k]);
   }
  }


  
/*product*/
  for(i=0;i<Kdiv;i++)
  {
   for(j=0;j<Kdiv;j++)
   {
   p[i][j]=0;
    for(k=0;k<NCOL;k++)
    {
    p[i][j]=p[i][j] + (a[i][k] * b[k][j]);
    }
   }
  }


/*making matrix*/

  	  sprintf(st,"PRODUCT1");
          fp2 = fopen(st,"w");         
            for(i=0;i<Kdiv;i++)
            {
             for(j=0;j<Kdiv;j++)
             fprintf(fp2,"%17.17e ",p[i][j]);
             fprintf(fp2,"\n");
            }
          fclose(fp2);
}
