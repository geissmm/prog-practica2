#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX_PALABRAS 20
#define MAX_CARACT 30


bool separadores(char c);
void saltar_separadores(char &d_c);
void palabras_identificar(char &d_c, char p[]);
bool final_texto(char p[]); //donde acaba el texto con los dos puntos 
void palabras_texto(char &d_c, char p[]);
void leer_palabras_texto(char &d_c, char p[]);
bool marca(char p[]); 
void leer_palabras_identificar(char &d_c, char p[]);
void convertir_minusculas(char p[]);
bool punto_final(char d_c); //donde acaban las palabras SPAM
void quitar_puntos_final(char p[]); //para que no coja las palabras con ..



int main () {
	char palabras_buscar[MAX_PALABRAS][MAX_CARACT +1];
	int num_palabras_buscar = 0;
	char p[MAX_CARACT + 1];
	char d_c = ' ';
	int cont_palabras[MAX_PALABRAS] = {0};
	float ratio = 0;
	
	printf("Escribe máximo %d palabras con largada máxima %d: \n", MAX_PALABRAS, MAX_CARACT);
	
	bool ult_palabra = false;
	while (num_palabras_buscar < MAX_PALABRAS && !ult_palabra) {
		leer_palabras_identificar(d_c, p);
			
		if (!marca(p)) {
			convertir_minusculas(p);
			strcpy(palabras_buscar[num_palabras_buscar], p);
			num_palabras_buscar ++;
		}
	if (punto_final(d_c)) {
		ult_palabra = true;			
	 } else {
	 	ult_palabra = false;
	}
}
		
		
	printf("Escribe un texto acabado en '..': \n");
	
	bool fin = false;
	while (!fin) {
		leer_palabras_texto(d_c, p);
		if (!marca(p)) {
			if (final_texto(p)) {
			quitar_puntos_final(p); //para que no coja las palabras con los puntos ..
			fin = true;
			}
		
		convertir_minusculas(p);
		for (int i=0; i < num_palabras_buscar; i++) {
			if (strcmp(p, palabras_buscar[i]) == 0) {
				cont_palabras[i] ++;
			}
		}
	}
}

	int palabras_repetidas = 0;
	printf("Resultados: \n");
	for (int i=0; i < num_palabras_buscar; i++) {
		printf("La palabra %s aparece %d veces. \n", palabras_buscar[i], cont_palabras[i]);
		if (cont_palabras[i] >= 2) {
			palabras_repetidas ++;
		}
	}
	
	ratio = (float)palabras_repetidas / num_palabras_buscar;
	printf("Ratio: palabras con 2 o más apariciones / total de palabras = %d / %d = %.3f \n", palabras_repetidas, num_palabras_buscar, ratio);

	if (ratio >=0.5) {
		printf("El mensaje es SPAM. \n");
	} else {
		printf("El mensaje no es SPAM. \n");
	}	
}

bool separadores(char c) {
	return (c == ' ' || c == '\n' || c == '\t' || c == ',' || c == ';');
}

void saltar_separadores(char &d_c) {
	while (separadores(d_c) == true) {
        	scanf("%c", &d_c);
	}
}
void palabras_identificar(char &d_c, char p[]) {
	int i=0;
	while (!separadores(d_c) && !punto_final(d_c) && i < MAX_CARACT) { 
		p[i] = d_c;
		i++;
		scanf("%c", &d_c);
	}
	p[i]= '\0';
}

bool final_texto(char p[]) {
	int longitud = strlen(p);
	char siguiente;
	if (longitud >=2) {
		if (p[longitud -1] == '.' && p[longitud -2] == '.') { //cuando en la longitud -1 y -2 de p hay .. es el final del texto 
			return true;
			
		} else {
			return false;
		}
	}
	return false;
}

void palabras_texto(char &d_c, char p[]) {
	int i=0;
	while (!separadores(d_c) && i < MAX_CARACT && !final_texto(p)) {
		p[i] = d_c;
		i++;
		scanf("%c", &d_c);
	}
	p[i] = '\0';
}

void leer_palabras_identificar(char &d_c, char p[]) {
	saltar_separadores(d_c);
	palabras_identificar(d_c, p);
}

void leer_palabras_texto(char &d_c, char p[]) {
	saltar_separadores(d_c);
	palabras_texto(d_c, p);
}

bool marca(char p[]) {
	return(p[0] == '\0');
 	
}

void convertir_minusculas(char p[]) {
	for (int i=0; p[i] != '\0'; i++) {
		if (isalpha(p[i])) {
			p[i] = tolower(p[i]);
		}	
	}
}

bool punto_final(char d_c) { 
	return (d_c == '.');
}

void quitar_puntos_final(char p[]) { //para que no coja las palabras con los puntos, por ejemplo hola y hola.. con esto coge hola en los dos
	int nueva_longitud = 0;
	if (final_texto(p)) {
		nueva_longitud = strlen(p) - 2;
		p[nueva_longitud] = '\0';
	}
}
 




			
	
	
	
	
	
