#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* jedna lista, alfabetyczna */
struct node {
  char* word;
  int repetition;
  struct node* next;
};
void trim(char* word) { /* funkcja obcina stringa ze znakow specjalnych, np *()slowo lub slowo, zamienia na slowo */
  int i,j;
  int wordLength;
  /* Wywalanie z poczatku wyrazu: */

  while(word[0] < 65 || (word[0] > 90 && word[0] < 97) || word[0] > 122) {
    for(j=0;word[j]!='\0';j++) {

        word[j] = word[j+1]; /* przesuwam wszystkie znaki stringa o 1 w lewo */
    }
  }
  wordLength = strlen(word); /* wskakuje na koniec slowa */
  /* wywalanie z  konca: */
  for(i=wordLength-1;(word[i] < 65 || (word[i] > 90 && word[i] < 97) || word[i] > 122);i--) {
    word[i] = '\0';
  }
}

void lowercase(char* word) { /* przepisuje slowo w buforze na male litery */
    int i;
    for(i=0;word[i]!='\0';i++) {
        if(word[i] >= 65 && word[i] <= 90) {
                word[i] = word[i] + 32;
        }
    }
}

int compareWords(char* word1, char* word2) {/* zwraca 0 jesli wyrazy sa takie same, 1 jesli 1wszy jest wczesniejszy, 2 jesli 2gi. */
    int length,i;
    if(strlen(word1) > strlen(word2)) {
        length = strlen(word2);
    }
    else {
        length = strlen(word1);
    }
    for(i=0;i<length;i++) {
        if(word1[i] < word2[i]) {
            return 1; /* pierwszy jest mniejszy, czyli wczesniej w porzadku alfabetycznym */
        }
        if(word1[i] > word2[i]) {
            return 2; /* drugi jest wczesniej */
        }
    }
    return 0; /* wyrazy sie nie roznia */
 }

struct node* countFile(char* fileName) {
    char buffer[100];
    char* word;
    FILE* fileHandle;
    int wordLength;
    int flag = 1;
    struct node* newNode;
    struct node* listPointer; /* wskaznik do chodzenia po liscie i dodawania node'ow w odpowiednim miejscu */
    /* tworzenie listy z wyrazami */
    struct node* head = NULL;
    /* tworzenie wartownika */
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->repetition = 0;
    newNode->word = NULL;
    newNode->next = head;
    head = newNode;

  fileHandle = fopen(fileName, "rt"); /* rt - reading text */
  while(fscanf(fileHandle, "%s", buffer) != EOF) {
    listPointer = head; /* reset wskaznika do chodzenia po liscie na poczatku kazdej petli */
    trim(buffer);
    lowercase(buffer);
    wordLength = strlen(buffer);
    word  = (char*)malloc(wordLength*sizeof(char)); /*  alokacja pamieci */
    word = buffer; /* przepisanie z bufora na styrte */
    /* gdzies tu sprawdzanie, czy wyraz juz istnieje na liscie */
    /* lece po liscie i sprawdzam gdzie wstawic zeby byla kolejnosc alfabetyczna  tu jest problem bo np na poczatku to zawsze bedzie falszywe*/
    while(flag) { /* do napisania od nowa */
        if(compareWords(word, listPointer->next->word) == 2 && listPointer->next != NULL) { /* przesuwa, jesli aktualne slowo ma byc umieszczone dalej */
            listPointer = listPointer->next;
        }
        else if(compareWords(word, listPointer->next->word) == 0) { /* slowa sa identyczne */
            ++listPointer->next->repetition;
            flag = 0;
        }
        else { /* w przeciwnym wypadku tworzymy nowy node na slowo */
            newNode = (struct node*)malloc(sizeof(struct node));
            newNode->word = word;
            newNode->repetition = 1;
            newNode->next = listPointer->next;
            listPointer->next = newNode;
            flag = 0;
        }
    }
    /* Jesli juz jest, to repetition+1 */
    /* Jesli takiego wyrazu jeszcze nie ma na liscie: */

  }
  /* czytaj plik po wyrazie i pakuj wyraz do bufora. */
  return head;
}

void displayList(struct node* pointer) {
    while(pointer != NULL) {
    printf("Slowo: %s, ilosc: %d", pointer->word,pointer->repetition);
    pointer = pointer->next;
    }
}

int wordsCount() { /* zwraca liczbe wszystkich oraz roznych wyrazow */
  return 0;
}

void longestWord() { /* znajduje najdluzsze slowo */
  /*return;*/
}

int main(void) {

    struct node* head;

    head = countFile("file.txt");
    displayList(head);
    return 0;
}
