//Noms :        Abderraouf Benchoubane, Samy Cheklat, William Ringuet, Philippe Bonhomme

//Matricules :  1946665,1937812 , 2015739, 2012859

//Description : Fonction de controle du signal PWM, le fichier contient l'implementation de la fonction


#include "PWM.h"

/**
 * Methode qui genere un PWM pendant une duree passe en parametre, 
 * et ajuste les registre pour generer un PWM en phase correct en clk/8
 * @param pourcentageGauche correspondant à la vitesse de la roue gauche en %
 * @param pourcentageDroite correspondant à la vitesse de la roue droite en %
 */
void ajustementPWM (const uint8_t pourcentageGauche, const uint8_t pourcentageDroite)
{
    OCR1A = VALEUR_8BIT_MAX * (CENT_POUR_CENT - pourcentageDroite)/CENT_POUR_CENT;
    OCR1B = VALEUR_8BIT_MAX * (CENT_POUR_CENT - pourcentageGauche)/CENT_POUR_CENT;

    TCCR1A |= (1 << COM1A1) | (1 << COM1B1) | (1 << WGM10) | (1 << COM1A0) | (1 << COM1B0);

    TCCR1B |= (1 << CS11);

    TCCR1C = 0;

}