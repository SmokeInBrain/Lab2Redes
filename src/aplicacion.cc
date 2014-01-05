#include <string.h>
#include <omnetpp.h>
#include <cstdlib>
#include <iostream>
#include "trama_m.h"

using namespace std;

class aplicacion: public cSimpleModule {
public:
    //Funciones y variables globales
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void generaPalabraInfo1();
    virtual void generaPalabraInfo2();
    int cantidad_de_tramas;
    int cuenta_tramas=0;
    int contador=0;


};

//variables de apoyo en el codigo
int turno = 0;
int cont;

Define_Module(aplicacion)
;

void aplicacion::initialize() {
}

//Esta funcion trata con los mensajes
void aplicacion::handleMessage(cMessage *msg) {
    //si llega desde abajo
    if(msg->arrivedOn("desde_abajo")){
        /* Si su tipo es "mismo" comenzar a enviar tramas
         * Esto se usa para realizar la respuesta a la
         * solicitud de conexi—n
         */
        if(msg->getKind()==TOKEN){
            /*
             * si soy la primera estacion comienzo a enviar tramas
             */
            if (turno == 0) {
                cantidad_de_tramas = par("cantidadTramas");
                cantidad_de_tramas = 3 * cantidad_de_tramas;
                generaPalabraInfo1();
                turno = 1;

            }
            else {
                /*
                 * esto es para la segunda estaci—n
                 */
                cantidad_de_tramas = par("cantidadTramas");
                cantidad_de_tramas = 3 * cantidad_de_tramas;
                delete msg;
                cuenta_tramas++;
                if(cuenta_tramas == cantidad_de_tramas){
                        cuenta_tramas=0;
                        generaPalabraInfo2();


                }
            }

        }else{
            /*
             * cuando llega algo que no es respuesta de solicitud
             * de conexion, debo responder con tramas para continuar
             * el envio
             */
            cantidad_de_tramas = par("cantidadTramas");
            cantidad_de_tramas = 3 * cantidad_de_tramas;
            delete msg;
            cuenta_tramas++;
            if(cuenta_tramas == cantidad_de_tramas){
                    cuenta_tramas=0;
                    generaPalabraInfo2();
            }
        }

    }


}

/*
 * esta funcion envia tramas de la estacion A
 * a la estacion B
 */
void aplicacion::generaPalabraInfo1() {
    int direccion = par("direccion");
   // int tamT = par("tamTrama");
    ev<<"SE ENVIAN MENSAJES DE A -> B"<<endl;
    for (int i = 0; i < cantidad_de_tramas; i++) {
        Mensaje *mens = new Mensaje("mensaje", DATA);
        send(mens, "hacia_abajo");
        ev<<"Host "<<direccion<<" -LA PALABRA QUE SE ENVIO DESDE LA APLICACION ES:"<<mens<<endl;
    }
}

/*
 * esta funcion envia tramas de la estacion B
 * a la estacion A
 */
void aplicacion::generaPalabraInfo2() {
    int direccion2 = par("direccion");
   // int tamT2 = par("tamTrama");
    if(direccion2==2){
    ev<<"SE ENVIAN MENSAJES DE B -> A"<<endl;
    }else{
        ev<<"SE ENVIAN MENSAJES DE A -> B"<<endl;
    }
    for (int i = 0; i < cantidad_de_tramas; i++) {
        Mensaje *mens2 = new Mensaje("mensaje", DATA);
        send(mens2, "hacia_abajo");
        ev<<"Host "<<direccion2<<" -LA PALABRA QUE SE ENVIO DESDE LA APLICACION ES:"<<mens2<<endl;
    }
}




