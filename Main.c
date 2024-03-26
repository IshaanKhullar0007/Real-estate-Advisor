#include<stdio.h>
#include<string.h>
struct record{
    int id;
    char location[100];
    int cost;
    int area;
    int bhk;
}r;
void add_new_record(){
    int n;
    FILE *p;
    p=fopen("Database.txt","a");
    printf("Enter the Id of the property: ");
    scanf("%d",&r.id);
    printf("Enter the Location of the property: ");
    scanf("%s",r.location);
    printf("Enter the Cost of the property: ");
    scanf("%d",&r.cost);
    printf("Enter the Area of the property: ");
    scanf("%d",&r.area);
    printf("Enter the BHK of the property: ");
    scanf("%d",&r.bhk);
    fprintf(p,"%d %s %d %d %d\n",r.id,r.location,r.cost,r.area,r.bhk);
    fclose(p);
    printf("Record Added Successfully\n");
}

void display_the_property(){
    FILE *p;
    p=fopen("Database.txt","r");
    char c=fgetc(p);
    printf("\n");
    while(c != EOF){
        printf("%c",c);
        c=fgetc(p);
    }
    printf("\n");
}

void search(){
    FILE *p;
    p=fopen("Database.txt","r");
    char s[100];
    int found=0;
    printf("Enter location for the property: ");
    scanf("%s",s);
    while(fscanf(p,"%d %s %d %d %d\n",&r.id,r.location,&r.cost,&r.area,&r.bhk) != EOF){        
        if(strcmp(s,r.location)==0){
            printf("%d ",r.id);
            printf("%s ",r.location);
            printf("%d ",r.cost);
            printf("%d ",r.area);
            printf("%d\n",r.bhk);
            found=1;
        }
    }
    fclose(p);
    if(found==0)
        printf("No propertty at %s found\n",s);
}

void buy_or_sell(){
    int property,n;
    printf("1. Buy\n");
    printf("2. Sell\n");
    scanf("%d",&n);
    if(n==1){
    printf("Enter Id of property to buy: ");
    scanf("%d",&property);
    FILE *fp = fopen("Database.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    int found = 0;
    while (fscanf(fp, "%d %s %d %d %d\n",&r.id,r.location,&r.cost,&r.area,&r.bhk) != EOF){
        if (property!=r.id) {
            fprintf(temp, "%d %s %d %d %d\n",r.id,r.location,r.cost,r.area,r.bhk);
        } 
        else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    if (found==1) {
        remove("Database.txt");
        rename("temp.txt", "Database.txt");
        printf("\nProperty purchased successfully.\n");
    } 
    else {
        remove("temp.txt");
        printf("\nRecord not found.\n");
    }
    }
    else if(n==2){
        FILE *p;
        p=fopen("Database.txt","a");
        printf("Enter Id of the property to be added: ");
        scanf("%d",&r.id);
        printf("Enter the location of the property to be added: ");
        scanf("%s",r.location);
        printf("Enter the cost of the property to be added: ");
        scanf("%d",&r.cost);
        printf("Enter the area of the property to be added: ");
        scanf("%d",&r.area);
        printf("Enter the BHK of the property to be added: ");
        scanf("%d",&r.bhk);
        fprintf(p,"%d %s %d %d %d\n",r.id,r.location,r.cost,r.area,r.bhk);
        fclose(p);
        printf("Record Added Successfully\n");
    }
}

void edit_or_delete_record(){
    int n;
    printf("1. Edit record\n");
    printf("2. Delete record\n");
    scanf("%d",&n);
    if(n==1){
        int address;
        printf("Enter the Id to Update: ");
        scanf("%d",&address);
        FILE *fp = fopen("Database.txt", "r");
        FILE *temp = fopen("temp.txt", "w");
        int found = 0;
        while (fscanf(fp,"%d %s %d %d %d\n",&r.id,r.location,&r.cost,&r.area,&r.bhk) != EOF){
            if (address==r.id) {
                printf("Enter the New Location of the property: ");
                scanf("%s",r.location);
                printf("Enter the New Cost of the property: ");
                scanf("%d",&r.cost);
                printf("Enter the New Area of the property: ");
                scanf("%d",&r.area);
                printf("Enter the New BHK of the property: ");
                scanf("%d",&r.bhk);
                printf("Record Updated Successfully\n");
                found=1;
            }
            fprintf(temp,"%d %s %d %d %d\n",r.id,r.location,r.cost,r.area,r.bhk);
        }
        fclose(fp);
        fclose(temp);

        if (found) {
            remove("Database.txt");
            rename("temp.txt", "Database.txt");
            printf("\nRecord deleted successfully.\n");
        } 
        else {
            remove("temp.txt");
            printf("\nRecord not found.\n");
        }
    }
    else if(n==2){
        int address;
        printf("Enter the Id to delete: ");
        scanf("%d",&address);
        FILE *fp = fopen("Database.txt", "r");
        FILE *temp = fopen("temp.txt", "w");
        int found = 0;
        while (fscanf(fp, "%d %s %d %d %d\n",&r.id,r.location,&r.cost,&r.area,&r.bhk) != EOF){
            if (address!=r.id) {
                fprintf(temp, "%d %s %d %d %d\n",r.id,r.location,r.cost,r.area,r.bhk);
            } 
            else {
                found = 1;
            }
        }
        fclose(fp);
        fclose(temp);

        if (found) {
            remove("Database.txt");
            rename("temp.txt", "Database.txt");
            printf("\nRecord deleted successfully.\n");
        } 
        else {
            remove("temp.txt");
            printf("\nRecord not found.\n");
        }
    }
}

void apply_loans(){
    printf("\t\tHere's the list of Banks for Loans\n");
    printf("    \tName\tRate of Interest\tContact\n");
    printf("1.  \tSBI\t\t7%\t\t628 045 899\n");
    printf("2.  \tPNB\t\t8%\t\t973 244 8360\n");
    printf("3.  \tAxis\t\t7.7%\t\t954 657 4560\n");
    printf("4.  \tHDFC\t\t9%\t\t887 451 4787\n");
    printf("5.  \tUjjivan\t\t11%\t\t789 478 4567\n");
    printf("6.  \tOBC\t\t6%\t\t784 444 5654\n");
    printf("7.  \tDCB\t\t12.1%\t\t998 741 2450\n");
    printf("\n");
}

int main(){
    int choice;
    printf("\t\t\tWelcome to the Modern World\n");
    printf("Please select the option\n");
    while(1){
    printf("1. Add New Record\n");
    printf("2. Display the Property\n");
    printf("3. Search\n");
    printf("4. Buy or Sell\n");
    printf("5. Edit or Delete Record\n");
    printf("6. Apply Loans\n");
    printf("7. Exit...\n");
    scanf("%d",&choice);
    if(choice==1)
        add_new_record();
    else if(choice==2)
        display_the_property();
    else if(choice==3)
        search();
    else if(choice==4)
        buy_or_sell();
    else if(choice==5)
        edit_or_delete_record();
    else if(choice==6)
        apply_loans();
    else if(choice==7){
        printf("Bye...");
        printf("Sayonara...");
        break;
        }
    else
        printf("Invalid Choice\n");
    }
}