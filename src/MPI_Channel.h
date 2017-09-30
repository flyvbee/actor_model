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

using namespace std;
class MPI_Channel
{
public:
	MPI_Channel(int otherRank);
	~MPI_Channel();

	int receiveINT(int & msg);
	int sendINT(int & msg);
	int receiveVecINT(vector<int>&  msg);
	int sendVecINT(vector<int>&  msg);
private:
	int _otherRank;
	MPI_Comm _otherComm;

};