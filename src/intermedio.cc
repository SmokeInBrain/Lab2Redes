#include <string.h>
#include <omnetpp.h>
#include "trama_m.h"

class intermedio: public cSimpleModule {
protected:
    virtual void processMsgFromHigherLayer(cMessage *packet);
    //Procesador de mensajes desde la capa inferior
    virtual void processMsgFromLowerLayer(cMessage *packet);
    //Receptor de mensajes
    virtual void handleMessage(cMessage *msg);

};
Define_Module(intermedio)
;
void intermedio::handleMessage(cMessage *msg) {
    if (msg->arrivedOn("desde_abajo"))
        processMsgFromLowerLayer(msg);
    else
        processMsgFromHigherLayer(msg);
}
void intermedio::processMsgFromHigherLayer(cMessage *packet) {
    //Envia el paquete hacia la capa de enlace
    send(packet, "hacia_abajo");
}
void intermedio::processMsgFromLowerLayer(cMessage *packet) {
    //Envía el paquete hacia la capa de aplicación
    send(packet, "hacia_arriba");
}
