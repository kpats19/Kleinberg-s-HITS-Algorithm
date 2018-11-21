/* KEYUR PATEL cs610 6703 prp */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct storage{
	int x,y;
};
struct previousValue{
	int size,inDegree,outDegree;
	float previousHub,previousAuthority;
	struct storage *listOfEdge;
};

struct previousValue *  webtransposeMatrix_6703(struct previousValue *transposeMatrix,struct previousValue *vertexDetail,int n){

	int i,j;
	transposeMatrix = (struct previousValue *)malloc(sizeof (struct previousValue)*n);	
	
	for(i=0;i<n;i++){
	transposeMatrix[i].size=0;
	transposeMatrix[i].inDegree=0;
	transposeMatrix[i].outDegree=0;
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<vertexDetail[i].outDegree;j++){
		transposeMatrix[vertexDetail[i].listOfEdge[j].y].outDegree=transposeMatrix[vertexDetail[i].listOfEdge[j].y].outDegree+1;
	}
	}
	for (i=0;i<n;i++)
	transposeMatrix[i].listOfEdge = (struct storage *) malloc(sizeof(struct storage) * vertexDetail[i].outDegree);

	for (i=0;i<n;i++){
	
		for (j=0;j<vertexDetail[i].outDegree;j++){
	
		transposeMatrix[vertexDetail[i].listOfEdge[j].y].listOfEdge[transposeMatrix[vertexDetail[i].listOfEdge[j].y].size].x=vertexDetail[i].listOfEdge[j].y;
		transposeMatrix[vertexDetail[i].listOfEdge[j].y].listOfEdge[transposeMatrix[vertexDetail[i].listOfEdge[j].y].size].y=vertexDetail[i].listOfEdge[j].x;
		transposeMatrix[vertexDetail[i].listOfEdge[j].y].size++;

		}
	}
	return(transposeMatrix);
}

float * matrixMultiplication_6703(struct previousValue *adjacencyList,float * b,float c[],int n){
	
	int k,tmp,j,i;
	for (i=0;i<n;i++)c[i]=0;
	for(i = 0; i < n; i++) {
		for(j = 0; j < adjacencyList[i].size; j++) 	c[i] = c[i] + b[adjacencyList[i].listOfEdge[j].y];
	}
	return c;
}
void main(int argc, char *argv[]){

	int n,m,iteration,initialValue,vertex_1,vertex_2,i,j,k,node_count_errorrate=0;
	float *authority,*hub,sumhub=0,sumauthority=0,temp=0,errorrate=0;
	
	if (argc!=4){
		printf("\nplease run the code i.e. ""./ hits iterations initialvalue filename""\n");
		exit(0);
	}

	iteration = atoi(argv[1]);
 	 if (iteration==0&&strlen(argv[1])>1){
	printf("please enter the valid argument, instead:\t%s\n",argv[1]);
	exit(0);
	}else if (strlen(argv[1])==1&&iteration==0){
	char check[2];
	strcpy(check,argv[1]);
	int checker=check[0]-'\0';
	if (checker!=48){
	printf("please enter the valid argument, instead:\t%s\n",check);
	exit(0);
	}
	}
  	else {
		int check;
		int len = strlen(argv[1]);
		char  str[len];
		strcpy(str,argv[1]);
		for (i=0;i<len;i++)
		{	check= str[i]-'\0';
			if ((check<48 || check > 57)&&check!=45) {
			
				printf("please enter valid argument, instead:\t%s\n",argv[1]);
				exit(0);
			}
		}

	}	
  	
	initialValue =atoi(argv[2]);
 	if (initialValue==0&&strlen(argv[2])>1){
	printf("please enter the valid argument, instead:\t%s\n",argv[2]);
	exit(0);
	}else if (strlen(argv[2])==1&&initialValue==0){
	char check[2];
	strcpy(check,argv[2]);
	int checker=check[0]-'\0';
	if (checker!=48){
	printf("please enter the valid argument, instead:\t%s\n",check);
	exit(0);
	}
	}
  	else {
		int check;
		int len = strlen(argv[2]);
		char  str[len];
		strcpy(str,argv[2]);
		for (i=0;i<len;i++)
		{	check= str[i]-'\0';
			if ((check<48 || check > 57 )&&check!=45) {
			
				printf("please enter valid argument, instead:\t%s\n",argv[2]);
				exit(0);
			}
		}

	}
	if (-2>initialValue||1<initialValue){printf("Can not have such initial value have to use :-2,-1,0,1");exit(0);}
	printf("\niteration:%d\nintitialValue:%d\nFile path:%s\n",iteration,initialValue,argv[3]);
	
	if(iteration<1){
		if (iteration==0) errorrate=0.00001;
		else errorrate= (1/pow(10,(-1)*iteration));
		iteration=1;
		printf("\nErrorrate:%lf",errorrate);
		}
	
	FILE *openfile=fopen(argv[3],"rb");
	if (openfile==NULL){
		printf("Could not open file");
		exit(0);
	}
	fscanf(openfile,"%d %d",&n,&m);
	authority=  (float *) malloc(n * sizeof (float));
	hub=  (float *) malloc(n * sizeof (float));

	struct previousValue *vertexDetail= (struct previousValue *)malloc(sizeof (struct previousValue)*n);	
	for(i=0;i<n;i++){
	vertexDetail[i].size=0;
	vertexDetail[i].inDegree=0;
	vertexDetail[i].outDegree=0;
	}
 
	for(i=0;i<m;i++){
	fscanf(openfile,"%d %d",&vertex_1,&vertex_2);
	vertexDetail[vertex_1].outDegree=vertexDetail[vertex_1].outDegree+1;
	}
	
	for (i=0;i<n;i++)
	vertexDetail[i].listOfEdge = (struct storage *) malloc(sizeof(struct storage) * vertexDetail[i].outDegree);

	if( fseek(openfile ,0L, SEEK_SET) != 0 ) {
	printf("could not rewind the file SORRY ");
	exit(0);
	}
	fscanf(openfile,"%d %d",&vertex_1,&vertex_2);

	for(i=0;i<m;i++){
	fscanf(openfile,"%d %d",&vertex_1,&vertex_2);
	vertexDetail[vertex_1].listOfEdge[vertexDetail[vertex_1].size].y=vertex_2;
	vertexDetail[vertex_1].listOfEdge[vertexDetail[vertex_1].size].x=vertex_1;
	vertexDetail[vertex_1].size++;
	}
	struct previousValue *transposeMatrix;
       	float*b;
	
	b = (float *)malloc(sizeof(float)*n);
	float *c=  (float *) malloc(n * sizeof (float));
	
	transposeMatrix=webtransposeMatrix_6703(transposeMatrix,vertexDetail,n);
		
 	for(k=0;k<=iteration;k++){	
			
		if(errorrate!=0) iteration++;
		if (k==0){	
		if (initialValue==0)	temp =0;
		else if(initialValue==1) temp = 1;
		else if (initialValue == (-1)) temp = (1/(float)n); 
		else if (initialValue==(-2))temp = (1/sqrt(n));
	
		if (n>10){
		
			 temp = (1/(float)n); 
			errorrate= 0.00001;
		printf("\nN>10 N:%d \t Defualt Errorate (iteration=0): 0.00001 Initialvalue : %0.7f\n\n",n,temp);
		}

		for (i=0;i<n;i++){
		authority[i]=temp;
		hub[i]=temp;
		vertexDetail[i].previousAuthority= authority[i];
		vertexDetail[i].previousHub=hub[i];
		}
		if ((n<10))printf("\n\nBase:\t%d:",k);	
		for(i=0;i<n;i++) 
		{	
		if ((n<=10))printf("A/H[%d]=%.7f/%.7f ",i,authority[i],hub[i]);
		}
		}
		else{
		authority=matrixMultiplication_6703(transposeMatrix,hub,authority,n);
		hub=matrixMultiplication_6703(vertexDetail,authority,hub,n);
		sumauthority=0;
		sumhub=0;
		for (i=0;i<n;i++){
				sumauthority=sumauthority+authority[i]*authority[i];
				sumhub=sumhub+hub[i]*hub[i];
			}
			sumauthority=sqrt(sumauthority);
			sumhub=sqrt(sumhub);
			for(i=0;i<n;i++){
			authority[i]=authority[i]/sumauthority;
			hub[i]=hub[i]/sumhub;
			}		
			
			if ((n<=10)) printf("\nIter:\t%d:",k); 
			
			for(i=0;i<n;i++){
				if (((vertexDetail[i].previousHub-hub[i])<errorrate) && ((vertexDetail[i].previousAuthority-authority[i])<errorrate))node_count_errorrate++;
			if((n<=10)){	printf("A/H[%d]=%.7f/%.7f ",i,authority[i],hub[i]); if (i==4) printf(" ...other Vertices omitted ");}
				vertexDetail[i].previousHub =hub[i];
				vertexDetail[i].previousAuthority = authority[i];	
			}
			if (node_count_errorrate==n&&errorrate!=0){
			if (n>10)printf("Iteration:%d\nA/H[0]=%0.7f/%0.7f\nA/H[1]=%0.7f/%0.7f\nA/H[2]=%0.7f/%0.7f\nA/H[3]=%0.7f/%0.7f ...other Vertices omitted\n",k,authority[0],hub[0],authority[1],hub[1],authority[2],hub[2],authority[3],hub[3]);

				break;}
			node_count_errorrate=0;
		}
	}
}
