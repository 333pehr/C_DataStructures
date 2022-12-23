//Name: SEPEHR LATIFI AZAD, Number: 190254082, Ders: COM 201_HW_1
//Program is tested by Dev-C++, C LION, Programiz Online C compiler and onlinegdb.com IDEs

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//HospitalList Structure
struct HospitalList{
    char firstLetter;
    struct Record *firstRecordPtr;
}HospitalList;


//Record Structure
struct Record{
    char name[50];
    char surname[50];
    int personId;
    char polyclinic[50];
    struct Record *nextRecord;
}Record;

int main()
{
	//Declaration and initializing Hash Table for Hospital Patients' List
    struct HospitalList hospitalList[26];
    firstLatterInitializer(hospitalList);
    int menuKey = 0;
    while((menuKey<=8) && (menuKey>=0)){
        Menu();
        printf("your selection: ");
        scanf("%d",&menuKey);
        //Switch case for Menu:
        switch(menuKey){
            case 1:
                printf("\n \n \n");
                addNewRecord(hospitalList);
                break;
            case 2:
                printf("\n \n \n");
                Search(hospitalList);
                break;
            case 3:
                printf("\n \n \n");
                Delete(hospitalList);
                break;
            case 4:
                printf("\n \n \n");
                Traversing(hospitalList);
                break;
            case 5:
                printf("\n \n \n");
                printf("Sort Will be done by name\n");
                SortingByName(hospitalList);
                break;
            case 6:
                printf("\n \n \n");
                printf("Sort Will be done by name\n");
                SortingBySurname(hospitalList);
                break;
            case 7:
                printf("\n \n \n");
                printf("Sort Will be done by Polyclinic name\n");
                SortingByPolyclinic(hospitalList);
                break;
            case 8:
                printf("Have a nice Day!\n");
                return 0;
                break;
            default:
                printf("Invalid number! Please enter a number from 1 to 8 \n");
                break;
        }
    }
    return 0;
}
//Menu function
void Menu(){
    printf("PLEASE ENTER YOUR OPERATION NUMBER: \n");
    printf("1) Add New Record \n");
    printf("2) Search Record (with name, surname, and polyclinic name) \n");
    printf("3) Delete Record (with name, surname, and polyclinic name) \n");
    printf("4) Traversing \n");
    printf("5) Sort Records By Name \n");
    printf("6) Sort Records By Surname \n");
    printf("7) Sort Records By Polyclinic Name \n");
    printf("8) Exit \n");
}
//first characters stored in array: (initializer)
void firstLatterInitializer(struct HospitalList hospitalList[]){
    int i=0;
    int c ='a';
    for(c ='a';c<='z';c++,i++){
        hospitalList[i].firstLetter = c;
        hospitalList[i].firstRecordPtr = NULL;
    }
}

//Add New Record Function
void addNewRecord(struct HospitalList hospitalList[]){
    int i = 0;
    int polyclinicNumber = 0;
    struct Record* newRecord = (struct Record*)malloc(sizeof(struct Record));
    //getting new patient's information
    printf("Please enter patient's name:");
    scanf("%s",newRecord->name);
    printf("Please enter patient's surname:");
    scanf("%s",newRecord->surname);
    printf("Please enter patient's person ID(should be number):");
    scanf("%d",&newRecord->personId);
    printf("Please enter patient's polyclinic number [1)Orthodontics 2)Endoscopy 3)Implant 4)Cardiology]:");
    scanf("%d",&polyclinicNumber);
    //switch case is used as we have just 4 options for polyclinics
    switch(polyclinicNumber){
        case 1:
            strcpy(newRecord->polyclinic,"Orthodontics");
            break;
        case 2:
            strcpy(newRecord->polyclinic,"Endoscopy");
            break;
        case 3:
            strcpy(newRecord->polyclinic,"Implant");
            break;
        case 4:
            strcpy(newRecord->polyclinic,"Cardiology");
            break;
        default:
            printf("Invalid number! Please enter a number from 1 to 4 \n");
    }
    //Traversing in the array of first letters
    for(i=0; i<26; i++){
        if(newRecord->name[0] == hospitalList[i].firstLetter){
            break;
        }
    }
    // Checking if firstRecordPtr is null or not
    if(hospitalList[i].firstRecordPtr == NULL){
        hospitalList[i].firstRecordPtr = newRecord;
        newRecord->nextRecord = NULL;
    }
    else{
        struct Record*temp;
        temp = hospitalList[i].firstRecordPtr;
        while(temp->nextRecord != NULL){
            temp = temp->nextRecord;
        }
        temp->nextRecord = newRecord;
        newRecord->nextRecord = NULL;
    }
    printf("name: %s surname: %s person ID: %d polyclinic: %s  added successfully! \n",newRecord->name, newRecord->surname,  newRecord->personId, newRecord->polyclinic);
    printf("********* \n");
    printf("\n \n");
}

//Searching Function
void Search(struct HospitalList hospitalList[]){
    //Declarations and initializations:
    char searchItem[50];
    int i = 0;
    int searchfound = 0;
    struct Record*temp;
    //getting input for search
    printf("Please enter Name, Surname or Polyclinic Name :\n");
    scanf("%s", searchItem);
    for(i = 0; i<26; i++){
        //traversing in hospital list
        if(hospitalList[i].firstRecordPtr != NULL){
            temp = hospitalList[i].firstRecordPtr;
            while(temp != NULL){
                //check for finding corresponding item
                if((strcmp(temp->name,searchItem) == 0) || (strcmp(temp->surname,searchItem) == 0) || (strcmp(temp->polyclinic,searchItem) == 0)){
                    printf("patient found: name: %s surname: %s personId: %d polyclinic: %s \n",temp->name , temp->surname, temp->personId, temp->polyclinic);
                    searchfound ++; //show if search find anything or not
                }
                temp = temp->nextRecord;
            }
        }
    }
    if(searchfound == 0){
        printf("Nothing found! \n");
    }
    else if (searchfound >= 1){
        printf("Total results are %d \n", searchfound);
    }
    printf("********* \n");
    printf("\n \n");
}

//Delete Function
void Delete(struct HospitalList hospitalList[]){
    //initialization and Declarations:
    char DeleteItem[50];
    int i = 0;
    struct Record*prev;
    struct Record*current;
    int isDeleted= 0; // will check if the operation will be done or not (will have value either 0 or 1)
    printf("Please enter Name, Surname or Polyclinic Name :\n");
    scanf("%s", DeleteItem);
    for(i = 0; i<26; i++){
        //traversing in hospital list
        if(hospitalList[i].firstRecordPtr != NULL){
            current = hospitalList[i].firstRecordPtr;
            while(current != NULL){
                //check for finding corresponding item
                if((strcmp(current->name,DeleteItem) == 0) || (strcmp(current->surname,DeleteItem) == 0) || (strcmp(current->polyclinic,DeleteItem) == 0)){
                    //conditions for deleting
                    printf("Patient found: name: %s surname: %s personId: %d polyclinic: %s \n",current->name , current->surname, current->personId, current->polyclinic);
                    //1.At the beginning of the linked list
                    if(current == hospitalList[i].firstRecordPtr){
                        current = hospitalList[i].firstRecordPtr;
                        hospitalList[i].firstRecordPtr = current->nextRecord;
                        current->nextRecord = NULL;
                        free(current);
                        printf("Patient Deleted successfully \n");
                        current= hospitalList[i].firstRecordPtr;
                        isDeleted = 1;
                    }
                    else{
                        //2.At the end of the linked list
                        if(current->nextRecord == NULL){
                            prev->nextRecord = NULL;
                            free(current);
                            printf("Patient Deleted successfully \n");
                            isDeleted = 1;
                        }
                            //3.At the Mid of the linked list
                        else{
                            prev->nextRecord = current->nextRecord;
                            current->nextRecord = NULL;
                            free(current);
                            printf("Patient Deleted successfully \n");
                            isDeleted = 1;
                        }
                    }
                    break;
                }
                prev->nextRecord = current;
                current = current->nextRecord;
            }
        }
    }
    //check if the operation was successful or not
    if(isDeleted == 0){
        printf("we could not find a Patient with %s specification \n", DeleteItem);
    }
    printf("********* \n");
    printf("\n \n");
}
//Traversing Function
void Traversing(struct HospitalList hospitalList[]){
    //initialization and Declarations:
    struct Record* temp;
    int i =0;
    int counter = 0;
    printf("Patients registered in the system: \n");
    //For loop in hospitalList Array
    for(i = 0;i<26;i++){
        if(hospitalList[i].firstRecordPtr != NULL){
            temp = hospitalList[i].firstRecordPtr;
            //While loop for each linked list
            while(temp != NULL){
                printf("name: %s surname: %s person ID: %d polyclinic: %s \n",temp->name, temp->surname, temp->personId, temp->polyclinic);
                temp = temp->nextRecord;
                counter ++;
            }
        }
    }
    printf("Total number of Patients :%d \n", counter);
    printf("********* \n");
    printf("\n \n");
}
//Sorting By name Function (Bubble Sort Method used)
void SortingByName(struct HospitalList hospitalList[]){
    //initialization and Declarations:
    int nodeCtr = 0;
    int numberOfNodes = 0;
    int ctr = 0;
    struct Record* currentNode;
    struct Record* nextNode;
    struct Record* RecordCounter;
    int i;
    //For loop in hospitalList Array
    for(i = 0; i < 26; i++){
        if((hospitalList[i].firstRecordPtr != NULL) && (hospitalList[i].firstRecordPtr->nextRecord != NULL)){
            numberOfNodes = 0;
            RecordCounter = hospitalList[i].firstRecordPtr;
            currentNode = hospitalList[i].firstRecordPtr;
            nextNode = nextNode->nextRecord;
            //numberOfNodes is the number of the nodes for each linkedList
            while(RecordCounter != NULL){
                numberOfNodes ++;
                RecordCounter = RecordCounter->nextRecord;
            }
            //Bubble Sort
            for(nodeCtr = numberOfNodes-2; nodeCtr>=0;nodeCtr--){
                currentNode= hospitalList[i].firstRecordPtr;
                nextNode = currentNode->nextRecord;
                for(ctr = 0; ctr<=nodeCtr; ctr++){
                    if(strcmp(currentNode->name, nextNode->name)>0){
                        swapFunction(currentNode,nextNode);
                    }
                    currentNode = nextNode;
                    nextNode = nextNode->nextRecord;
                }
            }
        }
    }
    printf("Sort By Name Completed Successfully\n");
    printf("********* \n");
    printf("\n \n");
}
//Main Swap function that is used for sorting sort functions
void swapFunction(struct Record* a,struct Record* b){
    char tempName[50];
    char tempSurname[50];
    int tempPersonId = 0;
    char tempPolyclinic[50];
    strcpy(tempName,a->name);
    strcpy(tempSurname,a->surname);
    strcpy(tempPolyclinic,a->polyclinic);
    tempPersonId = a->personId;
    strcpy(a->name,b->name);
    strcpy(a->surname,b->surname);
    strcpy(a->polyclinic,b->polyclinic);
    a->personId = b->personId;
    strcpy(b->name,tempName);
    strcpy(b->surname,tempSurname);
    strcpy(b->polyclinic,tempPolyclinic);
    b->personId = tempPersonId;
}
//Sorting By Surname Function (Bubble Sort Method used)
void SortingBySurname(struct HospitalList hospitalList[]){
    //initialization and Declarations:
    int nodeCtr = 0;
    int numberOfNodes = 0;
    int ctr = 0;
    struct Record* currentNode;
    struct Record* nextNode;
    struct Record* RecordCounter;
    int i = 0;
    //For loop in hospitalList Array
    for(i = 0; i < 26; i++){
        if((hospitalList[i].firstRecordPtr != NULL) && (hospitalList[i].firstRecordPtr->nextRecord != NULL)){
            numberOfNodes = 0;
            RecordCounter = hospitalList[i].firstRecordPtr;
            currentNode = hospitalList[i].firstRecordPtr;
            nextNode = nextNode->nextRecord;
            //numberOfNodes is the number of the nodes for each linkedList
            while(RecordCounter != NULL){
                numberOfNodes ++;
                RecordCounter = RecordCounter->nextRecord;
            }
            //Bubble Sort
            for(nodeCtr = numberOfNodes-2; nodeCtr>=0;nodeCtr--){
                currentNode= hospitalList[i].firstRecordPtr;
                nextNode = currentNode->nextRecord;
                for(ctr = 0; ctr<=nodeCtr; ctr++){
                    if(strcmp(currentNode->surname, nextNode->surname)>0){
                        swapFunction(currentNode,nextNode);
                    }
                    currentNode = nextNode;
                    nextNode = nextNode->nextRecord;
                }
            }
        }
    }
    printf("Sort By Surname Completed Successfully\n");
    printf("********* \n");
    printf("\n \n");
}
//Sorting By Polyclinic name Function (Bubble Sort Method used)
void SortingByPolyclinic(struct HospitalList hospitalList[]){
    //initialization and Declarations:
    int nodeCtr = 0;
    int numberOfNodes = 0;
    int ctr = 0;
    struct Record* currentNode;
    struct Record* nextNode;
    struct Record* RecordCounter;
    int i = 0;
    //For loop in hospitalList Array
    for(i = 0; i < 26; i++){
        if((hospitalList[i].firstRecordPtr != NULL) && (hospitalList[i].firstRecordPtr->nextRecord != NULL)){
            numberOfNodes = 0;
            RecordCounter = hospitalList[i].firstRecordPtr;
            currentNode = hospitalList[i].firstRecordPtr;
            nextNode = nextNode->nextRecord;
            //numberOfNodes is the number of the nodes for each linkedList
            while(RecordCounter != NULL){
                numberOfNodes ++;
                RecordCounter = RecordCounter->nextRecord;
            }
            //Bubble Sort
            for(nodeCtr = numberOfNodes-2; nodeCtr>=0;nodeCtr--){
                currentNode= hospitalList[i].firstRecordPtr;
                nextNode = currentNode->nextRecord;
                for(ctr = 0; ctr<=nodeCtr; ctr++){
                    if(strcmp(currentNode->polyclinic, nextNode->polyclinic)>0){
                        swapFunction(currentNode,nextNode);
                    }
                    currentNode = nextNode;
                    nextNode = nextNode->nextRecord;
                }
            }
        }
    }
    printf("Sort By polyclinic Completed Successfully\n");
    printf("********* \n");
    printf("\n \n");
}

