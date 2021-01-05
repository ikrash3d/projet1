//Noms :        Abderraouf Benchoubane, Samy Cheklat, William Ringuet, Philippe Bonhomme

//Matricules :  1946665,1937812 , 2015739, 2012859

//Description : Procedures qui effectuent les manoeuvres du robot

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>  

#include "del.h"
#include "PWM.h"
#include "lcm_so1602dtr_m_fw.h"
#include "customprocs.h"
#include "SeptSegment.h"

/*Definition des pins en entree pour les sonars *************************************************/
#define DEL_DDR  DDRD          // port de l'AVR occupe par le PWM et le bouton poussoir
#define DEL_PORT PORTD         // Pin de l'AVR occupé par le PWM et le bouton poussoir
#define LCD_DDR  DDRB          // Data Direction Register (DDR) de l'AVR occupé par l'ecran LCD.
#define LCD_PORT PORTB         // Pin de l'AVR occupé par l'ecran LCD
#define PWM_DEL_ENABLE 0xF7
#define MODE_ENTREE_PORT 0x00

#define UNE_SECONDE 1000
#define DEUX_SECONDES 2000
#define DELAI_INCREMENTATION 100
/***********************************************************************************************/

void initialiserManoeuvre();
void clearPort();

void manoeuvre1();
void manoeuvre2();
void manoeuvre3();
void manoeuvre4();
void manoeuvre5();
void manoeuvre6();
void manoeuvreIndeterminer();
 