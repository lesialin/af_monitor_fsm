#ifndef _AFMONITOR_H
#define _AFMONITOR_H
#include "StateMachine.h"

// structure to hold event data passed into state machine
struct MotionData: public EventData
{
    float gyro[3];
    float acc[3];
    float gravity[3];

};

struct AFStat: public EventData
{
    float fv;
    float pd;
    float pd_conf;

};

struct AEStat: public EventData
{
    unsigned int* lum_sum;
    unsigned int* lum_count;
};


 
struct AFMonitorData : public EventData
{
    MotionData* motion_data;
    AFStat* af_stat;
    AEStat* ae_stat;

};


// the AFMonitor state machine class
class AFMonitor : public StateMachine
{
public:
    AFMonitor() : StateMachine(ST_MAX_STATES) {}

    // external events taken by this state machine
    void is_stable();
    void is_unstable();
    void re_init();

    bool stability;

    // function to evaluate focus stability
    bool eval_stability(AFMonitorData*);

private:
    // state machine state functions
    void ST_Init(AFMonitorData*);
    void ST_Stable(AFMonitorData*);
    void ST_Tend2Unstable(AFMonitorData*);
    void ST_Unstable(AFMonitorData*);
    void ST_Tend2Stable(AFMonitorData*);

    

    // state map to define state function order
    BEGIN_STATE_MAP
		STATE_MAP_ENTRY(&AFMonitor::ST_Init)
        STATE_MAP_ENTRY(&AFMonitor::ST_Stable)
        STATE_MAP_ENTRY(&AFMonitor::ST_Tend2Unstable)
        STATE_MAP_ENTRY(&AFMonitor::ST_Unstable)
        STATE_MAP_ENTRY(&AFMonitor::ST_Tend2Stable)

    END_STATE_MAP

    // state enumeration order must match the order of state
    // method entries in the state map
    enum E_States { 
        ST_INIT = 0,
        ST_STABLE,
        ST_TEND2UNSTABLE,
        ST_UNSTABLE,
        ST_TEND2STABLE,
        ST_MAX_STATES
    };
};
#endif // _MOTOR_H
