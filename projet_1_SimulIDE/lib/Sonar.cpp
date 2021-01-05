//Noms :        Abderraouf Benchoubane, Samy Cheklat, William Ringuet, Philippe Bonhomme

//Matricules :  1946665, 1937812 , 2015739, 2012859

//Description : Fichier qui implemente les methodes de la classe du sonar


#include "Sonar.h"

/**
* Constructeur par defaut de la class Sonar
*/
Sonar ::Sonar() : distanceGauche_(0),distanceDevant_(0),distanceDroite_(0)
{
    DDRB |= (1 << TRIGGERING_PIN);
    DDRA &=~((1 << ECHO_SONAR_GAUCHE) & (1 << ECHO_SONAR_DEVANT) & (1 << ECHO_SONAR_DROITE));
}

/**
 * Methode pour recevoir l'echo du sonar gauche
 */
void Sonar::recevoirEchoGauche()
{

    uint8_t timer = INIT_TIMER;

    PORTB |= (1<< TRIGGERING_PIN);

    _delay_us(DELAI_TRIGGER);

    PORTB &= (~(1<<TRIGGERING_PIN)); 

    while(!(PINA & _BV(ECHO_SONAR_GAUCHE)))
    {}
    while(PINA & _BV(ECHO_SONAR_GAUCHE))
    {

        timer++;
        _delay_us(INCREMENT_TIMER);

    }
    distanceGauche_ = timer;
}

/**
 * Methode pour recevoir l'echo du sonar de devant
 */
void Sonar::recevoirEchoDevant()
{

    uint8_t timer = INIT_TIMER;
    
    PORTB |= (1<< TRIGGERING_PIN);
    
    _delay_us(DELAI_TRIGGER);

    PORTB &= (~(1<<TRIGGERING_PIN)); 

    while(!(PINA & _BV(ECHO_SONAR_DEVANT)))
    {}
    while(PINA & _BV(ECHO_SONAR_DEVANT))
    {
        timer++;
        _delay_us(INCREMENT_TIMER);

    }
    distanceDevant_ = timer;

}

/**
 * Methode pour recevoir l'echo du sonar droite
 */
void Sonar ::recevoirEchoDroite()
{

    uint8_t timer = INIT_TIMER;
    
    PORTB |= (1<< TRIGGERING_PIN);

    _delay_us(DELAI_TRIGGER);
    
    PORTB &= (~(1<<TRIGGERING_PIN)); 

    while(!(PINA & _BV(ECHO_SONAR_DROITE)))
    {}
    while(PINA & _BV(ECHO_SONAR_DROITE))
    {

        timer++;
        _delay_us(INCREMENT_TIMER);

    }  
    distanceDroite_ = timer; 

}

/**
 * Methode pour determiner les distances a partir des longeurs d'ondes
 */
void Sonar::determinerDistance()
{
    distanceGauche_ = (float)distanceGauche_/CONV_ONDE_TO_DISTANCE;
    distanceDevant_ = (float)distanceDevant_/CONV_ONDE_TO_DISTANCE;
    distanceDroite_ = (float)distanceDroite_/CONV_ONDE_TO_DISTANCE;
}

/**
 * Methode qui retourne la distances de l'objet a gauche du robot
 * @return distanceGauche_ la distance de l'objet a gauche du robot
 */
float Sonar::getDistanceGauche()const
{
    return distanceGauche_;
}


/**
 * Methode qui retourne la distances de l'objet a devant du robot
 * @return distanceDevant_ la distance de l'objet a devant du robot
 */
float Sonar::getDistanceDevant()const
{
    return distanceDevant_;
}

/**
 * Methode qui retourne la distances de l'objet a droite du robot
 * @return distanceDroite_ la distance de l'objet a droite du robot
 */
float Sonar::getDistanceDroite()const
{
    return distanceDroite_;
}

/**
 * Methode qui affiche les distances et les commentaires reliee a la distance
 */
void Sonar::afficherSonars()
{
    LCM display(&DISPLAY_DDR,&DISPLAY_PORT);

    char distanceGaucheStr[4];
    char distanceDroitStr[4];
    char distanceDevantStr[4];

    dtostrf(distanceGauche_, 2, 1, distanceGaucheStr);
    dtostrf(distanceDroite_, 2, 1, distanceDroitStr);
    dtostrf(distanceDevant_, 2, 1, distanceDevantStr);

    if(distanceGauche_ < DISTANCE_DNG )
    {
        display.write("DNGR",DEBUT_LIGNE_2);                           
        display.write(distanceGaucheStr,DEBUT_LIGNE_1);                
        display<<"m";
    }
    else if (distanceGauche_< DISTANCE_OK && distanceGauche_ >= DISTANCE_DNG)
    {
        display.write("ATTN",DEBUT_LIGNE_2);
        display.write(distanceGaucheStr,DEBUT_LIGNE_1);
        display<<"m";
    }
    else if (distanceGauche_ >= DISTANCE_OK)
    {
        display.write(" OK ",DEBUT_LIGNE_2);
        display.write(distanceGaucheStr,DEBUT_LIGNE_1);
        display<<"m";
    }

    if(distanceDevant_ < DISTANCE_DNG )
    {
        display.write("DNGR",CENTRE_LIGNE_2);                          
        display.write(distanceDevantStr,CENTRE_LIGNE_1);                 
        display<<"m";
    }
    else if (distanceDevant_< DISTANCE_OK && distanceDevant_ >= DISTANCE_DNG)
    {
        display.write("ATTN",CENTRE_LIGNE_2);
        display.write(distanceDevantStr,CENTRE_LIGNE_1);
        display<<"m";        
    }
    else if (distanceDevant_ >= DISTANCE_OK)
    {
        display.write(" OK ",CENTRE_LIGNE_2);
        display.write(distanceDevantStr,CENTRE_LIGNE_1);
        display<<"m";
    }

    if(distanceDroite_ < DISTANCE_DNG )
    {
        display.write("DNGR",FIN_LIGNE_2);                           
        display.write(distanceDroitStr,FIN_LIGNE_1);
        display<<"m";

    }
    else if (distanceDroite_< DISTANCE_OK && distanceDroite_ >= DISTANCE_DNG)
    {
        display.write("ATTN",FIN_LIGNE_2);
        display.write(distanceDroitStr,FIN_LIGNE_1);
        display<<"m";
    }
    else if (distanceDroite_ >= DISTANCE_OK)
    {
        display.write(" OK ",FIN_LIGNE_2);
        display.write(distanceDroitStr,FIN_LIGNE_1);
        display<<"m";
    }
    _delay_ms(LCD_REFRESH);
}