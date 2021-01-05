 //Noms :        Abderraouf Benchoubane, Samy Cheklat, William Ringuet, Philippe Bonhomme

//Matricules :  1946665,1937812 , 2015739, 2012859

#include "SeptSegment.h"


static volatile uint8_t tableauSegments[5];

static volatile uint8_t compteur = COMPTEUR_INIT; 

/**
 * Methode qui sépare les entiers envoyes en parametres en unité et en dizaine
 * @param pourcentageGauche qui correspond au nombre allume a gauche sur le septSegment (0 a 99)
 * @param pourcentageDroit qui correspond au nombre allume a droite sur le septSegment (0 a 99)
 */
void convertisseurVersSeptSeg(const uint8_t pourcentageGauche, const uint8_t pourcentageDroit)
{

    tableauSegments[0] = transitionPourcentage((pourcentageGauche/10));            //Calcul qui permet d'aller chercher la dizaine
    tableauSegments[1] = transitionPourcentage((pourcentageGauche%10));            //Calcul qui permet d'aller chercher l'unite
    tableauSegments[2] = SEPARATION;
    tableauSegments[3] = transitionPourcentage((pourcentageDroit/10));
    tableauSegments[4] = transitionPourcentage((pourcentageDroit%10));

}

/**
 * Methode qui initilasie les ports afin de faire fonctionner le SeptDegment adequatement
 */
void initSeptSegment()
{
    DDR_7SEGMENTS_POWER |=  (1<<SEGMENT1_POWER)|(1<<SEGMENT2_POWER)|
                            (1<<SEGMENT3_POWER)|(1<<SEGMENT4_POWER)|(1<<SEGMENT5_POWER);
    
    DDR_7SEGMENTS_DATA = PORT7SEG_OUVERT;

}


/**
 * Fonction qui retourne une variable qui permet d'allumer le SeptSegment avec l'unite qui est, passe en parametre
 * @param seg le chiffre qui sera allume par le SeptSegment
 */
uint8_t transitionPourcentage(const uint8_t seg) 
{
    switch (seg) 
    {
        case 0 :
            return ZERO;

        case 1 :
            return UN;

        case 2:
            return DEUX;

        case 3:
            return TROIS;

        case 4:
            return QUATRE;

        case 5: 
            return CINQ;

        case 6:
            return SIX;

        case 7:
            return SEPT;

        case 8:
            return HUIT;

        case 9:
            return NEUF;
    }
    return 0;
}

/**
 * Methode qui initialise les registres pour avoir un Timer en mode OverFlow
 */
void initMinuterieDeux()
{
    TCCR2B |=( 1 << CS21); //prescalaire de 64
    TCNT2 = 0;
    TIMSK2 |= ( 1 << TOIE2);
    TIFR2  |= ( 1 << TOV2);
    sei();

}
/**
 * Methode qui remet les registres en arret pour le Timer2 en mode OverFlow
 */
void arretMinuterieDeux()
{
    TCCR2B &= ~( 1 << CS21); 
    TCNT2 = 0;
    TIMSK2 &= ( 1 << TOIE2);
    TIFR2  &= ~( 1 << TOV2);
    sei();
}
/**
 * Methode qui nous permet de gerer les interruption de type 
 * "overflow" afin d'afficher des valeurs sur le sept segments
 */

ISR(TIMER2_OVF_vect)
{
    PORTA |= ALLUMER_7SEG; 
    
    PORT_7SEGMENTS_POWER &= ~(1 << (compteur+3));
    PORT_7SEGMENTS_DATA = tableauSegments[compteur];

    compteur++;
    if(compteur >= COMPTEUR_MAX)
    {
        compteur = COMPTEUR_RESET; 
    } 
}