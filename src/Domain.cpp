#include "Domain.h"

using namespace std;
Domain
::Domain(){
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
}

Domain
::~Domain(){
}

int Domain
::hello_world(){
	DemoMSG<<"Domain::hello_world " <<endl;
	
	return 1;
}


int Domain
::partition_input_A(){
	DemoMSG<<"Domain::partition_input_A " <<endl;
	
	return 1;
}


int Domain
::partition_input_B(){
	DemoMSG<<"Domain::partition_input_B " <<endl;
	
	return 1;
}


int Domain
::new_step(){
	DemoMSG<<"Domain::new_step " <<endl;
	
	return 1;
}


int Domain
::update(){
	DemoMSG<<"Domain::update " <<endl;
	
	return 1;
}


int Domain
::compute(){
	DemoMSG<<"Domain::compute " <<endl;
	
	return 1;
}


int Domain
::check_residual(){
	DemoMSG<<"Domain::check_residual " <<endl;
	
	return 1;
}


int Domain
::commit(){
	DemoMSG<<"Domain::commit " <<endl;
	
	return 1;
}


int Domain
::revert(){
	DemoMSG<<"Domain::revert " <<endl;
	
	return 1;
}


int Domain
::collect_results(){
	DemoMSG<<"Domain::collect_results " <<endl;
	
	return 1;
}


int Domain
::say_bye(){
	DemoMSG<<"Domain::say_bye " <<endl;
	
	return 1;
}

