#include <iostream>
#include <string>

#include "Sensor.h"
#include "City.h"

using namespace std;

int main(void)
{
	
	
    //create a city
    City* Lyon=new City();
    
    //String to stock commands entered by users
    string Command;
    
    //stock int in order to give as argument to method
    int Id;
    int Year;
    int Month;
    int Day;
    int Hour;
    int Minute;
    int Seconde;
    char Value;
    int D7;
    
    // get commands entered by users
    cin>>Command;

    while (Command.compare("EXIT")!=0) {
	
		#ifdef MAP
		cout<< "nouveau depart boucle" << endl;
		cout<< "la commande entree est : " << Command << endl;
		#endif

      if (Command.compare("STATS_C")==0) {
		  
		#ifdef MAP
		cout<< "Appel a la commande STATS_C" << endl;
		#endif

        cin>>Id;
        
        //-------------------call the methode here----------
        
        //trace
        #ifdef MAP
			cout<<Id<<endl;
        #endif
        
		// Clear the command
        Command="";

     } else if (Command.compare("STATS_D7_H24")==0) {
		  
		#ifdef MAP
		cout<< "Appel a la commande STATS_D7_H24" << endl;
		#endif

        cin>>D7;
        cin>>Hour;
        //--------------call the methode here-------------------
        
        //trace
        #ifdef MAP
        cout<<D7<<endl;
        cout<<Hour<<endl;
        #endif
  
		// Clear the command
        Command="";

      } else if (Command.compare("STATS_D7")==0) {
		  
		#ifdef MAP
		cout<< "Appel a la commande STATS_D7" << endl;
		#endif

          cin>>D7;
          //--------------call the methode here---------------
          
          //trace
          #ifdef MAP
          cout<<D7<<endl;
          #endif
  
		// Clear the command
        Command="";
      }
      else if (Command.compare("ADD")==0) {
		  
		  #ifdef MAP
		  cout<< "Appel a la commande ADD" << endl;
		  #endif

          // stock into int
           cin>>Id;
           cin>>Year;
           cin>>Month;
           cin>>Day;
           cin>>Hour;
           cin>>Minute;
           cin>>Seconde;
           cin>>D7;
           cin>>Value;

          #ifdef MAP
          cout<< "Id : "<<Id<<", Year : "<<Year<<", Month : "<<Month<<", Day : "<<Day<<", Hour : "<<Hour<<", Minute : "<<Minute<<", Seconde : "<<Seconde<<", D7 : "<<D7<<", Value : "<<Value<<endl;
          #endif
          
        
        // ----------------------------call the addMethode here----------------------------
        //cast char to int for the sensor state
        
        //City.addState(int time, Day, Id, int traffic, sensorState)
        
        
		// Clear the command
		Command="";
		
            }
      else if (Command.compare("MAX_TS")==0) {
		  
		#ifdef MAP
		cout<< "Appel a la commande MAX_TS" << endl;
		#endif
		  	

        //-----------call methode here------------------
        
		// Clear the command
		Command="";
		
            }
            
		#ifdef MAP
		cout<< "attente d'une nouvelle consigne" << endl;
		#endif
		// wait for a new command
		cin>>Command;
   }
	
	
   return 0;
}

