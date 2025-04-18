#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<dirent.h>
#define FILENAME "dataframe.txt"

std::vector<std::string> Type;

enum  DATA_TYPE { 
    INVALID = -1,
    INTEGER,
    STRING,
    BOOL
};

bool validType(std::string typeValue){
    if(typeValue == "int" || typeValue == "string" || typeValue == "bool") return true;
    return false;
}

void printType(){
    if(!Type.empty()){
        for(std::string value:Type){
            std::cout<<value<<"\n";
        }
    }else{
        std::cerr<<"The vector in empty\n";
    }

}

// attributes are column names
bool createDataframe(std::map<std::string,std::string> attributes){
    std::fstream file;
    DIR *dir;   
    struct dirent *en;
    dir = opendir("file_handling_and_exception_handling");
    if(dir){
        while((en = readdir(dir))!=NULL){
            std::string fileName = en->d_name;
            if(fileName == FILENAME){
                std::cerr<<"The dataframe alread exsists\n";
                closedir(dir);
                return false;
            }
        }
    }
    std::cout<<"Creating dataFrame\n";
    file.open(FILENAME,std::ios::app);
    if(file.is_open()){
        for(const auto & attr :attributes){
            if(validType(attr.second)){
            file<<attr.first<<" ";
            Type.push_back(attr.second);
            }else{
                std::cerr<<"Invalid data type entered \n";
                return false;
            }
        }
        std::cout<<"The dataframe is created successfully\n";
        printType();
        file<<"\n";    
        file.close();
    }else{
        std::cerr<<"There is an error in creating the dataframe";
        return false;
    }
    return true;
}

void writeInDataframe(std::vector<std::string> values){
    std::fstream file;
    DIR *dir;   
    bool flag = true;
    if(flag){
        file.open(FILENAME,std::ios::app);
        if(file.is_open()){
            for(const auto& value:values){
                file<<value<<" ";
            }
            file<<"\n";
        }else{
            std::cout<<"Error in opening the file\n";
            return;
        }    
    }else{
        std::cout<<"Error in changing the flag\nExpected flag value " <<!flag<< " got "<<flag<<"\n";
        return;
    }
}

void readFromDataFrame(){
    std::cout<<"Reading the contents from the file\n";
    std::fstream file;
    std::string line;
    file.open(FILENAME,std::ios::in);
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

int main(){
    std::vector<std::string> values = {"18","Ajay","07"};
    writeInDataframe(values);
    readFromDataFrame();
    return 0;
}