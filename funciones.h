struct Producto 
{
    char nombre[20];
    float precio;
};
struct Venta
{
    char cliente[30];
    char cedula [11];
    int numProductos;
    float total;
    struct Producto productos[5];

};

int validarNum();
void imprimirProductos();
void realizarVenta(struct Venta ventas[], int *totalVentas);
void listarVentars(struct Venta ventas[], int totalVentas);
void buscarVenta(struct Venta ventas[], int totalVentas);


