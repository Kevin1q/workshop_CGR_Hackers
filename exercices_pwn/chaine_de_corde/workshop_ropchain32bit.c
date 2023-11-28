#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 300 

char *banner_file = NULL;

int vuln(){
    char commande[32];

    printf("Tappez une commande shell : ");

    fgets(commande, BUFFER_SIZE-1, stdin);
    commande[strcspn(commande, "\n")] = '\0';

    if (strcmp(commande, "ls") == 0) {
        printf("resultat de la commande :\n");
        system("ls");
    }

    else {
        printf("Vous n'avez pas les permissions d'executer cette commande !");
    }

    return 0;
}

void banner() {

    FILE *fptr;
    int c;

    if (banner_file == NULL) {
        banner_file = (char *)malloc(32);
        strcpy(banner_file, "logo.txt");
    }

    fptr = fopen(banner_file, "r");
    if (!fptr) {
        printf("Problem opening banner file (%s)\n", banner_file);
        return;
    }

    while ((c = fgetc(fptr)) != EOF) {
        printf("%c", c);
    };
    printf("\n");
  
    fclose(fptr);

}


void saisie_nom(char* nom){
    printf("Votre nom : ");
    fgets(nom, BUFFER_SIZE-1, stdin);
}

int main() {
    char buff[BUFFER_SIZE];

    banner();

    printf("\t--- Connexion to TMSH - The Most Secure Shell (v3.1.1) ---\n");

    saisie_nom(buff);
    
    printf("Bonjour ");
    printf(buff);

    vuln();

    return 0;
}