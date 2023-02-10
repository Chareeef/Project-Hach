#ifndef HACH_H
#define HACH_H
#define MAX 100

typedef struct HachTable HachTable;
typedef struct Personnage Personnage;
typedef enum XY XY;

enum XY {male = 1, femelle = 2};

struct Personnage {
	char* name;
	int age;
	XY gender;
	Personnage* suivant;
};


struct HachTable {
	Personnage *personnages[MAX];
};


HachTable* initHach ();
int hach (char* name);
void add (HachTable* table, char* name, int age, XY gender);
int searchAge (HachTable* table, char* name);
Personnage* create(char *name, int age, XY gender);
void display(HachTable* table);
int item(HachTable* table, char* name);
void efface (HachTable* table, char* name);

#endif