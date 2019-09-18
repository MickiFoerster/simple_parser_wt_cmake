#include <iostream>
#include <iomanip>
using namespace std;


extern int yyparse();
extern void scan_begin(const char * cmd);
extern void scan_end ();

int main(int argc, char* argv[])
{
	string inputbuffer;
	cout << "Type in a SPL code:\n";

	for( ;; ) {
		cout << ">";
		cin >> inputbuffer;
		scan_begin(inputbuffer.c_str());
		int rc=yyparse();
		scan_end();
		cout << "parser returns: " << rc << endl;
	}

	return 0;
}



