#ifndef PARSER_C_INCLUDED
#define PARSER_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Venta.h"

int parser_VentaFromText(FILE* pFile , LinkedList* pArrayListVenta)
{
    int retorno=-1;
    char auxId[500];
    char auxFecha[500];
    char auxTipo[500];
    char auxCantidad[500];
    char auxImporte[4096];
    char auxCuit[4096];
    int flag=0;

    Venta* pAuxVenta;

    if (pFile!=NULL && pArrayListVenta!=NULL)
    {
        while (!feof(pFile))
        {
            if (flag==0)
            {
                flag++;
                continue;
            }

            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxFecha,auxTipo,auxCantidad,auxImporte,auxCuit);


            //printf ("ID: %s \n",auxId);
            pAuxVenta = Venta_newParametros(auxId,auxFecha,auxTipo,auxCantidad,auxImporte,auxCuit);
            if (pAuxVenta !=NULL)
            {
                ll_add(pArrayListVenta,pAuxVenta);
                retorno=0;
            }
        }
        fclose(pFile);
    }

    return retorno;
}


#endif // PARSER_C_INCLUDED
