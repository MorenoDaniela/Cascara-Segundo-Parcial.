#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"
#include "Controller.h"
#include "Venta.h"
#include "funciones.h"

int main()
{
    LinkedList* listaVenta = ll_newLinkedList();
    controller_loadFromText("data.csv",listaVenta);
    controller_ListVenta(listaVenta);
    controller_saveAsTextInformes("informes",listaVenta);
    return 0;
}
