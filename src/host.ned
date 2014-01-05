module host{
    parameters:
        int direccion;        
        int cantidadTramas;
	    int tamanoVentana;
	   // cantidadTramas: numeric const,
	    int numACK;
	    int probError;
    gates:
        input entrada;
        output salida;
    submodules:
        varAplicacion: aplicacion{
            parameters:                
                direccion = direccion;
                cantidadTramas = cantidadTramas;

            @display( "p=98,44;i=abstract/penguin");
        }
        varIntermedio: intermedio{
            @display("p=98,152;i=abstract/switch");
        }
        varEnlace: enlace{
            parameters:                
                direccion = direccion;
                tamanoVentana = tamanoVentana;
                numACK = numACK;
                probError = probError;
                cantidadTramas=cantidadTramas;
            @display( "p=97,245;i=block/plug");
        }
    connections:
        varAplicacion.hacia_abajo --> varIntermedio.desde_arriba;
        varIntermedio.hacia_arriba --> varAplicacion.desde_abajo;
        varIntermedio.hacia_abajo --> varEnlace.desde_arriba;
        varEnlace.hacia_arriba --> varIntermedio.desde_abajo;
        varEnlace.hacia_fisico --> salida;
        entrada --> varEnlace.desde_fisico;
    //@display( "o=,,;b=208,315,,,,");
}


