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

class MPI_Channel;
class ObjectBroker;

class ActorSubdomain: public Domain
{
public:
	ActorSubdomain(MPI_Channel* theChannel_,
                   ObjectBroker* theBroker);
	virtual ~ActorSubdomain();
	int run();

private:
	MPI_Channel* theChannel;
	ObjectBroker* theBroker;
	std::vector<int> msg;
};