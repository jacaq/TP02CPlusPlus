#ifndef __DATAPOINT_H__
#define __DATAPOINT_H__
#include <iostream>
#include <string>
//Importation des fonction std pour les affichages dans le main.
using std::cout;
using std::endl;
using std::cin;
//#include <cmath>//finalement inutile

class Datapoint{
    
private:
    //Les quatre attributs de la classe Datapoint.
    std:: string letimeStamp;
    float latitude;
    float longitude;
    float temperature;
    
public:
    
    //Constructeur du Datapoint
    Datapoint(std::string date, float latitude, float longitude,float temperature){
            this->letimeStamp= date;
            this->latitude=latitude;
            this->longitude= longitude;
            //Pour convertir des Fahrenheits en Celsius il suffit de faire: (Fahrenheit - 32) * 5/9;
            //on transforme en Celsius ici directement.
            this->temperature=(temperature-32)*5/9;
    }

    //Fonction qui retourne la ligne qui sera écrite dans le fichier.
    std::string ecrireInformations() const{
        std::string ligne;
        std::string tempLat= std::to_string(latitude) ;
        std::string tempLong= std::to_string(longitude);
        std::string tempTemp= std::to_string(temperature);
        ligne=letimeStamp+" ";
        ligne+=tempLat+" ";
        ligne+=tempLong+" ";
        ligne+=tempTemp+" ";
        ligne+="\n";
        return ligne;
    }
    
    //Redéfinition de l'opérateur< pour mettre en ordre la priority_queue.
    bool operator< (const Datapoint& le_datapoint_a_droite) const{
        if (le_datapoint_a_droite.latitude < this->latitude){
            return false;
        }
        else if(this->latitude == le_datapoint_a_droite.latitude){
            if(le_datapoint_a_droite.longitude > this->longitude )
                return false;
        }
     return true;   
    }
    
    
    
};

#endif