
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int code;
    int recNo;
} BinTreeElementType;             /*ο τύπος των στοιχείων του ΔΔΑ
                                                ενδεικτικά τύπου int */
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
void menu(int *choice);
int BuildBST(BinTreePointer *Root);
void PrintStudent(int RecNum);
void printStudentsWithGrade();
void RecBSTInorder(BinTreePointer Root);

int main()
{
    FILE *Fp;
    BinTreePointer ARoot,LOCPTR;
    int choice ,size;
    boolean found;
    StudentT student;
    BinTreeElementType indexRec;
    menu(&choice);

    while(choice!=6)
    {
        switch(choice)
    {
    case 1:
        size = BuildBST(&ARoot);
        printf("%d\n",size);
        break;
    case 2:
        Fp = fopen("foitites.dat","a");
        if(Fp==NULL)
        {
            printf("CANT OPEN THIS FILE \n");
            exit(1);
        }
        else
        {
            printf("Give student's AM: ");
                scanf("%d", &student.code);
                getchar();
                 indexRec.code=student.code;
                RecBSTSearch(ARoot, indexRec, &found, &LOCPTR);
                if(!found)
                {
                    printf("Give student surname: ");
                    fgets(student.surname,20,stdin);
                    student.surname[strlen(student.surname)-1]='\0';
                    printf("Give student name: ");
                    fgets(student.name,20,stdin);
                    student.name[strlen(student.name)-1]='\0';
                    printf("Give student's registration year: ");
                    scanf("%d", &student.year);
                    getchar();

                    printf("Give student's grade: ");
                    scanf("%f", &student.grade);

                    printf("Give student sex F/M: ");
                    scanf("%c", &student.sex);
                    getchar();
                    printf("size=%d\n", size);
                    indexRec.recNo=size;
                    RecBSTInsert(&ARoot, indexRec);
                    fprintf(Fp, "%d, %s, %s, %c, %d, %f%c",student.code, student.surname, student.name,student.sex, student.year, student.grade, '\n');
                    size++;
        }
            else
                printf("STUNEDNT ALREADY EXIST");
        fclose(Fp);
        break;
    }
    case 3:
        printf("GIVE STUDENTS  AM: ");
            scanf("%d", &student.code);
            indexRec.code=student.code;
            RecBSTSearch(ARoot, indexRec, &found, &LOCPTR);
            if(found)
            {
                indexRec.recNo=LOCPTR->Data.recNo;
                PrintStudent(indexRec.recNo);
            }
            else
                printf("Not found\n\n");
            break;

    case 4:
         printf("PRINT ALL STUDENTS DATA\n");
            RecBSTInorder(ARoot);
            printf("\n");
            break;
    case 5:
        printf("PRINT STUDENTS THAT HAVE GRATE >= GIVEN GRADE");
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
    FILE *FP;
    StudentT student;
    BinTreeElementType indexRec;
    int size;
    int nscan;
    char termch;

    CreateBST(&(*Root));
    FP = fopen("foitites.dat", "r");
    size = 0;

    if( FP == NULL)
    {
        printf("Cant open this file\n");
        exit(1);
    }
    else
    {
        while(TRUE)
       {
           nscan = fscanf(FP,"%d, %20[^,], %20[^,], %c, %d, %g%c",&student.code,student.surname,student.name,&student.sex,&student.year,&student.grade,&termch);
            if (nscan==EOF)
                break;
            if (nscan!=7 || termch!='\n')
            {
                printf("Error404\n");
                exit(1);
            }
            else
            {
                indexRec.code = student.code;
                indexRec.recNo = size;
                RecBSTInsert(Root,indexRec);
                size++;
            }
    }
    }
    fclose(FP);
    return size;
}

void PrintStudent(int RecNum)
{
    FILE *infile;
    int nscan,lines;
    char termach;
    StudentT student;

    lines = 0;
    infile = fopen("foitites.dat", "r");

    if(infile == NULL)
        {
            printf("File Can't open\n");
            exit(1);
        }
        else{
            while(lines <= RecNum)
            {
                nscan=fscanf(infile,"%d, %20[^,], %20[^,], %c, %d, %f%c",&student.code, student.surname, student.name,&student.sex, &student.year, &student.grade, &termach);
                if(nscan==EOF)
                    break;
                else if(nscan != 7 || termach!='\n')
                    exit(1);
                else
                    lines++;

            }
            if(lines>RecNum)
            {
                printf("%d, %s, %s, %c, %d, %.2f\n",
               student.code, student.surname, student.name,
               student.sex, student.year, student.grade);
            }
            fclose(infile);
        }
}

void printStudentsWithGrade()
{
    FILE *infile;
    int nscan;
    char termch;
    StudentT student;
    float Grade;

    printf("GIVE THE GRADE:");
    scanf("%g",&Grade);

    infile = fopen("foitites.dat", "r");
    if(infile==NULL)
        printf("FILE CANT OPEN\n");
    else {
        while(TRUE)
        {
            nscan=fscanf(infile,"%d, %20[^,], %20[^,], %c, %d, %f%c",&student.code,student.surname,student.name,&student.sex,&student.year,&student.grade,&termch);
            if(nscan == EOF)
               {
                   break;
               }
            if(nscan != 7 ||termch!='\n')
                exit(1);
            else if(student.grade>=Grade)
            {
                printf("%d, %s, %s, %c, %d, %g\n",student.code, student.surname, student.name,student.sex, student.year, student.grade);

            }

        }

    }
    fclose(infile);
}
