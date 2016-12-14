#include "Table.h"
using namespace std;

int main(int argc, char const *argv[])
{
	 
	Table truth;
	truth.get_variable_number();
	truth.get_truth();
	truth.exp_format();
	truth.ergodic();
	truth.print_table();
	truth.primary_disjunctive();
	truth.principal_conjunctive();
	return 0;
}