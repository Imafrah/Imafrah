#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define Max_line 100
#define Min_password 8



int check_password(const char *passoword){
    int len=strlen(passoword);
    int up=0,low=0,digit=0,special=0;

    for(int i=0;i<len;i++){
        if(isdigit(passoword[i])){
            digit=1;
        }
        if(isupper(passoword[i])){
            up=1;
        }
        if(islower(passoword[i])){
            low=1;
        }
        if(!isalnum(passoword[i])){
            special=1;
        }
    }

    if(len>=Min_password && digit==1&& up==1 && low==1 &&special==1){
        return 3;
    }
    else if(len>=Min_password && digit==1&& up==1 && low==1){
        return 2;
    }else{
        return 1;
    }
}




int main(){
    // FILE *file= fopen("credentials.txt","r");
    // if(!file){
    //     printf("Error opening file\n");
    //     return 1;
    // }
    // char line[Max_line];
    // printf("Compromised Credentials\n");
    // while(fgets(line,sizeof(line),file)){
    //     char *username=strtok(line,":\n");
    //     char *password=strtok(NULL,"\n");
    char username[20],password[20];
    printf("Enter the user name\n");
    scanf("%s",username);
    printf("Enter the password\n");
    scanf("%s",password);

        if(username&&password){
            printf("%s: %s\n",username,password );
            int strenth=check_password(password);
            if(strenth==3){
                printf("Password strenth is strong\n");
            }
            else if(strenth==2){
                printf("Password strenth is Medaim\n");
            }
            else{
                printf("Password strenth is Weak\n");
            }
        }
    }
    // fclose(file);