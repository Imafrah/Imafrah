#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define Max_line 300
#define Min_password 8

void phishing(){
    const char *fake_emails[]={
        "Warning! Suspicious login detected.Click here to login",
        "Your Account will be locked! Reset your password now.",
        "Congratulation! You have won a prize.Click to clam"
    };

    printf("\nPhishing Simulation Emails Simulation:\n");
    for(int i=0;i<3;i++){
        printf("Email %d : %s\n",i+1,fake_emails[i]);
    }
}




void check_network(FILE *file){
    if(!file){
        printf("Error Opening a file\n");
        return;
    }
    char line[Max_line];
    printf("\nNetwork Vunerabilities:\n");
    while(fgets(line,Max_line,file)){
        char *dev=strtok(line,",");
        char *vul=strtok(NULL,",");

        if(dev && vul){
            printf("Device: %s - Issue  : %s\n",dev,vul);
        }
    }
    fclose(file);
}





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
    
    FILE *file=fopen("cred_breach.txt","r");
    if(!file){
        printf("Error Opening the File \n");
        return 1;
    }
    char line[Max_line];
    printf("Compromised Password:\n");
    while(fgets(line,Max_line,file)){
        char *username=strtok(line,",");
        char *password=strtok(NULL,",");
        char *info =strtok(NULL,",");
    
        if(username&&password&& info){
            printf("User %s: Password %s:Info:%s\n",username,password,info );
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

    fclose(file);
    phishing();
    FILE *networkFile = fopen("network.txt", "r");
    if (networkFile) {
        check_network(networkFile);
    } else {
        printf("Error Opening Network File\n");
    }

    return 0;

}
