#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<ctype.h>


struct train
{

      //220
    char from[100];
    char destination[100];
    char nameoftrain[100];
    char offday[100];
    char departure[100];
    char arrival[100];
};
struct train node[10000];

struct Trains
{

    char nameoftrain[50];
    char from[50];
    char destination[50];
    int Shuvon_chair;
    int Snigdha;
    int Ac_seat;
    int Ac_Birth;
    int First_chair;
    int First_Birth;
    int First_Seat;
    int Shuvon;
    int sulov;

};
struct Trains node2[10000];



struct User
{

    char date[100];
    char phn[20];
    char secret_code[20];
    char start[100];
    char destination[100];
    char train[100];
    char clss[100];
    int passengers;
    int total_fare;

};
struct User user;


struct Classs
{
    char clss[20];
};
struct Classs classs[11];

void waitFor (unsigned int secs) {
    time_t retTime;
    retTime = time(0) + secs;
    while (time(0) < retTime);
}

char s2[100];
char s3[100];
char send_date[100],current_day_name[10];
int days[10],months[10],years[10],count=0,delet;

int date_range(char *date)
{
    int n;
    //char date[100];
   // gets(date);
    n=strstr(date,"Jan")-date;
    if(n>=0) return 1;
    else if((strstr(date,"Feb")-date)>=0)return 2;
    else if((strstr(date,"Mar")-date)>=0)return 3;
    else if((strstr(date,"Apr")-date)>=0)return 4;
    else if((strstr(date,"May")-date)>=0)return 5;
    else if((strstr(date,"Jun")-date)>=0)return 6;
    else if((strstr(date,"Jul")-date)>=0)return 7;
    else if((strstr(date,"Aug")-date)>=0)return 8;
    else if((strstr(date,"Sep")-date)>=0)return 9;
    else if((strstr(date,"Oct")-date)>=0)return 10;
    else if((strstr(date,"Nov")-date)>=0)return 11;
    else if((strstr(date,"Dec")-date)>=0)return 12;

}



void next5_days(int a,int b,int c)
{

    int d,e,f,g;
    count++;
    d=a+1;
    e=b+1;
    f=c+1;
    g=1;
    if(a==28 && b==2 && c%4==0){

       days[count]=d;
       months[count]=b;
       years[count]=c;
    }
    else if(a==29 && b==2 && c%4==0){

         days[count]=g;
       months[count]=e;
       years[count]=c;

    }

    else if(a==28 && b==2){
             days[count]=g;
       months[count]=e;
       years[count]=c;
    }

    else if(a==31 && b==12){

             days[count]=g;
       months[count]=g;
       years[count]=f;

    }
    else if(a==30 && b!=1 && b!=3 && b!=5 && b!=7 && b!=8 && b!=10 && b!=12){

              days[count]=g;
       months[count]=e;
       years[count]=c;

    }
    else if(a<=30 && b<=12 ){


              days[count]=d;
       months[count]=b;
       years[count]=c;
    }

    else if(a==31 && b<12){


              days[count]=g;
       months[count]=e;
       years[count]=c;
    }
    else if(a<31 && b<12){


              days[count]=d;
       months[count]=b;
       years[count]=c;
    }



    if(count<5){

        next5_days(days[count],months[count],years[count]);
    }



}




int Date(char date[])
{

    int a,b,c,d,e,f,g;
    char s1_day[5],s2_month[5],s3_year[10];
    strncpy(s1_day,date,2);
    strncpy(s2_month,date+2,2);
    strncpy(s3_year,date+4,4);

    a=atoi(s1_day);
    b=atoi(s2_month);
    c=atoi(s3_year);
    d=a+1;
    e=b+1;
    f=c+1;
    g=1;

    if(a>29 && b==2 && c%4==0)return 0;
    else if(a>28 && b==2)return 0;
    else if(a>=31 && b<12 && b!=1 && b!=3 && b!=5 && b!=7 && b!=8 && b!=10 && b!=12)return 0;
    else if(a>31 || b>12) return 0;
    else return 1;
}



void times()
{
    int d,e=0;
    char s[100],temp;
    time_t current_time;
    current_time=time(NULL);
    strcpy(s,ctime(&current_time));
    strcpy(s3,ctime(&current_time));
    strcat(s3,"\0");
    temp=s[0];
    s[0]=s[1];
    s[1]=temp;
    temp=s[3];
    s[3]=s[5];
    s[5]=temp;
    for(d=0;d<strlen(s);d++){
        if(s[d]!=' ' && s[d]!=':') {
                s2[e]=s[d];
                if(isalpha(s2[e]) && islower(s2[e])) s2[e]=toupper(s2[e]);
                e++;
        }
    }
    if(s2[0]=='O') s2[0]='W';
    if(s2[1]=='O') s2[1]='W';
    if(s2[2]=='O') s2[2]='W';
    if(s2[3]=='O') s2[3]='W';
    if(s2[4]=='O') s2[4]='W';
    if(s2[5]=='O') s2[5]='W';
    s2[e]='\0';


}


char train1[100][100],ss[100][20],train_name[100][20],train_offday[20][10],train_starting_time[20][20];
FILE *f1, *f2,*f3,*f4,*f5,*f6,*f7,*f8,*f9,*f10,*f11,*f12,*f13,*f14,*f15,*f16;
int i,k,nam,found=0;

void search(char *sear1, char *sear2)
{
    int j;
    char s1[100],s2[100];
    strcpy(s1,sear1);
    strcpy(s2,sear2);
    j=0;
    k=1;
    nam=0;
    for(j=0;j<i;j++){
        if(strcmp(s1,node[j].from)==0 && strcmp(s2,node[j].destination)==0){
            if(k==1 )
                printf("\n    Serial          Name         Offday     departure      Arrival\n\n");
            printf("%8d.    %12s      %8s    %8s      %8s\n",k,node[j].nameoftrain,node[j].offday,node[j].departure,node[j].arrival);
            strcpy(train_name[k],node[j].nameoftrain);
            strcpy(train_offday[k],node[j].offday);
            strcpy(train_starting_time[k],node[j].departure);


            k++;
        }
    }

    printf("\n%d. Main menu\n",k);
    printf("%d. Exit\n\n",k+1);
}




int main()
{
     //SetColor(42);
     system("COLOR A");
    f1=fopen("trains.txt","a+");
    f2=fopen("Destination.txt","r");
    f3=fopen("user.txt","a+");
    f4=fopen("class.txt","r");
    f5=fopen("password.txt","r+");
    f6=fopen("seatsavailable.txt","a+");
   // f7=fopen("seatsfilledup.txt","r+");
    f8=fopen("fare.txt","a+");
    f9=fopen("classname.txt","r");
    f10=fopen("seatsfilledup2.txt","w+");
    f12=fopen("password2.txt","w+");
    f13=fopen("filename.txt","a+");
    if(ferror(f1)){
            printf("          ERROR\n");
            return 0;
    }
    if(ferror(f2)){
            printf("          ERROR\n");
            return 0;
    }
    if(ferror(f3)){
            printf("          ERROR\n");
            return 0;
    }
     if(ferror(f4)){
            printf("          ERROR\n");
            return 0;
    }
     if(ferror(f5)){
            printf("          ERROR\n");
            return 0;
    }
     if(ferror(f6)){
            printf("          ERROR\n");
            return 0;
    }
     if(ferror(f9)){
            printf("          ERROR\n");
            return 0;
    }
     if(ferror(f8)){
            printf("          ERROR\n");
            return 0;
    }

    char admin_password[100],date_user[50],times_user[300],times_user_hour[10],times_user_minute[3],times_user_second[3],current_date[20],user_date[20];
    int j,clss,train,choice1,m,choice2,confirm,number_of_trains;
    char dest[100],desti[100],dep[100],contact[20],trainch[100],selected_train[20],day[5],month[5],year[5],date[20],password[100];
    char filename[10][15],date_name[10][15],day_name[10],month_name[10],year_name[10],filenames[20][20];

    int r,q;
    printf("\n\n\n\n\n\n\n\n\n\n\n                                      LOADING");
    printf("\n\n                                ");
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++);
        printf("*");
    }
    //waitFor(3);
    if (system("CLS")) system("clear");
    i=0;
    do{
        fscanf(f1,"%s %s %s %s %s %s",&node[i].from,&node[i].destination,&node[i].nameoftrain,&node[i].offday,&node[i].departure,&node[i].arrival);
        i++;
    }while(!feof(f1));
    number_of_trains=i;
    fseek(f1,0,0);


    system("COLOR CF");
    printf("\n\n\n\n------------------------------------------------------------------------------\n");
    printf("\n                           .....WELCOME.....\n");
    printf("                                  TO\n");
    printf("                           BANGLADESH RAILWAY\n");
    printf("------------------------------------------------------------------------------\n");

    waitFor(3);

    if (system("CLS")) system("clear");
    system("COLOR B");


        printf("\n*******************************************************************************\n");
        printf("                  .....   .....                                   \n");
        printf("                  ||   \\  ||   \\                                \n");
        printf("                  ||   /  ||__ /                                   \n");
        printf("                  ||   \\  ||   \\                                  \n");
        printf("                  ||.../  ||   |                                  \n\n");

        printf("                BANGLADESH RAILWAY\n                                \n");
        printf("--------------------------------------------------------------------------------    \n");
        printf("--------------------------------------------------------------------------------  \n");

        //waitFor(3);

        //

        main_menu:

        {
            int buy_ad,user_hour,user_minute,user_second,user_total_seconds,selected_train_hours,selected_train_minutes,total_seconds_selected_train;
                char date_file_name[20],selected_train_offday[20],selected_train_starting_time[20],selected_train_hour[10],selected_train_minute[20];

                printf("\n1. Buy ticket\n2. Admin\n\n\n0. Exit\n\n");
                scanf("%d",&buy_ad);
                if(buy_ad!=1 && buy_ad!=2){
                    return 0;
                }
                else if(buy_ad==1){
                                if (system("CLS")) system("clear");
                                system("COLOR A");
                                int date_check;

                                times();
                                //printf("%s\n",s3);
                                s3[strlen(s3)-1]='\0';
                                strncpy(times_user,s3+11,8);
                                times_user[8]='\0';


                                strncpy(times_user_hour,times_user,2);
                                times_user_hour[2]='\0';

                                strncpy(times_user_minute,times_user+3,2);
                                times_user_minute[2]='\0';
                                user_minute=atoi(times_user_minute);
                                strncpy(times_user_second,times_user+6,2);
                                times_user_second[2]='\0';
                                user_second=atoi(times_user_second);


                                user_hour=atoi(times_user_hour);


                                user_total_seconds=user_hour*3600+user_minute*60+user_second;

                               if(user_hour<9 || user_hour>23 || (user_hour==23 && (user_minute>0 || user_second>0))){

                                     if (system("CLS")) system("clear");
                                    system("COLOR C");
                                    printf("\n\n\n\n         Ticket is available only from 9 am to 11 pm\n");
                                    printf("                    Your Time is %s\n",times_user);
                                    printf("\n                         TRY LATER\n\n\n\n\n");
                                    printf("                         THANK YOU\n\n\n\n");
                                   // waitFor(5);
                                    return 0;

                                }



                enterdate:
                        {
                             printf("\nEnter Journey Date:\n\n");
                             printf("dd mm yyyy\n");

                             scanf("%s %s %s",&day,&month,&year);
                             if(strlen(day)!=2 || strlen(month)!=2 || strlen(year)!=4){
                                     if (system("CLS")) system("clear");
                                     system("COLOR C");
                                     printf("\n\n\n            Enter date & month with 2 digits & Year with 4 Digits\n\n");
                                     waitFor(4);
                                     if (system("CLS")) system("clear");
                                     system("COLOR A");

                                    goto enterdate;

                             }

                             strcpy(date,day);
                             strcat(date,month);
                             strcat(date,year);
                             date_check=Date(date);
                             if(date_check==0){

                                if (system("CLS")) system("clear");
                                system("COLOR C");
                                printf("\n\n                               Invalid date!!!\n");
                                printf("                              Enter Date Again\n\n\n\n\n\n\n\n");
                                waitFor(3);
                                if (system("CLS")) system("clear");
                                system("COLOR A");
                                goto enterdate;
                             }

                             char currentday[10],currentyear[10],currentmonth[10];
                             int current_month, current_day,current_year,input_month,input_day,input_year;
                             times();

                             current_month=date_range(s3);

                             strncpy(current_day_name,s3,3);
                             if(islower(current_day_name[0])) current_day_name[0]=toupper(current_day_name[0]);
                             if(islower(current_day_name[1])) current_day_name[1]=toupper(current_day_name[1]);
                             if(islower(current_day_name[2])) current_day_name[2]=toupper(current_day_name[2]);
                             strcat(current_day_name,"DAY");

                             itoa(current_month,currentmonth,10);

                             strncpy(currentday,s2+6,2);
                             strncpy(currentyear,s2+14,4);
                             currentday[2]='\0';
                             current_day=atoi(currentday);
                             currentyear[4]='\0';
                             current_year=atoi(currentyear);
                             input_day=atoi(day);
                             input_year=atoi(year);
                             input_month=atoi(month);

                             strcpy(user_date,day);
                             strcat(user_date,month);
                             strcat(user_date,year);

                             days[0]=current_day;
                             months[0]=current_month;
                             years[0]=current_year;
                             strcpy(current_date,currentday);
                             strcat(current_date,currentmonth);
                             strcat(current_date,currentyear);
                             printf("current year is %d\n",current_year);
                             next5_days(current_day,current_month,current_year);

                             int i,check=0,y=0;
                             printf("%d %d %d\n\n",input_day,input_month,input_year);
                             for(i=0;i<6;i++){
                                 //printf("%d %d %d\n",days[i],months[i],years[i]);
                                    itoa(days[i],day_name,10);
                                    itoa(months[i],month_name,10);
                                    itoa(years[i],year_name,10);
                                    strcpy(date_name[i],day_name);
                                    strcat(date_name[i],month_name);
                                    strcat(date_name[i],year_name);
                                   // puts(date_name[i]);

                                 if(input_day==days[i] && input_month==months[i] && input_year==years[i]){

                                    check++;
                                    //break;
                                 }
                             }


                             do{
                                fscanf(f13,"%s",&filename[y]);
                                y++;
                             }while(!feof(f13));

                             //return 0;
                             if(check==0){
                                if (system("CLS")) system("clear");
                                    system("COLOR C");
                                    printf("       Ticket is Available only for today && next 5 days\n");
                                    printf("                              ENTER DATE AGAIN\n\n\n\n\n\n\n\n");
                                    waitFor(5);
                                    if (system("CLS")) system("clear");
                                    system("COLOR A");
                                    goto enterdate;

                             }

                        }
                        strcpy(date_file_name,date);
                        strcat(date_file_name,".txt");

/////// new edit from here

                        fseek(f13,0,0);
                        char File_Names[20];
                        char initial_name[50];
                        int initial_seat[10];
                        int fcount=0;
                        while(!feof(f13)){
                            fscanf(f13,"%s",&File_Names);
                            if(strcmp(date,File_Names)==0) fcount++;

                        }

                        if(fcount==0){

                            f14=fopen(date_file_name,"w+");
                            f15=fopen("initialseats.txt","r");
                            fseek(f15,0,0);
                            while(!feof(f15)){
                                fscanf(f15,"%s %d %d %d %d %d %d %d %d %d",&initial_name,&initial_seat[0],&initial_seat[1],&initial_seat[2],&initial_seat[3],&initial_seat[4],&initial_seat[5],&initial_seat[6],&initial_seat[7],&initial_seat[8]);
                                fprintf(f14,"%s %d %d %d %d %d %d %d %d %d\n",initial_name,initial_seat[0],initial_seat[1],initial_seat[2],initial_seat[3],initial_seat[4],initial_seat[5],initial_seat[6],initial_seat[7],initial_seat[8]);

                            }

                            fprintf(f13,"%s\n",date);

                            fclose(f14);
                            fclose(f15);

                        }






//////new edit up to here

                       f7=fopen(date_file_name,"r");



                       if (system("CLS")) system("clear");
                       system("COLOR B");

                step1: //starting point
                    {
                     printf("\nSelect starting point from below:                        \n\n");
                     printf("1. DHAKA\n2. CHITTAGONG\n3. RAJSHAHI\n4. MYMENSINGH\n5. KHULNA\n6. SYLHET\n7. Exit\n\n");
                     scanf("%d",&choice1);
                     if(choice1==1) strcpy(dep,"DHAKA");
                     else if(choice1==2) strcpy(dep,"CHITTAGONG");
                     else if(choice1==3) strcpy(dep,"RAJSHAHI");
                     else if(choice1==4) strcpy(dep,"MYMENSINGH");
                     else if(choice1==5) strcpy(dep,"KHULNA");
                     else if(choice1==6) strcpy(dep,"SYLHET");
                     else if(choice1==7) {
                            if (system("CLS")) system("clear");
                            system("COLOR A");
                            printf("\n\n                               THANK YOU\n\n\n\n\n");
                            return 0;
                     }
                     else {
                            if (system("CLS")) system("clear");
                            system("COLOR C");
                            printf("                      Wrong key!!!\n                      Enter again\n\n");
                            waitFor(2);
                            if (system("CLS")) system("clear");
                            system("COLOR B");
                            goto step1;

                     }

                     if (system("CLS")) system("clear");
                     system("COLOR A");
                }

                step2:// Destination
                    {
                        //found=0;
                     printf("\nEnter the first three letters  of your Destination:\n (Enter 1 to go back to Main Menu)\n (Enter 0 to exit)\n\n");
                     scanf("%s",&dest);
                     if(strcmp(dest,"1")==0){
                            if (system("CLS")) system("clear");
                            system("COLOR B");
                        goto main_menu;
                     }
                     else if(strcmp(dest,"0")==0) {
                            if (system("CLS")) system("clear");
                            system("COLOR A");
                            printf("\n\n                            THANK YOU\n\n\n\n\n");
                            return 0;

                     }
                     for(m=0;m<3;m++){
                            if(islower(dest[m])) dest[m]=toupper(dest[m]);
                     }
                     if (system("CLS")) system("clear");
                     system("COLOR D");


              // select destination

                        fseek(f2,0,0);
                        int s=1,x=0,count11,j;
                        char st[100][100]={0};
                        for(k=0;k<i;k++){

                            count11=0;
                            if(strcmp(dep,node[k].from)==0 && strncmp(node[k].destination,dest,3)==0){
                                    for(j=1;j<=s;j++){
                                        if(strcmp(ss[j],node[k].destination)==0) count11++;
                                    }
                                    if(count11==0){
                                        strcpy(ss[s],node[k].destination);
                                       // s++;
                                        found++;

                                         if(s==1 && found>0){
                                        printf("\n    Serial     Destination\n\n");
                                    }
                                    printf("%8d.        %8s\n",s,ss[s]);
                                     s++;



                                    }

                                   // puts(ss[s]);




                            }

                        }

                        fseek(f2,0,0);

                        if(found==0){
                            if (system("CLS")) system("clear");
                            system("COLOR C");
                            printf("                         NOT FOUND\n                        Enter Again\n");
                            waitFor(2);
                            if (system("CLS")) system("clear");
                            system("COLOR A");
                            goto step2;
                        }
                        printf("\n%d. Main menu\n%d. Exit\n\n",s,s+1);
                        printf("\nSelect Destination from above list:\n\n");
                        scanf("%d",&choice2);
                        strcpy(desti,ss[choice2]);
                        if(choice2==s){
                                found=0;
                            if (system("CLS")) system("clear");
                            system("COLOR A");
                            goto main_menu;
                        }
                        else if(choice2==s+1){
                            if (system("CLS")) system("clear");
                            system("COLOR A");
                            printf("\n\n                            THANK YOU\n\n\n\n\n");
                            return 0;
                        }
                        else if(choice2>s+1 || choice2<1){
                            if (system("CLS")) system("clear");
                            system("COLOR C");
                            printf("                      Wrong key!!! \n                     \n\n");
                             waitFor(2);
                            if (system("CLS")) system("clear");
                            system("COLOR D");
                            return 0;

                      }
                        if (system("CLS")) system("clear");
                        system("COLOR B");
                    }


                step4:// select train
                    {
                     if(found>0){
                        if(strcmp(dep,desti)==0){
                            if (system("CLS")) system("clear");
                            system("COLOR C");
                            printf("               Starting Point & Destination is same!!\n\n                           Enter Again\n");
                            waitFor(4);
                            if (system("CLS")) system("clear");
                            system("COLOR D");
                            goto step2;
                        }
                        search(dep,desti);
                        printf("\nSelect your train from above list:\n\n");
                      }
                     else printf("Enter 1 or 2\n\n");
                     scanf("%d",&train);
                     if(found>0){
                        strcpy(selected_train,train_name[train]);

                        strcpy(selected_train_offday,train_offday[train]);
                        strcpy(selected_train_starting_time,train_starting_time[train]);

                        strncpy(selected_train_hour,selected_train_starting_time,2);
                        strncpy(selected_train_minute,selected_train_starting_time+3,2);
                        selected_train_hours=atoi(selected_train_hour);
                        selected_train_minutes=atoi(selected_train_minute);
                        total_seconds_selected_train=selected_train_hours*3600+selected_train_minutes*60;



                        if(strcmp(selected_train_offday,current_day_name)==0){
                                 if (system("CLS")) system("clear");
                                  system("COLOR C");
                                  printf("\n\n\n\n                Today is OFFDAY for this train\n\n\n\n\n\n");
                                  waitFor(4);
                                  if (system("CLS")) system("clear");
                                  system("COLOR A");
                                  goto main_menu;
                        }
                       else if(total_seconds_selected_train-user_total_seconds<3600 && strcmp(user_date,current_date)==0){
                            if (system("CLS")) system("clear");
                            system("COLOR C");
                            printf("\n\n\n\n      Ticket is available before one hour of starting time\n\n\n\n\n\n\n");
                            waitFor(4);
                            if (system("CLS")) system("clear");
                            system("COLOR A");
                            goto main_menu;
                        }









                     }
                     puts(selected_train);
                     if(train<k)
                        strcpy(trainch,train1[train]);
                     else if(train==k) {
                            if (system("CLS")) system("clear");
                            system("COLOR D");
                            goto main_menu;
                     }
                     else if(train==k+1) {
                            if (system("CLS")) system("clear");
                            system("COLOR A");
                            printf("\n\n                                    THANK YOU\n\n\n\n\n");
                            return 0;
                     }
                     else
                     {
                         if (system("CLS")) system("clear");
                         system("COLOR C");
                         printf("                      Wrong key!!!\n                      Enter Again\n\n");
                          waitFor(2);
                            if (system("CLS")) system("clear");
                            system("COLOR B");
                            goto step4;
                     }
                     if (system("CLS")) system("clear");
                     system("COLOR D");
                }

                step5://  class
                    {
                     int find=0;
                     printf("%s\n",trainch);
                     printf("Select Class(Enter the serial):\n\n");
                     printf(" 1. Shovon chair\n 2. Snigdha\n 3. AC Seat\n 4. AC Birth\n 5. First Chair\n 6. First Birth\n 7. First Seat\n 8. Shuvon\n 9. Sulov\n\n10. Back to Main Menu\n11. Exit\n\n");
                     scanf("%d",&clss);
                     if(clss==10) {
                            if (system("CLS")) system("clear");
                            system("COLOR B");
                            goto main_menu;
                     }
                     else if(clss==11) {
                            if (system("CLS")) system("clear");
                            system("COLOR A");
                            printf("\n\n                                THANK YOU\n\n\n\n\n");
                            return 0;
                     }
                     else if(clss>11 || clss<1){
                            if (system("CLS")) system("clear");
                            system("COLOR C");
                            printf("                      Wrong key!!! \n                      Enter Again\n\n");
                             waitFor(2);
                            if (system("CLS")) system("clear");
                            system("COLOR D");
                            goto step5;

                     }
                     else {

                        do{
                            fscanf(f4,"%s %s %s %s %s %s %s %s %s %s",&classs[0].clss,&classs[1].clss,&classs[2].clss,&classs[3].clss,&classs[4].clss,classs[5].clss,&classs[6].clss,&classs[7].clss,&classs[8].clss,&classs[9].clss);
                            printf("%s %s\n\n",selected_train,classs[0].clss);
                            if(strcmp(classs[clss].clss,"YES")==0) find++;
                            else if (strcmp(selected_train,classs[0].clss)==0){
                                if(strcmp(classs[clss].clss,"NO")==0){
                                    if (system("CLS")) system("clear");
                                    system("COLOR C");
                                    printf("               This class is not available in this train\n");
                                    printf("\n                              Enter Again\n");
                                    waitFor(4);
                                    if (system("CLS")) system("clear");
                                    system("COLOR D");
                                    fseek(f4,0,0);
                                    //find=0;
                                    goto step5;

                                }

                            }
                          } while(!feof(f4));

                          fseek(f4,0,0);

                          if(find==0){
                            if (system("CLS")) system("clear");
                                    system("COLOR C");
                                    printf("               This class is not available in this train\n");
                                    printf("\n                              Enter Again\n");
                                    waitFor(4);
                                    if (system("CLS")) system("clear");
                                    system("COLOR D");
                                    //find=0;
                                    fseek(f4,0,0);
                                    goto step5;
                            }
                     }
                     if (system("CLS")) system("clear");
                     system("COLOR A");
                  }
                       int passenger,passengers,adult,child;
                       int fares[15],totalfare;
                        //fair[0]=0;
                       char sstart[100],sdestination[100],sname_oftrain[100];
            step6:// passengers
                {

                     printf("Enter the number of passengers: (Adult & Child)\n\n");
                     printf("\tAdult: ");

                     scanf("%d",&adult);
                     printf("\n\tChild: ");
                     scanf("%d",&child);
                     passengers=adult+child;

                     //printf("\n\n 1. Back to previous page\n 0. Exit\n\n");
                    // scanf("%d",&passengers);
                     if(passengers>4){
                        if (system("CLS")) system("clear");
                        system("COLOR A");
                        printf("\n\n                       Maximum number of passengers is 4\n");
                        printf("                            Enter Again\n\n\n");
                        waitFor(3);
                        if (system("CLS")) system("clear");
                        system("COLOR 6");
                        goto step6;


                     }

                     fseek(f7,0,0);

                     char astarting_point[50],adestination_point[50],aname_of_train[100];
                     int seat_available[15],the_available_seat;
                     char fstarting_point[50],fdestination_point[50],fname_of_train[100];
                     int  seat_filled_up[15],the_filled_up_seat;
                     do{
                      //  fscanf(f6,"%s %s %s %d %d %d %d %d %d %d %d %d",&astarting_point,&adestination_point,&aname_of_train,&seat_available[1],&seat_available[2],&seat_available[3],&seat_available[4],&seat_available[5],&seat_available[6],&seat_available[7],&seat_available[8],&seat_available[9]);
                     fscanf(f6,"%s %d %d %d %d %d %d %d %d %d",&aname_of_train,&seat_available[1],&seat_available[2],&seat_available[3],&seat_available[4],&seat_available[5],&seat_available[6],&seat_available[7],&seat_available[8],&seat_available[9]);

                      //  fscanf(f7,"%s %s %s %d %d %d %d %d %d %d %d %d",&fstarting_point,&fdestination_point,&fname_of_train,&seat_filled_up[1],&seat_filled_up[2],&seat_filled_up[3],&seat_filled_up[4],&seat_filled_up[5],&seat_filled_up[6],&seat_filled_up[7],&seat_filled_up[8],&seat_filled_up[9]);
                        fscanf(f7,"%s %d %d %d %d %d %d %d %d %d",&fname_of_train,&seat_filled_up[1],&seat_filled_up[2],&seat_filled_up[3],&seat_filled_up[4],&seat_filled_up[5],&seat_filled_up[6],&seat_filled_up[7],&seat_filled_up[8],&seat_filled_up[9]);

                        /*if(strcmp(astarting_point,dep)==0 && strcmp(adestination_point,desti)==0  &&  strcmp(aname_of_train,selected_train)==0){
                            the_available_seat=seat_available[clss];
                            the_filled_up_seat=seat_filled_up[clss];

                            break;
                        }
*/

                         if(strcmp(aname_of_train,selected_train)==0){
                            the_available_seat=seat_available[clss];
                            the_filled_up_seat=seat_filled_up[clss];

                            break;
                        }

                     } while(!feof(f6));

                     fseek(f6,0,0);
                     fseek(f7,0,0);

                     int choice;
                     if(the_filled_up_seat+passengers>the_available_seat){
                            if (system("CLS")) system("clear");
                            system("COLOR C");
                            printf("\n\n                        Seat is not Available\n");
                            waitFor(2);
                            if (system("CLS")) system("clear");
                            system("COLOR B");
                            printf("Enter from below:\n\n");
                            printf(" 1. Main Menu\n 0. Exit");
                            scanf("%d",&choice);
                            if(choice==1){
                                if (system("CLS")) system("clear");
                                system("COLOR A");
                                goto enterdate;
                            }
                            else {
                                if (system("CLS")) system("clear");
                                system("COLOR A");
                                printf("\n\n\n\n\n\n                          THANK YOU\n\n\n\n\n\n\n\n");
                                return 0;
                            }
                       }
                       else {
                            seat_filled_up[clss]=seat_filled_up[clss]+passengers;

                       }












                     if (system("CLS")) system("clear");
                     system("COLOR D");
                }

                farestep:
                      {

                       do{
                          fscanf(f8,"%s %s %s %d %d %d %d %d %d %d %d %d",&sstart,&sdestination,&sname_oftrain,&fares[1],&fares[2],&fares[3],&fares[4],&fares[5],&fares[6],&fares[7],&fares[8],&fares[9]);
                          if(strcmp(sstart,dep)==0 && strcmp(sdestination,desti)==0 && strcmp(sname_oftrain,selected_train)==0){
                            totalfare=(fares[clss]) * passengers;
                            break;
                        }


                      }
                      while(!feof(f8));
                      fseek(f8,0,0);

                      confirmation:
                               {
                            printf("Total Ticket fare is: %d TK\n\n",totalfare);
                            printf("Do you want to buy?\n");
                            printf("1. YES\n2. NO\n\n");
                            scanf("%d",&confirm);

                            if(confirm==2){
                                if (system("CLS")) system("clear");
                                system("COLOR A");
                                printf("\n\n\n\n\n\n                  THANK YOU\n\n\n\n\n");
                                return 0;
                            }
                            else if(confirm!=1){
                                 if (system("CLS")) system("clear");
                                system("COLOR C");
                                printf("\n                             WRONG KEY\n");
                                printf("                            ENTER AGAIN\n\n\n\n");
                                waitFor(2);
                                 if (system("CLS")) system("clear");
                                 system("COLOR D");
                                 goto confirmation;
                            }


                        }




                    }

                    if (system("CLS")) system("clear");
                             system("COLOR B");
                step7:// contact number
                    {
                        printf("Give your contact number:\n\n");
                        printf("(Enter 1 to go back to Main Menu)\n");
                        printf("(Enter 0 to Exit)\n\n");
                        scanf("%s",&contact);
                        if(strlen(contact)!=11){
                               if (system("CLS")) system("clear");
                             system("COLOR C");
                            printf("\n\n       It should be 11 digits\n");
                            printf("            ENTER AGAIN\n\n\n\n\n\n\n");
                            waitFor(4);
                                if (system("CLS")) system("clear");
                             system("COLOR D");
                             goto step7;

                        }
                        if(strcmp(contact,"1")==0){
                            if (system("CLS")) system("clear");
                            system("COLOR B");
                            goto main_menu;
                        }
                        else if(strcmp(contact,"0")==0){
                            if (system("CLS")) system("clear");
                                system("COLOR A");
                                printf("\n\n                               THANK YOU\n\n\n\n\n");
                                return 0;
                        }
                        if (system("CLS")) system("clear");
                        system("COLOR A");
                        printf("\n                        CONGRATES!!\n");
                        printf("                Your ticket is confirmed\n\n");
                        waitFor(3);

                        //system("COLOR B");
                        times();
                       if (system("CLS")) system("clear");

                        //waitFor(4);

                    }

                     if (system("CLS")) system("clear");
                        system("COLOR B");

                    int num;
                    char test[100];
                    strcpy(date_user,day);
                    strcat(date_user,"/");
                    strcat(date_user,month);
                    strcat(date_user,"/");
                    strcat(date_user,year);
                step8: // user data
                    {
                        s2[strlen(s2)]='\0';
                        strcpy(user.date,date_user);
                        strcpy(user.phn,contact);
                        strcpy(user.secret_code,s2);
                        strcpy(user.start,dep);
                        strcpy(user.destination,desti);
                        strcpy(user.train,selected_train);
                        do{
                            fscanf(f9,"%d %s",&num,&test);
                            if(num==clss){
                                strcpy(user.clss,test);
                                break;
                            }
                        }while(!feof(f9));if (system("CLS")) system("clear");
                        system("COLOR B");

                        fseek(f9,0,0);

                        user.passengers=passengers;
                        user.total_fare=totalfare;
                        fprintf(f3,"%8s %8s %8s",user.date,user.phn,user.secret_code);
                        fprintf(f3,"  %8s %8s %8s %8s %4d %4d\n",user.start,user.destination,user.train,user.clss,user.passengers,user.total_fare);
                    }

                    fseek(f3,0,0);

                    char fillstring[1000][50],fillint[10],c;

                step9:// update seat
                    {
                       fseek(f7,0,0);
                        fseek(f10,0,0);
                        while(1){

                            fscanf(f7,"%s %d %d %d %d %d %d %d %d %d",&fillstring[2],&fillint[1],&fillint[2],&fillint[3],&fillint[4],&fillint[5],&fillint[6],&fillint[7],&fillint[8],&fillint[9]);

                            if(strcmp(fillstring[2],selected_train)==0){
                                fillint[clss]=fillint[clss]+passengers;
                            }
                            if(feof(f7)){
                                fprintf(f10,"%s %d %d %d %d %d %d %d %d %d",fillstring[2],fillint[1],fillint[2],fillint[3],fillint[4],fillint[5],fillint[6],fillint[7],fillint[8],fillint[9]);
                            if(feof(f7)) break;

                            }
                            else fprintf(f10,"%s %d %d %d %d %d %d %d %d %d\n",fillstring[2],fillint[1],fillint[2],fillint[3],fillint[4],fillint[5],fillint[6],fillint[7],fillint[8],fillint[9]);

                        }
                        fseek(f10,0,0);

                        fclose(f7);

                        f7=fopen(date_file_name,"w+");

                        while(1){

                            fscanf(f10,"%s %d %d %d %d %d %d %d %d %d",&fillstring[2],&fillint[1],&fillint[2],&fillint[3],&fillint[4],&fillint[5],&fillint[6],&fillint[7],&fillint[8],&fillint[9]);
                            if(feof(f10)){
                                fprintf(f7," %12s %4d %4d %4d %4d %4d %4d %4d %4d %4d",fillstring[2],fillint[1],fillint[2],fillint[3],fillint[4],fillint[5],fillint[6],fillint[7],fillint[8],fillint[9]);
                            break;
                            }

                            else
                                fprintf(f7,"%12s %4d %4d %4d %4d %4d %4d %4d %4d %4d\n",fillstring[2],fillint[1],fillint[2],fillint[3],fillint[4],fillint[5],fillint[6],fillint[7],fillint[8],fillint[9]);


                        }


                    }

                    printf("Your secret code is:\n%s\n",s2);

                        printf("Keep the code secret for the further purpose\n");
                        printf("\n\n\n\n            THANK YOU\n\n\n\n\n\n\n");

                        waitFor(6);
                        if (system("CLS")) system("clear");
                        system("COLOR B");
                        goto main_menu;




               }
            else if(buy_ad==2){
               admin:
                    {
                        passwordstep:

                            {
                                if (system("CLS")) system("clear");
                                system("COLOR D");
                                printf("Enter your password:\n");
                                int pass=0;
                                char c;
                                while (pass<=50){
                                    password[pass]=getch();
                                    c=password[pass];

                                    if(c==13) break;
                                    else printf("*");
                                    pass++;

                                }
                                password[pass]='\0';

                                fscanf(f5,"%s",&admin_password);
                                admin_password[strlen(admin_password)]='\0';

                                if(strcmp(password,admin_password)==0){
                                    if (system("CLS")) system("clear");
                                    system("COLOR A");
                                    printf("\n\n\n\n                        Successfully logged in\n");

                                }


                                else {
                                    if (system("CLS")) system("clear");
                                    system("COLOR C");
                                    printf("                        Wrong password\n");
                                    printf("                      Enter Passwoed Again\n");
                                    waitFor(3);
                                    if (system("CLS")) system("clear");
                                    system("COLOR A");
                                    goto passwordstep;

                               }
                               waitFor(3);

                            }
                               if (system("CLS")) system("clear");
                                system("COLOR B");


                            Admin_Action_step:

                            {
                                if (system("CLS")) system("clear");
                                int chce,rename_action,p,q,r,count11=0,selection,zero=0,nonzero=100,take;
                                char train_data[20][20],name_of_train[20],data_change[10][20],new_name[20],new_data[20][20];
                                char current_password[50],new_password[50],new_password2[50],current_file[25],new_file[25],users_data[20][30],contact_num[15],secret_code[25];
                                printf("Select from below:\n\n");
                                printf("\n 1. Search User Data\n 2. Search Train\n 3. Update Train Data\n 4. Delete Train Data\n 5. Add Train\n 6. Change Password\n7. Main menu\n0. Exit\n");

                                scanf("%d",&chce);
                                if(chce==0){
                                    if (system("CLS")) system("clear");
                                    return 0;
                                }
                                if(chce==1){
                                     Enter1:
                                        {
                                             if (system("CLS")) system("clear");
                                                system("COLOR D");
                                                printf("Enter user's contact number\n\n");
                                                scanf("%s",&contact_num);
                                                if (system("CLS")) system("clear");
                                                system("COLOR A");

                                                count11=0;
                                                rewind(f3);
                                                do{
                                                    fscanf(f3,"%s %s %s %s %s %s %s %s %s",&users_data[0],&users_data[1],&users_data[2],&users_data[3],&users_data[4],&users_data[5],&users_data[6],&users_data[7],&users_data[8]);

                                                    if(strcmp(users_data[1],contact_num)==0){

                                                        printf("\n    Date     Contact No\t     Secret Code\t Starting Point\t   Destination\t   Train         Class  Passengers  Fare\t\n ");
                                                        printf("%10s %12s  %12s %16s    %12s %12s %12s %8s    %2s\n",users_data[0],users_data[1],users_data[2],users_data[3],users_data[4],users_data[5],users_data[6],users_data[7],users_data[8]);
                                                        count11++;
                                                        break;
                                                    }

                                                }while(!feof(f3));
                                                return 0;

                                                if(count11==0){
                                                      if (system("CLS")) system("clear");
                                                    system("COLOR C");
                                                    printf("\n\n\n\n\n                        NOT FOUND\n");
                                                        printf("                          ENTER AGAIN\n\n\n\n\n\n");
                                                        waitFor(4);
                                                        goto Enter1;
                                                }



                                                printf("1. Main Menu\n2. Exit\n\n");
                                                scanf("%d",&take);
                                                if(take==1){
                                                    if (system("CLS")) system("clear");
                                                system("COLOR B");
                                                goto main_menu;
                                                }
                                                else {
                                                    if (system("CLS")) system("clear");
                                                    return 0;
                                                }


                                        }



                                }



                                else if(chce==2){
                                     Enter2:
                                         {
                                                      if (system("CLS")) system("clear");
                                            system("COLOR D");
                                            printf("Enter the Name of Train\n\n");
                                            scanf("%s",&name_of_train);
                                              if (system("CLS")) system("clear");
                                            system("COLOR A");

                                            for(q=0;q<strlen(name_of_train);q++){
                                                if(islower(name_of_train[q])) name_of_train[q]=toupper(name_of_train[q]);

                                            }
                                            count11=0;
                                            rewind(f1);
                                            do{
                                                fscanf(f1,"%s %s %s %s %s %s",&train_data[1],&train_data[2],&train_data[3],&train_data[4],&train_data[5],&train_data[6]);
                                                if(strcmp(train_data[3],name_of_train)==0){
                                                    printf("\nStarting point   Destination        Train         OFF Day       starting Time    Arrival Time\n");
                                                    printf("%8s\t %8s\t %8s\t %8s\t %8s\t %8s\n",&train_data[1],&train_data[2],&train_data[3],&train_data[4],&train_data[5],&train_data[6]);
                                                    count11++;
                                                    break;
                                                }

                                            } while(!feof(f1));
                                            rewind(f1);

                                             if(count11==0){
                                                  if (system("CLS")) system("clear");
                                                system("COLOR C");
                                                printf("\n\n\n\n\n            The Train %s is NOT FOUND\n");
                                                printf("                    ENTER AGAIN\n\n\n\n\n\n");
                                                waitFor(4);
                                                goto Enter2;

                                            }
                                            printf("\n1. Main Menu\n0. Exit\n\n");
                                            scanf("%d",&take);
                                            if(take==1){
                                                         if (system("CLS")) system("clear");
                                                        system("COLOR B");
                                                        goto main_menu;
                                            }
                                            else{
                                                    if (system("CLS")) system("clear");

                                                return 0;
                                            }

                                         }


                                }

                                else if(chce==3){
                                     Enter3:
                                         {
                                            if (system("CLS")) system("clear");
                                            system("COLOR B");

                                            printf("Enter the name of Train\n");
                                            scanf("%s",&name_of_train);
                                            for(r=0;r<strlen(name_of_train);r++){
                                                        if(islower(name_of_train[r])) name_of_train[r]=toupper(name_of_train[r]);
                                            }
                                            count11=0;
                                            for(q=0;q<number_of_trains;q++){
                                                if(strcmp(name_of_train,node[q].nameoftrain)==0){

                                                count11++;
                                                if (system("CLS")) system("clear");
                                                system("COLOR A");
                                                printf("\nStarting point  Destination         Train       Off day      starting Time   Arrival Time    \n");
                                                    printf("    %s        %s      %s       %s            %s           %s\n\n",node[q].from,node[q].destination,node[q].nameoftrain,node[q].offday,node[q].departure,node[q].arrival);


                                                     printf("What do you want to change?\n");
                                                    printf(" 1. Starting Point\n 2. Destination\n 3. Name of Train\n 4. Off day\n 5. Starting Time\n 6. Arrival Time\n\n");
                                                    scanf("%d",&selection);
                                                    if (system("CLS")) system("clear");
                                                    system("COLOR D");
                                                    printf("Enter new name\n");
                                                    scanf("%s",&new_name);
                                                    for(r=0;r<strlen(new_name);r++){
                                                        if(islower(new_name[r])) new_name[r]=toupper(new_name[r]);
                                                    }

                                                    if(selection==1) strcpy(node[q].from,new_name);
                                                    else if(selection==2) strcpy(node[q].destination,new_name);
                                                    else if(selection==3) strcpy(node[q].nameoftrain,new_name);
                                                    else if(selection==4) strcpy(node[q].offday,new_name);
                                                    else if(selection==5) strcpy(node[q].departure,new_name);
                                                    else if(selection==6) strcpy(node[q].arrival,new_name);

                                                   //
                                                    remove("trains.txt");
                                                    //fclose(f1);
                                                    f15=fopen("trains.txt","w");
                                                    rewind(f15);
                                                    if(f15==NULL) printf("\n                ERROR\n");
                                                    for(p=0;p<number_of_trains;p++){
                                                        fprintf(f15,"%s %s %s %s %s %s\n",node[p].from,node[p].destination,node[p].nameoftrain,node[p].offday,node[p].departure,node[p].arrival);
                                                    }
                                                    rewind(f15);

                                                    if (system("CLS")) system("clear");
                                                    system("COLOR A");
                                                    printf("\n\n              Data changes successfully\n\n\n");
                                                    waitFor(4);
                                                    if (system("CLS")) system("clear");
                                                    system("COLOR B");
                                                    goto Admin_Action_step;



                                                }
                                            }
                                            if(count11==0){
                                                printf("\n\n\n\n\n            The Train %s is NOT FOUND\n",name_of_train);
                                                printf("                    ENTER AGAIN\n\n\n\n\n\n");
                                                waitFor(4);
                                                goto Enter3;

                                            }
                                         }



                                }
                                else if(chce==4){
                                        Enter4:
                                            {
                                                if (system("CLS")) system("clear");
                                            system("COLOR D");
                                            printf("Enter the name of Train\n");
                                            scanf("%s",&name_of_train);
                                             for(r=0;r<strlen(name_of_train);r++){
                                                        if(islower(name_of_train[r])) name_of_train[r]=toupper(name_of_train[r]);
                                            }
                                            count11=0;
                                            for(q=0;q<number_of_trains;q++){
                                                if(strcmp(name_of_train,node[q].nameoftrain)==0){
                                                    delet=q;
                                                    count11++;
                                                    break;
                                                }
                                            }

                                            if(count11>0){
                                                    remove("trains.txt");
                                                    //fclose(f1);
                                                f14=fopen("trains.txt","w+");

                                                rewind(f14);
                                                for(q=0;q<number_of_trains;q++){
                                                    if(q!=delet){
                                                        fprintf(f14,"%s %s %s %s %s %s\n",node[q].from,node[q].destination,node[q].nameoftrain,node[q].offday,node[q].departure,node[q].arrival);
                                                    }
                                                }
                                                rewind(f14);
                                                if (system("CLS")) system("clear");
                                                system("COLOR A");
                                                printf("\n\n\n\n\n             Data is deleted successfully\n\n\n\n");
                                                waitFor(4);
                                                 if (system("CLS")) system("clear");
                                                system("COLOR B");
                                                goto Admin_Action_step;


                                            }
                                            else if(count11==0){
                                                if (system("CLS")) system("clear");
                                                system("COLOR C");
                                                printf("\n\n\n\n                    NOT FOUND\n");
                                                printf("                  Enter again\n\n\n\n\n\n\n\n");
                                                waitFor(3);
                                                if (system("CLS")) system("clear");
                                                system("COLOR B");
                                                goto Enter4;



                                            }
                                        }

                                }
                                else if(chce==5){
                                     if (system("CLS")) system("clear");
                                                system("COLOR A");

                                    printf("Enter new data to Add\n");
                                    printf("Starting point: ");
                                    scanf("%s",&new_data[0]);
                                    printf("\nDestination: ");
                                    scanf("%s",&new_data[1]);
                                    printf("\nName of train: ");
                                    scanf("%s",&new_data[2]);
                                    printf("\nOff day: ");
                                    scanf("%s",&new_data[3]);
                                    printf("\nStarting Time: ");
                                    scanf("%s",&new_data[4]);
                                    printf("\nArrival Time: ");
                                    scanf("%s",&new_data[5]);
                                    //fseek(f1,0,2);
                                    rewind(f1);
                                    fprintf(f1,"%s %s %s %s %s %s\n",new_data[0],new_data[1],new_data[2],new_data[3],new_data[4],new_data[5]);

                                    rewind(f1);
                                    if (system("CLS")) system("clear");
                                                system("COLOR A");
                                    printf("Now Enter ticket fare\n");
                                    printf("Shuvon chair: ");
                                    scanf("%d",&node2[0].Shuvon_chair);
                                    printf("snighdha: ");
                                    scanf("%d",&node2[0].Snigdha);
                                    printf("AC seat: ");
                                    scanf("%d",&node2[0].Ac_seat);
                                    printf("AC BIRTH: ");
                                    scanf("%d",&node2[0].Ac_Birth);
                                    printf("First chair: ");
                                    scanf("%d",&node2[0].First_chair);
                                    printf("First Birth: ");
                                    scanf("%d",&node2[0].First_Birth);
                                    printf("First seat: ");
                                    scanf("%d",&node2[0].First_Seat);
                                    printf("Shuvon: ");
                                    scanf("%d",&node2[0].Shuvon);
                                    printf("sulov: ");
                                    scanf("%d",&node2[0].sulov);
                                    rewind(f8);
                                    fprintf(f8,"%12s %12s %12s %4d %4d %4d %4d %4d %4d %4d %4d %4d\n",new_data[0],new_data[1],new_data[2],node2[0].Shuvon_chair,node2[0].Snigdha,node2[0].Ac_seat,node2[0].Ac_Birth,node2[0].First_chair,node2[0].First_Birth,node2[0].First_Seat,node2[0].Shuvon,node2[0].sulov);
                                    rewind(f8);
                                    int z=0;
                                    rewind(f16);
                                    rewind(f13);
                                     do{
                                        fscanf(f13,"%s",&filenames[z]);
                                        strcat(filenames[z],".txt");
                                        f16=fopen(filenames[z],"a+");
                                        fprintf(f16,"%12s %4d %4d %4d %4d %4d %4d %4d %4d %4d\n",new_data[2],zero,zero,zero,zero,zero,zero,zero,zero,zero);
                                        fclose(f16);
                                        z++;
                                     }while(!feof(f13));
                                     rewind(f13);
                                     rewind(f16);
                                    rewind(f6);
                                    fprintf(f6,"%s %s %s %d %d %d %d %d %d %d %d %d\n",new_data[0],new_data[1],new_data[2],nonzero,nonzero,nonzero,nonzero,nonzero,nonzero,nonzero,nonzero,nonzero);
                                    rewind(f6);
                                     if (system("CLS")) system("clear");
                                                system("COLOR A");
                                    printf("\n\n\n\n              Successfully added new data\n\n\n\n\n\n\n");
                                    waitFor(4);
                                     if (system("CLS")) system("clear");
                                                system("COLOR B");
                                               goto Admin_Action_step;

                                }

                                if(chce==6){

                                    if (system("CLS")) system("clear");
                                    system("COLOR A");
                                    Current_password_step:

                                    printf("\nEnter Your Current Password: \n\n");
                                    scanf("%s",&current_password);
                                    if(strcmp(current_password,admin_password)!=0){
                                          if (system("CLS")) system("clear");
                                        system("COLOR C");
                                        printf("\n\n\n\n\n                       WRONG PASSWORD\n                    ENTER PASSWORD AGAIN\n\n\n\n\n\n");

                                         waitFor(3);
                                         if (system("CLS")) system("clear");
                                        system("COLOR A");
                                        goto Current_password_step;


                                    }





                                    else {


                                        new_password_step:{
                                            if (system("CLS")) system("clear");
                                                        system("COLOR D");



                                               printf("\nEnter a new Password:\n");
                                                scanf("%s",&new_password);
                                                if (system("CLS")) system("clear");
                                                        system("COLOR D");
                                                printf("\nEnter new password Again:\n");
                                                scanf("%s",&new_password2);

                                                if(strcmp(new_password,new_password2)!=0){
                                                        if (system("CLS")) system("clear");
                                                        system("COLOR C");

                                                    printf("\n\n\n       It doesn't match with previous one\n            ENTER NEW PASSWORD AGAIN\n\n\n\n");
                                                          waitFor(5);

                                                         if (system("CLS")) system("clear");
                                                        system("COLOR A");
                                                        goto new_password_step;
                                                }
                                                else{
                                                    fclose(f5);
                                                   f5=fopen("password.txt","w");
                                                    fprintf(f5,"%s",new_password);
                                                     if (system("CLS")) system("clear");
                                                        system("COLOR A");
                                                        fclose(f5);
                                                        printf("\n\n\n\n              Password has been changed successfully\n\n\n\n\n\n");
                                                        waitFor(3);

                                                         if (system("CLS")) system("clear");
                                                        system("COLOR A");
                                                        goto Admin_Action_step;



                                                }
                                            }

                                    }
                                }

                                else if(chce==6666){
                                    if (system("CLS")) system("clear");
                                    printf("Enter the existing file to change\n\n");
                                    scanf("%s",&current_file);
                                    if (system("CLS")) system("clear");
                                    printf("Enter the new file name\n\n");
                                    scanf("%s",&new_file);
                                    if (system("CLS")) system("clear");
                                    strcat(current_file,".txt");
                                    strcat(new_file,".txt");
                                    rename_action=rename(current_file,new_file);
                                    if(rename_action==0)
                                    printf("Successfully changed file name\n");
                                    else printf("file name couldn't be changed\n");
                                    waitFor(3);
                                    if (system("CLS")) system("clear");
                                        system("COLOR B");
                                        goto Admin_Action_step;

                                }
                                else if(chce==7){
                                    if (system("CLS")) system("clear");
                                        system("COLOR B");
                                        goto main_menu;
                                }



                            }
                    }



            }

        }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    fclose(f6);
    fclose(f7);
    fclose(f8);
    fclose(f9);
    fclose(f10);
    fclose(f15);


     return 0;

}
