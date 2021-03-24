#include <stdio.h>
#include <stdlib.h> //pour le exit(1);
#include <queue>//pour le queue
#include "datapoint.h"
#include <fstream> //pour l'Écriture dans un fichier

/*
 * @Auteur Joannie_RANGER
 * À noter quee les accents sont supprimés pour une lecture console sans affichage inadéquate pour la console.
*/

int main(int argc, char **argv)
{
	//doit avoir un conteneur de type approprié pour recevoir type datapoint.
    
    //Pointeur du fichier .txt des données brutes:
    FILE *pointeurFichier= fopen ("rawdata.txt","rt");
    
    /*Conteneur des datapoints
      selon l'ordre découlant de la latitude nord>sud et si égalité prend en considération la longitude ouest>est */
    std::priority_queue <Datapoint> lesLignes; 
    
    //Si l'ouverture du fichier ne fonctionne pas. On ferme le programme.
    if(pointeurFichier==NULL) exit(1);
    
    //Variable temp pour créer des datapoint
    char text1[60];
    char text2[60];
    std::string vStation,vDate; float vLatitude,vLongitude; int vTemperature;
    char ligne[100];
    
    //lire une ligne:
    //Dans le fichier "rawdata.txt"---> %unFloat(un espace)%unFloat(un espace)%unString(un espace)%unInt(un espace)%unString
    //fscanf(pointeurFichier, "%f %f %s %d %s", &vLatitude,&vLongitude,&vStation,&vTemperature,&vDate);

    while ( fgets( ligne, 100, pointeurFichier ) != NULL ) {
            
            fscanf(pointeurFichier, "%f %f %s %d %s", &vLatitude,&vLongitude,text1,&vTemperature,text2);
            //Noter que cette valeur "vStation" est inutile pour nous donc, on ne l'utilise pas pour notre datapoint
            vStation=(std::string(text1)); 
            vDate=(std::string(text2));
            //Ligne qui affiche un traitement pour chacune des lignes effectués. 
            cout<<"Traitement d'une ligne du fichier rawdata.txt: division en variable"<<endl;
            
            //Ajout dans la priority_queue
            lesLignes.push(Datapoint(vDate,vLatitude,vLongitude,vTemperature));
    }
    
    //fscanf(pointeurFichier, "%f %f %s", &vLatitude,&vLongitude,text1);
    /*Objet output file stream. Permet d’écrire dans un fichier
     * Fichier qui sera ouvert. S’il n’existe pas, le fichier sera créé.*/

    int taille=lesLignes.size();
    
    //pour écrire
    std::ofstream unFichier;
    
    unFichier.open("canada.txt");//on ouvre en mode trunc(par defaut) pour écrire et la sortie sera dans le nom de fichier canada.txt
    cout<<"\nDebut du traitement de l'information pour creation du fichier\n"<<endl;
    for (int i=0; i<taille;i++){
        if (unFichier.is_open()) {  
            std::string ligneAjout=lesLignes.top().ecrireInformations();
            unFichier << ligneAjout;
            //Ligne qui affiche un traitement pour chacune des lignes effectués.
            cout<<"Ecriture d'une ligne dans le fichier canada.txt et POP"<<endl;
            lesLignes.pop();
        }else{std::cout<<"Impossible: fichier non ouvert"<<std::endl;}
    }
    unFichier.close();
    
    //Ligne qui indique la fin du traitement du fichier
    cout<<"\n\n==================   La transformation en fichier <<canada.txt>> est completee!   ==================\n"<<endl;
    
    
    //Fermeture du fichier 
    fclose(pointeurFichier);
    
}

