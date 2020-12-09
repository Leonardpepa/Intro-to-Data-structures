
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int code;
    int recNo;
} BinTreeElementType;





typedef struct BinTreeNode *BinTreePointer;
struct BinTreeNode
{
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;





typedef struct
{
    int code;
    char surname[20];
    char name[20];
    char sex;
    int year;
    float grade;
} StudentT;

typedef enum
{
    FALSE, TRUE
} boolean;
void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void RecBSTInorder(BinTreePointer Root);
void RecBSTPreorder(BinTreePointer Root);
void RecBSTPostorder(BinTreePointer Root);



void menu(int *choice);
int BuildBST(BinTreePointer *Root);
void PrintStudent(int RecNum);
void printStudentsWithGrade();


int main()
{
    FILE *fp;
    BinTreePointer Root,Lockptr;
    int choice ,size;
    boolean found;
    StudentT Students;
    BinTreeElementType indexRec;
    menu(&choice);

    while(choice!=6)
    {
        switch(choice)
    {
    case 1:
        size = BuildBST(&Root);

        break;

    case 2:

        fp = fopen("foitites.dat","a");
        if(fp==NULL)
        {
            printf("Cant  Open File \n");
            exit(1);
        }
        else
        {
            printf("Give student's AM: ");
                scanf("%d", &Students.code);
                getchar();
                 indexRec.code=Students.code;
                RecBSTSearch(Root, indexRec, &found, &Lockptr);
                if(!found)
                {
                    printf("Give  student  surname: ");
                    fgets(Students.surname,20,stdin);
                    Students.surname[strlen(Students.surname)-1]='\0';
                    printf("Give  student  name: ");
                    fgets(Students.name,20,stdin);
                    Students.name[strlen(Students.name)-1]='\0';
                    printf("Give  student's  registration year: ");
                    scanf("%d", &Students.year);
                    getchar();

                    printf("Give  student's  grade: ");
                    scanf("%f", &Students.grade);
                    getchar();
                    printf("Give  student  sex  F/M: ");
                    scanf("%c", &Students.sex);
                    getchar();
                    printf("size= %d\n", size);
                    indexRec.recNo=size;
                    RecBSTInsert(&Root, indexRec);
                    fprintf(fp, "%d, %s, %s, %c, %d, %f%c",Students.code, Students.surname, Students.name,Students.sex, Students.year, Students.grade, '\n');
                    size++;
        }
            else
                printf(" Student Already  Exist ");
        fclose(fp);
        break;
    }
    case 3:
        printf("Give  Students  AM: ");
            scanf("%d", &Students.code);
            indexRec.code=Students.code;
            RecBSTSearch(Root, indexRec, &found, &Lockptr);
            if(found)
            {
                indexRec.recNo=Lockptr->Data.recNo;
                PrintStudent(indexRec.recNo);
            }
            else
                printf("Not found\n\n");
            break;

    case 4:
         printf("Print   All  Studens  Data\n");
            RecBSTInorder(Root);
            printf("\n");
            break;

    case 5:
        printf("Print  Studens  That  Have  Great  >= Given  Grade");
            printStudentsWithGrade();
            printf("\n");
            break;

    case 6 :
        break;

        }
    menu(&choice);
}
return 0;
}

void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    if (BSTEmpty(*Root))
    {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data.code = Item.code;
        (*Root) ->Data.recNo = Item.recNo;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else if (Item.code < (*Root) ->Data.code)
        RecBSTInsert(&(*Root) ->LChild,Item);
    else if (Item.code > (*Root) ->Data.code)
        RecBSTInsert(&(*Root) ->RChild,Item);
    else
        printf("To %d EINAI HDH STO DDA\n", Item.code);
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                  boolean *Found, BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{

    if (BSTEmpty(Root))
        *Found=FALSE;
    else if (KeyValue.code < Root->Data.code)
        RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
    else if (KeyValue.code > Root->Data.code)
        RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
    else
    {
        *Found = TRUE;
        *LocPtr=Root;
    }
}

void RecBSTInorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        RecBSTInorder(Root->LChild);
        printf("(%d, %d) ", Root->Data.code, Root->Data.recNo);
        RecBSTInorder(Root->RChild);
    }
}

void menu(int *choice)
{
    printf("                       MENU                              \n");
    printf("---------------------------------------------------------\n");
    printf("1. Build BST \n");
    printf("2. Insert new student \n");
    printf("3. Search for a student \n");
    printf("4. Print all students (Traverse Inorder) \n");
    printf("5. Print students with a >= given grade \n");
    printf("6. Quit \n");
    do
    {
        printf("\n");
        printf("Choice: ");
        scanf("%d", choice);
        getchar();
        printf("\n");
    }
    while(*choice <= 1 && *choice >= 6);
}

int BuildBST(BinTreePointer *Root)
{
    FILE *fP;
    StudentT Students;
    BinTreeElementType indexRec;
    int size;
    int nscan;
    char termch;
    CreateBST(&(*Root));
    fP = fopen("foitites.dat", "r");
    size = 0;
    if( fP == NULL)
    {
        printf("Cant open this file\n");
        exit(1);
    }
    else
    {
        while(TRUE)
       {
           nscan = fscanf(fP,"%d, %20[^,], %20[^,], %c, %d, %g%c",&Students.code,Students.surname,Students.name,&Students.sex,&Students.year,&Students.grade,&termch);
            if (nscan==EOF)
                break;
            if (nscan!=7 || termch!='\n')
            {

                exit(1);
            }
            else
            {
                indexRec.code = Students.code;
                indexRec.recNo = size;
                RecBSTInsert(Root,indexRec);
                size++;
            }
          }
    }
    fclose(fP);
    return size;
}

void PrintStudent(int RecNum)
{
    FILE *infile;
    int nscan,lines;
    char termach;
    StudentT Students;
    lines = 0;
    infile = fopen("foitites.dat", "r");
    if(infile == NULL)
        {
            printf("File Cant Open\n");
            exit(1);
        }
        else{
            while(lines <= RecNum)
            {
                nscan=fscanf(infile,"%d, %20[^,], %20[^,], %c, %d, %f%c",&Students.code, Students.surname, Students.name,&Students.sex, &Students.year, &Students.grade, &termach);
                if(nscan==EOF)
                    break;
                else if(nscan != 7 || termach!='\n')
                    exit(1);
                else
                    lines++;

            }
            if(lines>RecNum)
            {
                printf("%d, %s, %s, %c, %d, %.2f\n",Students.code, Students.surname, Students.name,Students.sex, Students.year, Students.grade);
            }
            fclose(infile);
        }
}

void printStudentsWithGrade()
{


    FILE *infile;
    int nscan;
    char termch;
    StudentT Students;
    float Grade;
    printf("Give  The   Grade:");
    scanf("%g",&Grade);
    infile = fopen("foitites.dat", "r");
    if(infile==NULL)
        printf("Cant Open File\n");
    else {
        while(TRUE)
        {
            nscan=fscanf(infile,"%d, %20[^,], %20[^,], %c, %d, %f%c",&Students.code,Students.surname,Students.name,&Students.sex,&Students.year,&Students.grade,&termch);
            if(nscan == EOF)
               {
                   break;
               }
            if(nscan != 7 ||termch!='\n')
                exit(1);
            else if(Students.grade>=Grade)
            {
                printf("%d, %s, %s, %c, %d, %g\n",Students.code, Students.surname, Students.name,Students.sex, Students.year, Students.grade);
            }
         }
    }
    fclose(infile);
}
