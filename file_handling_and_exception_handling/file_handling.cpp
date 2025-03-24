#include<iostream>
#include<fstream>

using namespace std;

main(){
    fstream myFile;
    myFile.open("sample.txt",ios::out);//ios is the mode. out->write
    if(myFile.is_open()){
        myFile<<"Hello world\nLine one\nLine two"; 
        myFile.close();
    }
    myFile.open("sample.txt",ios::app);//ios is the mode. app->append
    if(myFile.is_open()){
        myFile<<"\nI am Ajay"; 
        myFile.close();
    }

    myFile.open("sample.txt",ios::in);//ios is the mode. in->read
    if(myFile.is_open()){
        string line; 
        while(getline(myFile,line)){
             cout<<line<<endl;
        }
        myFile.close();
    }
}