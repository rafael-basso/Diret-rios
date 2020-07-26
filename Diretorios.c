/*INTEGRANTES:
    Rafael Donizete Basso
    Rafael Victor Menegon
    Mateus Bratek
    Octavio Miguel dos Santos*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
char comando[80]="\0";
char *recebe_comando,*parametro;
int val=0;

char nome[1000][8]={'/'};
int pai[1000]={0};
int i,j,posicao=0,cod_dir=0;

char login[10];
char senha[10];

printf("login: ");
gets(login);
printf("senha: ");
gets(senha);
while(strcmp(login,"root")!=0 || strcmp(senha,"toor")!=0){
printf("usuario inexistente\n");
printf("login: ");
fflush(stdin);
gets(login);
printf("senha: ");
fflush(stdin);
gets(senha);
}

while(val==0){
ponto:
printf("root@slax:# ");
fflush(stdin);
gets(comando);
if(strcmp(comando,"\0")==0||strncmp(comando,"          ",strlen(comando))==0)
  printf("error\n");
else{
recebe_comando=strtok(comando," ");
parametro=strtok(NULL,"\0");

if(strcmp(recebe_comando,"mkdir")==0 && parametro!=NULL){
    for(i=1;i<1000;i++){
        if(strcmp(nome[i],parametro)==0&&pai[i]==posicao){
            printf("diretorio existente\n");
            goto ponto;
        }
      }
      cod_dir++;
      strcpy(nome[cod_dir],parametro);
      pai[cod_dir]=posicao;
    }

else if(strcmp(recebe_comando,"rmdir")==0 && parametro!=NULL){
   for(i=1;i<=cod_dir;i++){
    if(pai[i]==posicao && strcmp(parametro,nome[i])==0){
        for(j=1;j<=cod_dir;j++){
         if(pai[j]==i){
            printf("diretorio nao vazio\n");
            goto ponto;
         }
        }
        strcpy(nome[i],"\0");
        pai[i]=999;
        goto ponto;
      }
   }
   printf("diretorio inexistente\n");
}

else if(strcmp(recebe_comando,"cd")==0 && parametro!=NULL){
    if(strcmp(parametro,"..")==0){
        if(posicao==0){
            printf("diretorio raiz\n");
            goto ponto;
        }
        else{
        posicao=pai[posicao];
        goto ponto;
        }
    }
    if(strcmp(parametro,".")==0){
      goto ponto;
    }
    if(strcmp(parametro,"/")==0){
      posicao=0;
      goto ponto;
    }
    for(i=1;i<1000;i++){
       if(strcmp(parametro,nome[i])==0&&pai[i]==posicao){
         posicao=i;
         goto ponto;
       }
     }
     printf("diretorio invalido\n");
   }

else if(strcmp(recebe_comando,"pwd")==0 && parametro==NULL){
     printf("%s\n",nome[posicao]);
}

else if(strcmp(recebe_comando,"ls")==0 && parametro==NULL){
   for(i=1;i<=cod_dir;i++){
      if(pai[i]==posicao)
        printf("%s  ",nome[i]);
     }
     putchar('\n');
}

else if(strcmp(recebe_comando,"clear")==0 && parametro==NULL){
   system("clear");
}

else if(strcmp(recebe_comando,"copyright")==0 && parametro==NULL){
   printf("Desenvolvido por:\n");
   printf("******************\n");
   printf("Rafael Donizete Basso\nRafael Victor Menegon\nMateus Bratek\nOctavio Miguel dos Santos\n");
   printf("******************\n");
}

else if(strcmp(recebe_comando,"poweroff")==0 && parametro==NULL){
   system("clear");
   printf("Saindo..\n");
   val=1;
  }
else
   printf("error\n");
     }
   }

return 0;
}
