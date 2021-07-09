COORD c={0,0};
void gotoxy(int x,int y){
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}struct Contact{
    int sno,age;
    char category[20],name[20],gender,address[50],email[50],phn_n[20];
}cont;