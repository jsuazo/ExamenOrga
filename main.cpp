// queue::push/pop
#include "Evaluador.h"
#include "NodoAVL.h"
#include <iostream>
#include "tinyxml2.h"
#include <iostream>
#include <list>
using namespace std;
using namespace tinyxml2;

//Devuelve la cantidad de usuarios que tiene 18 anios o mas dado el nombre de un archivo XML
int contarMayoresDeEdadXML(string nombre_archivo)
{
   int contador =0;

    XMLDocument doc;
    doc.LoadFile(nombre_archivo.c_str());
    XMLElement* current_element = doc.FirstChildElement("current")->FirstChildElement("edad");

    if(atoi(current_element->Attribute("value"))>=18)
    contador++;

    return contador;
}

//Devuelve el numero anterior del nodo raiz de un Arbol dado
int obtenerNumeroAnterior(NodoAVL* raiz)
{
  NodoAVL *temporal = raiz;
  int sucesor = -1;
  temporal = temporal->izq;

  if( NULL != temporal )
  {
    while( NULL != temporal->der)
      temporal = temporal->der;

    sucesor = temporal->num;
  }

  return sucesor;


}

//Devuelve el numero siguiente del nodo raiz de un Arbol dado
int obtenerNumeroSiguiente(NodoAVL* raiz)
{
  NodoAVL *temporal = raiz;
  int sig = -1;
  temporal = temporal->der;

  if( NULL != temporal )
  {
    while( NULL != temporal->izq)
      temporal = temporal->izq;

    sig = temporal->num;
  }

  return sig;


}

//NOta: Fuente: //http://stackoverflow.com/questions/9438183/avl-find-successor

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
