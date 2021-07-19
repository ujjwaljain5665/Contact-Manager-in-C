//Search By Category.
void search_category(){
    FILE *fp;
    int i,found=0;
    char cat[20];
    system("cls");
    printf("Enter Category To Be Searched:");
    gets(cat);
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
    gotoxy(80,3);
    printf("Email");
    gotoxy(95,3);
    printf("Phone Number");

    fp=fopen("info.dat","rb");
    i=5;
    while(fread(&cont,sizeof(cont),1,fp)!=0){
        if(strcmpi(cont.category,cat)==0){
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
            gotoxy(80,i);
            printf("%s",cont.email);
            gotoxy(95,i);
            printf("%s",cont.phn_n);
            i++;
            found=1;
        }
    }
    if(found==0){
        system("cls");
        gotoxy(16,5);
        printf("Record Not Found Press any key to continue.");
        fclose(fp);
        getch();
        return;
    }
    fclose(fp);
    gotoxy(25,i+2);
    printf("Press Any Key To Continue");
    getch(); 
}

//Search By Name.
void search_name(){
    FILE *fp;
    int i,found=0;
    char nam[20];
    system("cls");
    printf("Enter Name To Be Searched:");
    gets(nam);
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
    gotoxy(80,3);
    printf("Email");
    gotoxy(95,3);
    printf("Phone Number");

    fp=fopen("info.dat","rb");
    i=5;
    while(fread(&cont,sizeof(cont),1,fp)!=0){
        if(strcmpi(cont.name,nam)==0){
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
            gotoxy(80,i);
            printf("%s",cont.email);
            gotoxy(95,i);
            printf("%s",cont.phn_n);
            i++;
            found=1;
        }
    }
    if(found==0){
        system("cls");
        gotoxy(16,5);
        printf("Record Not Found Press any key to continue.");
        fclose(fp);
        getch();
        return;
    }
    fclose(fp);
    gotoxy(25,i+2);
    printf("Press Any Key To Continue");
    getch(); 
}

//Search By Phone Number.
void search_phnno(){
    FILE *fp;
    int i,found=0;
    char phn[20];
    system("cls");
    printf("Enter Phone Number To Be Searched:");
    gets(phn);
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
    gotoxy(80,3);
    printf("Email");
    gotoxy(95,3);
    printf("Phone Number");

    fp=fopen("info.dat","rb");
    i=5;
    while(fread(&cont,sizeof(cont),1,fp)!=0){
        if(strcmpi(cont.phn_n,phn)==0){
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
            gotoxy(80,i);
            printf("%s",cont.email);
            gotoxy(95,i);
            printf("%s",cont.phn_n);
            i++;
            found=1;
        }
    }
    if(found==0){
        system("cls");
        gotoxy(16,5);
        printf("Record Not Found Press any key to continue.");
        fclose(fp);
        getch();
        return;
    }
    fclose(fp);
    gotoxy(25,i+2);
    printf("Press Any Key To Continue");
    getch(); 
}