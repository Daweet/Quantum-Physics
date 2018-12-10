/*****************************************************************************/
/**                        FORMING MATRIX                                   **/
/**                                                                         **/
/*****************************************************************************/

#include <stdio.h>
#include <math.h>

#define Kdiv  8
#define NCOL  8

main()
{


/*declaration*/


  FILE    *fp, *fp3, *fp2, *fp1;
  double a[Kdiv][Kdiv], b[Kdiv][Kdiv], c[Kdiv][Kdiv], g[Kdiv][Kdiv]; 
  int i,j,k;
  char st[130];

/*reading input file*/


  fp=fopen("MatrixGenerated2.txt" , "r");
  for(i=0;i<Kdiv;i++){
   for(j=0;j<NCOL;j++){
  fscanf(fp,"%lf ",&a[i][j]);
  }
  }
  fclose(fp);

  fp1=fopen("Eigenvector2.txt" , "r");
  for(i=0;i<NCOL;i++){
   for(j=0;j<NCOL;j++){
  fscanf(fp1,"%lf ",&b[i][j]);
  }
  }
  fclose(fp1);

  fp3=fopen("Eigenvalue2.txt" , "r");
  for(i=0;i<NCOL;i++){
   for(j=0;j<NCOL;j++){
  fscanf(fp3,"%lf ",&c[i][j]);
  }
  }
  fclose(fp3);

/*product*/
  for(i=0;i<Kdiv;i++)
  {
   for(j=0;j<NCOL;j++)
   {
  g[i][j]=0;
    for(k=0;k<NCOL;k++)
    {
   g[i][j]=g[i][j] + (a[i][k] * b[k][j]);
    }
   }
  } 
  


/*making matrix*/

  	   sprintf(st,"Gnew11");
          fp2 = fopen(st,"w");         
            for(i=0;i<Kdiv;i++)
            {
               for(j=0;j<NCOL;j++){
                 fprintf(fp2,"%17.17e ",g[i][j]/sqrt(c[j][j]));
               }
               fprintf(fp2,"\n");
            }
          fclose(fp2);
}
