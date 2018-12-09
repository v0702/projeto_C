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
    boolean X=0, Y;

    writeStruct(&num_A);
    while(X!=1)//while A==B then the program will keep asking you to
    {          //rewrite B until they are different
        writeStruct(&num_B);
        X = equalEntry(&num_A, &num_B);//returns 1 if the they are equal
        if(X!=1)//prints to the screen if the register are equal
            printf("\nRegister already exist please try again.\n");
    }
    Y = comesFirst(&num_A, &num_B);//returns 1 if num_A comes fist to num_B

    if(Y==1)
        printf("\n%s %s\n comes first to\n%s %s\n", num_A.nome, num_A.apelido, num_B.nome, num_B.apelido);
    else
         printf("\n%s %s\n comes first to\n%s %s\n", num_B.nome, num_B.apelido, num_A.nome, num_A.apelido);
}

void writeStruct(ESTUDANTE *nome)//writes the info on the student
{
    printf("\nType the name:");
    scanf("%s", nome->nome);//using 'scanf' rather than 'gets' because I only need to one word, rather than a a phrase
    printf("\nType the surname:");
    scanf("%s", nome->apelido);
    printf("\nType where you living:");
    gets(nome->residencia);
    printf("\nType your phone number:");
    scanf("%d", nome->telefone);
}
int equalEntry (ESTUDANTE *A,ESTUDANTE *B)//check if they are equal
{//TODO
    maisc first_maisc, second_maisc;//only to be used if it is the first letter
    minsc first_minsc, second_minsc;//to be use the other times
    int i=0;//will server to count syllables

    while(A->nome[i] == B->nome[i])//if the syllables match it moves onto the next one;
    {
        ++i;
    }//if this ends it means the syllables don't match on the i

}
int comesFirst ()//TODO
{
    
}
