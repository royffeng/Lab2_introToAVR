/*	Author: rfeng016
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
    DDRC = 0x00; PORTC = 0xFF; // Configure port C's 8 pins as inputs
    DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs, initialize to 0s

    unsigned char tmpA; // Temporary variable to hold the value of A
    unsigned char tmpB; // Temporary variable to hold the value of B
    unsigned char tmpC; // Temporary variable to hold the value of C

    unsigned char tmpD = 0x00; // Temporary variable to hold the value of D
    unsigned char weight = 0x00;

    while(1) {
        tmpA = PINA;
	tmpB = PINB;
	tmpC = PINC;
        tmpD = 0x00;

        weight = tmpA + tmpB + tmpC;

        if (weight > 140) {
            tmpD = tmpD | 0x01;
        }

        if (tmpA > tmpC) {
            if (tmpA - tmpC > 80) {
                tmpD = tmpD | 0x02;
            }
        } else {
            if (tmpC - tmpA > 80) {
                tmpD = tmpD | 0x02;
            }
        }

        weight = weight >> 2;

        PORTD = tmpD | weight;
    }
    return 0;
}
