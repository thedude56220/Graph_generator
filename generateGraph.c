#include "generateGraph.h"
// The dude

int * * mallocDeMatriceDynamique (int n)
{
	int i;
	
	int **mat= (int **) malloc (n * sizeof (int));
	if(mat==NULL)
		{
		fprintf(stderr,"\nerror de 1. malloc dans mallocDeMatriceDynamique (generateGraph.c)\n");
		exit(1);
		}
		
	for(i=0;i<n;i++)
		{
		mat[i]=(int*) malloc(n * sizeof (int));
		if(mat[i]==NULL)
			{
			fprintf(stderr,"\nerror de 2. malloc dans mallocDeMatriceDynamique (generateGraph.c)\n");
			exit(1);
			}
		}
	return(mat);
}

void freeDeMatriceDynamique (int * * mat, int n)
{
	int i;
		
	for(i=0;i<n;i++)
		free(mat[i]);
	free(mat);
}

void displayMatDyn(int * * mat, int n)
{
	int i,j;
	printf("\nDisplay Matrice Dynamique:\n");
	for(i=0;i<n;i++)
		{
		printf("\n i=%d:\t",i);
		for(j=i+1;j<n;j++)
				printf(" [%d,%d,%d] ",i,j,mat[i][j]);
		}
	printf("\n");
}

int * * InitMat(int * * mat, int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			mat[i][j]=0;
	return(mat);
}

int * * BuildAtRandomAGraph(int * * mat, int n)
{
	int i,j;
	mat=InitMat(mat,n);
	for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(rand()<16383)
					mat[i][j]=1;  /* +1 au indice pour avoir des sommets */ 
	return(mat);
}

int nbVoisinDuSommeti (int * * mat, int ligne,int n)
{
	int j,cpt=0;
	for(j=0;j<n;j++)
		if (mat[ligne][j] ==1)
			cpt++;
	return(cpt);
}

void WriteInFile (int * * mat, int n)
{
	int i,j,nbVoisinDei;
	FILE * fp = fopen("graph.txt","w");
	
	fprintf(fp,"%d",n);
	
	for(i=0;i<n-1;i++)
		{
		nbVoisinDei = nbVoisinDuSommeti (mat,i,n);
		fprintf(fp,"\n%d %d ",i+1,nbVoisinDei);
		for(j=i+1;j<n;j++)
			if(mat[i][j] == 1)
					fprintf(fp," %d ",j+1);
		}
	fprintf(fp,"\n -1 ");
	fclose(fp);
}


G createANewGraph(int nb)
{
	G g;
	int n=5;
	int ** matDyn = mallocDeMatriceDynamique (n);
	matDyn = BuildAtRandomAGraph(matDyn,n);
	WriteInFile (matDyn, n);
	g=getGraphInFileNoSymetric(g);
	freeDeMatriceDynamique (matDyn,n);
	return(g);
}
