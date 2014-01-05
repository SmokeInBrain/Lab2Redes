simple enlace{
	
	parameters:
	    
	    int direccion;  
	    //int tamTrama;
	    int tamanoVentana;
	   	int cantidadTramas;
	    int numACK;
	    int probError;
	
	gates:
	    
	    input desde_fisico;
	    output hacia_fisico;
	    
	    input desde_arriba;
	    output hacia_arriba;
}