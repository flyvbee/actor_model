#include "PartitionedDomain.h"


// PartitionedDomain
// ::PartitionedDomain(){

// }

using namespace std;
int PartitionedDomain
::addSubdomain(ShadowSubdomain* theSub){
	theSubs.push_back(theSub);
	return 1;
}




int PartitionedDomain
::hello_world(){
	cout<<" PartitionedDomain::hello_world " <<endl;
	this->Domain::hello_world();
	for (auto sub: theSubs){
		sub->hello_world();
	}
	return 1;
}

int PartitionedDomain
::partition_input_A(){
	this->Domain::partition_input_A();
	for (auto sub: theSubs){
		sub->partition_input_A();
	}
	return 1;
}

int PartitionedDomain
::partition_input_B(){
	this->Domain::partition_input_B();
	for (auto sub: theSubs){
		sub->partition_input_B();
	}
	return 1;
}

int PartitionedDomain
::new_step(){
	this->Domain::new_step();
	for (auto sub: theSubs){
		sub->new_step();
	}
	return 1;
}

int PartitionedDomain
::update(){
	this->Domain::update();
	for (auto sub: theSubs){
		sub->update();
	}
	return 1;
}

int PartitionedDomain
::compute(){
	this->Domain::compute();
	for (auto sub: theSubs){
		sub->compute();
	}
	return 1;
}

int PartitionedDomain
::check_residual(){
	this->Domain::check_residual();
	for (auto sub: theSubs){
		sub->check_residual();
	}
	return 1;
}

int PartitionedDomain
::commit(){
	this->Domain::commit();
	for (auto sub: theSubs){
		sub->commit();
	}
	return 1;
}

int PartitionedDomain
::revert(){
	this->Domain::revert();
	for (auto sub: theSubs){
		sub->revert();
	}
	return 1;
}

int PartitionedDomain
::collect_results(){
	this->Domain::collect_results();
	for (auto sub: theSubs){
		sub->collect_results();
	}
	return 1;
}

int PartitionedDomain
::say_bye(){
	this->Domain::say_bye();
	for (auto sub: theSubs){
		sub->say_bye();
	}
	return 1;
}
