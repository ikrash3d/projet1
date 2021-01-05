//Noms :        Abderraouf Benchoubane, Samy Cheklat, William Ringuet, Philippe Bonhomme

//Matricules :  1946665, 1937812 , 2015739, 2012859

//Description : Fichier qui declare la classe et les methodes du sonar

#define F_CPU 8000000UL  
#include <avr/io.h> 
#include <util/delay.h>
#include <avr/interrupt.h>

#include "lcm_so1602dtr_m_fw.h"
#include "customprocs.h" 
#include <stdlib.h>

/*Definition des pins en entree pour les sonars */
#define DISPLAY_DDR DDRB                                    // Data Direction Register (DDR) AVR occupe par l'ecran LCD
#define DISPLAY_PORT PORTB                                  // Port AVR occupe par l'ecran LCD 
#define TRIGGERING_PIN PB0
#define ECHO_SONAR_GAUCHE PA0
#define ECHO_SONAR_DEVANT PA1
#define ECHO_SONAR_DROITE PA2
#define INIT_TIMER 0
#define DISTANCE_OK 3
#define DISTANCE_DNG 1
#define LCD_REFRESH 250
#define INCREMENT_TIMER 100
#define DELAI_TRIGGER 10
#define CONV_ONDE_TO_DISTANCE 58
#define DEBUT_LIGNE_1 0
#define CENTRE_LIGNE_1 6
#define FIN_LIGNE_1 12
#define DEBUT_LIGNE_2 16
#define CENTRE_LIGNE_2 22
#define FIN_LIGNE_2 28
/************************************************/

class Sonar 
{
    public:
        Sonar();

        void recevoirEchoGauche();
        void recevoirEchoDroite();
        void recevoirEchoDevant();

        void determinerDistance();

        float getDistanceGauche()const;
        float getDistanceDevant()const;
        float getDistanceDroite()const;

        void afficherSonars();


    private: 

        float distanceGauche_;
        float distanceDevant_;
        float distanceDroite_;

};