#include<iostream>
#include<queue>
#include<thread>

class PatientEmergency{
    private:
        struct Patients{
            std::string name;
            unsigned short priority;
            unsigned short age;
            unsigned int patient_id;
            bool operator<(const Patients& other) const {
                if(this->priority < other.priority){
                    return true;
                }else if(this->priority == other.priority){
                    return this->age < other.age;
                }
                return false;
            }
        };
        std::priority_queue<Patients> patients;
        int m_count = 0;
    public:
        void getPatientCount(){
            std::cout<<"The number of patients is "<<m_count<<std::endl;
        }

        void addPatients(std::string patient_name,unsigned short patient_priority,unsigned short patient_age, unsigned int patient_id ){
            if(patient_priority > SHRT_MAX || patient_priority < SHRT_MIN){
                throw -1;
            }
            patients.push({patient_name,patient_priority,patient_age,patient_id});
            m_count++;
        }

        void treatPatients(){
            if(patients.empty()){
                std::cout<<"All the patients are treated"<<std::endl;
                return;
            }
            std::cout<<"Treating Patient "<<patients.top().name<<std::endl;
            std::cout<<"Patient "<<patients.top().name<<" treated"<<std::endl;
            patients.pop();
            m_count--;
        }

        void displayPendingPatients(){
            std::priority_queue<Patients>PendingPatients = patients;
            if(PendingPatients.empty()){
                std::cout<<"All the patients are treated"<<std::endl;
                return;
            }
            int i = 0;
            while(!PendingPatients.empty()){
                std::cout<<i+1<<" "<<PendingPatients.top().name<<std::endl;
                ++i;
                PendingPatients.pop();
            }
        }
};

int main(){
    PatientEmergency obj;
    try{
        obj.addPatients("Patient One",8,55,1);
        obj.addPatients("Patient Two",6,85,2);
        obj.addPatients("Patient Three",5,25,3);
        obj.addPatients("Patient Four",8,35,4);
        obj.addPatients("Patient Five",10,45,5);
    }catch(int err){
        std::cout<<"Exception "<<err<<" has occured"<<std::endl;
    }
    obj.displayPendingPatients();
    std::cout<<std::endl;
    obj.getPatientCount();
    std::cout<<std::endl;
    obj.treatPatients();
    obj.treatPatients();
    obj.getPatientCount();
    std::cout<<std::endl;
    obj.displayPendingPatients();

    return 0;
}