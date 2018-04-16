int main(int argc, char *argv[])
{	
	int N, int i, int j, int i1, int j1;
	FILE *in;	
	//Se declaran las variables para los datos originales, el polinomio de lagrange y los 		//de la transformada
	float **d, d1, DFT, l, valor = 0; 
	in = fopen(argv[1],"r");
	cout<<"ingrese el numero de elementos: "; cin>>N;
	double x[N], y[N], x1[N], y1[N], nuevo[N][N],real[N][N], imag[N][N], A[N][N];


	//Leer datos
	i = 0;
	for(i = 0; i < N; i++)
	{
		fscanf(in,"%f,%f\n",&d[0][i],&d[1][i]);
	} 
	//Llenar vectores
	for(i = 0; i < N; i++)
	{
		x[i] = &d[0][i];
	}
	for(i = 0; i < N; i++)
	{
		y[i] = &d[1][i];
	}
	//Polinomio de Lagrange
	for(i = 0; i < N; i++)
	{
		l = y[i];
		for(j = 0; j < N; j++)
		{
			if(i!=j)
			{
             			l=(l*(z-x[j]))/(x[i]-x[j]);
            		}
		}
		valor = valor + l;
		x1[i]= i;
		y1[i]= valor; 
		nuevo[0][i]=x1[i]
		nuevo[i][1]=y1[i]
	}
	//Transformada de fourier
	for (i = 0; i < N; i++) 
	{
	  for (j = 0; j < N; j++) 
	  {
	    for (i1 = 0; i1 < N; i1++) 
	    {
	      for (j1 = 0; j1 < N; j1++)
	      {
	        real[i][j]+=(nuevo[i1][j1]*cos(2*3.1415*((1.0 * i * i1 / N)+(1.0*j*j1/N))))/sqrt(N*N);
	        imag[i][j]-=(nuevo[i1][j1]*cos(2*3.1415*((1.0 * i * i1 / N)+(1.0*j*j1/N))))/sqrt(N*N);
	        A[i][j]=sqrt(real[i1][j1]*real[i1][j1]+imag[i1][j1]* imag[i1][j1]);
	      }
	    }
	  }
	}
	//Guardar los datos
	out = fopen("transformada.txt", "w");
	fprintf(out, "%f ", A, real, imag);
	fprintf(out, "\n");
	fclose(out);

	return 0;
}

