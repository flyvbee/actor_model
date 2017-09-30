#pragma once
#include <Domain.h>
#include <vector>
#include <ActorSubdomain.h>
#include <MPI_Channel.h>
#include <MPI_Machine.h>
#include <ObjectBroker.h>
#include <PartitionedDomain.h>
#include <shadowActorActions.h>
#include <ShadowSubdomain.h>
#include <mpi.h>

class ObjectBroker;
class MPI_Channel;
using namespace std;
#define MMout std::cout << "MPI_Machine(" << procID << "): "
class MPI_Machine
{
public:
	MPI_Machine(ObjectBroker *theBroker, int argc, char** argv);
	~MPI_Machine();

	int getProcessID();
	int getNumProcess();
	// for slave processes
	int runActor();

	// for the shadow of the master process.
	MPI_Channel* startActor(int actorType, int slaveID);
	int shutdown(int slaveID);
private:
	int procID;
	int numProc;
	vector<MPI_Channel*> theChannels;
	ObjectBroker* theBroker;
	
};