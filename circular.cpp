#include <iostream>
#include <string>
using namespace std;

struct usuario{
    int id, edad;
    string dueño, raza;
    float peso;
};

usuario solicitarnombre(void){
    usuario p;

    cout << "nombre del dueño: ";
    getline(cin, p.dueño);
    cout << "agrege el id: ";
    cin >> p.id; cin.ignore();
    cout << "nombre de la raza: ";
    getline(cin, p.raza);
    cout << "edad del animal: ";
    cin >> p.edad;cin.ignore();
    cout << "peso del animal: ";
    cin >> p.peso;cin.ignore();
    return p;
}

void mostrardescripcion(usuario p){
    cout << "dueño: " << p.dueño<<endl;
    cout << "raza: " << p.raza<<endl;
    cout << "edad: " << p.edad<<endl;
    cout << "peso: " << p.peso<<endl;
    cout << " (" << p.id << ")  ";
}

typedef usuario T;

struct nodo{
    T dato;
    nodo *sig;
    nodo *ant;
};

class ListaDoble{
    private:
        nodo *pInicio;
    public:
        ListaDoble();
        ~ListaDoble();
        void agregarnombre(T);
        void mostrarnombre(void);
        void eliminarnombre(T);
        bool empty(void);
        void mostrarListaRec(void);
        void mostrarListaRecAux(nodo *);
        void insOrdenAscendente(int);
};

ListaDoble::ListaDoble(void){
    pInicio = NULL;
}

ListaDoble::~ListaDoble(void){
    nodo *p;
    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaDoble::agregarnombre(T dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else{
        nodo *saltarin = pInicio;
        while(saltarin->sig != NULL)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
}

void ListaDoble::mostrarnombre(void){
    nodo *saltarin = pInicio;
    while(saltarin != NULL){
        mostrardescripcion(saltarin->dato);
        saltarin = saltarin->sig;
    }
}
/*/
void ListaDoble::mostrarListaRec(void)
{
    mostrarListaRecAux(pInicio);
}

void ListaDoble::mostrarListaRecAux(nodo *saltarin)
{
    if(saltarin){
        mostrarListaRecAux(saltarin->sig);
        cout<< saltarin->dato << endl;
    }
}/*/

/*/void ListaDoble::insOrdenAscendente(int id)
{
    nodo *nuevo, *saltarin;
    usuario *id;

    nuevo = new nodo;
    nuevo->id = id;
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio;
    }
    else{
        if(id < pInicio->dato){
            nuevo->sig = pInicio;
            saltarin = pInicio;
            while(saltarin->sig != pInicio)
                saltarin = saltarin->sig;
            saltarin->sig = nuevo;
            pInicio = nuevo;
        }
        else{
            saltarin = pInicio;
            while(saltarin->sig != pInicio && saltarin->sig->dato < dato)
                saltarin = saltarin->sig;
            nuevo->sig = saltarin->sig;
            saltarin->sig = nuevo;
        }
    }
}/*/


void ListaDoble::eliminarnombre(T datoB){
    if(!pInicio){ 
        cout << "Actualmente no hay usuarios registrado." << endl;
    }
    else{ 
        nodo *saltarin = pInicio;
        while(saltarin && (saltarin->dato).dueño.compare(datoB.dueño)!=0) 
            saltarin = saltarin->sig; 
        if(!saltarin) 
            cout << "la ID no esta registrado" << endl;
        else{ 
            if(!saltarin->ant && saltarin->sig){ 
                pInicio = pInicio->sig;
                pInicio->ant = NULL;
                delete saltarin;
            }
            else
                if(saltarin->ant && !saltarin->sig){
                    saltarin->ant->sig = NULL;
                    delete saltarin;
                }
                else
                    if(saltarin->ant && saltarin->sig){
                        saltarin->ant->sig = saltarin->sig;
                        saltarin->sig->ant = saltarin->ant;
                        delete saltarin;
                    }
                    else{
                        pInicio = NULL;
                        delete saltarin;
                    }
            cout << "usuario eliminada exitosamente!" << endl;
        }
    }
}

bool ListaDoble::empty(void){
    return pInicio == NULL;
}