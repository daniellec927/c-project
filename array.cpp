/*
 Com Sci 31 Project 4
 array.cpp
 Author: Danielle Choi
 UID: 306008729
 Discussion Section: 1C
 Date: 2023/02/19.
 */

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int locateMaximum(const string array[],int n);
int countFloatingPointValues(const string array[],int n);
bool hasNoCapitals(const string array[],int n);
int shiftLeft(string array[],int n,int amount,string placeholder);

int main() {
    //test cases
    string data[5]={"mamaBbcca","mamaBbcca","12,","98.76","tyrion"};
    string folks[8]={"samwell","jon","margaery","daenerys","tyrion","sansa","magdalena","jon"};
    string hello[5]={"ash","hello","12,","98.76","help"};
    string hello1[5]={"ash","hello","12,","98.76","hellop"};
    string p1[5]={"ash","hello","12","98.76.","help"};
    string p2[5]={"ash","hello","12.","98.76","help"};
    string p3[5]={"ash","hello","12..","98.76","help"};
    string p4[5]={"ash","hello","12..","+98.76","help"};
    string p5[5]={"ash","hello","12..","98.f76","help"};
    string p6[5]={"123","4.57",".12","98.","help"};
    string p7[5]={"123","4.57",".12",".","help"};
    string data2[5]={"mamabbcca","mamaBbcca","12,","98.76","tyrion"};
    string data3[10] = {"1", "1.", ".1", "01", ".01", "01.", "1 1", "1 ", "1,000,000", "1..0"};
    string empty[5]={"mamaBbcca","mamaBbcca","12,","98.76",""};
    string empty2[5]={"mamabbcca","mamabbcca","12,","98.76",""};
    string onlyempty[5]={"","","","",""};
    string same[5]={"hi","hi","hi","hi","hi"};

    assert(locateMaximum(data, 5)==4);
    assert(locateMaximum(data, 4)==0);
    assert(locateMaximum(data, 0)==-1);
    assert(locateMaximum(hello, 5)==4);
    assert(locateMaximum(hello1, 5)==4);
    assert(locateMaximum(folks, 5)==4);
    assert(locateMaximum(folks, 8)==4);
    assert(locateMaximum(empty, 5)==0);
    assert(locateMaximum(data3, 10)==9);
    assert(locateMaximum(onlyempty, 5)==0);
    assert(locateMaximum(same, 5)==0);

    assert(countFloatingPointValues(data, 5)==1);
    assert(countFloatingPointValues(data, 0)==-1);
    assert(countFloatingPointValues(folks, 1)==0);
    assert(countFloatingPointValues(p1, 5)==1);
    assert(countFloatingPointValues(p2, 5)==2);
    assert(countFloatingPointValues(p3, 5)==1);
    assert(countFloatingPointValues(p4, 5)==0);
    assert(countFloatingPointValues(p5, 5)==0);
    assert(countFloatingPointValues(p6, 5)==4);
    assert(countFloatingPointValues(p7, 5)==3);
    assert(countFloatingPointValues(empty, 5)==1);

    assert(hasNoCapitals(data, 5)==false);
    assert(hasNoCapitals(data, 0)==true);
    assert(hasNoCapitals(folks, 8)==true);
    assert(hasNoCapitals(hello, 5)==true);
    assert(hasNoCapitals(data2, 5)==false);
    assert(hasNoCapitals(empty, 5)==false);
    assert(hasNoCapitals(empty2, 5)==true);

    assert(shiftLeft(data, 5, 2, "foo")==2);
    assert(shiftLeft(data, 0, 2, "foo")==-1);
    assert(shiftLeft(data, 5, -1, "foo")==-1);
    assert(shiftLeft(data, 5, 0, "foo")==0);
    assert(shiftLeft(data, 5, 10, "bar")==5);
    assert(shiftLeft(data, 3, 10, "bar")==3);
    assert(shiftLeft(data, 3, 2, "bar")==2);
    assert(shiftLeft(folks, 8, 2, "jon")==2);
    assert(shiftLeft(empty, 5, 2, "jon")==2);

    cerr<<"All tests succeeded"<<endl;
    
//    cout<<shiftLeft(empty, 5, 2, "jon")<<endl;
//    for (int i=0;i<5;i++){
//        cout<<empty[i]<<" ";
//    }
    cout<<endl;
    return 0;
}

int locateMaximum(const string array[],int n){
    if(n<=0)
        return -1;
    int maxIndex=0;
    for (int i=1;i<n;i++){
        for (int j=0;j<array[i].length();j++){
            if (array[i][j]>array[maxIndex][j]){
                maxIndex=i; //change the maxIndex if the new element is larger than the previous element of the maxIndex
                break;
            } else if (array[i][j]==array[maxIndex][j])
                continue; //if the i-th character of the elements have the same value, continue the loop
            else
                break;
        }
    }
    return maxIndex;
}

int countFloatingPointValues(const string array[],int n){
    if (n<=0)
        return -1;
    bool floatingPoint=false;
    int numOfFloatingPoints=0;
    for (int i=0;i<n;i++){
        if (array[i]=="")
            continue; //if the element is an empty string, don't count it but continue the loop
        int numOfDot=0;
        int numOfNum=0;
        for (int j=0;j<array[i].length();j++){
            if (array[i][j]>='0'&&array[i][j]<='9'){
                floatingPoint=true;
                numOfNum++;
            } else if(array[i][j]=='.'){
                floatingPoint=true;
                numOfDot++;
            } else
                floatingPoint=false;
            if (numOfDot>1)
                floatingPoint=false; // if there is more than one dot in the string
            if (!floatingPoint)
                break;
        }
        if (numOfNum==0)
            floatingPoint=false; //if there is no number in the string
        if (floatingPoint){
            numOfFloatingPoints++;
        }
    }
    return numOfFloatingPoints;
}

bool hasNoCapitals(const string array[],int n){
    if (n<=0)
        return true;
    for (int i=0;i<n;i++){
        for (int j=0;j<array[i].length();j++){
            if(array[i][j]>='A'&&array[i][j]<='Z')
                return false;
        }
    }
    return true;
}

int shiftLeft(string array[],int n,int amount,string placeholder){
    if (n<=0||amount<0)
        return -1;
    int numOfPlaceholder=0;
    for (int i=0;i<n;i++){
        if (i<n-amount)
            array[i]=array[i+amount]; //move the element to the left of the amount
        else{
            array[i]=placeholder; //replace the rest of the array with placeholder
            numOfPlaceholder++;
        }
    }
    return numOfPlaceholder;
}
