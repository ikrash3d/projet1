//Noms :        Abderraouf Benchoubane, Samy Cheklat, William Ringuet, Philippe Bonhomme

//Matricules :  1946665, 1937812 , 2015739, 2012859

//Description : Procedures qui effectuent les manoeuvres du robot

#include "manoeuvres.h"


/**
 * Procedure qui initilasie les port et les registres du Setp Segment, de la del et du PWM pour effectué les manoeuvres
 */
void initialiserManoeuvre()
{
    initSeptSegment();
    initMinuterieDeux();
    DDR_7SEGMENTS_POWER |= (1<<SEGMENT1_POWER) | (1<<SEGMENT2_POWER)
                           | (1<<SEGMENT3_POWER) | (1<<SEGMENT4_POWER) | (1<<SEGMENT5_POWER);     
    DDRD = PWM_DEL_ENABLE;                 
}

/**
 * Procedure qui arrete les ports losrqu'on passe en mode manoeuvre a un mode
 * detection
 */
void clearPort()
{
    arretMinuterieDeux();
    DDRC = MODE_ENTREE_PORT;
    DDRD = MODE_ENTREE_PORT;
    DDRA = MODE_ENTREE_PORT;
    
}

/**
 * Procedure qui permet au robot d'executer la manouvre 1 
 */
void manoeuvre1()
{
    DEL del(&DEL_DDR,&DEL_PORT);
    LCM display(&LCD_DDR, &LCD_PORT);

    initialiserManoeuvre();  
    display.clear();              
    display.write("Manoeuvre 1");
    del.vertDroit();       
    del.vertGauche();

    for(uint8_t i = 90; i >= 52; i--)
    {                                                   //Les valeurs en parametres d'ajustementPWM() representent le % dans l'ordre, la roue gauche et la roue droite   
        ajustementPWM(i,90);                            //Les valeurs en parametres de convertisseurVersSept representent le % de chaque roue dans l'ordre,
        convertisseurVersSeptSeg(i, 90);                //la roue gauche et la roue droite sur l'afficheur 7segments
        _delay_ms(DELAI_INCREMENTATION);
    }

    _delay_ms(UNE_SECONDE);

    for(uint8_t i = 52; i <= 90; i++)
    {
        ajustementPWM(i,90);
        convertisseurVersSeptSeg(i, 90);
        _delay_ms(DELAI_INCREMENTATION);
    }

    _delay_ms(DEUX_SECONDES);
    clearPort();
    display.clear();
}   

/**
 * Procedure qui permet au robot d'executer la manouvre 2
 */
void manoeuvre2()
{
    DEL del(&DEL_DDR,&DEL_PORT);
    LCM display(&LCD_DDR, &LCD_PORT);

    initialiserManoeuvre();
    display.clear();
    display.write("Manoeuvre 2");
    del.vertDroit();
    del.vertGauche();

    for(uint8_t i = 90; i >= 52; i--)
    {
        ajustementPWM(90,i);
        convertisseurVersSeptSeg(90, i);
        _delay_ms(DELAI_INCREMENTATION);
    }

    _delay_ms(1000);

    for(uint8_t i = 52; i <= 90; i++)
    {
        ajustementPWM(90,i);
        convertisseurVersSeptSeg(90, i);
        _delay_ms(DELAI_INCREMENTATION);
    }

    _delay_ms(DEUX_SECONDES);
    clearPort();
    display.clear();
}

/**
 * Procedure qui permet au robot d'executer la manouvre 3
 */
void manoeuvre3()
{
    DEL del(&DEL_DDR,&DEL_PORT);
    LCM display(&LCD_DDR, &LCD_PORT);

    initialiserManoeuvre();
    display.clear();
    display.write("Manoeuvre 3");

    del.rougeGauche();
    del.vertDroit();
    ajustementPWM(50, 50);
    convertisseurVersSeptSeg(50,50);

    _delay_ms(UNE_SECONDE);

    del.vertDroit();
    del.vertGauche();
    ajustementPWM(66,66);
    convertisseurVersSeptSeg(66,66);

    _delay_ms(DEUX_SECONDES);

    del.rougeDroit();
    del.vertGauche();
    ajustementPWM(50,50);
    convertisseurVersSeptSeg(50,50);

    _delay_ms(UNE_SECONDE); 

    del.vertGauche();
    del.vertDroit();
    ajustementPWM(78,78);
    convertisseurVersSeptSeg(78,78);

    _delay_ms(DEUX_SECONDES);
    clearPort();
    display.clear();
}

/**
 * Procedure qui permet au robot d'executer la manouvre 4
 */
void manoeuvre4() 
{
    DEL del(&DEL_DDR,&DEL_PORT);
    LCM display(&LCD_DDR, &LCD_PORT);

    initialiserManoeuvre();
    display.clear();
    display.write("Manoeuvre 4");

    del.rougeDroit();
    del.vertGauche();
    ajustementPWM(50,50);
    convertisseurVersSeptSeg(50,50);

    _delay_ms(UNE_SECONDE);

    del.vertDroit();
    del.vertGauche();
    ajustementPWM(66,66);
    convertisseurVersSeptSeg(66,66);

    _delay_ms(DEUX_SECONDES);

    del.rougeGauche();
    del.vertDroit();
    ajustementPWM(50,50);
    convertisseurVersSeptSeg(50,50);

    _delay_ms(UNE_SECONDE);

    del.vertDroit();
    del.vertGauche();
    ajustementPWM(78,78);
    convertisseurVersSeptSeg(78,78);

    _delay_ms(DEUX_SECONDES);
    clearPort();
    display.clear();
}

/**
 * Procedure qui permet au robot d'executer la manouvre 5
 */
void manoeuvre5() 
{
    DEL del(&DEL_DDR,&DEL_PORT);
    LCM display(&LCD_DDR, &LCD_PORT);

    initialiserManoeuvre();
    display.clear();
    display.write("Manoeuvre 5");
   
    del.vertGauche();
    del.rougeDroit();
    ajustementPWM(50,50);
    convertisseurVersSeptSeg(50,50);
   
    _delay_ms(DEUX_SECONDES);
   
    del.eteintDELS();
    del.vertDroit();
    del.vertGauche();
    
    for(uint8_t i = 0; i <= 21; i++)
    {
        ajustementPWM(i*3, i*3);
        convertisseurVersSeptSeg(i*3,i*3);
        _delay_ms(125);
    }
    _delay_ms(DEUX_SECONDES);
    clearPort();
    display.clear();
}

/**
 * Procedure qui permet au robot d'executer la manouvre 6
 */
void manoeuvre6() 
{
    DEL del(&DEL_DDR,&DEL_PORT);
    LCM display(&LCD_DDR, &LCD_PORT);

    initialiserManoeuvre();
    display.clear();
    display.write("Manoeuvre 6");

    del.vertDroit();
    del.vertGauche();
    
    for(uint8_t i = 0; i <= 7; i++)
    {
        ajustementPWM(90 - (i*7), 90 - (i*7));
        convertisseurVersSeptSeg(90 - (i*7), 90 - (i*7));
        _delay_ms(500);
    }
    
    _delay_ms(DEUX_SECONDES);
    clearPort();
    display.clear();
}

/**
 * Procedure qui permet au robot de detecter qu'aucune combiaison est
 * trouvee
 */
void manoeuvreIndeterminer()
{
    LCM display(&LCD_DDR, &LCD_PORT);
    display.clear();
    display.write("Combinaison ");
    display.write("non evaluee",16);
    
    _delay_ms(DEUX_SECONDES);
    display.clear();
    clearPort();
}
