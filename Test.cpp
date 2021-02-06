#include <iostream>
#include <string>
#include <queue>

using namespace std;

void core_request(string how_long, string jobID, bool &core, queue <string> jobqueue)
{
    if(core == true) //true == free
    {
        core = false; //false == busy
        //schedule CORE completion at time
        //current_time + how_long for job jobID;
    }
    else
    {
        //jobqueue.push_back(jobID);  //queue jobID in readyQueue
    }
} //core_request

//change to int to return completion time?
void core_release(string jobID, bool &core, queue <string> Rqueue, int &completion)
{
    if(!Rqueue.empty())
    {
        //Rqueue.pop_back().front();
        //completion = current_time + how_long; //how_long == jobID
    }
    else
    {
        core = true;
    }
    //process next job request for job jobID
} //core_release

void disk_request(int how_long, queue <string> Dqueue, string jobID, int &completion, bool &disk)
{
    if(how_long == 0)
    {
        //perform next job request
    }
    else if(disk == true) //true == free
    {
        disk = false; //false == busy
        //schedule DISK completion event at time
        //completion = current_time + how_long for job jobID
    }
    else
    {
        //Dqueue.push_back(jobID) in diskQueue
    }
} // disk_request

void disk_completion(int how_long, string jobID, queue <string> Dqueue, int &completion, bool &disk)
{
    if(!Dqueue.empty())
    {
        //Dqueue.pop_back()
        //completion = current_time + how_long; //how_long == jobID
    }
    else
    {
        disk = true;
    }
    //process next job request for job jobID
} //disk_completion

void spooler_request(int how_long, string jobID, queue <string> Squeue, int &completion, bool &disk)
{
    if(disk == true) //true == free //should be spooler bool?
    {
        disk = false;
        //schedule SPOOLER completion event at time
        //completion = current_time + how_long; //how_long == jobID
    }
    else
    {
        //Squeue.push(jobID);
    }
} //spooler_request

void spooler_release(int how_long, string jobID, queue <string> Squeue, int &completion, bool &spooler)
{
    if(!Squeue.empty())
    {
        Squeue.pop();
        //completion = current_time + how_long;
    }
    else
    {
        spooler = true;
    }
    //process next job request for job jobID
} //spooler_release

int main()
{
    string keyword, argument;

    while(cin >> keyword >> argument)
    {
        cout << keyword << argument << endl;
    }

    return 0;
}
//get timer working
//3 queues
//add time each process finishes at and divide it by number of jobs = computing itme;
//total simulation time in ms - 
//number of jobs that have been completed - 
//total number of disc requests - 
//cpu utilization, fraction of time device was busy between 0 and 1 -