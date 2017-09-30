#include "ShadowSubdomain.h"

using namespace std;
ShadowSubdomain
::ShadowSubdomain(int slaveID,
				  MPI_Machine &theMachine,
                  ObjectBroker &theObjectBroker)
{
	theChannel = theMachine.startActor(shadowActorAction_create_subdomain, slaveID);
	msg = vector<int>(4);
}

ShadowSubdomain
::~ShadowSubdomain(){
}

int ShadowSubdomain
::hello_world(){
	msg[0] = shadowActorAction_hello_world;
	theChannel->sendVecINT(msg);
	return 1;
}

int ShadowSubdomain
::partition_input_A(){
	msg[0] = shadowActorAction_partition_input_A;
	theChannel->sendVecINT(msg);
	return 1;
}

int ShadowSubdomain
::partition_input_B(){
	msg[0] = shadowActorAction_partition_input_B;
	theChannel->sendVecINT(msg);
	return 1;
}

int ShadowSubdomain
::new_step(){
	msg[0] = shadowActorAction_new_step;
	theChannel->sendVecINT(msg);
	return 1;
}

int ShadowSubdomain
::update(){
	msg[0] = shadowActorAction_update;
	theChannel->sendVecINT(msg);
	return 1;
}

int ShadowSubdomain
::compute(){
	msg[0] = shadowActorAction_compute;
	theChannel->sendVecINT(msg);
	return 1;
}

int ShadowSubdomain
::check_residual(){
	msg[0] = shadowActorAction_check_residual;
	theChannel->sendVecINT(msg);
	return 1;
}

int ShadowSubdomain
::commit(){
	msg[0] = shadowActorAction_commit;
	theChannel->sendVecINT(msg);
	return 1;
}

int ShadowSubdomain
::revert(){
	msg[0] = shadowActorAction_revert;
	theChannel->sendVecINT(msg);
	return 1;
}

int ShadowSubdomain
::collect_results(){
	msg[0] = shadowActorAction_collect_results;
	theChannel->sendVecINT(msg);
	return 1;
}

int ShadowSubdomain
::say_bye(){
	msg[0] = shadowActorAction_say_bye;
	theChannel->sendVecINT(msg);
	return 1;
}
