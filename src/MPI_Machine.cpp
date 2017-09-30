#include "MPI_Machine.h"

using namespace std;
MPI_Machine
::MPI_Machine(ObjectBroker *theBroker_, int argc, char **argv)
: theBroker(theBroker_)
{
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &procID);
	MPI_Comm_size(MPI_COMM_WORLD, &numProc);
	theChannels = vector<MPI_Channel*>(numProc) ;

	for (int i = 0; i < numProc; i++){
	    theChannels[i] = new MPI_Channel(i);
	}
}

MPI_Machine
::~MPI_Machine(){
	MPI_Finalize();
}
int MPI_Machine
::getProcessID(){
	return procID;
}

int MPI_Machine
::getNumProcess(){
	return numProc;
}

int MPI_Machine
::runActor(){
	MMout<<"MPI_Machine::runActor " <<endl;
    int done = 0;
    int msg = -1;
    // loop until recv kill signal
    while (!done){
    	if (!theChannels[0] ->receiveINT(msg) ){
    		cerr<<"ERROR!!! MPI_Machine::runActor failed to recv actorType " <<endl;
    		return 0;
    	}
    	int actorType = msg ;
    	if(msg == shadowActorAction_shutdown_slave_process ){
    		MMout<<"    Finalizing current actor " <<endl;
    		done = 1;
    		if(! theChannels[0] ->sendINT(done) ){
    			cerr<<"ERROR!!! MPI_Machine::runActor failed to send done status " <<endl;
    			return 0;
    		}
    	}else{
    		ActorSubdomain *theActor = theBroker->getNewActor(actorType, theChannels[0]);
    		if (!theActor){
    			cerr<<"ERROR!!! MPI_Machine::runActor failed to getNewActor " <<endl;
    			return 0;
    		}
    		int created=1;
    		if (!theChannels[0] ->sendINT(created)){
    		    cerr << "MachineBroker::run(void) - failed to send ID\n";
    		    return 0;
    		}
    		if (!theActor->run()){
    		    cerr << "MachineBroker::run(void) - actor failed while running\n";
    		    return 0;
    		}
    		delete theActor;
    	}
    }
	MMout<<"Actor Done!"<<endl;
	return 1;
}



MPI_Channel* MPI_Machine
::startActor(int actorType, int slaveID){
	MMout<<"MPI_Machine::startActor " <<endl;
	int msg = actorType;
	if(!theChannels[slaveID]->sendINT(msg)){
		cerr<<"ERROR!!! MPI_Machine::startActor failed to send actorType" <<endl;
		return 0;
	}
	int remote_actor_started=0;
	if (!theChannels[slaveID]->receiveINT(remote_actor_started)){
		cerr << "MPI_Machine::startActor() - failed recv remote actor # " << actorType  << "start status!" << endl;
		return 0;
	}
	if(!remote_actor_started){
		cerr << "MPI_Machine::startActor() - could not start remote actorType # " << actorType << endl;
		return 0;
	}
	return theChannels[slaveID];
}

int MPI_Machine
::shutdown(int slaveID){
	MMout<<"MPI_Machine::shutdown " <<endl;
	int msg = shadowActorAction_shutdown_slave_process;
	if(!theChannels[slaveID]->sendINT(msg)){
		cerr<<"ERROR!!! MPI_Machine::shutdown failed to send shutdown" <<endl;
		return 0;
	}
	int remote_actor_closed=0;
	if (!theChannels[slaveID]->receiveINT(remote_actor_closed)){
		cerr << "MPI_Machine::shutdown() - failed to recv close remote actor status " << endl;
		return 0;
	}
	if(!remote_actor_closed){
		cerr << "MPI_Machine::shutdown() - could not closed remote actor " << endl;
		return 0;
	}
	return 1;
}