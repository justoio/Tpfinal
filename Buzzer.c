/*
 * Buzzer.c
 *
 *  Created on: 9 de nov. de 2019
 *      Author: Icomp2015
 */
#include "LPC17xx.h"
#include "lpc17xx_dac.h"
#include "lpc17xx_pinsel.h"
void confDAC(){
	DAC_Init(LPC_DAC);
return;}
void confPinDAC(){
	PINSEL_CFG_Type PinCfg;
	PinCfg.Portnum=PINSEL_PORT_0;    /**< Port Number, should be PINSEL_PORT_x,
	                        where x should be in range from 0 to 4 */
	PinCfg.Pinnum=PINSEL_PIN_26;        /**< Pin Number, should be PINSEL_PIN_x,
	                        where x should be in range from 0 to 31 */
	PinCfg.Funcnum= PINSEL_FUNC_2;    /**< Function Number, should be PINSEL_FUNC_x,
	                        where x should be in range from 0 to 3 */
	PinCfg.Pinmode=PINSEL_PINMODE_TRISTATE;    /**< Pin Mode, should be:
	                        - PINSEL_PINMODE_PULLUP: Internal pull-up resistor
	                        - PINSEL_PINMODE_TRISTATE: Tri-state
	                        - PINSEL_PINMODE_PULLDOWN: Internal pull-down resistor */
	PinCfg.OpenDrain=PINSEL_PINMODE_NORMAL;    /**< OpenDrain mode, should be:
	                        - PINSEL_PINMODE_NORMAL: Pin is in the normal (not open drain) mode
	                        - PINSEL_PINMODE_OPENDRAIN: Pin is in the open drain mode */
	PINSEL_ConfigPin(&PinCfg);
return;}
/*
 * Delay: 400000 equiv 11Hz
 */
void delayBuzzer(){
	for(uint32_t i=0;i<4000000000;i++){}
return;}
/*
 * Funcion Cuadrada
 */
void soundCorrect(){
	for(uint32_t i=0;i<1000;i++){
		//if(i%2)DAC_UpdateValue(LPC_DAC,1023);
		//else DAC_UpdateValue(LPC_DAC,0);
		DAC_UpdateValue(LPC_DAC,0);
		delayBuzzer();
		DAC_UpdateValue(LPC_DAC,1000);
		delayBuzzer();
		DAC_UpdateValue(LPC_DAC,0);

	}
return;}
void soundIncorrect(){
	for(uint32_t i=0;i<1000;i++){
		if(i%2)DAC_UpdateValue(LPC_DAC,1023);
		else DAC_UpdateValue(LPC_DAC,0);
		delayBuzzer();
		}
return;}
