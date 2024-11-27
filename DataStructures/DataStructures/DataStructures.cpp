using namespace std;
#include <iostream>
#include "LinkedList.h"
int main()
{
    LinkedList lista, listaOrdenada;
    lista.addAtStart(4);
    lista.addAtStart(8);
    lista.addAtStart(6);
    cout << "Esta: " << lista.find(6) <<"\n";
    cout << "Esta: " << lista.find(7) << "\n";
    lista.print();
    cout << "teste\n";
    //lista.remove(8);
    lista.print();
    lista.addAfter(8, 15);
    lista.addAfter(4, 99);
    cout << "To aqui: \n";
    lista.print();
    cout << "Teste ordenado: \n";
    listaOrdenada.addOrdened(4);
    listaOrdenada.addOrdened(2);
    listaOrdenada.addOrdened(3);
    listaOrdenada.addOrdened(1);
    listaOrdenada.print();
}
