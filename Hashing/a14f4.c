#include<stdio.h>
#include<stdlib.h>
typedef char StackElementType;
typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);
void TraverseStack(StackPointer Stack);

int main(){
    StackPointer Astack;
    CreateStack(&Astack);
    char x[40];
    printf("EISAGETE MIA PARASTASI: ");
    scanf("%s",&x);
     int i=0;
     while(x[i]!='\0')
     {
         if(x[i]=='(' || x[i]==')' || x[i]=='{' || x[i]=='}' || x[i]=='[' || x[i]==']' )
         {
             Push(&Astack,x[i]);

         }
         i++;
     }

     boolean found=FALSE;
     StackPointer currptr;
     currptr=Astack;

     while(currptr!=NULL )
     {
        if(currptr->Data==')' && currptr!=NULL)
         {

             currptr=currptr->Next;
             if(currptr==NULL) break;

             if(currptr->Data=='(' && currptr!=NULL)
             {
                 currptr=currptr->Next;

                 if(currptr==NULL)
                 {
                     found=TRUE;
                     break;
                 }

             }

         }
         if(currptr->Data=='}' || currptr->Data==']' && currptr!=NULL )
         {
             currptr=currptr->Next;



             if(currptr->Data==')' && currptr!=NULL)
             {

                 currptr=currptr->Next;
                 if(currptr==NULL) break;


                 if(currptr->Data=='(' && currptr!=NULL)
                 {
                     currptr=currptr->Next;

                     if(currptr->Data=='{' || currptr->Data=='[' && currptr!=NULL )
                        {
                            currptr=currptr->Next;
                            if(currptr==NULL)
                            {
                                found=TRUE;
                                break;
                            }

                        }
                 }

             }
         }
         currptr=currptr->Next;

     }



     if(found)
        printf("CORRECT");
     else if(!found && !EmptyStack(Astack))
        printf("WRONG");
        if(EmptyStack(Astack))
            printf("CORRECT");





}
void CreateStack(StackPointer *Stack)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη στοίβα.
   Επιστρέφει: Μια κενή συνδεδεμένη στοίβα, Stack
*/
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* Δέχεται:     Μια συνδεδεμένη στοίβα, Stack.
   Λειτουργία:  Ελέγχει αν η Stack είναι κενή.
   Επιστρέφει:  TRUE αν η στοίβα είναι κενή, FALSE διαφορετικά
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον
                δείκτη Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει στην κορυφή της συνδεδεμένης στοίβας, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον δείκτη Stack.
   Λειτουργία: Αφαιρεί από την κορυφή της συνδεδεμένης στοίβας,
                αν η στοίβα δεν είναι κενή, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα και το στοιχείο Item.
   Έξοδος:     Μήνυμα κενής στοίβας, αν η συνδεδεμένη στοίβα είναι κενή
*/
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}
void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%c ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}


