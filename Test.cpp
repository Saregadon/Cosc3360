#include <iostream>
#include <string>
#include <vector>

using namespace std;

void core_request(string how_long, string jobID, bool &core, vector <string> jobqueue)
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
void core_release(string jobID, bool &core, vector <string> Rqueue, int &completion)
{
    if(!Rqueue.empty())
    {
        //Rqueue.pop_back().front();
        //completion = current_time + how_long;
    }
    else
    {
        core = true;
    }
    //process next job request for job jobID
} //core_release

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