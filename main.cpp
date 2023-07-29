/* 
1 - LOGIN E CADASTRO    .(Check)
2 - Login               .(Check)
3 - Checar saldo        .(Check)
4 - Fazer transferencia .(Check)
5 - Gerente             .(Check)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TF 50

int main(){
    int contaNumeros[TF], contaSenhas[TF]; /* Vetores de numero da conta, senha e saldo */
    int esc, contaNum, contaPass; /* Variavel temporarias */
    float vlrTransf, contaSaldo[50];
    int pos, posAux, TL=0, i; /* Variaveis Auxiliares */

    char adm[20], admPass[20],op;

    printf("BEM VINDO AO ONLINE BANKING!\n");
    do{
        printf("Menu:\n1- Login\n2- Cadastro\n3- Gerente\n0- Sair\n-> ");
        fflush(stdin);
        scanf("%d",&esc);

        switch (esc){
            case 1: /* Login na conta */
                printf("Conta: ");
                scanf("%d",&contaNum);
                printf("Senha: ");
                scanf("%d",&contaPass);

                pos=0;
                while(pos<TL && contaNum!=contaNumeros[pos])
                    pos++;
                
                if(contaNum==contaNumeros[pos] && pos<TL){/* Verifica se conta existe */
                    if(contaPass==contaSenhas[pos]){ /* Verifica se a senha esta correta, se sim entra na conta */
                        system("cls");
                        printf("Bem vindo a sua conta!\n");
                        printf("C/C: %d\n", contaNumeros[pos]);
                        printf("Saldo: R$ %.2f\n", contaSaldo[pos]);

                        printf("Opcoes: \n1- Transferir dinheiro\n2- Depositar\n9- Sair\n-> ");
                        scanf("%d",&esc);
                        if(esc==1){
                            printf("Digite o valor a ser transferido: ");
                            scanf("%f", &vlrTransf);
                            printf("Digite a conta destino: ");
                            scanf("%d",&contaNum);

                            if(contaSaldo[pos]==vlrTransf || contaSaldo[pos]>vlrTransf){ /* Verifica se tem saldo */
                                posAux=0;
                                while(posAux<TL && contaNum!=contaNumeros[posAux])
                                    posAux++;

                                if(contaNum==contaNumeros[posAux] && posAux<TL){ /* Achou a conta */
                                    contaSaldo[pos]-=vlrTransf;
                                    contaSaldo[posAux]+=vlrTransf;
                                    system("pause");
                                    system("cls");
                                    printf("Transacao efetuada com sucesso!\n");
                                    printf("Seu saldo agora eh de: R$ %.2f\n", contaSaldo[pos]);
                                }
                                else{ /* Nao achou a conta */
                                    printf("Conta nao encontrada!\n");
                                }
                            }
                            else{ /* Saldo insuficiente */
                                printf("Saldo insuficiente!\n");
                            }
                        }
                        if(esc==2){
                            printf("Digite o valor a ser depositado: ");
                            scanf("%f",&vlrTransf);
                            contaSaldo[pos]+=vlrTransf;
                        }
                    }
                    else{ /* Se senha incorreta */
                        printf("Senha incorreta!\n");
                    }
                }
                else{/* Se conta nao existir*/
                    printf("Conta nao encontrada!\n");
                }

                break;

            case 2: /* Cadastro de conta */
                if(TL<TF){ /* Se houver espaco para a nova conta */
                    printf("Escolha um senha: ");
                    scanf("%d",&contaPass);
                    contaNumeros[TL] = 1000+TL;
                    printf("O numero de sua nova conta: %d\n", contaNumeros[TL]);
                    contaSenhas[TL] = contaPass;
                    contaSaldo[TL] = 0;
                    TL++;
                    system("pause");
                    system("cls");
                    printf("Conta cadastrada!\n");
                }
                else{
                    printf("Nao ha vagas em nosso banco para sua conta!\n");
                }
                break; 

            case 3:
                printf("Usuario: ");
                fflush(stdin);
                gets(adm);
                printf("Senha: ");
                fflush(stdin);
                gets(admPass);
                if(strcmp(adm,"admin")==0 && strcmp(admPass,"adminadmin")==0){
                    do{
                        system("cls");
                        printf("Menu:\n1- Ver todas as contas e senhas\n2- Ver todos os saldos\n3- Zerar todas as contas\n9- Sair\n->");
                        scanf("%d",&esc);
                        switch (esc)
                        {
                        case 1:
                            for(i=0; i<TL; i++){
                                printf("Contas[%d]: %d\n",i,contaNumeros[i]);
                                printf("Senha[%d]: %d\n",i,contaSenhas[i]);
                            }
                            break;
                        
                        case 2:
                            for(i=0; i<TL; i++){
                                printf("Saldo[%d]: %.2f\n",i,contaSaldo[i]);
                            }
                            break;

                        case 3:
                            printf(" !!! ESSA ACAO E IRREVERSIVEL, TEM CERTEZA QUE QUER CONTINUAR? (Y/N)\n");
                            fflush(stdin);
                            scanf("%c", op);
                            if(op=='y'||op=='Y')
                            {
                                for(i=0;i<TL;i++){
                                    contaSaldo[i]= 0;
                                }
                            }
                            break;

                        default: printf("Nenhuma opcao foi escolhida!\n");
                        break;    
                        }
                        system("pause");
                    }while(esc!=9);
                }



            default: printf("Nenhuma opcao foi escolhida!\n");
                break;
        }
    system("pause");
    system("cls");

    }while(esc!=0);




}