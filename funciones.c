#include <stdio.h>
#include <string.h>
#include "funciones.h"

int validarNum()
{
    int valor;
    do
    {
        scanf("%d", &valor);
        if (valor <= 0)
        {
            printf("Error. Dato invalido");
        }
        return valor;
    } while (valor <= 0);
}

struct Producto productosDisponibles[] =
    {
        {"Laptop", 500},
        {"Celular", 100},
        {"Tablet", 150},
        {"Impresora", 220},
        {"PC", 450}};

void imprimirProductos()
{
    printf("\nProductos disponibles:\n");
    printf("#\tNombre\t\tPrecio\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t%s\t\t%.2f\n", i + 1, productosDisponibles[i].nombre, productosDisponibles[i].precio);
    }
}

void mostrarProductos()
{
    imprimirProductos();
}

void realizarVenta(struct Venta ventas[], int *totalVentas)
{
    if (*totalVentas >= 10)
    {
        printf("No se pueden realizar mas ventas\n");
        return;
    }
    struct Venta nuevaVenta;
    printf("Ingrese el nombre del cliente: ");
    scanf("%[^\n]", nuevaVenta.cliente);
    printf("Ingrese el documento de identidad del cliente: ");
    scanf("%s", nuevaVenta.cedula);

    imprimirProductos();
    printf("Ingrese el numero de productos a vender (max 5): ");
    nuevaVenta.numProductos = validarNum();

    if (nuevaVenta.numProductos > 5)
    {
        printf("Error. No se pueden vender mas de 5 productos.\n");
        return;
    }
    nuevaVenta.total = 0;
    for (int i = 0; i < nuevaVenta.numProductos; i++)
    {
        int idProducto;
        printf("Ingrese el # del producto %d: ", i + 1);
        scanf("%d", &idProducto);
        if (idProducto < 1 || idProducto > 5)
        {
            printf("Error. El producto no se encuentra en la lista.\n");
            i--;
            continue;
        }
        nuevaVenta.productos[i] = productosDisponibles[idProducto - 1];
        nuevaVenta.total += nuevaVenta.productos[idProducto - 1].precio;
    }

    ventas[*totalVentas] = nuevaVenta;
    (*totalVentas)++;
    printf("Venta realizada con exito\n");
}

void listarVentars(struct Venta ventas[], int totalVentas)
{
    float totalGeneral = 0;
    printf("\n Listado de Ventas \n");
    printf("Cliente\t\tCedula\t\tNum productos\t\tTotal\n");
    for (int i = 0; i < totalVentas; i++)
    {
        printf("%s\t\t%s\t\t%d\t\t%.2f\n", ventas[i].cliente, ventas[i].cedula, ventas[i].numProductos, ventas[i].total);
        totalGeneral += ventas[i].total;
    }
    printf("Total de ventas realizadas: %.2f\n", totalGeneral);
}

void buscarVenta(struct Venta ventas[], int totalVentas)
{
    char cedulaBuscada[11];
    int encontrado = 0;
    printf("Ingrese el documento de identidad del cliente a buscar: ");
    scanf("%s", cedulaBuscada);
    printf("\nCompras del cliente\n");
    printf("Cliente\t\tCedula\t\tNum productos\t\tTotal\n");

    for (int i = 0; i < totalVentas; i++)
    {
        if (strcmp(ventas[i].cedula, cedulaBuscada) == 0)
        {
            printf("%s\t\t%s\t\t%d\t\t%.2f\n", ventas[i].cliente, ventas[i].cedula, ventas[i].numProductos, ventas[i].total);
            encontrado = 1;
        }
    }
    if (!encontrado)
    {
        printf("No se encontro el cliente\n");
    }
}
