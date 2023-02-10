#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Hach.h"

HachTable *initHach() {
	HachTable *table = malloc(sizeof(HachTable));

	if (table == NULL)
	exit(EXIT_FAILURE);

	for (int i = 0; i < MAX; i++) {
		table->personnages[i] = NULL;
	}

	return table;
}

int hach(char *name) {
	int i = 0,
	numHache = 0;

	for (i = 0; name[i] != '\0'; i++) {
		numHache += name[i];
	}

	numHache %= MAX;

	return numHache;
}

void add(HachTable *table, char *name, int age, XY gender) {
	int index = hach(name);
	Personnage *character = table->personnages[index];

	// Vérifier si une entrée existe déjà à l'indx
	if (character == NULL) {
		// Allouer de la mémoire pour un nouveau personnage
		character = malloc(sizeof(Personnage));
		if (character == NULL) exit(EXIT_FAILURE);
		// Initialiser les champs de l'entrée
		character->name = strdup(name);
		character->age = age;
		character->gender = gender;
		character->suivant = NULL;
		table->personnages[index] = character;
		return;
	}
	// Vérifier si l'entrée existe déjà dans la liste chainée
	while (character->suivant != NULL) {
		if (strcmp(name, character->name) == 0) {
			character->age = age;
			character->gender = gender;
			return;
		}
		character = character->suivant;
	} // Ajouter une nouvelle entrée si elle n'existe pas déjà
	if (strcmp(name, character->name) == 0) {
		character->age = age;
		character->gender = gender;
	}
	else
	{
		Personnage *new_character = malloc(sizeof(Personnage));
		if (new_character == NULL) {
			printf("Error: Unable to allocate memory for new character\n");
			return;
		}
		new_character->name = strdup(name);
		new_character->age = age;
		new_character->gender = gender;
		new_character->suivant = NULL;
		character->suivant = new_character;

	}
}

int item(HachTable *table, char *name) {
	int index = hach(name);
	Personnage *character = table->personnages[index];

	while (character != NULL && strcmp(name, character->name)) {
		character = character->suivant;
	}

	if (character == NULL) {
		printf("Personnage non trouvé\n");
		return 1;
	}

	printf("Prénom : %s / Age : %d / Genre : ", character->name, character->age);
	switch (character->gender) {
		case male:
		printf("Mâle\n");
		break;
		case femelle:
		printf("Femelle\n");
		break;
		default:
		printf("Error\n");
	}
	return 0;
}

int searchAge(HachTable *table, char *name) {
	int index = hach(name);
	Personnage *character = table->personnages[index];



	if (table->personnages[index] != NULL) {
		if (strcmp(name, character->name) == 0) {
			return character->age;
		}

		while (character->suivant != NULL) {
			character = character->suivant;

			if (strcmp(name, character->name) == 0) {
				return character->age;
			}
		}
	}

	return -1;
}


void display (HachTable* table) {
	for (int i = 0; i < MAX; i++) {
		if (table->personnages[i] != NULL) {
			Personnage *character = table->personnages[i];
			while (character != NULL) {
				printf("\tPrénom : %s \n Age : %d \n Genre : ", character->name, character->age);
				switch (character->gender) {
					case male:
					printf("Mâle\n\n");
					break;
					case femelle:
					printf("Femelle\n\n");
					break;
					default:
					printf("Error\n\n");
				}
				character = character->suivant;
			}
		}
	}
}

void efface (HachTable* table, char* name) {
	int index = hach(name);
	Personnage* erased = table->personnages[index];
	Personnage* precedent = NULL;
	
	if (erased == NULL) {
		printf("Nom Introuvable.\n"); 
		return;
	}
	
	while (erased != NULL && erased->name != NULL && strcmp(name, erased->name) != 0) {
		precedent = erased;
		erased = erased->suivant;
	}
	if (erased != NULL) {
		if (precedent != NULL ){
			precedent->suivant = erased->suivant;
		} else {
			table->personnages[index] = erased->suivant;
		}
	}
	free(erased->name);
	free(erased);
}