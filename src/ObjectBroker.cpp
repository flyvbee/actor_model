#include "ObjectBroker.h"


using namespace std;
ActorSubdomain *
ObjectBroker
::getNewActor(int action_tag, MPI_Channel* theChannel) {
	switch(action_tag){
		case shadowActorAction_create_subdomain:{
			return new ActorSubdomain(theChannel, this)	;
		}
		default:{
			cerr << "ObjectBroker::getNewActor - ";
			cerr << " - no action_tag exists for "<< action_tag <<endl ;
			return 0;
		}
	}
	
}


