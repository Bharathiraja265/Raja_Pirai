#include<stdio.h>
#include <string.h>
#include<ctype.h>
#include <unistd.h>

struct Details {
    char publisher[50];
    char author[50];
    long version;
    int publishingYear;
    long price;
};

void print(struct Details detail){
    printf("\n");
    printf("publisher\'s Name: %s\n",detail.publisher);
    printf("Author\'s Name: %s\n",detail.author);
    printf("Version: %ld\n",detail.version);
    printf("publishing Year: %d\n",detail.publishingYear);
    printf("Price: %ld\n",detail.price);
}

int main(void){
    struct Details list[1001];
    int size = 0;

    char publisher[50];
    char author[50];
    long version;
    int publishingYear;
    long price;


    while(1){
        printf("Choose The Options:\n");
        printf("1: Enter a New App Detail ");
        printf("2: Display the details of app by Author Name.\n");
        printf("3: Sort The details of application in the increasing order of price.\n");
        printf("4: Display the Details of the application by the given publisher in the given year.\n");
        printf("5: Sort the Application in the increasing order of author and publishing year.\n");
        printf("6: End the program.\n");

        int option;
        scanf("%d ",&option);
        getchar();
        printf("\nOption %d \n",option);
        switch(option){
            case 1:
                printf("\n--- Enter the Details ---\n");
                printf("\nPublisher\'s Name: \n");
                scanf("%[^\n]s ",publisher);
                sleep(5);
                printf("\nAuthor\'s Name: \n");
                scanf("%[^\n]s ",author);
                sleep(5);
                printf("\nVersion: \n");
                scanf("%ld ",&version);
                sleep(5);
                printf("\nPublish Year: \n");
                scanf("%d ",&publishingYear);
                sleep(5);
                printf("\nPrice: \n");
                scanf("%ld ",&price);
                sleep(5);
                struct Details detail;
                strcpy(detail.publisher, publisher);
                strcpy(detail.author, author);
                detail.version = version;
                detail.publishingYear = publishingYear;
                detail.price = price;
                list[size] = detail;
                size++;
                option = 0;
                printf("\n--- Sucessfully Stored ---\n");
                break;
        case 2:
            printf("\nEnter the Author\'s name:\n");
            scanf("%s ",author);
            sleep(5);
            printf("\n Author Name %s \n",author);
            for(int index = 0; index < size; index++){
                if(strcmp(list[index].author, author) == 0){
                    print(list[index]);
                }
            }
            option = 0;
            break;
        case 3:
           for(int index = 0; index < size; index++){
               for(int currIndex =0; currIndex < size; currIndex++){
                   if(list[index].price > list[currIndex].price){
                       struct Details temp = list[index];
                       list[index] = list[currIndex];
                       list[currIndex] = temp;
                   }
               }
           }
           printf("\nSorted in the Order of Increasing Price\n");
           for(int index = 0; index < size; index++){
               print(list[index]);
               printf("\n");
           }
           option = 0;
           break;
        case 4:
            printf("\nEnter the publisher\'s name: \n");
            scanf("%s ",publisher);
            sleep(5);
            printf("\nEnter the publishing Year: \n");
            scanf("%d ",&publishingYear);
            sleep(5);
            for(int index = 0; index < size; index++){
                if(list[index].publishingYear == publishingYear && strcmp(list[index].publisher, publisher) ==0){
                    print(list[index]);
                }
            }
            option = 0;
            break;
        case 5:
           for(int index = 0; index < size; index++){
               for(int currIndex = 0; currIndex < size; currIndex++){
                   if(list[index].publishingYear > list[currIndex].publishingYear){
                       struct Details temp = list[index];
                       list[index] = list[currIndex];
                       list[currIndex] = temp;
                   }
               }
           }
           printf("\nSorted in the Order of Increasing publishing Year\n");
           for(int index = 0; index < size; index++){
               print(list[index]);
               printf("\n");
           }
           option = 0;
           break;
        case 6:
            printf("\nProgram Ended\n");
            return 0;
        default:
            printf("\n!!!!!!! Choose the correct Option !!!!!!!!\n");
            option = 0;
        }
    }


}