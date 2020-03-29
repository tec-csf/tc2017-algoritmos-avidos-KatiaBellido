/*
    Resolver Fontanero con Kat
    A01023638
     
*/

#include <iostream>
#include <vector>

using namespace std;
class Fontanero
{
    Fontanero(){}
    public:
    int numCliente, tiempo, llegar;
    Fontanero(int _numCliente, int _tiempo, int _llegar)
    {
        numCliente = _numCliente;
        tiempo = _tiempo;
        llegar = _llegar;
    }
};
class Satisfaccion
{
    Satisfaccion(){}
    public:
        int jornada, sati;
        vector<Fontanero> solucion;
        Satisfaccion(int _sati){
            sati = _sati;
        }
        void mejorarSatis(vector<Fontanero> trabajo)
        {
            int tiempoDeEspera = 0;
            int clientesSati = 0;
            for (Fontanero f : trabajo)
            {
                int temp = tiempoDeEspera + f.llegar;
                f.llegar = temp;
                solucion.push_back(f);
                tiempoDeEspera = temp;
                
            }
            jornada = tiempoDeEspera;

            cout<<"Tabla satisfaccion clientes:"<< solucion.size()<<endl;

            for (Fontanero i : solucion)
            {
                cout<<"Cliente #"<<i.numCliente<<"\t Tiempo de Reparacion: "<< i.tiempo <<"\t Tiempo Espera: "<<i.llegar;
                if (i.llegar <= sati)
                {
                    cout<<"\t cliente satisfecho"<<endl;
                    clientesSati++;   
                }
                else  if(i.llegar > sati && i.llegar <= sati+20 ) //los numeros son decididos por la empresa establecidos siempre 
                {
                    cout<<"\t cliente medio satisfecho"<<endl;
                }
                else
                {
                    cout<<"\t cliente insatisfecho"<<endl;
                }
                
                
            }

            cout<<"Tiempo de la Jornada del fontanero: "<<jornada<<endl;
            cout<<"Número de Clientes Satisfechos: "<<clientesSati<<endl;
        }

};
bool tiempo(Fontanero i, Fontanero j) 
{
    return (i.tiempo < j.tiempo);
}

int main()
{
    int numClientes = 5;
    
    vector<Fontanero> listaTrabajo;
    for (int i = 0; i < numClientes; i++)
    {
        //numCliente, Reparacion, llegar; 
        Fontanero algo(i+1,rand() %20 +5, rand()%30);
        listaTrabajo.push_back(algo);
    }
    sort(listaTrabajo.begin(), listaTrabajo.end(), tiempo); //tiempo busca la funcion bool tiempo :D 

    Satisfaccion empresa(30);
    empresa.mejorarSatis(listaTrabajo);

    return 0;
}