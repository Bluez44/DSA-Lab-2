// In this exercise, we will use Standard Template Library List (click open in other tab to show more) to implement a Data Log. 

// This is a simple implementation in applications using undo and redo. For example in Microsoft Word, you must have nodes to store states when Ctrl Z or Ctrl Shift Z to go back or forward.

// DataLog has a doubly linked list to store the states of data (an integer) and iterator to mark the current state. Each state is stored in a node, the transition of states is depicted in the figure below. 

// Your task in this exercise is implement functions marked with /*  * TODO   */.

#include<bits/stdc++.h>
using namespace std;

class DataLog
{
private:
    list<int> logList;
    list<int>::iterator currentState;

public:
    DataLog();
    DataLog(const int &data);
    void addCurrentState(int number);
    void subtractCurrentState(int number);
    void save();
    void undo();
    void redo();

    int getCurrentStateData()
    {
        return *currentState;
    }
    
    void printLog()
    {      
        for (auto i = logList.begin(); i != logList.end(); i++) {
            if(i == currentState) cout << "Current state: ";
            cout << "[ " << *i << " ] => ";
        }
        cout << "END_LOG";
    }
};

DataLog::DataLog()
{
    /*
     * TODO:  add the first state with 0
     */
     logList.push_front(0);
     currentState = logList.begin();
}

DataLog::DataLog(const int &data)
{
    /*
     * TODO:  add the first state with data
     */
     logList.push_front(data);
     currentState = logList.begin();
}

void DataLog::addCurrentState(int number)
{
    /*
     * TODO: Increase the value of current state by number
     */
    cout << "Add\n";
    *currentState += number;
    printLog(); cout << endl;
}

void DataLog::subtractCurrentState(int number)
{
    /*
     * TODO: Decrease the value of current state by number
     */
    cout << "sub\n";
    *currentState -= number;
    printLog(); cout << endl;
}

void DataLog::save()
{
    /*
     * TODO: This function will create a new state, copy the data of the currentState
     *       and move the currentState Iterator to this new state. If there are other states behind the 
     *       currentState Iterator, we delete them all before creating a new state.
     */
    // logList.push_back(*currentState);
    // currentState++;
    if(currentState != logList.end()) {
        auto it = currentState;
        auto it2 = currentState;
        it++;
        while(it2 != logList.end()) it2++;
        logList.erase(it,it2);
    }

        logList.push_back(*currentState);
        currentState++;
    
    cout << "Save\n";
     printLog(); cout << endl;
}

void DataLog::undo()
{
    /*
     * TODO: Switch to the previous state of the data
     *       If this is the oldest state in the log, nothing changes
     */
     if(currentState != logList.begin()) {
        currentState--;
     }
    //  cout << "Undo\n";
     printLog(); cout << endl;
}

void DataLog::redo()
{
    /*
     * TODO: Switch to the latter state of the data
     *       If this is the latest state in the log, nothing changes
     */
    currentState++;
    if(currentState == logList.end()) currentState--;
}

int main() {
   DataLog log(10);
log.save();
log.undo();
log.undo();
log.addCurrentState(15);
log.save();
log.addCurrentState(15);
log.save();
log.save();
log.undo();
log.redo();
log.printLog();
cout << "\n";
log.redo();
log.printLog();
    return 0;

}