#include <stdio.h>
#include<stdlib.h>

typedef struct{
	int code;
	char nom[20];
	int quantite;
	float prix;
	float ttc;
}produit;

typedef struct{
    int jour,mois,annee;
    float prix;
}date;

produit p[100];
date d[100];
int n,li=0,v=0;

void ajouter(){
	int i,m,j=0;
	printf("Combien de produit vous voulez ajouter : ");	scanf("%d",&n);
	for(i=li;i<li+n;i++){
		printf("Les infos du produit n%d\n",i+1);
		printf("Enter le code : ");			scanf("%d",&p[i].code);
	
		printf("Enter le nom : ");			scanf("%s",p[i].nom);
		printf("Enter le prix : ");			scanf("%f",&p[i].prix);
		printf("Enter la quantite : ");		scanf("%d",&p[i].quantite);
		p[i].ttc=p[i].prix+(p[i].prix*15/100);
		printf("\n");
	}
	li+=n;
	printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&m);
    system("cls");
    if (m==1)
        menu();
    else
        close();
}
void lister(){
	produit tmp;
	int i,j,m;
	printf("\t\t CODE \t NOM \t\t QUANTITE \t PRIX  \t PRIX TTC");
	for(i=0;i<li;i++){
		printf("\nProduit n%d",i+1);
		printf("\t %5d \t %-10s \t   %5d \t %.2f \t %.2f",p[i].code,p[i].nom,p[i].quantite,p[i].prix,p[i].ttc);
	}
	printf("\n\n\n2)Trier par prix\n3)Trier par nom\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&m);
    system("cls");
    if (m==1)
        menu();
    else if(m==2){
    	for(i=0;i<li-1;i++){
 			for(j=0;j<li-1-i;j++){
	 			if(p[j].prix<p[j+1].prix){
	 				tmp=p[j];
	 				p[j]=p[j+1];
	 				p[j+1]=tmp;
				}
			}
		}
		system("cls");
    	printf("\t\t CODE \t NOM \t\t QUANTITE \t PRIX  \t PRIX TTC");
		for(i=0;i<li;i++){
			printf("\nProduit n%d",i+1);
			printf("\t %5d \t %-10s \t   %5d \t %.2f \t %.2f",p[i].code,p[i].nom,p[i].quantite,p[i].prix,p[i].ttc);
		}
		printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
    	scanf("%d",&m);
    	system("cls");
    	if (m==1)
        	menu();
    	else
    	    close();
    	
	}else if(m==3){
	for (i = 0; i < li; i++) 
    	for (j = 0; j < li; j++)
      		if (strcmp(p[i].nom, p[j].nom) < 0){
		        tmp = p[i];
		        p[i] = p[j];
		        p[j] = tmp;
        	}
		system("cls");
    	printf("\t\t CODE \t NOM \t\t QUANTITE \t PRIX  \t PRIX TTC");
		for(i=0;i<li;i++){
			printf("\nProduit n%d",i+1);
			printf("\t %5d \t %-10s \t   %5d \t %.2f \t %.2f",p[i].code,p[i].nom,p[i].quantite,p[i].prix,p[i].ttc);
		}
		printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
    	scanf("%d",&m);
    	system("cls");
    	if (m==1)
        	menu();
    	else
    	    close();
		
	}else
        close();
	
}
void acheter(){
	int i,m,code,qte,e=0;
	printf("Entrer le code du produit : ");	scanf("%d",&code);
	for(i=0;i<li;i++){
		if(p[i].code==code){
			printf("\nEntrer la date d\'aujourdhui : (jj/mm/aaaa) \n");
			scanf("%d/%d/%d",&d[i+v].jour,&d[i+v].mois,&d[i+v].annee);
			
			printf("\nEntrer la quantite : ");	scanf("%d",&qte);
			if(p[i].quantite<qte || qte<0)	{
				printf("la quantite est invalide ");break;
			}
			else{
				d[i+v].prix=(qte * p[i].ttc);
				p[i].quantite-=qte;
				printf("\n\n\tVotre operation a bien ete effectue ");
				v++;
			}
		e++;
		}
	}if(e==0)
		printf("\nLe produit n\'existe pas !");
	printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
    	scanf("%d",&m);
    	system("cls");
    	if (m==1)
        	menu();
    	else
    	    close();
	
}
void rechercher(){
	int i,c,r,m,existe=0;
	char nr[15];
	system("cls");
	printf("\n\tRechercher par :\n1)Code \n2)Nom \n3)Etat de stock\n");
	printf("\nEntrer votre choix : ");	scanf("%d",&c);
	switch(c){
		case 1:{
			printf("\nEntrez le code de l\'element a rechercher: ");
			scanf("%d", &r);
			for (i=0;i<li;i++){
				if(p[i].code == r){
					printf("\t\t CODE \t NOM \t\t QUANTITE \t PRIX  \t PRIX TTC");
					printf("\nProduit n%d",i+1);
					printf("\t %5d \t %-10s \t   %5d \t %.2f \t %.2f",p[i].code,p[i].nom,p[i].quantite,p[i].prix,p[i].ttc);	
					existe++;
				}
			}
			if(existe == 0)
				printf("\nLe produit est introuvable !!");
			break;
		}
		case 2:{
			printf("\nEntrez le nom de produit a rechercher: ");
			scanf("%s", &nr);
			system("cls");
			printf("\t\t CODE \t NOM \t\t QUANTITE \t PRIX  \t PRIX TTC");
			for (i=0;i<li;i++){
				if(strcmp(nr, p[i].nom) == 0){
					printf("\nProduit n%d",i+1);
					printf("\t %5d \t %-10s \t   %5d \t %.2f \t %.2f",p[i].code,p[i].nom,p[i].quantite,p[i].prix,p[i].ttc);	
					existe++;
				}
			}
			if(existe == 0)
				printf("\nLe produit est introuvable !!");
			break;
		}
		case 3:{
			for (i=0;i<li;i++){
				
				if(p[i].quantite < 3){
					printf("\t\t CODE \t NOM \t\t QUANTITE \t PRIX  \t PRIX TTC");
					printf("\nProduit n%d",i+1);
					printf("\t %5d \t %-10s \t   %5d \t %.2f \t %.2f",p[i].code,p[i].nom,p[i].quantite,p[i].prix,p[i].ttc);
					existe++;
				}
			}
			if(existe == 0)
				printf("\nLe produit est introuvable !!");
			break;
		}
	}
	printf("\n\nEntrer 2 pour rechercher a nouveau \nEntrer 1 pour retourner au menu et 0 pour fermer:\n");
    scanf("%d",&m);
    system("cls");
    if (m==1)
        menu();
    else if(m==2)
    	rechercher();
    else
        close();
}

void alimenter(){
	int i,m,code,qte,e=0;
	printf("Entrer le code du produit : ");	scanf("%d",&code);
	for(i=0;i<li;i++){
		if(p[i].code==code){
			printf("\nEntrer la quantite a ajouter: ");	scanf("%d",&qte);
			if(qte<0)	{
				printf("la quantite est invalide ");break;
			}
			else{
				p[i].quantite+=qte;
				printf("\n\nVotre operation a bien ete effectue .");
				printf("\nApres la mise a jour de la quantite : %d\t%s\t%d",p[i].code,p[i].nom,p[i].quantite);
			}
		e++;
		}
	}if(e==0)
		printf("\nLe produit n\'existe pas !");
	printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
    	scanf("%d",&m);
    	system("cls");
    	if (m==1)
        	menu();
    	else
    	    close();
	
}
void stat_j_courant(){
	int i,m,jj,mm,aa;
	float s=0,max=0,min=d[0].prix;
	printf("Entrer la date (jj/mm/aaaa): ");	scanf("%d/%d/%d",&jj,&mm,&aa);
	printf("v= %d\n",v);
	printf("\nles ventes : \n");
	for(i=0;i<v;i++){
		printf("%d/%d/%d :\t%.2f\n",d[i].jour,d[i].mois,d[i].annee,d[i].prix);
		if(jj==d[i].jour && mm==d[i].mois && aa==d[i].annee){
			if(d[i].prix >max)
				max=d[i].prix;
			if(d[i].prix <min)
				min=d[i].prix;
			s+=d[i].prix;
			
		}
		
	}
	printf("\nLe total des prix des produits vendus :  %.2f DH",s);
	printf("\nLa moyenne des prix des produits vendus :  %.2f DH",(s/(float)v));
	printf("\nLe Max des prix des produits vendus :  %.2f DH",max);
	printf("\nLe Min des prix des produits vendus :  %.2f DH",min);
	printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
    	scanf("%d",&m);
    	system("cls");
    	if (m==1)
        	menu();
    	else
    	    close();
}
void supprimer(){
	int i,j,m,code,e=0;
	printf("Entrer le code du produit : ");	scanf("%d",&code);
	for(i=0;i<li;i++){
		if(p[i].code==code){
			for (j=i; j < li - 1; j++)
         		p[j] = p[j+1];
			printf("\n\nVotre operation a bien ete effectue .");
			li--;
			e++;
		}
	}if(e==0)
		printf("\nLe produit n\'existe pas !");
	printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
    	scanf("%d",&m);
    	system("cls");
    	if (m==1)
        	menu();
    	else
    	    close();
	
}
void fermer(){
	printf("Fermeture de l\'application ...");
}

void menu(){
	int c;
	system("cls");
	printf("\t---------------------------------------\n");
	printf("\t  SYSTEME DE GESTION DE PHARMACIE\n");
	printf("\t_______________________________________\n");
	printf("\t1)Ajouter un produit\n");
	printf("\t2)Lister les produits\n");
	printf("\t3)Acheter un produit\n");
	printf("\t4)Rechercher un produit\n");
	printf("\t5)Alimenter le stock\n");
	printf("\t6)Statistique de vente\n");
	printf("\t7)Supprimer un produit\n");
	printf("\t8)Fermer\n");
	scanf("%d",&c);
	system("cls");
	switch(c){
		case 1:	ajouter();break;
		case 2:	lister();break;
		case 3:	acheter();break;
		case 4:	rechercher();break;
		case 5:	alimenter();break;
		case 6:	stat_j_courant();break;
		case 7:	supprimer();break;
		case 8:	fermer();break;
	}
}
int main(){
	menu();
}
