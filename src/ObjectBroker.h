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
class ActorSubdomain;

class ObjectBroker
{
public:
	// ObjectBroker();
	// ~ObjectBroker();
	
	ActorSubdomain* getNewActor(int action_tag, MPI_Channel* theChannel);
	

};