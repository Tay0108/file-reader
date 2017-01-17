#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* jedna lista, alfabetyczna */
struct node {
  char* word;
  int repetition;
  struct node* next;
};

struct sum {
    int sumAll;
    int sumUnique;
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

int compareWords(char* word1, char* word2) {/* zwraca 0 jesli wyrazy sa takie same, 1 jesli 1wszy jest wczesniejszy, 2 jesli 2gi. -1 jesli ktorys jest nullem*/
    int length,i;
    if(word1 == NULL || word2 == NULL) {
        return -1;
    }

    if(strlen(word1) < strlen(word2)) {
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
        while(listPointer->next != NULL && compareWords(buffer, listPointer->next->word) == 2) {
            listPointer = listPointer->next;
        }
        if(listPointer->next != NULL && compareWords(buffer, listPointer->next->word) == 0) {
            ++listPointer->next->repetition;
        }
        else {
            wordLength = strlen(buffer);
            word  = (char*)malloc(wordLength*sizeof(char)); /*  alokacja pamieci */
            strcpy(word,buffer); /* przepisanie z bufora na styrte */

            newNode = (struct node*)malloc(sizeof(struct node));
            newNode->word = word;
            newNode->repetition = 1;
            newNode->next = listPointer->next;
            listPointer->next = newNode;
        }
    }
    /* Jesli takiego wyrazu jeszcze nie ma na liscie: */
  return head;
}

void displayList(struct node* pointer) { /* pomija wartownika, 1wszy node */
    while(pointer->next != NULL) {
        printf("Slowo: %s, ilosc: %d \n", pointer->next->word,pointer->next->repetition);
        pointer = pointer->next;
    }
}

struct sum wordsCount(struct node* pointer) { /* zwraca liczbe wszystkich oraz roznych wyrazow */
    struct sum wordsSum;
    wordsSum.sumAll = 0;
    wordsSum.sumUnique = 0;
    while(pointer->next != NULL) {
        wordsSum.sumAll += pointer->next->repetition;
        ++wordsSum.sumUnique;
        pointer = pointer->next;
    }
  return wordsSum;
}

char* longestWord(struct node* pointer) { /* znajduje najdluzsze slowo */
    char tmp[1] = {'\0'}; /* brzydki cheat, zeby nie wyrzucalo bledu jak liczy strlen z NULLa */
    char* longest = tmp;
    while(pointer->next != NULL) {
        if(strlen(longest) < strlen(pointer->next->word)) {
            longest = pointer->next->word;
        }
    pointer = pointer->next;
    }
  return longest;
}

int main(void) {

    struct node* head;
    struct sum wordsSum;
    char* longest;

    head = countFile("file.txt");
    displayList(head);
    wordsSum = wordsCount(head);
    longest = longestWord(head);
    printf("Liczba wszystkich wyrazow: %d\n", wordsSum.sumAll);
    printf("Liczba unikalnych wyrazow: %d\n", wordsSum.sumUnique);
    printf("Najdluzsze slowo: %s (%d liter)", longest, strlen(longest));
    return 0;
}
