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
int main(int argc, char *argv[])
{
	ObjectBroker theBroker;
	MPI_Machine theMachine(&theBroker, argc, argv);
	int rank = theMachine.getProcessID();
	int np = theMachine.getNumProcess();
	PartitionedDomain theMasterDomain;
    if(rank!=0){
    	theMachine.runActor(); // block receive the subdomain
    }else{
    	int Num_Subdomains = np - 1; 
    	for (int i = 1; i <= Num_Subdomains; i++)
    	{
    	    ShadowSubdomain *theSubdomain = new ShadowSubdomain(i, theMachine, theBroker); // block send the subdomain
    	    if(! theMasterDomain.addSubdomain(theSubdomain) ){
    	        cerr<<"   Failed to add Subdomain # " << i <<" !\n";
    	        return -1;
    	    }
    	    cout << "   Subdomain # " << i << " created. \n";
    	}

    	theMasterDomain.hello_world();
    	theMasterDomain.partition_input_A();
    	theMasterDomain.partition_input_B();

    	theMasterDomain.new_step();
    	theMasterDomain.update();
    	theMasterDomain.compute();
    	theMasterDomain.check_residual();
    	theMasterDomain.commit();
    	theMasterDomain.revert();

    	theMasterDomain.collect_results();
    	theMasterDomain.say_bye();

        for (int i = 1; i <= Num_Subdomains; ++i){
            theMachine.shutdown(i);
        }
    }

	return 0;
}