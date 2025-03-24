#include<iostream>
#include<fstream>
#include <bits/stdc++.h>
using namespace std;

class EncryptDecrypt{
    private:
        string fileName = "TaskOne.txt";
        vector<int> encrypt(string line){
            vector<int> arr;
            for(int i = 0;i<line.length();++i){
                int convert = line[i];
                arr.push_back(convert);
            }
            return arr;
        }

        void decrypt(int line){
            
        }

    public:
        void writeInFile(){
            string line;
            getline(cin,line);
            vector<int> encrpyted = encrypt(line);
            fstream myFile;
            myFile.open(fileName,ios::app);
            if(myFile.is_open()){
                for(int num:encrpyted){
                    myFile<<num;
                }
            }
        }

        void readFromFile(){
            fstream myFile;
            myFile.open(fileName,ios::in);
            if(myFile.is_open()){
                string line;
                while(getline(myFile,line)){
                    int num = 0;
                    for(int i = 0;i<line.length();++i){
                        num = num * 10 + (line[i] - '0');
                        if(num>=32 && num <=122){
                            char ch = (char)num;
                            cout<<ch;
                            num = 0;
                        }
                    }
                }
            }
        }

        
};

main(){
    EncryptDecrypt obj;
    bool run = true;
    while(run){
       obj.writeInFile();
        cout<<"Do you want to continue ?";
         string choice;
       cin>>choice;
       if(choice=="No"||choice == "no"){
            run = false;
         }
    }
    obj.readFromFile();
    system("pause>0");
}
