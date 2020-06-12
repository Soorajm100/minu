#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<conio.h>
#include <ctype.h>
#include <windows.h>
#include<time.h>
#define AB      "0123456789"
#define ABLEN   ( sizeof(AB) - 1 )
#define ARRSIZ  5
void reg();
void login();
int kal();
void wastemanagement();
void link();
void attendance(char n[30],char ui[30]);
void complaint();
void kali();
char* random();


int o;

struct web
{  
  
  char name[30],pass[30];
  char complaint[1000]; 
    
  char attendance[5];
  char  date[10], time[10],year[10],month[10],weekd[10],day[10];

  
  char  id[10];
  char feedback[1000];
  
}w[99];

void setcolor(int ForgC)
{ WORD wColor;
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;

if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
{
	wColor=(csbi.wAttributes & 0xB0)+(ForgC & 0x0B);
//	SetConsoleTextAttributes(hStdOut,wColor);
	SetConsoleTextAttribute(hStdOut,wColor);

}
}

char* random(){
   srand( time(NULL) );
 
    static char arr[ARRSIZ] = {'\0'};    
    int  nletters = 1;
    int  ndigits  = ARRSIZ - nletters;
   
   arr[0]='#';
    int b = 1;
    while ( ndigits ) {
        int c = AB[ rand() % ABLEN ];
      
         if ( ndigits && isdigit(c) ) {
            ndigits--;
        }
        else {
            continue;
        }
        arr[b++] = c;
    }
    return arr;
    }

    

char* timy(){

    static char arr[10] = {'\0'};   
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
 
     
   strcpy(arr,asctime(tm));
   return arr;

  }

int ram()
{
    int k;
    time_t t;
     time(&t);

int s=0;
char c;


setcolor(10);



 


      
 printf("\nenter 1 for admin login ");
 printf("\n");
  printf("enter  2 for registration of members \n");
 printf("enter 3 for normal account of login of members");
 printf("\nenter 4 for exit from program");
 printf("\n");
 printf("enter 5 for Wastemanagement");

 
 
 
  scanf("%d",&k);
  printf("\n");
 switch(k)
 {  
     case 1:
      printf("Admin login section:\n");
      char username[10]="Kalam";
      char password[10]="123";
      char username1[10];
      char password1[10];
   
    
      bool p=true;
         
          if(strcmp(username,username1)!=0||strcmp(password1,password)!=0){
      while(p)
      {
          
           if(strcmp(username,username1)!=0||strcmp(password1,password)!=0)
          {
         
      printf("\nEnter the username=");
      scanf("%s",username1);
      printf("\n");
      printf("enter the password=");
      while((c=getch())!=13)
        {
          password1[s++]=c;
          printf("%c",'*');
        }
         
      printf("\n");
      printf("\n\n\n\n");
      
      }
      if(strcmp(username,username1)!=0||strcmp(password1,password)!=0)
      {
        printf("You have entered wrong password or username \n");

      }
           
          if(strcmp(username,username1)==0&&strcmp(password1,password)==0)
          {   
          
              kal();
              break;
              
          }
          
      }
        }
      printf("A Warm Welcome.You are successfully able to login\n");
      ram();
     
      break;
  
    case 2:

      


reg();
ram();


 break;
 case 3:
 printf("welcome to the login zone");
 login();
 ram();

case 4:exit(0);
        break;
case 5: link();
         break;

   


     default:printf("no valid user");
     printf("\n");
     
     
 }
     return 0;
}



    int static i=0;  
 void reg()
{ 
  

  i=i+1;
FILE *fp;
    char c,checker[30];
int z=0;int k=0;

  time_t t1;
 t1 = time(NULL);
 char time[10],month[10],day[10],year[10],weekd[10],date[15];
        sscanf(ctime(&t1),"%s %s %s %s %s",weekd,month,day,time,year);
      fp=fopen("ran2","ab+");
      
    printf("\n\n\t\t\t\t");
                        printf("------------------------------        \n");
                printf( "                               |                              |\n");
 printf( "                               |WELCOME TO REGISTRATION ZONE  | \n");
        printf("                               --------------------------------     \n " );
      strcpy(date,timy());
      
   
      printf("\n\n\t\t\t\t  ENTER USERNAME: ");
      scanf("%s",checker);
        strcpy(w[i].year,year);
       strcpy(w[i].date,date);
               strcpy(w[i].time,time);
        strcpy(w[i].weekd,weekd);
        strcpy(w[i].month,month);
        strcpy(w[i].day,day);

    char id9[10];   
strcpy(id9,random());
    
    

   
        
  
 
           fseek(fp,0L,0);
        while(!feof(fp))
        {
          fread(&w[i],sizeof(w[i]),1,fp);
      
          if(strcmp(checker,w[i].name)==0||strcmp(id9,w[i].id)==0)
            {
              system ("cls");
           printf("\n\n\t\t\tUSERNAME OR USERID  ALREDY EXISTS");
         
               reg();
            }
          else
          {  
            strcpy(w[i].id,id9);
            strcpy(w[i].name,checker);
          
         
            
            break;
          }
        }

  
      printf("\n\n\t\t\t\t  DESIRED PASSWORD: ");
      
      while((c=getch())!=13)
        {
          w[i].pass[z++]=c;
          printf("%c",'*');
        }
         
    
    fseek(fp,0L,2);
           
    
      fwrite(&w[i],sizeof(w[i]),1,fp);


      fclose(fp);
      printf("\n\n\tPress enter if you agree with Username and Password");
      if((c=getch())==13)
        {
      system ("cls");
        printf("\n\n\t\tYou are successfully registered\n");
        printf("YOUR USER ID IS=%s\n",w[i].id);
        printf("PLEASE REMEMBER THIS FOR FURTHER USE");
      
        printf("\n\n\t\tTry login your account??\n\n\t\t  ");
        printf("> PRESS 1 FOR YES\n\n\t\t  > PRESS 2 FOR NO\n\n\t\t\t\t");
        int n;
        scanf("%d",&n);
        switch(n)
          {
              case 1: system ("cls");
                    login();
                    break;
              case 2: system ("cls");
                    printf("\n\n\n\t\t\t\t\tTHANK YOU FOR REGISTERING");
                    break;
          }
        }
        
      
    getch();



}
int static j;
int t=2;
void login()
{   

       
      FILE *fp;
      char c,name[30],pass[30]; int z=0;
      int checku,checkp;
     
      
      fp=fopen("ran2","rb+");
      printf("\n\n\t\t\t\t");
                        printf("------------------------------        \n");
                printf( "                               |                              |\n");
 printf( "                               |   WELCOME TO LOG IN ZONE     | \n");
        printf("                                 ------------------------------     \n " );
      
   
      
        printf("\n\n\t\t\t\t  ENTER USERNAME: ");
        scanf("%s",name);
        printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
        while((c=getch())!=13)
        {
          pass[z++]=c;
          printf("%c",'*');
        }
        pass[z]='\0';
        
        static int j;
        fseek(fp,0L,0);
         j=0;
      while(!feof(fp))
        {
       
        
        fread(&w[j],sizeof(w[j]),1,fp);
          checku=strcmp(name,w[j].name);
         
          checkp=strcmp(pass,w[j].pass);
      
         
         j++;
        
          if(checku==0&&checkp==0)
          {
             t=1;
              
            printf("\n\n\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
            printf("\n\n\n\t\t\t\tWELCOME, HAVE A NICE DAY\n");
           
           kal();
            break;
          }
        }
          fseek(fp,0L,0);
        while(!feof(fp)){
     
        j=0;
        fread(&w[j],sizeof(w[j]),1,fp);
          checku=strcmp(name,w[j].name);
         
          checkp=strcmp(pass,w[j].pass);
         j++;
       if(checku==0&&checkp!=0)
          {
           
            printf("\n\n\n\t\t\tWRONG PASSWORD!! Not %s??",name);
            printf("\n\n\t\t\t\t  (Press 'Y' to re-login)");
            if(getch()=='y'||getch()=='Y')
              login();
          }
        }
        fseek(fp,0L,0);
         j=0; 
         if(t!=1){
         while(!feof(fp)){
           
        
        fread(&w[j],sizeof(w[j]),1,fp);
       
          checku=strcmp(name,w[j].name);
         
          checkp=strcmp(pass,w[j].pass);
         j++;
         
         if(checku!=0)
          { 
           
              printf("%s",w[j].name);
            printf("%s",w[j].pass);
            printf("\n\n\n\t\t\tYou are not a Registered User\n \t\t\tPress enter to register yourself");
            if(getch()==13)
            system ("cls");
            reg();
          }
         }
   
      
      getch();
}


}
int kal()
{
    int r, h, n;

    n=10;

    for(r=n/2; r<=n; r+=2)
    {    
        for(h=1; h<n-r; h+=2)
        {
            printf(" ");
        }

        for(h=1; h<=r; h++)
        {
            printf("*");
        }
     
        for(h=1; h<=n-r; h++)
        {
            printf(" ");
        }
      
        for(h=1; h<=r; h++)
        {
            printf("*");
        }
        
        printf("\n");
    }
     
    for(r=n; r>=1; r--)
    {    
        for(h=r; h<n; h++)
        {
            printf(" ");
        }
      
        for(h=1; h<=(r*2)-1; h++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
int k=8;
     int  l=0;
           
    void link()
 {
     FILE *fp;
     char name[20];
     int check;
     char id2[10];
      char date[10],time1[10],month[10],day[10],year[10],weekd[10];
     fp=fopen("ran2","rb+");
     printf("ENTER THE USER-ID:");
     scanf("%s",id2);
     
         
     
  
 
       
        fseek(fp,0L,0);
      while(!feof(fp))
        {
          
        fread(&w[l],sizeof(w[l]),1,fp);
        
          check=strcmp(w[l].id,id2) ;
       
          

          
          if (check==0)
          {
             printf("Hi  %s .How are u . Your registration number is %s?? ",w[l].name,w[l].id);
             strcpy(w[l].name,name);
              int h;
                 

              kai:
              printf("\n\t\t\t\t\t\t\t\t\t\t\t\t>Enter 1 for writing  complaint .");
              printf("\n\t\t\t\t\t\t\t\t\t\t\t\t>Enter 2 for attendance");
              printf("\n\t\t\t\t\t\t\t\t\t\t\t\t>Enter 3 for viewing complaint");
              printf("\n\t\t\t\t\t\t\t\t\t\t\t\t>Enter 4 for viewing your attendance for correct disposal of waste");
              printf("\n\t\t\t\t\t\t\t\t\t\t\t\t>Enter 5 for  entering reply for complaints from anonymous account of admin in user section");
              printf("\n\t\t\t\t\t\t\t\t\t\t\t\t>Enter 6 for public view of reply from admin\n");
        printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("This is the workspace eveything has to be written here:\n");
              scanf("%d",&h);
              system("cls");
              switch(h){
                case 1:   if((strcmp(w[l].pass,"500"))){
                
                         system("cls");
                          
                          printf("\nYou have entered the complaint zone\n");
                       
                          FILE *fp1;
                          char co[1000];

                           fp1=fopen("ran25","ab+");
                           printf("\nEnter your complaint here\n");
                           gets(co);
                           printf("\n\n\n\n\n");
                           strcpy(w[l].complaint,co);
                                 

                            fwrite(&(w[l]),sizeof(w[l]),1,fp1);  
                               fseek(fp1,0L,2); 
                            fclose(fp1);
                            goto kai;
                           
                         
                        break;
                }
                case 2: system("cls");
      
                           printf("\nYou have entered the attendance zone\n");
                        FILE *fp2;
                          char at[5];
                           fp2=fopen("ran4","ab+");
                           printf("Enter Y if cleaning is done.\n");
                           printf("Enter N if cleaning is not done\n");
                           scanf("%s",at);
                           strcpy(w[l].attendance,at);
                
                            fwrite(&(w[l]),sizeof(w[l]),1,fp2);
                            
                            
                            printf("\nYour attendance has been successfully registered\n");

                            fclose(fp2);
                            goto kai;
                         break;
                case 3:
                         system("cls");
                         FILE *f9;
                         


                          
                          if((f9=fopen("ran25","rb+"))!=NULL){
                           
                                    
                                
                                    fread(&w[l],sizeof(w[l]),1,f9);
                                    
                                    printf("\nTodays date:%s\n",w[l].date);
                                    printf("Please note the id and username is hidden for safety purpose\n");
                                    printf("-------------------------------------------------------------------------------------------------------------------------------\n");
                       
                                         

                                  fseek(f9,0L,0); 
                                    
                                  while(!feof(f9))
                                  {
                                       if(feof(f9)){
                                            break;
                                          }
                                        fread(&w[l],sizeof(w[l]),1,f9);
                                          
                                        if(feof(f9)){
                                            break;
                                          }
                                             
                                  }        
                                
                                    printf("\n  %s \n ",w[l].complaint);
                          
                                             
                                        
                                         
                                    printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
                                     
                                  
                                  
                                }
                                    break;
                              

            
              case 4:system("cls");
                         FILE *f4;
                                 
                          if((f4=fopen("ran4","rb+"))!=NULL){
                  
                                           fseek(f4,0L,0);
                                          
                                    fread(&w[l],sizeof(w[l]),1,f4);
                                   
                                
                       printf("Todays date:%s  \n",w[l].date);
                       printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                                 
                                     fseek(f4,0L,0);
                                     while(!feof(f4)){
                                    fread(&w[l],sizeof(w[l]),1,f4);
                                   
                                    if(feof(f4)){
                                            break;
                                          }
                                         }
                                    
                                    printf("\n User-id %s has given %s at %s\n ",w[l].id,w[l].attendance,w[l].time);
                              printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                                 
                               
                          }
                          
                                break;
                    case 5: system("cls");
                            if(!(strcmp(w[l].pass,"500"))){

                                printf("You have entered the admin feedback zone");
                       
                          FILE *fp8;
                          char fe[1000];

                           fp8=fopen("ran75","ab+");
                           printf("Enter your feedback here");
                           gets(fe);
                           printf("\n\n\n\n\n");
                           strcpy(w[l].feedback,fe);
                                 

                            fwrite(&(w[l]),sizeof(w[l]),1,fp8);  
                               fseek(fp8,0L,2); 
                            fclose(fp8);
                            goto kai;
                          
                     

                                }
                                
                          break;
            
                              
                     case 6:   system("cls");
                         FILE *f10;
                         


                          
                          if((f10=fopen("ran75","rb+"))!=NULL){
                           
                                    
                                
                                    fread(&w[l],sizeof(w[l]),1,f10);
                                    
                                    printf("\nTodays date:%s\n",w[l].date);
                                    printf("Please note the id and username is hidden for safety purpose\n");
                                    printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
                       
                                         

                                  fseek(f10,0L,0); 
                                    
                                  while(!feof(f10))
                                  {
                                       if(feof(f10)){
                                            break;
                                          }
                                        fread(&w[l],sizeof(w[l]),1,f10);
                                          
                                        if(feof(f10)){
                                            break;
                                          }
                                             
                                        }      
                                
                                    printf("\n  %s \n ",w[l].feedback);
                          
                                    
                                             
                                        
                                         
                                    printf("--------------------------------------------------------------------------------------------------------------------------------------------------\n");
                                         
                               
                                             
                                  
                                  
                                }
                                    break;
                                    
                                
                    default: exit(0);




    }
                      
                       
      
        }
          l++;
        
 }
}
int main()
{
  ram();
  return 0;
}
