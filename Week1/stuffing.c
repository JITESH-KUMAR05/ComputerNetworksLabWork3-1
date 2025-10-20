// Bit stuffing
#include<stdio.h>
#include<string.h>

void bitStuffing(const char *input,char * output){
    int c=0;
    int j=0;
    for(int i=0;input[i]!='\0';i++){
        output[j++]=input[i];
        if(input[i]=='1'){
            c++;
        }
        else{
            c=0;
        }

        if(c==5 && i>0 && input[i-5]=='0'){
            output[j++]='0';
            c=0;
        }
    }
    output[j]='\0';
}

void destuffing(const char * stuffed,char *destuffed){
    int c=0;
    int j=0;
    for(int i=0;stuffed[i]!='\0';i++){
        destuffed[j++]=stuffed[i];
        if(stuffed[i]=='1'){
            c++;
        }else{
            c=0;
        }
        if(c==5){
            i++;
            c=0;
        }
    }
    destuffed[j]='\0';
}

int main(){
    char input[] = "011111101111110";
    char stuffed[100];
    char destuffed[100];
    bitStuffing(input,stuffed);
    printf("Original : %s\n",input);
    printf("stuffed : %s \n",stuffed);
    destuffing(stuffed,destuffed);
    printf("Destuffed : %s\n",destuffed);

    return 0;
}