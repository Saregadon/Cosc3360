//Christian Schuering - Assignment 1
//PSID 1932884

//Program evaluates job queues and implements a FIFO basis of a waiting list for jobs

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <numeric>

using namespace std;
/* Linked List Implementation
struct node
{
    node* prev;
    node* next;
    string k; //keyword
    int a; //argument
};

struct linecounter
{
    linecounter* next;
    int linestart; //line starts after job #
    int lineend; //line end ends before next # or end of file
};

void addnode(node* head, string keyword, int argument)
{
    node* data = new node; //allocating memory for new node
    data->k = keyword; //adding keyword to block [i] of new node
    data->a = argument; //adding argument to block [i] of new node
    data->next = head; //setting next node as the head
    head = data; //setting the head to a new nullptr node
}

//probably just implement doubly linked list
void deletenode(node* head, node* temp) //head and temp = head->next->next (put in main)
{
    node* prev = head;
    if(head == temp)
    {
        if(head->next == nullptr)
        {
            cout << "Can't transfer nullptr to next node." << endl; return;
        }

        //setting keyword and argument = to the next nodes in the list;
        head->k = head->next->k;
        head->a = head->next->a;

        //store address of next node inside of temp variable for deletion
        temp = head->next;

        //quite literally delete temp
        delete temp;
        return;
    }

    while(prev->next != nullptr && prev->next != temp) prev = prev->next;

    if(prev->next == nullptr)
    {
        cout << "Can't delete nullptr previous node" << endl; return;
    }

    //provide the next variable behind the head node to delete the previous node
    prev->next = prev->next->next;

    delete temp;
    return;
}
*/
void core_request(string how_long, int jobID, vector<int> jobqueue, bool &core)
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
void core_release(int how_long, int jobID, vector<int> Rqueue, int &completion, bool &core)
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

void disk_request(int how_long, vector<int> Dqueue, int jobID, int &completion, bool &disk)
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

void disk_completion(int how_long, int jobID, vector<int> Dqueue, int &completion, bool &disk)
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

void spooler_request(int how_long, int jobID, vector<int> Squeue, int &completion, bool &disk)
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

void spooler_release(int how_long, int jobID, vector<int> Squeue, int &completion, bool &spooler)
{
    if(!Squeue.empty())
    {
        Squeue.pop_back();
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
    //head node is the 0th node when starting
    //node* head;

    //linecounter = jobstarting number && linecounter = jobending number
    //linecounter* head;

    vector<string> veckeyword; //keyword
    vector<string> vecargument; //argument
    vector<string> jobnumber; //iterates anytime a new job is issued
    vector<string> expectedtimeforjob; //pushes expected time for each new job

    //array holds core, disk and spooler;
    string keyword;
    string argument;

    while(cin >> keyword >> argument)
    {
        //cout << keyword << argument << endl;
        //addnode(head, keyword, argument);
        veckeyword.push_back(keyword);
        vecargument.push_back(argument);
    }

    cout << "/////////////////////////////////////" << endl;

    for(int i = 0; i < veckeyword.size(); i++)
    {
        //equation start
        cout << veckeyword[i] + " ";
        cout << vecargument[i] + " ";
        cout << endl;

        if(veckeyword[i] == "JOB") //takes in the job #
        {
            jobnumber.push_back(vecargument[i]);
            int numberhold = 0, j = i++;
            while(veckeyword[j] != "JOB") // then iterates through the keywords, while at the same time ignoring the keyword JOB
            {
                numberhold += stoi(vecargument[j]); //adding the arguments up until the next job
                j++;
            }
            expectedtimeforjob.push_back(to_string(numberhold)); //giving an expected time completion for each new job
        }
        else if(veckeyword[i] == "CORE")
        {

        }
        else if(veckeyword[i] == "PRINT")
        {

        }
        else if(veckeyword[i] == "DISK")
        {

        }
    }
    
    for(int i = 0; i < expectedtimeforjob.size(); i++)
    {
        cout << expectedtimeforjob[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < jobnumber[i].size(); i++)
    {
        cout << jobnumber[i] << " ";
    }
    cout << endl;

    return 0;
}
//get timer working
//3 queues
//add time each process finishes at and divide it by number of jobs = computing itme;
//total simulation time in ms - 
//number of jobs that have been completed - 
//total number of disc requests - 
//cpu utilization, fraction of time device was busy between 0 and 1 -
//must use strings, manipulate when changing to ints then change back to strings for final output