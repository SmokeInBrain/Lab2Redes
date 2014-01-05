//
// Generated file, do not edit! Created by opp_msgc 4.3 from trama.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "trama_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("tipoPaquete");
    if (!e) enums.getInstance()->add(e = new cEnum("tipoPaquete"));
    e->insert(CONN, "CONN");
    e->insert(ACK, "ACK");
    e->insert(DATA, "DATA");
    e->insert(TOKEN, "TOKEN");
    e->insert(OK, "OK");
    e->insert(MISMO, "MISMO");
);

Register_Class(Mensaje);

Mensaje::Mensaje(const char *name, int kind) : cPacket(name,kind)
{
    this->tipo_var = 0;
    this->origen_var = 0;
    this->destino_var = 0;
    this->datos_var = 0;
    this->numeroDeTrama_var = 0;
    this->tramasTotal_var = 0;
}

Mensaje::Mensaje(const Mensaje& other) : cPacket(other)
{
    copy(other);
}

Mensaje::~Mensaje()
{
}

Mensaje& Mensaje::operator=(const Mensaje& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void Mensaje::copy(const Mensaje& other)
{
    this->tipo_var = other.tipo_var;
    this->origen_var = other.origen_var;
    this->destino_var = other.destino_var;
    this->datos_var = other.datos_var;
    this->numeroDeTrama_var = other.numeroDeTrama_var;
    this->tramasTotal_var = other.tramasTotal_var;
}

void Mensaje::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->tipo_var);
    doPacking(b,this->origen_var);
    doPacking(b,this->destino_var);
    doPacking(b,this->datos_var);
    doPacking(b,this->numeroDeTrama_var);
    doPacking(b,this->tramasTotal_var);
}

void Mensaje::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->tipo_var);
    doUnpacking(b,this->origen_var);
    doUnpacking(b,this->destino_var);
    doUnpacking(b,this->datos_var);
    doUnpacking(b,this->numeroDeTrama_var);
    doUnpacking(b,this->tramasTotal_var);
}

int Mensaje::getTipo() const
{
    return tipo_var;
}

void Mensaje::setTipo(int tipo)
{
    this->tipo_var = tipo;
}

int Mensaje::getOrigen() const
{
    return origen_var;
}

void Mensaje::setOrigen(int origen)
{
    this->origen_var = origen;
}

int Mensaje::getDestino() const
{
    return destino_var;
}

void Mensaje::setDestino(int destino)
{
    this->destino_var = destino;
}

const char * Mensaje::getDatos() const
{
    return datos_var.c_str();
}

void Mensaje::setDatos(const char * datos)
{
    this->datos_var = datos;
}

int Mensaje::getNumeroDeTrama() const
{
    return numeroDeTrama_var;
}

void Mensaje::setNumeroDeTrama(int numeroDeTrama)
{
    this->numeroDeTrama_var = numeroDeTrama;
}

int Mensaje::getTramasTotal() const
{
    return tramasTotal_var;
}

void Mensaje::setTramasTotal(int tramasTotal)
{
    this->tramasTotal_var = tramasTotal;
}

class MensajeDescriptor : public cClassDescriptor
{
  public:
    MensajeDescriptor();
    virtual ~MensajeDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MensajeDescriptor);

MensajeDescriptor::MensajeDescriptor() : cClassDescriptor("Mensaje", "cPacket")
{
}

MensajeDescriptor::~MensajeDescriptor()
{
}

bool MensajeDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<Mensaje *>(obj)!=NULL;
}

const char *MensajeDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MensajeDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int MensajeDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *MensajeDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "tipo",
        "origen",
        "destino",
        "datos",
        "numeroDeTrama",
        "tramasTotal",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int MensajeDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "tipo")==0) return base+0;
    if (fieldName[0]=='o' && strcmp(fieldName, "origen")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destino")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "datos")==0) return base+3;
    if (fieldName[0]=='n' && strcmp(fieldName, "numeroDeTrama")==0) return base+4;
    if (fieldName[0]=='t' && strcmp(fieldName, "tramasTotal")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MensajeDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "string",
        "int",
        "int",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *MensajeDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "tipoPaquete";
            return NULL;
        default: return NULL;
    }
}

int MensajeDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    Mensaje *pp = (Mensaje *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MensajeDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    Mensaje *pp = (Mensaje *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getTipo());
        case 1: return long2string(pp->getOrigen());
        case 2: return long2string(pp->getDestino());
        case 3: return oppstring2string(pp->getDatos());
        case 4: return long2string(pp->getNumeroDeTrama());
        case 5: return long2string(pp->getTramasTotal());
        default: return "";
    }
}

bool MensajeDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    Mensaje *pp = (Mensaje *)object; (void)pp;
    switch (field) {
        case 0: pp->setTipo(string2long(value)); return true;
        case 1: pp->setOrigen(string2long(value)); return true;
        case 2: pp->setDestino(string2long(value)); return true;
        case 3: pp->setDatos((value)); return true;
        case 4: pp->setNumeroDeTrama(string2long(value)); return true;
        case 5: pp->setTramasTotal(string2long(value)); return true;
        default: return false;
    }
}

const char *MensajeDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<6) ? fieldStructNames[field] : NULL;
}

void *MensajeDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    Mensaje *pp = (Mensaje *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


