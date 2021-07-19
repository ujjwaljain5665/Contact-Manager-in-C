#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include"struc.h"
#include"search.h"

//Functions Used.
void add_contact();
void list_contact();
void del_contact();
void edit_contact();
void search_contact();
void change_pass();

//Main Function.
void main(){
    char entered_pass[30],ch,original_pass[30],choice;
    int i;
    FILE *fp;
    system("cls");
    system("color 06");
    gotoxy(35,13);
    printf("****************************************");
    gotoxy(35,17);
    printf("****************************************");
    gotoxy(35,14);
    printf("*");
    gotoxy(35,15);
    printf("*");
    gotoxy(35,16);
    printf("*");

    gotoxy(74,14);
    printf("*");
    gotoxy(74,15);
    printf("*");
    gotoxy(74,16);
    printf("*");

    gotoxy(40,15);
    printf("Enter The Password:");
    i=0;
    while(1){
        ch=getch();
        if(ch==13){ //ASCII value of 'ENTER KEY'.
            entered_pass[i]='\0';
            break;
        }
        entered_pass[i]=ch;
        i++;
        printf("*");
    }
    // Cheking Password From file.
    fp=fopen("password.dat","r");
    fgets(original_pass,30,fp);
    fclose(fp);
    if(!strcmp(original_pass,entered_pass)==0){
        system("cls");
        gotoxy(35,15);
        printf("Incorrect Password Press Any Key To Exit..");
        getch();
        exit(0);
    }
    else{
        system("color 47");
        system("cls");
        gotoxy(40,12);
        printf("----------------------------");
        gotoxy(46,14);
        printf("Contact Manager");
        gotoxy(46,16);
        printf("Version : 1.0");
        gotoxy(46,18);
        printf("By - Ujjwal Jain");
        gotoxy(40,20);
        printf("----------------------------");
        gotoxy(30,22);
        printf("Please Wait:");
        for(i=0;i<30;i++){
            printf("%c",220);
            Sleep(50);
        }

        //Main Menu

        while(1){
            system("cls");
            system("color d0");
            gotoxy(43,1);
            printf("***Main Menu***");
            gotoxy(36,3);
            printf("----------------------------");
            gotoxy(40,5);
            printf("1.ADD NEW CONTACT");
            gotoxy(40,6);        
            printf("2.DELETE CONTACT");
            gotoxy(40,7);        
            printf("3.EDIT CONTACT");
            gotoxy(40,8);        
            printf("4.SEARCH CONTACT");
            gotoxy(40,9);        
            printf("5.LIST CONTACT");
            gotoxy(40,10);        
            printf("6.CHANGE PASSWORD");
            gotoxy(40,11);        
            printf("7.EXIT");
            gotoxy(36,13);
            printf("----------------------------");
            gotoxy(39,14);
            printf("ENTER YOUR CHOICE (1-7): ");
            choice=getche();
            switch(choice){
                case '1':
                    add_contact();
                    break;
                case '2':
                    del_contact();
                    break;
                case '3':
                    edit_contact();
                    break;
                case '4':
                    search_contact();
                    break;
                case '5':
                    list_contact();
                    break;
                case '6':
                    change_pass();
                    break;
                case '7':
                    system("cls");
                    system("color b0");
                    gotoxy(50,20);
                    printf("Exited");
                    exit(0);
                default:
                    system("cls");
                    gotoxy(18,5);
                    printf("...Inalid Choice...Program Terminated!!");
                    exit(0);
            }
        }
    }
    getch();
}

//Function To Change Password.
void change_pass(){
    FILE *fp;
    char current_pass[20],original_pass[20],new_pass[20],confirm_pass[20];
    system("cls");
    gotoxy(48,15);
    printf("Change Password");
    gotoxy(35,17);
    printf("****************************************");
    gotoxy(35,24);
    printf("****************************************");
    fflush(stdin);
    gotoxy(38,19);
    printf("Enter The Current Password:");
    gets(current_pass);
    fp=fopen("password.dat","r");
    fgets(original_pass,20,fp);
    fclose(fp);
    if(strcmp(current_pass,original_pass)!=0){
        system("cls");
        gotoxy(32,19);
        printf("Incorrect Password Please Check Your Password and Try Again.");
        gotoxy(35,20);
        printf("Press any key to continue.");
        getch();
        return;
    }
    gotoxy(38,21);
    printf("Enter New Password:");
    gets(new_pass);
    gotoxy(38,22);
    printf("Re-Enter Password:");
    gets(confirm_pass);
    if(strcmp(new_pass,confirm_pass)!=0){
        gotoxy(33,26);
        printf("Password Doesn't Match..Press any key to continue.");
        getch();
        return;
    }
    fp=fopen("password.dat","w");
    fprintf(fp,"%s",new_pass);
    fclose(fp);
    gotoxy(33,26);
    printf("Password Changed Successfully...Press any key to continue.");
    getch();
}
//Function To Search Contacts.
void search_contact(){
    char choice;
    system("cls");
    system("color bf");
    gotoxy(46,5);
    printf("***Search Options***");
    gotoxy(28,7);
    printf("-----------------------------------------------------------");
    gotoxy(28,13);
    printf("-----------------------------------------------------------");
    gotoxy(44,9);
    printf("1.Search By Category");
    gotoxy(44,10);
    printf("2.Search By Name");
    gotoxy(44,11);
    printf("3.Search By Phone Number");
    gotoxy(44,12);
    printf("4.Back To Main Menu");
    gotoxy(44,14);
    printf("Enter Your Choice :");
    choice=getche();
    switch(choice){
        case '1':
            search_category();
            break;
        case '2':
            search_name();
            break;
        case '3':
            search_phnno();
            break;
        case '4':
            return;
        default:
            system("cls");
            gotoxy(18,5);
            printf("...Invalid Choice...Press any key to continue.");
            getch();
            return;
    }
}
//Function To Add Contacts.
void add_contact(){
    system("cls");
    system("color 90");
    FILE *fp;
    gotoxy(42,1);
    printf("ADD NEW CONTACT");
    gotoxy(18,2);
    printf("********************************************************************");
    gotoxy(18,13);
    printf("********************************************************************");
    fflush(stdin);
    gotoxy(21,5);
    printf("ENTER CATEGORY (Friend/PG/Student/Customer/Salesman) :");
    gets(cont.category);
    fflush(stdin);
    gotoxy(21,6);
    printf("ENTER NAME:");
    gets(cont.name);
    fflush(stdin);
    gotoxy(21,7);
    printf("ENTER GENDER (M/F) :");
    scanf("%c",&cont.gender);
    fflush(stdin);
    gotoxy(21,8);
    printf("ENTER AGE:");
    scanf("%d",&cont.age);
    fflush(stdin);
    gotoxy(21,9);
    printf("ENTER ADDRESS:");
    gets(cont.address);
    fflush(stdin);
    gotoxy(21,10);
    printf("ENTER EMAILID:");
    gets(cont.email);
    fflush(stdin);
    gotoxy(21,11);
    printf("ENTER PHONE NUMBER:");
    gets(cont.phn_n);
    fflush(stdin);

    fp=fopen("info.dat","ab");
    fwrite(&cont,sizeof(cont),1,fp);
    fclose(fp);
    system("cls");
    gotoxy(32,15);
    printf("CONTACT SAVED SUCCESSFULLY...Press Any Key to Continue");
    getch();
}
//Function To List All Contacts.
void list_contact(){
    FILE *fp;
    int size,i,j;
    system("cls");
    system("color e0");
    fp=fopen("info.dat","rb");
    fseek(fp, 0, SEEK_END);
    size=ftell(fp);
    fclose(fp);
    if(size==0){
        gotoxy(15,2);
        printf("No records found");
        getch();
        return;
    }
    gotoxy(0,2);
    printf("----------------------------------------------------------------------------------------------------------------------");
    gotoxy(43,1);
    printf("LIST OF  CONTACTS");
    gotoxy(1,3);
    printf("S.no");
    gotoxy(8,3);
    printf("Category");
    gotoxy(20,3);
    printf("Name");
    gotoxy(40,3);
    printf("Gender");
    gotoxy(50,3);
    printf("Age");
    gotoxy(60,3);
    printf("Address");
    gotoxy(85,3);
    printf("Email");
    gotoxy(105,3);
    printf("Phone Number");

    fp=fopen("info.dat","rb");
    i=5;
    j=1;
    while(fread(&cont,sizeof(cont),1,fp)!=0){
        gotoxy(1,i);
        printf("%d",j);
        gotoxy(8,i);        
        printf("%s",cont.category);
        gotoxy(20,i);
        printf("%s",cont.name);
        gotoxy(40,i);
        printf("%c",cont.gender);
        gotoxy(50,i);
        printf("%d",cont.age);
        gotoxy(60,i);
        printf("%s",cont.address);
        gotoxy(85,i);
        printf("%s",cont.email);
        gotoxy(105,i);
        printf("%s",cont.phn_n);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(0,i);
    printf("----------------------------------------------------------------------------------------------------------------------");
    gotoxy(35,i+1);
    printf("Press Any Key To Continue");
    getch(); 
}
//Function To Delete Contacts.
void del_contact(){
    int found=0;
    char choice,name[20];
    FILE *fp1,*fp2;
    system("cls");
    system("color 4f");
    gotoxy(18,3);
    printf("********************************************************************");
    gotoxy(18,14);
    printf("********************************************************************");
    gotoxy(38,1);
    printf("Delete Contacts");
    gotoxy(36,5);
    printf("Enter Name To Be Deleted:");
    gets(name);
    fp1=fopen("info.dat","rb");
    while(fread(&cont,sizeof(cont),1,fp1)!=0){
        if(strcmpi(cont.name,name)==0){
            gotoxy(37,6);
            printf("Category:%s",cont.category);
            gotoxy(37,7);
            printf("Name    :%s",cont.name);
            gotoxy(37,8);
            printf("Gender  :%c",cont.gender);
            gotoxy(37,9);
            printf("Age     :%d",cont.age);
            gotoxy(37,10);
            printf("Address :%s",cont.address);
            gotoxy(37,11);
            printf("Email   :%s",cont.email);
            gotoxy(37,12);
            printf("Phone No:%s",cont.phn_n);
            found=1;
            break;
        }
    }
    if(found==0){
        system("cls");
        gotoxy(36,16);
        printf("Record Not Found....");
        getch();
        fclose(fp1);
        return;
    }
    rewind(fp1);
    gotoxy(35,19);
    printf("Are You Sure To Delete (Y/N) :");
    choice=getche();
    if(choice=='y'||choice=='Y'){
        fp2=fopen("temp.dat","wb");
        while(fread(&cont,sizeof(cont),1,fp1)!=0){
            if(strcmpi(cont.name,name)!=0){
                fwrite(&cont,sizeof(cont),1,fp2);
            }
        }
        fclose(fp2);
        fclose(fp1);
        remove("info.dat");
        rename("temp.dat","info.dat");
        system("cls");
        gotoxy(26,21);
        printf("Contact Deleted Successfully Press Any Key To Continue.");
        getch();
    }
    else if(choice=='n'||choice=='N'){
        fclose(fp1);
        gotoxy(37,21);
        printf("Deletion Terminated.");
        getch();
    }
}
//Function To Edit Contacts.
void edit_contact(){
    FILE *fp;
    int pos,found=0;
    char name[20];
    system("cls");
    system("color a0");
    gotoxy(46,1);
    printf("***Edit Contacts***");
    gotoxy(28,2);
    printf("-----------------------------------------------------------");
    gotoxy(40,3);
    printf("Enter Name to be edited:");
    gets(name);
    fp=fopen("info.dat","r+b");
    while(fread(&cont,sizeof(cont),1,fp)!=0){
        if(strcmpi(cont.name,name)==0){
            found=1;
            gotoxy(46,5);
            printf("Category:%s",cont.category);
            gotoxy(46,6);
            printf("Name    :%s",cont.name);
            gotoxy(46,7);
            printf("Gender  :%c",cont.gender);
            gotoxy(46,8);
            printf("Age     :%d",cont.age);
            gotoxy(46,9);
            printf("Address :%s",cont.address);
            gotoxy(46,10);
            printf("Email   :%s",cont.email);
            gotoxy(46,11);
            printf("Phone No:%s",cont.phn_n);
            gotoxy(28,12);
            printf("-----------------------------------------------------------");
            break;
        }
    }
    if(found==0){
        system("cls");
        gotoxy(34,10);
        printf("Record Not Found...Press any key to continue");
        fclose(fp);
        getch();
        return;
    }
    pos=ftell(fp);
    fseek(fp,pos-sizeof(cont),SEEK_SET);
    gotoxy(43,14);
    printf("***Enter New Details***");
    gotoxy(26,15);
    printf("---------------------------------------------------------------");
    gotoxy(26,24);
    printf("---------------------------------------------------------------");
    fflush(stdin);
    gotoxy(28,16);
    printf("ENTER CATEGORY(Friend/PG/Student/Customer/Salesman):");
    gets(cont.category);
    fflush(stdin);
    gotoxy(28,17);
    printf("ENTER NAME:");
    gets(cont.name);
    fflush(stdin);
    gotoxy(28,18);
    printf("ENTER GENDER (M/F) :");
    scanf("%c",&cont.gender);
    fflush(stdin);
    gotoxy(28,19);
    printf("ENTER AGE:");
    scanf("%d",&cont.age);
    fflush(stdin);
    gotoxy(28,20);
    printf("ENTER ADDRESS:");
    gets(cont.address);
    fflush(stdin);
    gotoxy(28,21);
    printf("ENTER EMAILID:");
    gets(cont.email);
    fflush(stdin);
    gotoxy(28,22);
    printf("ENTER PHONE NUMBER:");
    gets(cont.phn_n);
    fflush(stdin);
    fwrite(&cont,sizeof(cont),1,fp);
    fclose(fp);
    gotoxy(33,25);
    printf("Contact Edited Successfully Press Any Key To Continue.");
    getch();
}