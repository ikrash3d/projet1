
#define F_CPU 8000000UL
#include <avr/io.h> 
#include <avr/interrupt.h>
#include <util/delay.h>

/** Define qui active le portC de facon a ajoute le chiffre 
* qu'indique le nom de la variable avec le SeptSegment **
*/
#define DDR_7SEGMENTS_POWER   DDRA
#define PORT_7SEGMENTS_POWER  PORTA

#define SEGMENT1_POWER        PA3
#define SEGMENT2_POWER        PA4
#define SEGMENT3_POWER        PA5
#define SEGMENT4_POWER        PA6
#define SEGMENT5_POWER        PA7

#define DDR_7SEGMENTS_DATA    DDRC
#define PORT_7SEGMENTS_DATA   PORTC

#define PORT7SEG_OUVERT 0xFF
#define ALLUMER_7SEG 0xF8

#define ZERO 0XFC
#define UN 0X60
#define DEUX 0XDA
#define TROIS 0XF2
#define QUATRE 0X66
#define CINQ 0XB6
#define SIX 0XBE
#define SEPT 0XE0 
#define HUIT 0XFE
#define NEUF 0XF6
#define SEPARATION 0x02

#define COMPTEUR_RESET 0
#define COMPTEUR_INIT 0
#define COMPTEUR_MAX 5
/**********************************************************/

uint8_t transitionPourcentage(const uint8_t seg); 
void initMinuterieDeux();
void arretMinuterieDeux();
void initSeptSegment();
void convertisseurVersSeptSeg(const uint8_t pourcentageGauche, const uint8_t pourcentageDroit);