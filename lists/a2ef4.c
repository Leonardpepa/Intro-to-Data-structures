#include<stdio.h>
#include<stdlib.h>

typedef int ListElementType;           /* ο τύπος των στοιχείων της συνδεδεμένης λίστας
                                        ενδεικτικά τύπου int */
typedef struct ListNode *ListPointer;   //ο τύπος των δεικτών για τους κόμβους
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void OrderedLimearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void insert_at_the_end(ListPointer *Alist,ListElementType item);
void reverse_list(ListPointer *list,ListPointer predptr);


int main(){
    ListPointer Alist;
    CreateList(&Alist);
    printf("DWSE PLITHOS STOIXEIWN THS LISTAS:");
    int n;
    ListElementType item;
    ListPointer predptr=NULL;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        printf("DWSE STOIXEIO GIA EISAGWGH STHN ARXH THS LISTAS:");
        scanf("%d",&item);
        LinkedInsert(&Alist,item,predptr);


    }
    printf("*********Arxikh Lista*********\n");

    LinkedTraverse(Alist);
    reverse_list(&Alist,predptr);
printf("*********Teliki Lista*********\n");

    LinkedTraverse(Alist);








return 0;
}

void CreateList(ListPointer *List)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη λίστα.
  Επιστρέφει:  Τον μηδενικό δείκτη List
*/
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
/* Δέχεται:   Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
  Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι κενή.
  Επιστρέφει: True αν η λίστα είναι κενή και false διαφορετικά
*/
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο,
                ένα στοιχείο δεδομένων Item και έναν δείκτη PredPtr.
   Λειτουργία: Εισάγει έναν κόμβο, που περιέχει το Item, στην συνδεδεμένη λίστα
                μετά από τον κόμβο που δεικτοδοτείται από τον PredPtr
                ή στην αρχή  της συνδεδεμένης λίστας,
                αν ο PredPtr είναι μηδενικός(NULL).
  Επιστρέφει:  Την τροποποιημένη συνδεδεμένη λίστα με τον πρώτο κόμβο της
                να δεικτοδοτείται από τον List.
*/
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
 /*  printf("Insert &List %p, List %p,  &(*List) %p, (*List) %p, TempPtr %p\n",
   &List, List,  &(*List), (*List), TempPtr); */
   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο της
                 και έναν δείκτη PredPtr.
   Λειτουργία: Διαγράφει από τη συνδεδεμένη λίστα τον κόμβο που έχει
                για προηγούμενό του αυτόν στον οποίο δείχνει ο PredPtr
                ή διαγράφει τον πρώτο κόμβο, αν ο PredPtr είναι μηδενικός,
                εκτός και αν η λίστα είναι κενή.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη λίστα με τον πρώτο κόμβο
                να δεικτοδοτείται από τον List.
   Έξοδος:     Ένα μήνυμα κενής λίστας αν η συνδεδεμένη λίστα ήταν κενή .
*/
{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List)
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
   Λειτουργία: Διασχίζει τη συνδεδεμένη λίστα και
                επεξεργάζεται κάθε δεδομένο ακριβώς μια φορά.
   Επιστρέφει: Εξαρτάται από το είδος της επεξεργασίας.
*/
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;
   	 //   printf("%p\n",CurrPtr);

         while ( CurrPtr!=NULL )
        {
             printf("%d ",(*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
   }
   printf("\n");
}

void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
/* Δέχεται:   Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
  Λειτουργία: Εκτελεί μια γραμμική αναζήτηση στην μη ταξινομημένη συνδεδεμένη
              λίστα για έναν κόμβο που να περιέχει το στοιχείο Item.
  Επιστρέφει: Αν η αναζήτηση είναι επιτυχής η Found είναι true, ο CurrPtr δείχνει
                στον κόμβο που περιέχει το Item και ο PredPtr στον προηγούμενό του
                ή είναι nil αν δεν υπάρχει προηγούμενος.
                Αν η αναζήτηση δεν είναι επιτυχής η Found είναι false.
*/
{
   ListPointer CurrPtr;
   boolean stop;

   CurrPtr = List;
    *PredPtr=NULL;
   stop= FALSE;
   while (!stop && CurrPtr!=NULL )
    {
         if (CurrPtr->Data==Item )
         	stop = TRUE;
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
	*Found=stop;
}

void OrderedLimearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
/* Δέχεται:    Ένα στοιχείο Item και μια ταξινομημένη συνδεδεμένη λίστα,
                που περιέχει στοιχεία δεδομένων σε αύξουσα διάταξη και στην οποία
                ο δείκτης List δείχνει στον πρώτο  κόμβο.
   Λειτουργία: Εκτελεί γραμμική αναζήτηση της συνδεδεμένης ταξινομημένης λίστας
                για τον πρώτο κόμβο που περιέχει το στοιχείο Item ή για μια θέση
                για να εισάγει ένα νέο κόμβο που να περιέχει το στοιχείο Item.
   Επιστρέφει: Αν η αναζήτηση είναι επιτυχής η Found είναι true,
                ο CurrPtr δείχνει στον κόμβο που περιέχει το Item και
                ο PredPtr στον προηγούμενό του ή είναι nil αν δεν υπάρχει προηγούμενος.
                Αν η αναζήτηση δεν είναι επιτυχής η Found είναι false.
*/
{
   ListPointer CurrPtr;
   boolean DoneSearching;

   CurrPtr = List;
   *PredPtr = NULL;
   DoneSearching = FALSE;
   *Found = FALSE;
   while (!DoneSearching && CurrPtr!=NULL )
    {
         if (CurrPtr->Data>=Item )
         {
         	DoneSearching = TRUE;
         	*Found = (CurrPtr->Data==Item);
         }
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
}

void insert_at_the_end(ListPointer *Alist,ListElementType item){
    ListPointer currptr;
    currptr=*Alist;
    if(!EmptyList(*Alist))
    {
        while((*currptr).Next!=NULL)

        {
            currptr=(*currptr).Next;

        }

    }
    LinkedInsert(Alist,item,currptr);










}


void reverse_list(ListPointer *list,ListPointer predptr){
    ListPointer next;
    while(*list!=NULL)
    {
        next=(*list)->Next;
        (*list)->Next=predptr;
        predptr=*list;
        *list=next;



    }
    *list=predptr;


}
