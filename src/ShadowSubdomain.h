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
// class Domain;
class MPI_Machine;
class ObjectBroker;
class MPI_Channel;

using namespace std;
class ShadowSubdomain: public Domain
{
public:
	ShadowSubdomain(int tag,
				  MPI_Machine &theMachine,
                  ObjectBroker &theObjectBroker);
	virtual ~ShadowSubdomain();
	int hello_world();
	int partition_input_A();
	int partition_input_B();
	int new_step();
	int update();
	int compute();
	int check_residual();
	int commit();
	int revert();
	int collect_results();
	int say_bye();
private:
	MPI_Channel* theChannel;
	vector<int> msg;
};