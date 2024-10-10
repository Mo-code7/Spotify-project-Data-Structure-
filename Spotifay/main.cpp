#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a song
typedef struct {
    int songID;
    char name[100];
    char artist[100];
    int duration;
} Song;

// Structure to represent a node in the queue
typedef struct Node {
    Song data;
    struct Node* next;
} Node;

// Structure to represent the queue
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue (add) a song to the queue
void enqueue(Queue* queue, Song song) {

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = song;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("Song '%s' by %s added to the queue.\n", song.name, song.artist);
}

// Function to dequeue (remove) the front song from the queue
void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No songs to dequeue.\n");
        return;
    }

    Node* temp = queue->front;
    printf("Playing song '%s' by %s.\n", temp->data.name, temp->data.artist);

    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }
}

// Function to Display current the front song in the queue
void disCurr(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No songs to Display.\n");
        return;
    }

    Node* temp = queue->front;
    printf("Playing song '%s' by %s.\n", temp->data.name, temp->data.artist);

}

// Function to display the songs in the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    Node* current = queue->front;
    printf("Songs in the queue:\n");

    while (current != NULL) {
        printf("ID: %d, Name: %s, Artist: %s, Duration: %d seconds\n",
               current->data.songID, current->data.name, current->data.artist, current->data.duration);
        current = current->next;
    }
}

// Function to search for a song using id in the queue
void search(Queue* queue,int id) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    int flag=0;
    Node* current = queue->front;
    printf("\n");

    while (current != NULL) {
        if (current->data.songID == id) {
            printf("ID: %d, Name: %s, Artist: %s, Duration: %d seconds\n",
                   current->data.songID, current->data.name, current->data.artist, current->data.duration);
            flag=1;
            break;
        }
           if(flag==0){
               printf("Song not found\n");
           }

            current = current->next;
    }
}


int main() {

    int id=0;

    Queue* queue = createQueue();
    Song temp={0,"","",0};

    int choice = -1;

    do{
        printf("1.ADD All Songs\n");
        printf("2.DISPLAY Songs\n");
        printf("3.Display and Delete Current Song\n");
        printf("4.Display Current Song\n");
        printf("5.Search for a Song Using ID\n");
        printf("0.EXIT\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Insert the Song's ID: ");
                scanf("%d",&temp.songID);
                printf("Insert the Song Name: ");
                scanf("%s",temp.name);
                printf("Insert the Song's Author Name: ");
                scanf("%s",temp.artist);
                printf("Insert the Song duration: ");
                scanf("%d",&temp.duration);

                enqueue(queue,temp);

                printf("--------------------");
                printf("\n");
                break;
            case 2:

                displayQueue(queue);

                printf("--------------------");
                printf("\n");
                break;
            case 3:

                dequeue(queue);

                printf("--------------------");
                printf("\n");
                break;
            case 4:

                disCurr(queue);

                printf("--------------------");
                printf("\n");
                break;
            case 5:

                printf("Enter the Song Id: ");
                scanf("%d",&id);

                search( queue,id);

                printf("--------------------");
                printf("\n");
                break;
            case 0:

                return 0;

            default :
                printf("--------------------");
                printf("\n");
                printf("invalid input");
                printf("\n");
                printf("--------------------");
                printf("\n");
        }
    }while(choice!=0);

    return 0;
}


