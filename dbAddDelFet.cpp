#include<bits/stdc++.h>
using namespace std;

int hashMapOfDistrict[50001][200];
int hashMapOfAreaDistrict[50001][200];
int idMappingToAge[50001];
int idMappingToHashValue[50001];


void init(){
    for(int i=0;i<50001;i++){
        idMappingToAge[i]=0;
        idMappingToHashValue[i]=0;
        for(int j=0;j<200;j++){
            hashMapOfDistrict[i][j]=0;
            hashMapOfAreaDistrict[i][j]=0;
        }
    }
}

int generateAreaHashValue(char address[]){
    int hashValue=0,i=0;
    while(true){
        if(address[i]==',') break;
        if(address[i]=='\0') break;
        hashValue+=(i+1)*(address[i]-'a');
        i++;
    }
    return hashValue;
}

void printAdd(char address[]){
    for(int i=0;address[i];i++){
        cout<<address[i]<<" ";
    }
    cout<<endl;
}
int generateDistrictHashValue(char address[]){
    printAdd(address);
    int hashValue=0,i=0,j=0;
    while(true){
        if(address[i]==',') break;
        i++;
    }
    ++i;
    while(true){
        if(address[i]=='\0') break;
        hashValue+=(j+1)*(address[i]-'a');
        cout<<hashValue<<endl;
        i++,j++;;
    }
    return hashValue;
}

int generateIdHashValue(char id[]){
    int hashValue=0,i=0;
    while(true){
        if(id[i]=='\0') break;
        hashValue+=(i+1)*(id[i]-'0');
        i++;
    }
    return hashValue;
}

void addPatient(char id[],char address[],int age){
    int area=generateAreaHashValue(address);
    int district=generateDistrictHashValue(address);
    int hashValue=area+district;
    int uniqueId=generateIdHashValue(id);
    hashMapOfAreaDistrict[hashValue][age]++;
    hashMapOfDistrict[district][age]++;
    idMappingToHashValue[uniqueId]=hashValue;
    idMappingToAge[uniqueId]=age;
}

void removePatient(char id[]){
    int uniqueId=generateIdHashValue(id);
    int hashValue=idMappingToHashValue[uniqueId];
    int age=idMappingToAge[uniqueId];
    hashMapOfAreaDistrict[hashValue][age]--;
    hashMapOfDistrict[hashValue][age]--;
}

bool checkComma(char inArea[]){
    int i=0;
    while(true){
        if(inArea[i]=='\0') break;
        if(inArea[i]==',') return true;
        i++;
    }
    return false;
}

int numberOfPatient(char inArea[],int fromAge,int toAge){
    int district=0,cnt=0;
    int area=generateAreaHashValue(inArea);
    if(checkComma(inArea)){
        int district=generateDistrictHashValue(inArea);
        int hashValue=area+district;
        for(int i=fromAge;i<toAge;i++){
            cnt+=hashMapOfAreaDistrict[hashValue][i];
        }
    }else{
        int hashValue=area;
        for(int i=fromAge;i<toAge;i++){
            cnt+=hashMapOfDistrict[hashValue][i];
        }
    }
    return cnt;
}



int main(){
    // char name[]={'a','b','c',',','d','e','f'};
    // cout<<generateAreaHashValue(name)<<endl;
    int T,Q,queryType;
    char id[13],address[42];
    int age,start,end;
    cin>>T;

    for(int TC=1;TC<=T;TC++){
        init();
        cin>>Q;
        while(Q--){
            cin>>queryType;
            if(queryType==1){  // Add patitent
                cin>>id>>address>>age;
                addPatient(id,address,age);
            }else if(queryType==2){  // remove patient
                cin>>id;
                removePatient(id);
            }else if(queryType==3){  // Number of patient between age.
                cin>>address>>start>>end;
                cout<<"Number of Patient: "<<numberOfPatient(address,start,end)<<endl;
            }
        }
    }
}

/*
 1 
 9
 1 1001 a,x 56
 1 1002 b,x 41
 3 x 30 60
 3 a,x 30 60 
 1 1003 a,x 45 
 3 c,x 30 60 
 2 1001
 3 a,x 30 60 
 3 a 10 100

*/
