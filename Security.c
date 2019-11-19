/*
 * Security.c

 *
 *  Created on: 18 de nov. de 2019
 *      Author: Icomp2015
 */
#include "LPC17xx.h"
#define SIZE2 (uint8_t)((4))

uint8_t password1[SIZE2]={1,2,3,4};
uint8_t tryPassword[SIZE2];
uint8_t keyCouter=0;

void saveKey(uint8_t key){
	tryPassword[keyCouter]=key;
return;}
uint8_t testTryPass1(){
	for(uint8_t i=0;i<SIZE2;i++){
		if(password1[i]!=tryPassword[i])return 0;
	}
return 1;}
void keyCounter(){
	keyCouter++;
return;}

