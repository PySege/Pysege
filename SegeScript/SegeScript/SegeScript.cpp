#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

vector<string> tokenize(const string& line) {
	stringstream ss(line);
	string token;
	vector<string> tokens;

	while (ss >> token) {
		tokens.push_back(token);
	}

	return tokens;
}

void parseAndExecute(const string& line) {
	vector<string> tokens = tokenize(line);
	if (tokens.empty()) return;

	string command = tokens[0];

	if (command == "print") {
		for (size_t i = 1; i < tokens.size(); ++i) {
			cout << tokens[i] << " ";
		}
		cout << endl;
	}
	else if (command == "add") {
		if (tokens.size() >= 3) {
			int a = stoi(tokens[1]);
			int b = stoi(tokens[2]);
			cout << "Result: " << (a + b) << endl;
		}
		else {
			cout << "Error: correct usage -> add <num1> <num2>" << endl;
		}
	}
	else {
		cout << "Unknown command: " << command << endl;
	}
}

int main() {
	string input;

	cout << "Enter commands (print / add), or 'exit' to exit:\n";

	while (true) {
		cout << "> ";
		getline(cin, input);

		if (input == "exit") break;

		parseAndExecute(input);
	}

	return 0;
}
