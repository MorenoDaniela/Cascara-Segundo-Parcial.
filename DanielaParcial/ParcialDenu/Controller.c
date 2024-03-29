#ifndef CONTROLLER_C_INCLUDED
#define CONTROLLER_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Venta.h"
#include "parser.h"
#include "funciones.h"
#include "Controller.h"
#define MAX_ID 1000000
#define SORT_DOWN 0
#define SORT_UP 1

int controller_loadFromText(char* path , LinkedList* pArrayListVenta)
{
    int retorno=-1;

    FILE* pFile = NULL;

    if (path!=NULL && pArrayListVenta!=NULL)
    {
        pFile = fopen (path, "r");

                if (pFile!=NULL)
                {
                    ll_clear(pArrayListVenta);
                    if (!parser_VentaFromText(pFile,pArrayListVenta))
                    {
                        retorno=0;
                        printf ("Carga Venta ok.\n");
                    }
                }
            //}
        fclose (pFile);
    }
    return retorno;
}



int controller_ListVenta(LinkedList* pArrayListVenta)
{
    int retorno=-1;
    Venta* pVenta;
    int auxId;
    char bufferFecha[1000];
    char bufferCuit[500];
    int auxCantidad;
    char bufferTipo[4000];
    float bufferImporte;
    int length;
    int i;

    if (pArrayListVenta!=NULL)
    {
        length=ll_len(pArrayListVenta);
        for (i=0;i<length;i++)
        {
            pVenta = ll_get(pArrayListVenta,i);
            if (pVenta!=NULL)
            {
                if (!Venta_getId(pVenta,&auxId) &&
                    !Venta_getFecha(pVenta,bufferFecha) &&
                !Venta_gettipo(pVenta, bufferTipo) &&
                !Venta_getCantidad(pVenta,&auxCantidad) &&
                !Venta_getImporte(pVenta,&bufferImporte) &&
                !Venta_getCuit(pVenta,bufferCuit))
                {
                    printf("ID:%d Fecha:%s Tipo:%s Cantidad:%d Importe:%.2f Cuit: %s \n",auxId,bufferFecha, bufferTipo, auxCantidad, bufferImporte,bufferCuit);
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

int controller_saveAsTextInformes(char* path , LinkedList* pArrayListVenta)
{
    int retorno = -1;
    int totalPolaroid=0;
    int totalFotos=0;
    int total=0;
    float probar=0;//forma 1 con funcion ll_acumuladorFloat
    float cantidad=0;//forma 2 normal
    int ventasMayor150=0;
    int ventasMayor300=0;
    //int totalpolaroid=0;

    //LinkedList* Polaroid= ll_newLinkedList();
    //LinkedList* Mayores300 = ll_newLinkedList();

    FILE *pFile = NULL;

    if(path != NULL && pArrayListVenta != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            totalFotos=cantidadFotos(pArrayListVenta);
            total=ll_acumuladorInt(pArrayListVenta,TotalFotos);
            probar=ll_acumuladorFloat(pArrayListVenta,probarFloat);//forma 1
            cantidad=cantidadImporte(pArrayListVenta);//forma 2
            ventasMayor150=ll_count(pArrayListVenta,montoMayor150);
            ventasMayor300=ll_count(pArrayListVenta,montoMayor300);
            totalPolaroid=ll_count(pArrayListVenta,PolaroidReveladas);
            //totalpolaroid=cantidadPolaroid(pArrayListVenta);

            //printf ("Total polaroid: %d",Polaroid);
            fprintf(pFile, "*****************************\nInforme de Ventas\n*****************************\n");
            fprintf(pFile, "- Cantidad Total de fotos: %d\n", totalFotos);
            fprintf(pFile, "- Cantidad Total de fotos: %d\n", total);
            fprintf(pFile, "- Cantidad Total de importe: %.2f\n", probar);//forma 1
            fprintf(pFile, "- Cantidad Total de importe: %.2f\n", cantidad);//forma 2
            fprintf(pFile, "- Cantidad de ventas por un monto mayor a $150: %d \n",ventasMayor150);
            fprintf(pFile, "- Cantidad de ventas por un monto mayor a $300: %d \n",ventasMayor300);
            fprintf(pFile, "- Cantidad de polaroids: %d\n", totalPolaroid);
            //fprintf(pFile, "- Importe promedio por Entrega: %.2f\n", promedioPorEntrega);
            fprintf(pFile, "*****************************");

            retorno = 0;
        }
        if (retorno==0)
        {
            printf ("\nLista guardada correctamente.\n");
        }else
            printf ("\nNo se pudo guardar la lista correctamente.\n");
        fclose(pFile);
    }
    return retorno;
}

int TotalFotos (void* p)
{
    int retorno = 0;
    int cantidad=0;
    Venta* auxVenta = (Venta*)p;

    if (auxVenta!=NULL)
    {
        Venta_getCantidad(auxVenta,&cantidad);
        retorno=cantidad;
    }
    return retorno;
}

float probarFloat (void* p)
{
    float retorno = 0;
    float importe=0;
    Venta* auxVenta = (Venta*)p;

    if (auxVenta!=NULL)
    {
        Venta_getImporte(auxVenta,&importe);
        retorno=importe;
    }
    //printf ("%.2f \n",importe);
    return retorno;
}

int cantidadFotos(LinkedList* pArrayList)
{
    int retorno=-1;
    int i;
    int cantidadFotos=0;
    int acumulador=0;

    if (pArrayList!=NULL)
    {
        Venta* pAux;
        for (i=0;i<ll_len(pArrayList);i++)
        {
            pAux=ll_get(pArrayList,i);
            if(Venta_getCantidad(pAux,&cantidadFotos)==0)
            {
                acumulador = cantidadFotos+acumulador;
            }
            retorno=acumulador;
            //printf("Acumulador: %d",acumulador);
        }

    }
    return retorno;
}

float cantidadImporte(LinkedList* pArrayList)
{
    float retorno=-1;
    int i;
    float importe=0;
    float acumulador=0;

    if (pArrayList!=NULL)
    {
        Venta* pAux;
        for (i=0;i<ll_len(pArrayList);i++)
        {
            pAux=ll_get(pArrayList,i);
            if(Venta_getImporte(pAux,&importe)==0)
            {
                acumulador = importe+acumulador;
            }
            retorno=acumulador;
            //printf("Acumulador: %f",acumulador);
        }

    }
    return retorno;
}

int montoMayor150(void* p)
{
    int retorno=0;
    float auxImporte;
    int cantidad;
    float total;

    if (p!=NULL)
    {
        Venta_getImporte(p,&auxImporte);
        Venta_getCantidad(p,&cantidad);
        total= auxImporte*cantidad;
        if (total>150)
        {

            retorno=1;
        }
    }

    return retorno;
}

int montoMayor300(void* p)
{
    int retorno=0;
    float auxImporte;
    int cantidad;
    float total;

    if (p!=NULL)
    {
        Venta_getImporte(p,&auxImporte);
        Venta_getCantidad(p,&cantidad);
        total= auxImporte*cantidad;
        //printf ("Total: %f",total);
        if (total>300)
        {
            retorno=1;
        }
    }

    return retorno;
}

int PolaroidReveladas(void* p)
{
    int retorno = 0;
    Venta* auxVenta = (Venta*)p;

    if ((strcmp(auxVenta->tipo,"POLAROID_11x9")==0) || (strcmp(auxVenta->tipo,"POLAROID_10x10")==0))
    {
        retorno=1;
    }
    return retorno;
}

int cantidadPolaroid(LinkedList* arrayListVentas)
{
    int retorno=-1;
    int i;
    //char tipo;
    int cantidad;
    int acumulador;
    Venta* pAux;

    if (arrayListVentas!=NULL)
    {
        for (i=0;i<ll_len(arrayListVentas);i++)
        {
            pAux=ll_get(arrayListVentas,i);
            if ((strcmp(pAux->tipo,"POLAROID_11X9")==0) || (strcmp(pAux->tipo,"POLAROID_10X10")==0))
            {
                Venta_getCantidad(pAux,&cantidad);
                acumulador=cantidad+acumulador;
            }
        }
        retorno=acumulador;
    }
    return retorno;
}
#endif // CONTROLLER_C_INCLUDED
