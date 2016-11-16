#include <stdio.h>
#include <iostream>
#include <World.h>
#include <numeric>

using namespace std;

void Parse(const string& str, vector<string>& tokens, const string& delimiters = " ")
{
	// Skip delimiters at beginning.
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// Find first "non-delimiter".
	string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (string::npos != pos || string::npos != lastPos)
	{
		// Found a token, add it to the vector.
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// Skip delimiters.  Note the "not_of"
		lastPos = str.find_first_not_of(delimiters, pos);
		// Find next "non-delimiter"
		pos = str.find_first_of(delimiters, lastPos);
	}

	//En tokens tenemos el array separado 
	int size = tokens.size();

	if (size > 2) {

		for (int i = 2; i < size; ++i) {
			tokens[1] += " " + tokens[i];		
		}

		for (int i = 2; i < size; ++i) {
			tokens.erase(tokens.begin() +2);
		}
	}

	//Erase \n
	if(size > 1 )
		tokens[1].erase(tokens[1].size() - 1);
	else
		tokens[0].erase(tokens[0].size() - 1);
	

} 



int main()
{
	printf("\nHello World\n\n");
	printf("\nWelcome to ZORK\n");
	char line[50];



	//Entity *c = new Entity("a", "b", NULL);
	World w;

	vector <string> args;
	
	//getchar();

	while (true)
	{
		//getchar();
		

		fgets(line, 50, stdin);
		system("cls");

		//const char* args = line.c_str();
		
	
		Parse(line, args);

		if(w.Command(args) == false)
			cout << "\nSorry, I do not understand your command.\n" << endl;

		
		args.clear();

	}

}