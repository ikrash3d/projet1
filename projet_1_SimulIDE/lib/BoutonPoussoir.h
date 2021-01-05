//Noms :        Abderraouf Benchoubane, Samy Cheklat, William Ringuet, Philippe Bonhomme

//Matricules :  1946665,1937812 , 2015739, 2012859

//Description : Fonction qui retourne un booleen (Vrai ou faux), Si le bouton est bien enffonce la fonction retourne Vrai, si non la fonction retourne Fauxs

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>

/********DEFINE*********/

#define ANTI_REBOND 10


class BoutonPoussoir {
public:

    BoutonPoussoir(volatile uint8_t* pin, uint8_t masque);
    
    bool estAppuyer();

    void initialisationInteruption ();


private:
    
    volatile uint8_t *pin_;
    uint8_t masque_;
 
};
