#include<stdio.h>
typedef enum {FALSE, TRUE} boolean;
typedef enum {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z} maisc;
typedef enum {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z} minsc;

typedef struct Alunos //definition of the students structure
{
    char nome[20];
    char apelido[20];
    char residencia[20];
    int telefone;
} ESTUDANTE;

void writeStruct(ESTUDANTE*); //to write the different students
int equalEntry(ESTUDANTE*, ESTUDANTE*); //compares 2 entries
int comesFirst(ESTUDANTE*, ESTUDANTE*); //checks name order

void main()
{
    ESTUDANTE num_A, num_B;
    boolean X, Y=0;

    writeStruct(&num_A);
    do
    {
        writeStruct(&num_B);
        X = equalEntry(&num_A, &num_B);//returns 1 if the they are equal
        if(X==1)//prints to the screen if the register are equal
            printf("Register already exist please try again.\n");
    }
    while(X==1);//while A==B then the program will keep asking you to rewrite B until they are different

    Y = comesFirst(&num_A, &num_B);//returns 1 if num_A comes fist to num_B

    if(Y==1)
        printf("\n%s %s\ncomes first to\n%s %s\n", num_A.nome, num_A.apelido, num_B.nome, num_B.apelido);
    else
         printf("\n%s %s\ncomes first to\n%s %s\n", num_B.nome, num_B.apelido, num_A.nome, num_A.apelido);
}

void writeStruct(ESTUDANTE *nome)//writes the info on the student
{
    printf("New entry:\n");
    printf("Type the name:");
    scanf("%s", nome->nome);//using 'scanf' rather than 'gets' because I only need to one word, rather than a a phrase
    printf("Type the surname:");
    scanf("%s", nome->apelido);
    printf("Type where you living:");
    scanf("%s", nome->residencia);
    printf("Type your phone number:");
    scanf("%d", &nome->telefone);
}
int equalEntry (ESTUDANTE *A, ESTUDANTE *B)//check if they are equal
{
    int i;
    for(i=0;(A->nome[i] != '\0')||(B->nome[i] != '\0');++i)//keeps looping on the longest name
    {
        if(A->nome[i] != B->nome[i])//checks if the name is equal
        {
            return 0;//if this happens then the names are different thus return FALSE
        }
    }//if this finish then the name is the same
    for(i=0;(A->apelido[i] != '\0')||(B->apelido[i] != '\0');++i)//keeps looping on the longest surname
    {
        if(A->apelido[i] != B->apelido[i])//checks if the surname is equal
        {
            return 0;//surnames are different
        }
    }//if this finish then the surname is the same
    for(i=0;(A->residencia[i] != '\0')||(B->residencia[i] != '\0');++i)
    {
        if(A->residencia[i] != B->residencia[i])//checks if the home name is the same
        {
            return 0;//home is different
        }
    }//if this finish then the home is the same
    if(A->telefone != B->telefone)//checks if the phone number is the same
    {
        return 0;//phone number is different
    }//if this finish the the phone number is the same

    //if all of this finish then the DATA is already existing
    return 1;
}
int comesFirst(ESTUDANTE *A, ESTUDANTE *B)//checks what name comes first
{
    maisc first_maisc, second_maisc;//only to be used if it is the first letter
    minsc first_minsc, second_minsc;//to be use the other times
    first_maisc=A->nome[0];
    second_maisc=B->nome[0];
    if(first_maisc<second_maisc)
        return 1;
    else if(first_maisc>second_maisc)
        return 0;
    else//that being the first to letters are equal
    {
        //TODO
    }
}
