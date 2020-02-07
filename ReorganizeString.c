#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int main(){
     //LeetCode : 767. Reorganize String.. Amazon Interview Question
     printf("program..................................\n");
     char *s=(char*) malloc(sizeof(char)*100);
     strcpy(s,"aaabbc");
     int freq[26]={0};
     int i,last,max,maxIndex,len,index;
     for(i=0;s[i];i++){
          int in=s[i]-'a';
          freq[in]++;
     }
     len=i;
     last=-1;
     char *result=(char*) malloc(sizeof(char)*(len+1));
     for(index=0;index<len;index++){
     max=0;
     for(i=0;i<26;i++){
          if(freq[i]>max && i!=last){
               max=freq[i];
               maxIndex=i;
            }
         }
          if(max*2>len+1) printf("Not Possible\n");
          result[index]=maxIndex+'a';
          freq[maxIndex]--;
          last=maxIndex;
    }
  result[index]='\0';
  printf("----------------\n");
  for(int i=0;i<index;i++){
       printf("%c",result[i]);
  }
  //return result;

}