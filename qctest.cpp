/*
 Com Sci 31 Project 3
 qctest.cpp
 Author: Danielle Choi
 UID: 306008729
 Discussion Section: 1C
 Date: 2023/02/01.
 */

#include <iostream>
#include <string>
using namespace std;

bool isValidQC(string results);
int passQC(string results);
int defectQC(string results);
int totalQC(string results);
int batches(string results);

int main() {
    string results;
    cout<<"Enter results: ";
    getline(cin,results);
    
    if(isValidQC(results))
        cout<<"Valid"<<endl;
    else
        cout<<"Invalid"<<endl;
    cout<<"The total pass is "<<passQC(results)<<endl;
    cout<<"The total defect is "<<defectQC(results)<<endl;
    cout<<"The total QC is "<<totalQC(results)<<endl;
    cout<<"The number of batches is "<<batches(results)<<endl;
    
    return 0;
}

//functions

bool isValidQC(string results){
    if (results=="") //if the string has no data
        return false;
    if (results[0]!='Q') //if the string doesn't start with Q
        return false;
    if (results[1]<'1'||results[1]>'9') //if the number after Q is zero or less, or not a number
        return false;

    int Qstart=0,Qend=0,Qnum=0;
    int pStart=0,pEnd=0,pNum=0;
    int dStart=0,dEnd=0,dNum=0;
    /*
     Qstart is to determine the index of the first digit for the number after Q.
     Qend is to determine the index of the last digit for the number after Q.
     Qnum is to change the full number after Q, which is in a string type, to an integer.
     pStart is to determine the index of the first digit for the number after p.
     pEnd is to determine the index of the last digit for the number after p.
     pNum is to change the full number after p, which is in a string type, to an integer.
     dStart is to determine the index of the first digit for the number after d.
     dEnd is to determine the index of the last digit for the number after d.
     dNum is to change the full number after d, which is in a string type, to an integer.
     */
    
    int i=0; //i is the index of the string
    while (i<results.length()){
        if (results[i]=='Q'){
            i++;
            if (results[i]<'1'||results[i]>'9') {
                return false;
            } else { //if the number after Q is a number above 1
                Qstart=i;
                Qend=i;
                i++;
                while (results[i]>='0'&&results[i]<='9'){ //until the character is no longer a number
                    Qend=i;
                    i++;
                }
                Qnum=stoi(results.substr(Qstart,Qend-Qstart+1)); //change the substring into a an integer and assign it to Qnum
                if (results[i]=='p'){ //if p is right after the number ends
                    i++;
                    if (results[i]<'0'||results[i]>'9'){
                        return false;
                    } else { //if the character is a number
                        pStart=i;
                        pEnd=i;
                        i++;
                        while (results[i]>='0'&&results[i]<='9'){ //until the character is no longer a number
                            pEnd=i;
                            i++;
                        }
                        pNum=stoi(results.substr(pStart,pEnd-pStart+1)); //change the substring into a an integer and assign it to pNum
                        if (results[i]=='d'){ //if d is right after the number ends
                            i++;
                            if (results[i]<'0'||results[i]>'9'){
                                return false;
                            } else { //if the character is a number
                                dStart=i;
                                dEnd=i;
                                i++;
                                while (results[i]>='0'&&results[i]<='9'){ //until the character is no longer a number
                                    dEnd=i;
                                    i++;
                                }
                                dNum=stoi(results.substr(dStart,dEnd-dStart+1)); //change the substring into a an integer and assign it to dNum
                            }
                        } else { //if the character after the number ends is not p nor d
                            return false;
                        }
                    }
                } else if (results[i]=='d'){ //if d is right after the number ends
                    i++;
                    if (results[i]<'0'||results[i]>'9'){
                        return false;
                    } else { //if the character is a number
                        dStart=i;
                        dEnd=i;
                        i++;
                        while (results[i]>='0'&&results[i]<='9'){ //until the character is no longer a number
                            dEnd=i;
                            i++;
                        }
                        dNum=stoi(results.substr(dStart,dEnd-dStart+1)); //change the substring into a an integer and assign it to dNum
                        if (results[i]=='p'){ //if d is right after the number ends
                            i++;
                            if (results[i]<'0'||results[i]>'9'){
                                return false;
                            } else { //if the character is a number
                                pStart=i;
                                pEnd=i;
                                i++;
                                while (results[i]>='0'&&results[i]<='9'){ //until the character is no longer a number
                                    pEnd=i;
                                    i++;
                                }
                                pNum=stoi(results.substr(pStart,pEnd-pStart+1)); //change the substring into a an integer and assign it to pNum
                            }
                        } else { //if the character after the number ends is not p nor d
                            return false;
                        }
                    }
                } else { //if the character after the number ends is not p nor d
                        return false;
                }
                    
            }
        } else { //if the batch doesn't start with Q
            return false;
        }
        if (Qnum!=pNum+dNum) //if the total number of QC tests in a batch is not equal to the number of pass and defect test results
            return false;
        if ((results.substr(pStart,pEnd-pStart+1)!=to_string(pNum))||(results.substr(dStart,dEnd-dStart+1)!=to_string(dNum))) //if there is leading zeros
            return false;
    }
    return true; //if there is no invalid factors
}

int passQC(string results){
    if(!isValidQC(results))
        return -1;
    
    int pStart=0,pEnd=0,pNum=0,pTotal=0;
    /*
     pStart is to determine the index of the first digit for the number after p.
     pEnd is to determine the index of the last digit for the number after p.
     pNum is to change the full number after p, which is in a string type, to an integer.
     pTotal is the total sum of pNum.
     */
    
    int i=0;
    while (i<results.length()){
        if (results[i]=='p'){ //if it finds p in the string
            i++;
            pStart=i;
            pEnd=i;
            while (results[i]>='0'&&results[i]<='9'){ //until the character is no longer a number
                pEnd=i;
                i++;
            }
            pNum=stoi(results.substr(pStart,pEnd-pStart+1)); //change the substring into a an integer and assign it to pNum
            pTotal+=pNum;
        }
        i++;
    }
    return pTotal;
}

int defectQC(string results){
    if(!isValidQC(results))
        return -1;
    
    int dStart=0,dEnd=0,dNum=0,dTotal=0;
    /*
     dStart is to determine the index of the first digit for the number after d.
     dEnd is to determine the index of the last digit for the number after d.
     dNum is to change the full number after d, which is in a string type, to an integer.
     dTotal is the total sum of dNum.
     */
    
    int i=0;
    while (i<results.length()){
        if (results[i]=='d'){ //if it finds p in the string
            i++;
            dStart=i;
            dEnd=i;
            while (results[i]>='0'&&results[i]<='9'){ //until the character is no longer a number
                dEnd=i;
                i++;
            }
            dNum=stoi(results.substr(dStart,dEnd-dStart+1)); //change the substring into a an integer and assign it to dNum
            dTotal+=dNum;
        }
        i++;
    }
    return dTotal;
}

int totalQC(string results){
    if(!isValidQC(results))
        return -1;
    
    int Qstart=0,Qend=0,Qnum=0,Qtotal=0;
    /*
     Qstart is to determine the index of the first digit for the number after Q.
     Qend is to determine the index of the last digit for the number after Q.
     Qnum is to change the full number after Q, which is in a string type, to an integer.
     Qtotal is the total sum of Qnum.
     */
    
    int i=0;
    while (i<results.length()){
        if (results[i]=='Q'){ //if it finds Q in the string
            i++;
            Qstart=i;
            Qend=i;
            while (results[i]>='0'&&results[i]<='9'){ //until the character is no longer a number
                Qend=i;
                i++;
            }
            Qnum=stoi(results.substr(Qstart,Qend-Qstart+1)); //change the substring into a an integer and assign it to Qnum
            Qtotal+=Qnum;
        }
        i++;
    }
    return Qtotal;
}

int batches(string results){
    if(!isValidQC(results))
        return -1;
    
    int total=0; //total number of batches
    for (int i=0;i<results.length();i++){
        if (results[i]=='Q') //if it finds Q in the string
            total+=1;
    }
    return total;
}
