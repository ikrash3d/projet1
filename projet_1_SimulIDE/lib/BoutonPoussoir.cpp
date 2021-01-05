 //Noms :        Abderraouf Benchoubane, Samy Cheklat, William Ringuet, Philippe Bonhomme

//Matricules :  1946665,1937812 , 2015739, 2012859

//Description : Fonction qui retourne un booleen (Vrai ou faux), Si le bouton est bien enffonce la fonction retourne Vrai, si non la fonction retourne Fauxs

#include <avr/interrupt.h>
#include <avr/io.h> 
#include "BoutonPoussoir.h"
#include "del.h"


/**
 * Constructeur de la classe BoutonPoussoir
 * 
 * @param pin correspondant au port ou est connecte le bouton poussoir
 * @param masque correspondant a la broche ou est connecte le bouton poussoir
 * @param etat_actuel est une variable qui augment lors dùne ìnterruption
 */
BoutonPoussoir::BoutonPoussoir(volatile uint8_t* pin, uint8_t masque)
{
    pin_ = pin; 
    masque_= masque;
}   

/**
 * Methode qui verifie si le bouton est appuyer
 * @return bool qui determine si le bouton poussoir a été appuyer ou non
 */
bool BoutonPoussoir::estAppuyer() 
{
    if (!(*pin_ & masque_)) 
    {
        _delay_ms(ANTI_REBOND);
        if (!(*pin_ & masque_))
        { 
            return true; 
        }  
    }
    return false;
}

/**
 * Methode qui initialise les registres permettant une utilisation adequate dìnterruption
 */
void BoutonPoussoir::initialisationInteruption() 
{
    // cli est une routine qui bloque toutes les interruptions. Il serait bien mauvais d'être interrompu alors que le microcontroleur n'est pas prêt...
    cli ();
        
    // Cette procédure ajuste le registre EIMSK de l’ATmega324PA pour permettre les interruptions externes
    EIMSK |= (1 << INT1) ;
    
    // Il faut sensibiliser les interruptions externes aux changements de niveau du bouton-poussoir en ajustant le registre EICRA
    EICRA |= (1 << ISC10) | (1 << ISC11) ;
    
    // sei permet de recevoir à nouveau des interruptions.
    sei ();
}

