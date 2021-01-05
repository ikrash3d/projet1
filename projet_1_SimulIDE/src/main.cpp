//Noms :        Abderraouf Benchoubane, Samy Cheklat, William Ringuet, Philippe Bonhomme

//Matricules :  1946665, 1937812 , 2015739, 2012859

//Description : Fichier qui effectue les manoeuvres selon les conditions (main)

/*                                                                        Tableau d'etats
*********************************************************************************************************************************************************************
|ETAT PRESENT| (ENTRÉE) BOUTON-POUSSOIR | (ENTRÉE) DISTANCE GAUCHE | (ENTRÉE) DISTANCE DEVANT | (ENTRÉE) DISTANCE DROITE|  ETAT SUIVANT  |         SORTIE           |
*********************************************************************************************************************************************************************
|DÉTECTION	|              0            |           X              |            X             |           X             |   DÉTECTION    | AFFICHAGE DES DISTANCES  |                     
|DÉTECTION	|              1            |           X              |            X             |           X             |   MANOEUVRES   | AFFICHAGE DES DISTANCES  | 
|MANOEUVRES	|              X            |           OK             |            OK            |          ATTN           |   DÉTECTION    |       MANOEUVRE1         |
|MANOEUVRES	|              X            |          ATTN            |            OK            |           OK            |   DÉTECTION    |       MANOEUVRE2         |           
|MANOEUVRES	|              X            |           OK             |           DNGR           |          DNGR           |   DÉTECTION    |       MANOEUVRE3         | 
|MANOEUVRES	|              X            |          DNGR            |           DNGR           |           OK            |   DÉTECTION    |       MANOEUVRE4         |
|MANOEUVRES	|              X            |          DNGR            |           DNGR           |          DNGR           |   DÉTECTION    |       MANOEUVRE5         |
|MANOEUVRES	|              X            |          ATTN            |            OK            |          ATTN           |   DÉTECTION    |       MANOEUVRE6         |           
|MANOEUVRES	|              X            |---------------------------TOUTES AUTRES COMBINAISONS--------------------------|   DÉTECTION    | AUCUNE MANOEUVRES EVALUEE|                
*********************************************************************************************************************************************************************
*/

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h> 
#include <avr/interrupt.h>
#include "../lib/BoutonPoussoir.h"
#include "../lib/manoeuvres.h"
#include "../lib/Sonar.h"


/********DEFINE***********/

#define PIN_BOUTON PIND
#define MASQUE_BOUTON 0x08
#define ANTI_REBOND_ISR 30
#define TEMPS_CALCUL 20

enum Etats {DETECTION,MANOEUVRE};
volatile Etats etat_actuel = DETECTION; 

ISR ( INT1_vect ) {

    // laisser un delai avant de confirmer la réponse du bouton-poussoir: environ 30 ms (anti-rebond)

    _delay_ms(ANTI_REBOND_ISR);

    etat_actuel=Etats(MANOEUVRE);  //Incrementation de l'etat

    // se souvenir ici si le bouton est pressé ou relâché
    //changements d'états tels que ceux de la semaine précédente

    EIFR |= (1 << INTF1) ;
}


int main(){
    
    Sonar sonar;
    
    BoutonPoussoir bouton(&PIN_BOUTON, MASQUE_BOUTON);

    bouton.initialisationInteruption();

    for(;;){
        switch(etat_actuel){

            case(DETECTION):
            while(etat_actuel==Etats(DETECTION)){
                sonar.recevoirEchoGauche();
                sonar.recevoirEchoDevant();
                sonar.recevoirEchoDroite();

                sonar.determinerDistance();
                _delay_ms(TEMPS_CALCUL);
                sonar.afficherSonars();
            }   
            
            case(MANOEUVRE):
            if(sonar.getDistanceGauche() > DISTANCE_OK && sonar.getDistanceDevant() > DISTANCE_OK
              && sonar.getDistanceDroite() > DISTANCE_DNG && sonar.getDistanceDroite() < DISTANCE_OK)
            {
           
                manoeuvre1();
                etat_actuel = DETECTION;
                break;

            }
            if(sonar.getDistanceGauche() < DISTANCE_OK && sonar.getDistanceGauche() > DISTANCE_DNG 
              && sonar.getDistanceDevant() > DISTANCE_OK && sonar.getDistanceDroite() > DISTANCE_OK)
            {
                manoeuvre2();
                etat_actuel = DETECTION;
                break;

            }
            if(sonar.getDistanceGauche() > DISTANCE_OK && sonar.getDistanceDevant() < DISTANCE_DNG && sonar.getDistanceDroite() < DISTANCE_DNG)
            {
                manoeuvre3();
                etat_actuel = DETECTION;
                break;

            }
            if(sonar.getDistanceGauche() < DISTANCE_DNG && sonar.getDistanceDevant() < DISTANCE_DNG && sonar.getDistanceDroite() > DISTANCE_OK)
            {
                manoeuvre4();
                etat_actuel = DETECTION;
                break;

            }
            if(sonar.getDistanceGauche() < DISTANCE_DNG && sonar.getDistanceDevant() < DISTANCE_DNG && sonar.getDistanceDroite() < DISTANCE_DNG)
            {
                manoeuvre5();
                etat_actuel = DETECTION;
                break;

            }
            if(sonar.getDistanceGauche() < DISTANCE_OK && sonar.getDistanceGauche() > DISTANCE_DNG && sonar.getDistanceDevant() > DISTANCE_OK
               && sonar.getDistanceDroite() > DISTANCE_DNG && sonar.getDistanceDroite() < DISTANCE_OK)
            {
                manoeuvre6();
                etat_actuel = DETECTION;
                break;

            }
            else
            {

                manoeuvreIndeterminer();
                etat_actuel = DETECTION;

            }
        }
    }

    return 0;
}
