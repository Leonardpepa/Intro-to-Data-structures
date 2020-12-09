#include <stdio.h>
#include <stdlib.h>

#define NumberOfNodes 20    /*όριο μεγέθους της συνδεδεμένης λίστας,
                            ενδεικτικά τέθηκε ίσο με 50*/
#define NilValue -1          // ειδική μεδενικη τιμη δείχνει το τέλος της Συνδ.λίστας

typedef struct{
    int studentid;
    float grade;
    } ListElementType; /*τύπος δεδομένων για τα στοιχεία της συνδεδεμένης λίστας,
                                ενδεικτικά επιλέχθηκε ο τύπος int */
typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateLList(ListPointer *List);
boolean EmptyLList(ListPointer List);
boolean FullLList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);





int main()
{
        ListPointer Alist;
        NodeType node[NumberOfNodes];
        ListPointer Freeptr,Predptr;
        ListElementType Item;
        InitializeStoragePool(node,&Freeptr);
        CreateLList(&Alist);
        printf("DWSE ARI8MO MA8HTWN:");
        int n;
        scanf("%d",&n);
        while(n>20)
        {
            printf("MEGISTO PLITHIS 20 KSANA DWSE:");
             scanf("%d",&n);

        }
        int i;
        for(i=0;i<n;i++)
        {
            printf("\n");
            printf("DWSE ARI8MO MHTRWOU GIA EISAGWGH STH LISTA:");
            scanf("%d",&Item.studentid);
            printf("DWSE BA8MO GIA EISAGWGH STH LISTA: ");
            scanf("%g",&Item.grade);
            printf("DWSE TH 8ESH META THN OPOIA 8A GINEI H EISAGWGH STOIXEIOY: ");
            scanf("%d",&Predptr);
            Insert(&Alist,node,&Freeptr,Predptr,Item);
            TraverseLinked(Alist,node);

        }

        printf("DWSE TH 8ESH TOY PROHGOYMENOY STOIXEIOY PROS DIAGRAFH: ");

        scanf("%d",&Predptr);

        Delete(&Alist,node,&Freeptr,Predptr);
        TraverseLinked(Alist,node);

        for(i=0;i<2;i++)
        {
             printf("DWSE ARI8MO MHTRWOU GIA EISAGWGH STH LISTA:");
            scanf("%d",&Item.studentid);
            printf("DWSE BA8MO GIA EISAGWGH STH LISTA: ");
            scanf("%g",&Item.grade);
            printf("DWSE TH 8ESH META THN OPOIA 8A GINEI H EISAGWGH STOIXEIOY: ");
            scanf("%d",&Predptr);
            Insert(&Alist,node,&Freeptr,Predptr,Item);
            TraverseLinked(Alist,node);
        }
















return 0;
}


void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
/* Δέχεται:   Τον πίνακα Node και τον δείκτη FreePtr που δείχνει στον
                πρώτο διαθέσιμο κόμβο.
  Λειτουργία: Αρχικοποιεί τον πίνακα Node ως συνδεδεμένη λίστα συνδέοντας μεταξύ
                τους διαδοχικές εγγραφές του πίνακα,
                και αρχικοποιεί τον δείκτη FreePtr .
  Επιστρέφει: Τον τροποποιημένο πίνακα Node και τον
                δείκτη FreePtr του πρώτου διαθέσιμου κόμβου
*/
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.studentid=-1;
        Node[i].Data.grade=-1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.studentid=NilValue;
     Node[NumberOfNodes-1].Data.grade=NilValue;
    *FreePtr=0;
}

void CreateLList(ListPointer *List)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη λίστα.
   Επιστρέφει: Έναν (μηδενικό) δείκτη που δείχνει σε κενή λίστα
*/
{
  *List=NilValue;
}

boolean EmptyLList(ListPointer List)
/* Δέχεται:    Έναν δείκτη List που δείχνει σε μια συνδεδεμένη λίστα.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι κενή.
   Επιστρέφει: True αν η συνδεδεμένη λίστα είναι κενή και false διαφορετικά
*/
{
  return (List==NilValue);
}

boolean FullLList(ListPointer FreePtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι γεμάτη.
   Επιστρέφει: True αν η συνδεδεμένηλίστα είναι γεμάτη, false διαφορετικά
*/
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/* Δέχεται:   Τον πίνακα Node και τον δείκτη FreePtr.
  Λειτουργία: Αποκτά έναν "ελεύθερο" κόμβο που τον δείχνει ο δείκτης P.
  Επιστρέφει: Τον δείκτη P και τον τροποποιημένο  δείκτη FreePtr
                που δεικτοδοτεί στο πρώτο διαθέσιμο κόμβο
*/
{
  *P = *FreePtr;
  if (!FullLList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
/* Δέχεται:    Τον πίνακα Node, που αναπαριστά τη δεξαμενή των διαθέσιμων κόμβων,
                έναν δείκτη TempPtr και τον δείκτη FreePtr.
   Λειτουργία: Επιστρέφει στη δεξαμενή τον κόμβο στον οποίο δείχνει ο TempPtr.
   Επιστρέφει: Τον τροποποιημένο πίνακα Node και τον δείκτη FreePtr
*/
{
  Node[P].Next =*FreePtr;
  Node[P].Data.studentid = -1;
  Node[P].Data.grade = -1; /* Οχι αναγκαία εντολή, βοηθητική για να φαίνονται στην
                        εκτύπωση οι διαγραμμένοι κόμβοι */
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
/* Δέχεται:    Μια συνδεδεμένη λίστα, τον πίνακα Node, τον δείκτη PredPtr και
                ένα στοιχείο Item.
  Λειτουργία: Εισάγει στη συνδεδεμένη λίστα, αν δεν είναι γεμάτη, το στοιχείο
                Item μετά από τον κόμβο στον οποίο δείχνει ο δείκτης PredPtr.
  Επιστρέφει: Την τροποποιημένη συνδεδεμένη λίστα, τον τροποποιημένο πίνακα Node
                και τον δείκτη FreePtr.
  Εξοδος:     Μήνυμα γεμάτης λίστας, αν η συνδεδεμένη λίστα είναι γεμάτη
*/
{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullLList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data.studentid =Item.studentid;
        Node[TempPtr].Data.grade =Item.grade;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data.studentid =Item.studentid;
        Node[TempPtr].Data.grade =Item.grade;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)
/* Δέχεται:   Μια συνδεδεμένη λίστα και τον δείκτη PredPtr που δείχνει
                στον προηγούμενο κόμβο από αυτόν που θα διαγραφεί.
  Λειτουργία: Διαγράφει από τη συνδεδεμένη λίστα, αν δεν είναι κενή,
                τον προηγούμενο κόμβο από αυτόν στον οποίο δείχνει ο PredPtr.
  Επιστρέφει: Την τροποποιημένη λίστα και το δείκτη FreePtr.
  Έξοδος:     Μήνυμα κενής λίστας, αν η συνδεδεμένη λίστα είναι κενή
*/
{
  ListPointer TempPtr ;



  if (!EmptyLList(*List))
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);

    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);

      }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
/* Δέχεται:    Μια συνδεδεμένη λίστα.
   Λειτουργία: Κάνει διάσχιση της συνδεδεμένης λίστας, αν δεν είναι κενή.
   Έξοδος:     Εξαρτάται από την επεξεργασία
*/
{
  ListPointer CurrPtr;
  CurrPtr =List;
  int pl=0;
       while (CurrPtr != NilValue)
      {
        pl++;
        CurrPtr=Node[CurrPtr].Next;
       }
printf("Plithos stoixeiwn sth lista: %d\n", pl);

  if (!EmptyLList(List))
  {
      CurrPtr =List;

      while (CurrPtr != NilValue)
      {
        pl++;
          printf("[%d: (%d,%g) -> %d]",CurrPtr,Node[CurrPtr].Data.studentid,Node[CurrPtr].Data.grade, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}
