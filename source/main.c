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

    unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
    unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
    unsigned char tmpC = 0x00; // Temporary variable to hold the value of C
    unsigned char tmpD = 0x00; // Temporary variable to hold the value of D
    unsigned char weight = 0x00;

    while(1) {
        tmpA = PINA & 0xFF;
	tmpB = PINB & 0xFF;
	tmpC = PINC & 0xFF;
 
        weight = tmpA + tmpB + tmpC;

        if (weight > 0x3f) {
            tmpD = weight >> 2;
        }

        if (weight > 0x8C) {
            tmpD = tmpD | 0x01;
        } else {
            tmpD = tmpD & 0xFE;
        }

        if (tmpA > tmpC) {
            if (tmpC - tmpA > 0x50) {
                tmpD = tmpD | 0x02;
            } else {
                tmpD = tmpD & 0xFD;
            }
        } else {
            if (tmpC - tmpA > 0x50) {
                tmpD = tmpD | 0x02;
            } else {
                tmpD = tmpD | 0xFD;
            }
        }
        PORTD = tmpD;
    }
    return 0;
}
