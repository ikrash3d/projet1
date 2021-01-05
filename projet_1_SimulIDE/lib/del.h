//Noms :        Abderraouf Benchoubane, Samy Cheklat, William Ringuet, Philippe Bonhomme

//Matricules :  1946665,1937812 , 2015739, 2012859

//Description : Classe de controle de la LED, le fichier est l'entete descriptif de la class.


#include <avr/io.h> 

class DEL{
public:

        DEL(volatile uint8_t* ddr, volatile uint8_t* port);

        void vertDroit();
        void vertGauche();
        void rougeDroit();
        void rougeGauche();
        void eteintDELS();

private: 

        static const uint8_t ROUGEGAUCHE_ = 0x02;   //(1<<PORTD1); 
        static const uint8_t ROUGEDROIT_ = 0x80;    //(1<<PORTD7);
        static const uint8_t VERTGAUCHE_ = 0x01;    //(1<<PORTD0);  
        static const uint8_t VERTDROIT_ = 0x04;    //(1<<PORTD2);
        static const uint8_t ETEINT_ = 0x78;        //(1<<PORTD3) | (1<<PORT4) | (1<<PORTD5) | (1<<PORTD6);

        volatile uint8_t* port_;
};

