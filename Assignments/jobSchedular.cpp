#include<iostream>
#include<queue>
#include<unistd.h>
#include<thread>

class JobSchedular{
    private:
        struct Task
        {
            std::string jobName;
            unsigned short priority;
            unsigned int timeStamp,id;
            bool operator<(const Task& other) const{
                if(this->priority < other.priority){
                    return true;
                }else if(this->priority == other.priority){
                    return this->timeStamp > other.timeStamp;
                }
                return false;
            }
        };
        int m_count = 0;
        std::priority_queue<Task> jobs;
    
    public:
        void addTask(std::string jobName,unsigned short jobPriority,unsigned int timeStamp,unsigned int jobId){
            if(jobPriority>SHRT_MAX || jobPriority < SHRT_MIN){
                throw -1;
            }
            jobs.push({jobName,jobPriority,timeStamp,jobId});
            m_count++;
        }

        void runTask(){
            std::cout<<"Executing Job "<<jobs.top().jobName<<std::endl;
            sleep(jobs.top().timeStamp);
            std::cout<<"The job has been executed"<<std::endl;
            jobs.pop();
            m_count--;
        }
        void displayPendingTask(){
            std::priority_queue<Task> pendingTasks = jobs;
            int i = 0;
            if(jobs.empty()){
                std::cout<<"All Jobs have been executed"<<std::endl;
                return;
            }
            while(!pendingTasks.empty()){
                std::cout<<i+1<<" "<<pendingTasks.top().jobName<<std::endl;
                pendingTasks.pop();
                ++i;
            }
        }
};

int main(){
    JobSchedular jobSchedular;
    std::string jobName;
    unsigned short jobpPriority;
    unsigned int timeStamp ,id;
    try{
        jobSchedular.addTask("Run VS code",10,2,1);
        jobSchedular.addTask("Run spotify",5,9,2);
        jobSchedular.addTask("Run chome",7,10,3);
        jobSchedular.addTask("Run GPT",10,5,4);
    }catch(int err){
        std::cout<<"Exception "<<err<<" Occured"<<std::endl;
    }catch(...){
        std::cout<<"Unknown Exception occured"<<std::endl;
    }
    jobSchedular.displayPendingTask();
    
    jobSchedular.runTask();
    jobSchedular.runTask();

    jobSchedular.displayPendingTask();
    return 0;
}