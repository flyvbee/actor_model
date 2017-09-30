#include "ActorSubdomain.h"

using namespace std;

ActorSubdomain
::ActorSubdomain(MPI_Channel* theChannel_,
                   ObjectBroker* theBroker_)
:theChannel(theChannel_), theBroker(theBroker_)
{
}

ActorSubdomain
::~ActorSubdomain(){
}

int 
ActorSubdomain
::run(){
	bool doneSimulation = false;
	msg = vector<int>(4);

	while (!doneSimulation){
		theChannel->receiveVecINT(msg);
		int action = msg[0] ;
		switch(action){
			case shadowActorAction_hello_world:{
				this->hello_world();
				break;
			}
			case shadowActorAction_partition_input_A:{
				this->partition_input_A();
				break;
			}
			case shadowActorAction_partition_input_B:{
				this->partition_input_B();
				break;
			}
			case shadowActorAction_new_step:{
				this->new_step();
				break;
			}
			case shadowActorAction_update:{
				this->update();
				break;
			}
			case shadowActorAction_compute:{
				this->compute();
				break;
			}
			case shadowActorAction_check_residual:{
				this->check_residual();
				break;
			}
			case shadowActorAction_commit:{
				this->commit();
				break;
			}
			case shadowActorAction_revert:{
				this->revert();
				break;
			}
			case shadowActorAction_collect_results:{
				this->collect_results();
				break;
			}
			case shadowActorAction_say_bye:{
				this->say_bye();
				doneSimulation = true;
				break;
			}
			default:{
				cerr<< " ERROR!!! ActorSubdomain::run() Unknown Action! " ;
				cerr<< " actionTag = " << action <<endl;
				return 0;
			}
		}
	}
	return 1;
}
