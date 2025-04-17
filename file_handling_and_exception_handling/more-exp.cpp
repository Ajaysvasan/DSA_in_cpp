#include<iostream>
#include<fstream>
#define fileName "exp.txt"
void write(){
    std::string line;
    std::getline(std::cin,line);
    std::fstream file;
    file.open(fileName,std::ios::app);
    if(file.is_open()){
        file<<line<<"\n";
        std::cout<<"Content written in the file successfully\n";
    }else {
        throw "Error in writing the file";
    }
    file.close();
}

void read(){
    std::cout<<"Reading the contents from the file\n";
    std::fstream file;
    std::string line;
    file.open(fileName,std::ios::in);
    if(file.is_open()){
        while(std::getline(file,line)){
            std::cout<<line<<"\n";
        }
    }else{
        std::cerr<< "Error in file reading\n";
    }
    std::cout<<"The read operation was successfull\n";
    file.close();
}

void DeleteContents(){
    std::cout<<"Deleting the contents from the file\n";
    std::fstream file;
    file.open(fileName,std::ios::out);
    file.clear();
    file.close();
}

int main(){
    try{
        for(int i = 0;i<3;++i){
            // write();
        }
        read();
        DeleteContents();
        read();
    }catch(...){
        std::cerr<<"Exception occured\n";
    }
    return 0;
}