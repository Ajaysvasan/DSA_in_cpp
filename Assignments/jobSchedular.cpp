#include<iostream>
#include<queue>
#include<unistd.h>

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
        void addTask(std::string job_name,unsigned short job_priority,unsigned int timeStamp,unsigned int job_id){
            if(job_priority>SHRT_MAX || job_priority < SHRT_MIN){
                throw -1;
            }
            jobs.push({job_name,job_priority,timeStamp,job_id});
            m_count++;
        }

        void runTask(){
            std::cout<<"Executing Job "<<jobs.top().jobName<<std::endl;
            sleep(jobs.top().timeStamp);
            std::cout<<"The job has been executed"<<std::endl;
            jobs.pop();
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
    JobSchedular job_schedular;
    try{
        job_schedular.addTask("Run VS code",10,2,1);
        job_schedular.addTask("Run spotify",5,9,2);
        job_schedular.addTask("Run chome",7,10,3);
        job_schedular.addTask("Run GPT",10,5,4);
    }catch(int err){
        std::cout<<"Exception "<<err<<" Occured"<<std::endl;
    }catch(...){
        std::cout<<"Unknown Exception occured"<<std::endl;
    }
    job_schedular.displayPendingTask();
    
    job_schedular.runTask();
    job_schedular.runTask();

    job_schedular.displayPendingTask();
    return 0;
}