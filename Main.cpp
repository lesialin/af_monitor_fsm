// StateMachine sample application. The Motor.h/cpp state machine 
// follows the C/C++ Users Journal article by David Lafreniere "State 
// Machine Design in C++". The StateMachine base class has been updated
// to compile on modern C++ compilers but the article concepts still 
// hold true. 
//
// http://www.drdobbs.com/cpp/state-machine-design-in-c/184401236
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>   
#include "AFMonitor.h"
#include <iostream>

using namespace std;

int main(void)
{
	bool stability;
	bool fs_done;

	int loop_time = 50;
	
	srand(time(NULL));

	AFMonitor af_montior;
	
	

	while(loop_time >0){
		
		AFMonitorData* data = new AFMonitorData();
		
		//evaluate current stability
		stability = af_montior.eval_stability(data);
		fs_done  = (rand() % 2)==0 ? false: true;

		cout <<"stability = "<<stability<<", fs_done = "<<fs_done<<endl;
		
		if(fs_done){
			af_montior.re_init();
		}

		if(stability){

			af_montior.is_stable();
		}else{
			af_montior.is_unstable();

		}

		loop_time--;
	}
	
	


	return 0;
}

