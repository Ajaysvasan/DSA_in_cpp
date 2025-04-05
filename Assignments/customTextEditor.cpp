#include<iostream>
#include<fstream>
#include<string>
#include <sstream>

class Documents{
    private:
        std::string m_file_name = "document.txt";
        void write(std::string input){
            std::fstream m_my_file;
            m_my_file.open(m_file_name,std::ios::app);
            if(m_my_file.is_open()){
                m_my_file<<input+"\n";
            }
            m_my_file.close();
        }

        void read(){
            std::fstream m_my_file;
            m_my_file.open(m_file_name,std::ios::in);
            std::string line;
            if(m_my_file.is_open()){
                while(std::getline(m_my_file,line)){
                    std::cout<<line<<std::endl;
                }
            }
            m_my_file.close();
        }
        

    public:
        friend std::istream& operator>>(std::istream&in , Documents& doc){
            std::string input;
            std::getline(in,input);
            doc.write(input);
            return in;
        }

        friend std::ostream& operator<<(std::ostream&out,Documents&doc){
            doc.read();
            return out;
        }
};

int main() {
    Documents doc;
    std::string input;
    while (true) {
        std::cout << "Enter a string (or 'q' to quit): ";
        std::getline(std::cin, input);
        if (input == "q") break;

        std::stringstream ss(input);
        ss >> doc;
    }

    std::cout << "\nContents of the file:\n";
    std::cout << doc;
    return 0;
}