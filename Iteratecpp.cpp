// The following program is design to make a certain number of calls 
// to the system routine sleep. It takes two command line parameters:
// the number of iterations, and the duration of each iteration
// $ iterate 6 4
// 0 sleeping for 4 seconds
// 1 sleeping for 4 seconds
// 2 sleeping for 4 seconds
// 3 sleeping for 4 seconds
// 4 sleeping for 4 seconds
// 5 sleeping for 4 seconds
// $

#include <iostream> // for std::cout, & cetera
#include <sstream> // for istringstream
#include <cstdlib> // for exit
#include <Windows.h>
//
// Define a data structure
//
struct Control {
	int iterations;
	int seconds;
};
//
// parse the command line:
//

Control* initialize(int argc, char** argv) {
	Control* control = NULL;
	if (argc != 3) {
		std::cerr << "Usage: " << argv[0] << " iterations seconds"
			<< std::endl; exit(0);
	}
	else {
		control = new Control;
		control->iterations = 0;
		control->seconds = 0;
		{
			std::istringstream stream(argv[1]);
			if (!(stream >> control->iterations)) return control;
		}
		{
			std::istringstream stream(argv[2]);
			if (!(stream >> control->seconds)) return control;
		}
	}
	return control;
}
//
// finalize
//
void finalize(Control* control) {
	delete control;
}
//
//execute
//
void execute(Control* control) {
	if (control) {
		for (int i = 0; i < control->iterations; i++) {
			Sleep(control->seconds* 1000);
			std::cout << i << "sleeping for " << control->seconds
				<< " seconds" << std::endl;
		}
	}
}
//
//
//
int main(int argc, char** argv) {
	Control* control = initialize(argc, argv);
	execute(control);
	finalize(control);
	return 0;
}

