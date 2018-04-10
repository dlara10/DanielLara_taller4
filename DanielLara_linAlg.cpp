#include <iostream>

using namespace std;

double **matrix_product(double **m1, double **m2, int fm1, int cm1, int fm2, int cm2 );
double **get_matrix(int M, int N);

int main(){
	
	int varM1;
	int varN1;
	int varM2;
	int varN2;
	cout << "Ingresar valor M de la matriz 1:"<<endl;
	cin >> varM1;
	cout << "Ingresar valor N de la matriz 1:"<<endl;
	cin >> varN1;
	cout << "Ingresar valor M de la matriz 2:"<<endl;
	cin >> varM2;
	cout << "Ingresar valor N de la matriz 2:"<<endl;
	cin >> varN2;
	if(varN1 != varM2){
		cout <<"No es posible realizar la multiplicacion por el tamaño de las matrices"<< endl;
		return 0;
	}
	cout << "Para la matriz 1:"<<endl;
	double **m1 = get_matrix(varM1, varN1);
	cout << "Para la matriz 2:"<<endl;
	double **m2 = get_matrix(varM2, varN2);
	cout << "El resultado del producto de la matriz 1 y la matriz 2 es:"<<endl;
	double **m3 = matrix_product(m1, m2, varM1, varN1, varM2, varN2 );
	cout << m3 << endl;
	return 0;
}
double **matrix_product(double **m1, double **m2, int fm1, int cm1, int fm2, int cm2 ){
	//Se declara el tamaño de la matriz resultante basada en los parametros de entrada
	double **m3 = new double*[fm1];
	//Se crea la matriz
	int i;
	for(int i = 0; i < fm1; i++){
		m3[i] = new double[cm2]; 
	}
	int j;
	int k;
	//Se empiezan los recorridos para rellenar la matriz
	for(i = 0; i<fm1; i++){
		for(j = 0; j<cm2; j++){
				//Se llena la matriz en ceros
			m3[i][j] = 0;
			
			//Se rellena la matriz con el producto de las matrices que entran como resultado.
			for(k = 0; k<cm1; k++){
				m3[i][j] += m1[i][k]*m2[k][j];
			}
		}
	}
	return m3;
}
//Funcion que crea una matriz por medio de valores que entran en la consola
double **get_matrix(int M, int N){
	//Se inicializa la matriz
	double **m3 = new double*[M];
	int i;
	int j;
	for(int i = 0; i < M; i++){
		m3[i] = new double[N]; 
	}
	
	for(i = 0; i<M; i++){
		for(j = 0; j<N; j++){
				//Se llena la matriz mediante los valores que entran como parametros.
			double var;
			cout << "Ingresar valor de la matriz en la posicion:" << i << " " << j<<endl;
			cin >> var;
			m3[i][j] = var;
		
		}
	}
	return m3;

}
