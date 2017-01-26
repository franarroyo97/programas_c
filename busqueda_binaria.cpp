#include<iostream>
using namespace std;
bool busqueda_binaria(int vector[],int utiles_vector,int argumento_a_buscar){
	int izq=0;
	int der=utiles_vector;
	int med=(der+izq)/2;
	bool encontrado=false;
	while(vector[med] != argumento_a_buscar && izq != med && der != med ){
		if(vector[med] > argumento_a_buscar){
			cout<<"entro en el if "<<endl;
			der=med;
			med=(der+izq)/2;
		}
		else {
			cout<<"entro en el else "<<endl;
			izq=med;
			cout<<"ahora izq vale "<<izq<<endl;
			med=(der+izq)/2;;
			cout<<"ahora med vale "<<med<<endl;
			cout<<"ahora vector[med]vale "<<vector[med]<<endl;
		}
	}
	if (vector[med]== argumento_a_buscar){
		encontrado=true;
	}
	return encontrado;
}
void ordenar_insercion(int vector[],int utiles_vector){
	int izq=0;
	int i=0;
	int valor=0;
	for(izq=1;izq<utiles_vector;izq++){
		valor=vector[izq];
		for(i=izq; valor<vector[i-1] && i>0; i--){
			vector[i]=vector[i-1];
		}
		vector[i]=valor;	
	}
}
int main(){
	int const DIM_VECTOR=10000;
	int vector[DIM_VECTOR]={-9999};
	int utiles_vector=0;
	int argumento_a_buscar=0;
	int contador=0;
	int aux=0;
	do{
		cout<<"\ndigame un numero (tiene que ser mayor que el anteror): -9999 para no introducir mas";	
		cin>>aux;
		if (aux != -9999 ){
			vector[contador]=aux;
			utiles_vector++;
			contador++;
		}
	}
	while(aux != -9999 && contador < DIM_VECTOR);
	cout<<"\n dime el argumento a buscar";
	cin>>argumento_a_buscar;
	ordenar_insercion (vector,utiles_vector);
	if (busqueda_binaria(vector,utiles_vector,argumento_a_buscar)==true){
		cout<<"\n encontrado!!";
	}
	else{
		cout<<"\nno encontrado :("<<endl;
	}
	

}
