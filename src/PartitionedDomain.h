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

class ShadowSubdomain;
// class Domain;

using namespace std;
class PartitionedDomain: public Domain
{
public:
	// PartitionedDomain();
	// ~PartitionedDomain();
	
	virtual int hello_world() final;
	virtual int partition_input_A() final;
	virtual int partition_input_B() final;
	virtual int new_step() final;
	virtual int update() final;
	virtual int compute() final;
	virtual int check_residual() final;
	virtual int commit() final;
	virtual int revert() final;
	virtual int collect_results() final;
	virtual int say_bye() final;

	int addSubdomain(ShadowSubdomain* sub);
private:
	vector<ShadowSubdomain*> theSubs;
};