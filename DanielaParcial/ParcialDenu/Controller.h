#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path , LinkedList* pArrayListVenta);
int controller_ListVenta(LinkedList* pArrayListVenta);
//int controller_saveAsText(char* path , LinkedList* pArrayListVenta);
//int controller_saveAsTextInformes(char* path , LinkedList* pArrayListVenta);
int controller_saveAsTextInformes(char* path , LinkedList* pArrayListVenta);

int cantidadFotos(LinkedList* pArrayList);
int montoMayor300(void* p);
int montoMayor150(void* p);
int PolaroidReveladas(void* p);
int cantidadPolaroid(LinkedList* arrayListVentas);
#endif // CONTROLLER_H_INCLUDED
