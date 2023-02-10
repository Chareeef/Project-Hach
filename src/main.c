#include <stdlib.h>
#include <stdio.h>
#include "Hach.h"

int main () {
	HachTable* casting = initHach();
	add(casting, "Antoine", 18, male);
	add(casting, "Akio", 18, male);
	add(casting, "Thomas", 18, male); 
	add(casting, "Sarah", 38, femelle);
	add(casting, "Renaud", 11, male);
	add(casting, "Laurent", 44, male);
	add(casting, "Larenut", 30, male); 
	add(casting, "Coralie", 2, femelle); 
	add(casting, "Enami", 17, femelle); 
	add(casting, "Dorian", 18, male); 
	add(casting, "Aude", 9, femelle); 
	add(casting, "thor", 29, male);
	add(casting, "torh", 10, male); 
	add(casting, "roht", 49, femelle); 
	add(casting, "rhto", 98, male);
	
	efface(casting, "Larenut"); 
	efface(casting, "rhto");
	efface(casting, "thor");
	efface(casting, "roht");
	printf("age :  %d\n", searchAge(casting, "roht")); 
	printf("\t\tCasting :\n");
	display(casting);


	return 0;
}