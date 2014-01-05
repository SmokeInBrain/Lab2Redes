network red
{
    parameters:
        int cantidadTramas @prompt("Ingrese la cantidad de tramas");
        int tamanoVentana @prompt("Ingrese tamano de la ventana");
        // cantidadTramas: numeric const,
        int numACK @prompt("Ingrese el numero de ACK");
        int probError @prompt("Ingrese la probabilidad de error");



        @display("bgb=730,325");
    types:
        channel canal extends ned.DatarateChannel
        {
            delay = 10ms;
        }
    submodules:
        Host_1: host {
            parameters:
                cantidadTramas = cantidadTramas;
                tamanoVentana = tamanoVentana;
                numACK = numACK;
                probError = probError;
                direccion = 1;
                @display("p=40,146;i=old/server1");
        }
        Host_2: host {
            parameters:
                cantidadTramas = cantidadTramas;
                tamanoVentana = tamanoVentana;
                numACK = numACK;
                probError = probError;
                direccion = 2;
                @display("p=337,41;i=old/server1");
        }
        Host_3: host {
            cantidadTramas = cantidadTramas;
            tamanoVentana = tamanoVentana;
            numACK = numACK;
            probError = probError;
            direccion = 3;
            @display("p=605,157;i=old/server1");
        }
        Host_4: host {
            cantidadTramas = cantidadTramas;
            tamanoVentana = tamanoVentana;
            numACK = numACK;
            probError = probError;
            direccion = 4;
            @display("p=347,261;i=old/server1");
        }
    connections:
        Host_1.salida --> canal --> Host_2.entrada;
        Host_2.salida --> Host_3.entrada;
        Host_3.salida --> Host_4.entrada;
        Host_4.salida --> Host_1.entrada;
}
