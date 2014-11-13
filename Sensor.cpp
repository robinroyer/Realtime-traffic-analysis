


/*************************************************************************
                           ${file_base}  -  description
                             -------------------
    d�but                : ${date}
    copyright         1   : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <${file_base}> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <time.h>


//------------------------------------------------------ Include personnel
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

int Sensor::GetId(){
    return   idSensor;
}


void Sensor::Add(Sensor theOneToAdd){
    nextSensor=&theOneToAdd;
}




void Sensor::StatsIdSensor()
// Algorithme :
{
    // calculing percentage in a tab
    int tab[4];//!!!! a changer car on ne peut renvoyer un tab qui se supprime a la fin de la methode
    tab[0]=100*(traffic[0]/(  traffic[0]+  traffic[1]+  traffic[2]+  traffic[3]));
    tab[1]=100*(traffic[1]/(  traffic[0]+  traffic[1]+  traffic[2]+  traffic[3]));
    tab[2]=100*(traffic[2]/(  traffic[0]+  traffic[1]+  traffic[2]+  traffic[3]));
    tab[3]=100*(traffic[3]/(  traffic[0]+  traffic[1]+  traffic[2]+  traffic[3]));

    // to display stats of this sensor
    cout<<"V "<<tab[0]<<"%"<<endl;
    cout<<"J "<<tab[1]<<"%"<<endl;
    cout<<"R "<<tab[2]<<"%"<<endl;
    cout<<"N "<<tab[3]<<"%"<<endl;

} //----- Fin de M�thode

Sensor* Sensor::GetNext()
{

    return   nextSensor;

}

 float* Sensor::SensorUpdate(time_t currentTime, int state)
 {
     //the value we need to return
     float *BeingActived =new float[3];
     // updating traffic[4]
    if (difftime(currentTime,lastTime)<300){
          traffic[lastState]=+difftime(currentTime,lastTime);
          BeingActived[0]=difftime(currentTime,lastTime);
        }
    else {
          traffic[lastState]=+300;
          BeingActived[0]=300;
    }
    //stocking laststate and lasttime
    BeingActived[1]=lastState;
    BeingActived[2]=lastTime;

    //updating lastTime and lastState
      lastTime=currentTime;
      lastState=state;
      return BeingActived;

 }

//------------------------------------------------- Surcharge d'op�rateurs


//-------------------------------------------- Constructeurs - destructeur

Sensor::Sensor ()
//Alorithme :
{
    #ifdef MAP
    cout << "Appel au constructeur de Sensor par default" << endl;
    #endif

    nextSensor=NULL;
}

Sensor::Sensor(int Id)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <${file_base}>" << endl;
#endif
      idSensor=Id;
      //Sensor * sensorTemp = new Sensor();
      //nextSensor=sensorTemp;
      nextSensor=NULL;
      traffic[0]=0;
      traffic[1]=0;
      traffic[2]=0;
      traffic[3]=0;
      //to avoid a problem at the first add
      lastState=-1;
      lastTime=0;
} //----- Fin de ${file_base}


Sensor::~Sensor ( )
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au destructeur de <${file_base}>" << endl;
#endif
} //----- Fin de ~${file_base}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
