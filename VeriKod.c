#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//Data of student node takes 2 values: school number and name
struct Student
{
    int schoolnumber;
    char name[100];
    struct Student *next;
    
};

//Define singly linked list's head and tail nodes
struct Student *head, *tail = NULL; 

//Function to push new student details to list
void insert(int schoolnumber, char* name)
{
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    student->schoolnumber = schoolnumber;
    //Assigns inputted name to student struct
    strcpy(student->name, name);
    student->next = NULL;
    
    if(head==NULL){
        // if head is NULL
        // set student as the new head
        head = student;
    }
    else{
        // if list is not empty
        // insert student in beginning of head
        student->next = head;
        head = student;
    }
    
}

//Func to remove a student by their number
void Delete(int schoolnumber)
{
    struct Student * temp1 = head;
    struct Student * temp2 = head; 
    //Searches through the list until the data of school number in the node matches the inputted school number
    while(temp1!=NULL){
        //If inputted school number matches a nodes school number
        if(temp1->schoolnumber==schoolnumber){
            if(temp1==temp2){
                // this condition will run if
                // the record that we need to delete is the first node
                // of the linked list
                head = head->next;
                //Remove student
                free(temp1);
            }
            else{
                // temp1 is the node we need to delete
                // temp2 is the node previous to temp1
                temp2->next = temp1->next;
                //Remove student
                free(temp1); 
            }
            printf("---Record Successfully Deleted---\n");
            return;
        }
        //Moves to the next node to search
        temp2 = temp1;
        temp1 = temp1->next;
    }
    //If no school number data in nodes matches the inputted school number
    printf("---Student with school number %d is not found---\n", schoolnumber);
}

//Func to print results
void display() {  
    struct Student *current = head;  
    if(head == NULL) {  
        printf("List is empty \n");  
        return;  
    }  
    while(current != NULL) {  
        printf("%d ", current->schoolnumber);
        printf("%s\n", current->name);
        current = current->next; 
    }  
    printf("\n");  
}

//Func to swap data between consecutive nodes
void swap(char *p,char *q)
{
    char t[50] = "";
    strcpy(t,p);
    strcpy(p,q);
    strcpy(q,t);
}

//Display the entered school numbers in ascending order according to the IDs
void displayID()
{
    struct Student *current = head, *index = NULL;
    int temp;
    //If list empty
    if(head == NULL) {
        return;  
    }
    //If list not empty  
    else{
        //Moves through the list until NULL  
        while(current != NULL) { 
            //Assigns a variable for the following node 
            index = current->next; 
            //While next node exists      
            while(index != NULL){ 
                //Math results in last 4 digits of number = ID
                //Checks if current ID is greater than next nodes ID
                //If it is greater it swaps the number and name data between nodes
                if(current->schoolnumber%10000 > index->schoolnumber%10000) {  
                    temp = current->schoolnumber; 
                    current->schoolnumber = index->schoolnumber;
                    swap(index->name,current->name);
                    index->schoolnumber = temp;
                }  
                index = index->next;  
            }  
            current = current->next;  
        }      
    }
    //Display ID's by ascending order
    display();
}

//Display the entered school numbers in ascending order according to the YEAR
void displayYEAR()
{
    struct Student *current = head, *index = NULL;
    int temp;
    //If list empty
    if(head == NULL) {
        return;  
    }
    //If list not empty  
    else{
        //Moves through the list until NULL  
        while(current != NULL) { 
            //Assigns a variable for the following node 
            index = current->next; 
            //While next node exists      
            while(index != NULL){ 
                //Math results in 4th and 5th digits of number = YEAR
                //Checks if current YEAR is greater than next nodes YEAR
                //If it is greater it swaps the number and name data between nodes
                if((current->schoolnumber%1000000)/10000 > (index->schoolnumber%1000000)/10000) {  
                    temp = current->schoolnumber; 
                    current->schoolnumber = index->schoolnumber;
                    swap(index->name,current->name);
                    index->schoolnumber = temp;
                }  
                index = index->next;  
            }  
            current = current->next;  
        }      
    }
    //Display YEARs by ascending order
    display();
}

//Display the entered school numbers in ascending order according to the Faculty Numbers
void displayFACULTY()
{
    struct Student *current = head, *index = NULL;
    int temp;
    //If list empty
    if(head == NULL) {
        return;  
    }
    //If list not empty  
    else{
        //Moves through the list until NULL  
        while(current != NULL) { 
            //Assigns a variable for the following node 
            index = current->next; 
            //While next node exists      
            while(index != NULL){ 
                //Math results in first 3 digits of number = Faculty Number
                //Checks if current Faculty Number is greater than next nodes Faculty Number
                //If it is greater it swaps the number and name data between nodes
                if(current->schoolnumber/1000000 > index->schoolnumber/1000000) {  
                    temp = current->schoolnumber; 
                    current->schoolnumber = index->schoolnumber;
                    swap(index->name,current->name);
                    index->schoolnumber = temp;
                }  
                index = index->next;  
            }  
            current = current->next;  
        }      
    }
    //Display Faculty Numbers by ascending order
    display();
}

int main()
{
    head = NULL;
    //Assign variables
    int choice;
    char name[100];
    int schoolnumber;
    printf("1 - Insert student details\n2 - Display sorted by ID\n3 - Display sorted by Year\n4 - Display sorted by Faculty Codes\n5 - Delete student details\n6 - Exit");
    //Do according to user input case
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter school number: ");
                scanf("%d", &schoolnumber);
                printf("Enter Name_Surname: ");
                scanf("%s", name);
                insert(schoolnumber, name);
                break;
            case 2:
                displayID();
                break;
            case 3:
                displayYEAR();
                break;
            case 4:
                displayFACULTY();
                break;
            case 5:
                printf("Enter school number to delete: ");
                scanf("%d", &schoolnumber);
                Delete(schoolnumber);
                break;
            case 6:
                exit(0);
        }
    } while (choice != 0);
}