/*
    Resolver Mochila con Kat
    A01023638
    //use mucha ayuda 
*/
#include <iostream>
#include <vector>

using namespace std;

class Elemento
{
    public:
    int peso, beneficio,info;
    Elemento(){}
    Elemento (int _info,int _peso, int _beneficio)
    {
        info = _info;
        peso = _peso;
        beneficio = _beneficio;
    }

};

class mochi : public Elemento
{
    public:
    int alcance, ocupacion;
    vector<Elemento> solucion;
    mochi (){}
    mochi(int peso)
    {
        alcance=peso;
    }

    void meterCosas(vector<Elemento> objetitos)
    {
        int pesoTotal=0;
        for (Elemento e : objetitos) //que es esto?? 
        { 
            int temp = pesoTotal + e.peso;
            if (temp <= alcance)
            {
                solucion.push_back(e);
                pesoTotal = temp;
            }
            else
            {
                break;
            }
        }
        ocupacion = pesoTotal;
    }

    void printCositasMochi()
    {
        int cont= 0;
        cout<<"Elementos dentro de la mochila: "<< solucion.size()<<endl;
        for (Elemento e : solucion)
        {
            cout<<"objeto #"<<e.info<<"\t peso: "<< e.peso <<"\t beneficio: "<<e.beneficio<<endl;
            ++cont;
        }
        cout<<"Peso ocupado: "<<ocupacion<<endl;
        
    }
};


bool peso(Elemento i, Elemento j) //esto es necesario para el metodo de sort, lo ocupa de manera rara jejeje
{
    return (i.peso < j.peso);
}

int main()
{
    int cantidadTotal =5;
    vector<Elemento> objetos;
    //Elemento a;
    //objetos = { Elemento r(1,3), Elemento x(2,6), a(1,3), a(2,6), a(4,7) } //-> así no funciona jejejeje
    for (int i = 0; i < cantidadTotal; i++)
    {
        Elemento algo(i+1,rand() %5, rand()%10);
        objetos.push_back(algo);

    }
    int cont =0;
    cout<< "elementos totales: "<<endl;
    for (Elemento e : objetos) //accede al elemento en el vector, esto tuve que checarlo como lo hizo Victor debido a que no podía acceder de mi forma
        {
            cout<<"objeto #"<< e.info<<"\t peso: "<< e.peso <<"\t beneficio: "<<e.beneficio<<endl;
            ++cont;
        }

    sort(objetos.begin(), objetos.end(), peso );
    
    mochi kat(7);
    kat.meterCosas(objetos);
    kat.printCositasMochi();
    return 0;
}