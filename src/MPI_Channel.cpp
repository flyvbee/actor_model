#include "MPI_Channel.h"

constexpr int GLOBAL_MSG_TAG = 99;

using namespace std;
MPI_Channel
::MPI_Channel(int otherTag_)
: _otherRank(otherTag_), _otherComm(MPI_COMM_WORLD)
{
}



int
MPI_Channel
::sendINT(int& msg){
	int *data = &msg ;
	char *gMsg = (char *)data;;
	MPI_Send((void *)gMsg, 1, MPI_INT, _otherRank, GLOBAL_MSG_TAG, _otherComm);
	return 1;
}



int
MPI_Channel
::receiveINT(int& msg){
	int *data = &msg ;
	char *gMsg = (char *)data;;
	MPI_Status status;
	MPI_Recv((void *)gMsg, 1, MPI_INT, _otherRank, GLOBAL_MSG_TAG, _otherComm, &status);
	return 1;
}




int
MPI_Channel
::sendVecINT(vector<int>& msg){
	int *data = &msg[0] ;
	int sz = msg.size();
	char *gMsg = (char *)data;;
	MPI_Send((void *)gMsg, sz, MPI_INT, _otherRank, GLOBAL_MSG_TAG, _otherComm);
	return 1;
}



int
MPI_Channel
::receiveVecINT(vector<int>& msg){
	int *data = &msg[0] ;
	int sz = msg.size();
	char *gMsg = (char *)data;;
	MPI_Status status;
	MPI_Recv((void *)gMsg, sz, MPI_INT, _otherRank, GLOBAL_MSG_TAG, _otherComm, &status);
	return 1;
}




