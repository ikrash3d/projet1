//Noms :        Abderraouf Benchoubane, Samy Cheklat, William Ringuet, Philippe Bonhomme

//Matricules :  1946665,1937812 , 2015739, 2012859

//Description : Fonction de controle du signal PWM, le fichier contient l'entete de la fonction


#include <avr/io.h>  

/*********DEFINE**********/

#define VALEUR_8BIT_MAX 255
#define CENT_POUR_CENT 100

void ajustementPWM (const uint8_t pourcentageGauche, const uint8_t pourcentageDroite);

