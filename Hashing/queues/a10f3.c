#include<stdio.h>
#include<stdlib.h>
#define QueueLimit 20  //το όριο μεγέθους της ουράς

typedef int QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                  ενδεικτικά τύπος int */

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);






int main(){
    time_t t;
srand((unsigned) time(&t));

    QueueType Oddqueue;
    QueueType Evenqueue;
    CreateQ(&Oddqueue);
    CreateQ(&Evenqueue);
    QueueElementType odd=0;
    QueueElementType even=0;

    QueueElementType i;
    QueueElementType x;
    for(i=0;i<QueueLimit;i++){
        x=rand()%21;
    if(x%2==0){
        AddQ(&Evenqueue,x);
        even++;
    }
    else
    {
        AddQ(&Oddqueue,x);
        odd++;
    }





    }
   printf("Size of even queue :%d\n",even);
   TraverseQ(Evenqueue);
   printf("Size of odd queue :%d\n",odd);
   TraverseQ(Oddqueue);
   QueueElementType random_even,random_odd;
   random_even=rand()%even;
   random_odd=rand()%odd;
   printf("ramdom size of item: %d\n",random_even);
    printf("Size of even queue :%d\n",even);
    QueueElementType temp;
    for(i=0;i<random_even;i++)
    {
        RemoveQ(&Evenqueue,&temp);
        AddQ(&Evenqueue,temp);
    }
    TraverseQ(Evenqueue);

     printf("Size of odd queue :%d\n",odd);
     printf("ramdom size of item: %d\n",random_odd);

     for(i=0;i<random_odd;i++)
    {
        RemoveQ(&Oddqueue,&temp);
        AddQ(&Oddqueue,temp);
    }
    TraverseQ(Oddqueue);











return 0;

}


void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
    int NewRear;

	if(!FullQ(*Queue))
	{
		NewRear = (Queue ->Rear + 1) % QueueLimit;
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = NewRear;
	}
	else
		printf("Full Queue");
}




void TraverseQ(QueueType Queue) {
	int current;
	current = Queue.Front;
	while (current != Queue.Rear) {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
	printf("\n");
}


