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

    public:
        int jornada, fontanero;
        vector<Fontanero> solucion;
        Satisfaccion(){}
        void mejorarSatis(vector<Fontanero> trabajo)
        {
            int tiempoDeEspera = 0;
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
            cout<<"Cliente #"<<i.numCliente<<"\t Tiempo de Reparacion: "<< i.tiempo <<"\t Tiempo Espera: "<<i.llegar<<endl;
            }

            cout<<"Tiempo de la Jornada del fontanero: "<<jornada<<endl;
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

    Satisfaccion empresa;
    empresa.mejorarSatis(listaTrabajo);

    return 0;
}