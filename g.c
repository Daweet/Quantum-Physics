/*****************************************************************************/
/**                        FORMING MATRIX                                   **/
/**                                                                         **/
/*****************************************************************************/

#include <stdio.h>
#include <math.h>


#define Kdiv  8
#define NCOL 8

main()
{


/*declaration*/


  FILE    *fp, *fp3, *fp2, *fp1;
  double a[Kdiv][Kdiv], b[Kdiv][Kdiv], c[Kdiv][Kdiv], g[NCOL][Kdiv][NCOL]; 
  int i,j,k;
  char st[130];

/*reading input file*/


  fp=fopen("Eigenvalue2.txt" , "r");
  for(i=0;i<NCOL;i++){
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

  fp3=fopen("Gnew11" , "r");
  for(i=0;i<Kdiv;i++){
   for(j=0;j<NCOL;j++){
  fscanf(fp3,"%lf ",&c[i][j]);
  }
  }
  fclose(fp3);

/*product*/
  for(i=0;i<NCOL;i++)
  {
   for(k=0;k<NCOL;k++)
   {
    for(j=0;j<Kdiv;j++)
    {
   g[i][j][k]= sqrt(a[k][k]) * b[i][k] * c[j][k];
    }
   }
  } 


/*making matrix*/

  	   sprintf(st,"G11");
          fp2 = fopen(st,"w");         
            for(i=0;i<NCOL;i++)
            {
             for(j=0;j<Kdiv;j++)
              {
               for(k=0;k<NCOL;k++){
                 fprintf(fp2,"%17.17e ",g[i][j][k]);
               }
               fprintf(fp2,"\n");
              }
             }
          fclose(fp2);
}
