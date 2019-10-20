#include <assert.h>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>   
#include "AFMonitor.h"

using namespace std;

// halt motor external event
void AFMonitor::is_stable(void)
{
    // given the Halt event, transition to a new state based upon 
    // the current state of the state machine
    BEGIN_TRANSITION_MAP                        // - Current State -
        TRANSITION_MAP_ENTRY (ST_STABLE)        // ST_INIT
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // ST_STABLE
        TRANSITION_MAP_ENTRY (ST_STABLE)        // ST_TEND2UNSTABLE
        TRANSITION_MAP_ENTRY (ST_TEND2UNSTABLE) // ST_UNSTABLE
        TRANSITION_MAP_ENTRY (ST_STABLE)        // ST_TEND2STABLE
    END_TRANSITION_MAP(NULL)
}

// set motor speed external event
void AFMonitor::is_unstable(void)
{
     BEGIN_TRANSITION_MAP                        // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)     // ST_INIT
        TRANSITION_MAP_ENTRY (ST_TEND2UNSTABLE)  // ST_STABLE
        TRANSITION_MAP_ENTRY (ST_UNSTABLE)       // ST_TEND2UNSTABLE
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // ST_UNSTABLE
        TRANSITION_MAP_ENTRY (ST_UNSTABLE)       // ST_TEND2STABLE
    END_TRANSITION_MAP(NULL)
}

bool AFMonitor::eval_stability(AFMonitorData* af_monitor_data)
{
    int stability;
    // Initialize random number generator.
    
    stability  = (rand() % 2);

    if(stability==0){

        return false;
    }else{

        return true;

    }


}
// set motor speed external event
void AFMonitor::re_init()
{
     BEGIN_TRANSITION_MAP                        // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)     // ST_INIT
        TRANSITION_MAP_ENTRY (ST_INIT)  // ST_STABLE
        TRANSITION_MAP_ENTRY (ST_INIT)       // ST_TEND2UNSTABLE
        TRANSITION_MAP_ENTRY (ST_INIT)    // ST_UNSTABLE
        TRANSITION_MAP_ENTRY (ST_INIT)       // ST_TEND2STABLE
    END_TRANSITION_MAP(NULL)
}

// state machine sits here when motor is not running
void AFMonitor::ST_Init(AFMonitorData* af_monitor_data) 
{
	cout << "AFMonitor::ST_Init" << endl;
}

void AFMonitor::ST_Stable(AFMonitorData* af_monitor_data) 
{
    cout << "AFMonitor::ST_Stable" << endl;
}

void AFMonitor::ST_Tend2Unstable(AFMonitorData* af_monitor_data) 
{
    cout << "AFMonitor::ST_Tend2Unstable" << endl;
}

void AFMonitor::ST_Unstable(AFMonitorData* af_monitor_data) 
{
    cout << "AFMonitor::ST_Unstable" << endl;
}

void AFMonitor::ST_Tend2Stable(AFMonitorData* af_monitor_data) 
{
    cout << "AFMonitor::ST_Tend2Stable" << endl;
}



