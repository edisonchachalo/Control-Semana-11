#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main (int argc, char *argv[]) {


    struct Venta ventas[10];
    int totalVentas =0;
    int opcion;
    do
    {
        printf("\n Sistema de Ventas UDLA \n");
        printf("1. Ver productos\n");
        printf("2. Realizar venta\n");
        printf("3. Total Ventas realizadas\n");
        printf("4. Buscar venta\n");
        printf("5. salir\n");
        printf(">> ");
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 1:
                mostrarProductos();
                break;
            case 2:
                realizarVenta(ventas, &totalVentas);
                break;
            case 3:
                listarVentars(ventas, totalVentas);
                break;
            case 4:
                buscarVenta(ventas, totalVentas);
                break;
            case 5:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 5);
    
    return 0;
}