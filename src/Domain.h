#pragma once
#include <vector>
#include <iostream>
#include <mpi.h>

#define DemoMSG std::cout  << "Domain(" << rank << "): "

class Domain
{
public:
	Domain();
	virtual ~Domain();
	
	virtual int hello_world();
	virtual int partition_input_A();
	virtual int partition_input_B();
	virtual int new_step();
	virtual int update();
	virtual int compute();
	virtual int check_residual();
	virtual int commit();
	virtual int revert();
	virtual int collect_results();
	virtual int say_bye();
private:
	int rank;
};