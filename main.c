#include <stdio.h>
#include <stdlib.h>

typedef struct ddn{
    int j;
    int m;
    int a;
}ddn;

typedef struct cid{
    int Numerocarte;
    char Nom[20];
    char Prenom[20];
    char Sexe[1];
    char Ville[20];
}cid;

void ENREGISTRERTxT(FILE* pFile);
void LIREBin(FILE *pFile);
void ENREGISTRERBin(FILE *pFile);
void LIRETxT(FILE *pFile);
int main(){
    FILE* pFile;
    int choix=0;
    do{
        system("cls");
        printf("TAPEZ 1 POUR SAISIR UNE IDENTITEE (BINAIRE)\nTAPEZ 2 POUR AFFICHER LES IDENTITEES(BINAIRE)\nTAPEZ 3 POUR SAISIR UNE IDENTITEE (TEXTE) \nTAPEZ 4 POUR AFFICHER LES IDENTITEES (TEXTE)\nTAPEZ 5 POUR QUITTER\n");
        scanf("%i",&choix);
        if (choix==1){
            pFile = NULL;
            ENREGISTRERBin(pFile);
        }
        if (choix==2){
            LIREBin(pFile);
            system("pause");
        }
        if (choix==3){
            ENREGISTRERTxT(pFile);
        }
        if (choix==4){
            LIRETxT(pFile);
            system("pause");
        }
    }
    while (choix != 5);
    return 0;
}

void ENREGISTRERBin(FILE *pFile){
    ddn age;
    cid carte;
    pFile = fopen("MonFichierBin.bin", "wba");
    if (pFile == NULL){
        printf("IMPOSSIBLE D OUVRIR LE FICHIER BIN");
    }
    else{
        printf("SAISIR VOTRE NUMERO DE CARTE \n");
        scanf("%i",&carte.Numerocarte);
        printf("SAISIR VOTRE NOM \n");
        scanf("%s",carte.Nom);
        printf("SAISIR VOTRE PRENOM \n");
        scanf("%s",carte.Prenom);
        printf("SAISIR VOTRE VILLE \n");
        scanf("%s",carte.Ville);
        printf("SAISIR VOTRE SEX H OU F  \n");
        scanf("%s",carte.Sexe);
        printf("SAISIR VOTRE JOUR DE NAISSANCE \n");
        scanf("%i",&age.j);
        printf("SAISIR VOTRE MOIS DE NAISSANCE \n");
        scanf("%i",&age.m);
        printf("SAISIR VOTRE ANNEE DE NAISSANCE \n");
        scanf("%i",&age.a);
        fwrite(&carte, sizeof(carte), 1, pFile);
        fwrite(&age, sizeof(age), 1, pFile);
    }
    fclose(pFile);
}



void LIREBin(FILE *pFile){
    ddn age;
    cid carte;
    pFile = fopen("MonFichierBin.bin", "rb");
    if (pFile == NULL){
        printf("IMPOSSIBLE D OUVRIR LE FICHIER BIN");
    }
    else{
        fread(&carte, sizeof(carte), 1,pFile);
        fread(&age, sizeof(age), 1,pFile);
        printf("DATE DE NAISSANCE : %i / %i / %i \n",age.j,age.m,age.a);
        printf("NOM : %s\nPRENOM :%s \nSEXE: %s \nVILLE : %s \n NUMERO DE CARTE : %i \n",carte.Nom,carte.Prenom,carte.Sexe,carte.Ville,carte.Numerocarte);
    }
    fclose(pFile);
}

void ENREGISTRERTxT(FILE* pFile){
    ddn age;
    cid carte;
    pFile = fopen ("MonFichier.txt" , "a");
    if (pFile != NULL)
    {
        printf("SAISIR VOTRE NUMERO DE CARTE \n");
        scanf("%i",&carte.Numerocarte);
        printf("SAISIR VOTRE NOM \n");
        scanf("%s",carte.Nom);
        printf("SAISIR VOTRE PRENOM \n");
        scanf("%s",carte.Prenom);
        printf("SAISIR VOTRE VILLE \n");
        scanf("%s",carte.Ville);
        printf("SAISIR VOTRE JOUR DE NAISSANCE \n");
        scanf("%i",&age.j);
        printf("SAISIR VOTRE MOIS DE NAISSANCE \n");
        scanf("%i",&age.m);
        printf("SAISIR VOTRE ANNEE DE NAISSANCE \n");
        scanf("%i",&age.a);
        printf("QUEL EST VOTRE SEXE H OU F \n");
        scanf("%s",carte.Sexe);
        fprintf(pFile,"DATE DE NAISSANCE : %i / %i / %i \n",age.j,age.m,age.a);
        fprintf(pFile,"NOM : %s \n",carte.Nom);
        fprintf(pFile,"PRENOM : %s \n",carte.Prenom);
        fprintf(pFile,"SEXE : %s \n\n",carte.Sexe);
        fprintf(pFile,"VILLE : %s \n",carte.Ville);
        fprintf(pFile,"NUMERO DE CARTE : %i \n",&carte.Numerocarte);
    }
    else{
        printf("IMPOSSIBLE D OUVRIR LE FICHIER TEXTE");
    }
    fclose (pFile);
}

void LIRETxT(FILE* pFile)
{
    char buffer[255];
    if((pFile=fopen("MonFichier.txt","rb"))==NULL){
        fprintf(stderr,"ERREUR OUVERTURE DU FICHIER");
    }
    else{
        while(fgets(buffer,255,pFile)!=NULL){
            printf("%s",buffer);
        }
    }
    fclose(pFile);
    getchar();
}


