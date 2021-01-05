//Noms :        Abderraouf Benchoubane, Samy Cheklat, William Ringuet, Philippe Bonhomme

//Matricules :  1946665,1937812 , 2015739, 2012859

//Description : Classe de controle de la LED, le fichier contient les implementation des methodes de la class DEL

#include <avr/io.h> 
#include "del.h"


/**
 * Constructeur de la classe Del
 * @param port ou est connecte la del 
 */
DEL::DEL(volatile uint8_t* ddr, volatile uint8_t* port)
{
        *ddr |= ( 1 << PORTD0) | ( 1 << PORTD1) | ( 1 << PORTD2) | ( 1 << PORTD7); 
        port_ = port; 
}

/**
 * Methode qui permets d'allumer la del droite en rouge 
 */
void DEL::rougeDroit()
{       
        *port_ &= ~(VERTDROIT_); 
        *port_ |= ROUGEDROIT_;    
}


/**
 * Methode qui permets d'allumer la del gauche en rouge 
 */
void DEL::rougeGauche()
{       
        *port_ &= ~(VERTGAUCHE_);            
        *port_ |= ROUGEGAUCHE_;    
}

/**
 * Methode qui permets d'allumer la del droite en vert 
 */
void DEL::vertDroit()
{
        *port_ &= ~(ROUGEDROIT_);      
        *port_ |= VERTDROIT_;       
}

/**
 * Methode qui permets d'allumer la del droite en gauche
 */
void DEL::vertGauche()
{       

        *port_ &= ~(ROUGEGAUCHE_);
        *port_ |= VERTGAUCHE_;       
}

/**
 * Methode qui permets d'eteindre les dels en meme temps car aucune manoeuvre
 * nous demande de garder une roue ouverte pendant que l'autre est fermee
 */
void DEL::eteintDELS()
{
        *port_ &= ETEINT_; 
}
