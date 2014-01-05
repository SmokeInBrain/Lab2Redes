#include <string.h>
#include <omnetpp.h>
#include <iostream>
#include <cstdlib>
#include "trama_m.h"

class enlace: public cSimpleModule {
public:
    /*
     * variables a utilizar
     */
    int tamanoVentana;
    int cantTramas;
    int tramasEnviadas;
    int inicioVentana;
    int finVentana;
    int cantidadTramas;
    int numACK;
    double probError;
    int tramasRecibidasEnlace=0;
    int idHost;
    int destiny=0;
    int origen=0;
    int contador = 0;

    //Métodos
protected:

    virtual void initialize();
    virtual void processMsgFromHigherLayer(cMessage *dato);
    virtual void processMsgFromLowerLayer(cMessage *packet);
    virtual void handleMessage(cMessage *msg);
    virtual void peticion_conexion();
    virtual void pasa_token();
    virtual void tengo_token();
};

Define_Module(enlace);

/*
 * funcion de inicializacion
 */
void enlace::initialize(){

    /*
     * rescatamos los valores por pantalla
     */
    tamanoVentana = par("tamanoVentana");
    numACK = par("numACK");
    probError = par("probError");

    tramasEnviadas = 0;
    inicioVentana = 0;
    finVentana = tamanoVentana-1;
    cantidadTramas = par("cantidadTramas");

    bool posee_token;

    /*
     * validamos valores ingresados
     */
    if(tamanoVentana<=0)
    {
        ev<<"ERROR: El tamanio de la ventana deslizante debe ser mayor a 0"<<endl;
        endSimulation();
    }
    if(numACK>tamanoVentana)
    {
        ev<<"ERROR: El numero de tramas enviadas antes de recibir un ACK no puede ser mayor al tamanio de la ventana deslizante"<<endl;
        endSimulation();
    }
    if(probError<0 || probError>1){
        ev<<"ERROR: La probabilidad de error debe ser mayor a 0 y menor a 1"<<endl;
        endSimulation();
    }

    //obtengo el Id del host que enviara la informacion
    int idHost = getId();

    ev<<"id del host: "<<idHost<<endl;

    if(idHost == 8){
        posee_token = true;
        if(posee_token){
            tengo_token();
        }
    }

}
void enlace::handleMessage(cMessage *msg) {
    //Si el mensaje llega desde el otro Host
    if (msg->arrivedOn("desde_fisico")) {
        // si es trama de informacion
        if(msg->getKind() == DATA){
            //Procesarlo como si viniera desde abajo
            processMsgFromLowerLayer(msg);
        }
        //si es ACK lo recibo y lo borro
        if(msg->getKind() == ACK){
            delete msg;
        }

   }

    //Sino, el mensaje viene desde intermedio
    else {
        //Procesarlo como si viajara desde arriba
        processMsgFromHigherLayer(msg);
    }
}

//Si la palabra llega desde intermedio enviar al otro host
void enlace::processMsgFromHigherLayer(cMessage *dato) {
    //Enviar el paquete a través del canal
    Mensaje *trama = new Mensaje("Trama",DATA);
    cPacket* aux = check_and_cast<cPacket*>(dato);
    trama->encapsulate(aux);
    trama->setOrigen(par("direccion"));

    send(trama, "hacia_fisico");

}

//Si la palabra llega desde el otro host enviar hacia intermedio
void enlace::processMsgFromLowerLayer(cMessage *packet) {
    //Enviar el paquete hacia el nivel intermedio

    Mensaje* aux = check_and_cast<Mensaje*>(packet);
    ev<<"cant de tramas: "<<cantidadTramas<<endl;
    aux->decapsulate();
    origen = aux->getOrigen();
    int numHost = getId();
    ev<<"origen: "<<origen<<endl;
    contador++;
    ev<<"contador: "<<contador<<endl;
    if(packet->getKind()==DATA){
        if(contador<=cantidadTramas){
            send(packet, "hacia_arriba");
            tramasRecibidasEnlace++;
        }else{
            if(contador>cantidadTramas){
                send(packet,"hacia_fisico");
            }
        }
        if(tramasRecibidasEnlace == numACK){ //envio ack segun la cantidad indicada
            ev<<"Envio ACK desde el Host "<<numHost<<endl;
            Mensaje *mens = new Mensaje("Envio ACK", ACK);
            send(mens, "hacia_fisico");
            tramasRecibidasEnlace=0;

        }

    }
}


void enlace::peticion_conexion() {
    //Se genera el mensaje para la conexion.
    Mensaje *mens = new Mensaje("Peticion de conexion", CONN); //Envia una peticion de conexion
    send(mens, "hacia_fisico"); // Manda el mensaje al medio fisico
}

void enlace::pasa_token(){
    Mensaje *mens = new Mensaje("TOKEN",TOKEN);
    send(mens, "hacia_fisico");
}

void enlace::tengo_token(){
    Mensaje *mens = new Mensaje("TOKEN",TOKEN);
    send(mens, "hacia_arriba");
}

