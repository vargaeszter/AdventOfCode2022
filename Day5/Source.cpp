#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <exception>

std::vector<std::vector<char>> loadCargo() {

	std::ifstream fileStream;
	std::vector<std::vector<char>> cargo;

	fileStream.open("inputLayout.txt");
	std::string line;
	char temp;
	if (fileStream.is_open()) {
		while (std::getline(fileStream, line)) {
			if (cargo.size() == 0) {
				for (int i = 0; i < line.size(); i += 4) {
					cargo.push_back(std::vector<char>());
				}
			}

			for (int i = 0; 4 * i < line.size() - 2; i++) {
				temp = line[i * 4 + 1];
				if (temp != ' ')
					cargo.at(i).insert(cargo.at(i).begin(), temp);
			}

		}
		fileStream.close();
	}

	return cargo;

}

void organizeCargo1(std::vector<std::vector<char>>& cargo) {

	std::ifstream fileStream;
	fileStream.open("inputMoves.txt");
	std::string line;
	int num, from, to;
	char temp;
	if (fileStream.is_open()) {
		while (!fileStream.eof()) {
			fileStream >> line;
			if (!(line == "move" || line == "\nmove")) {
				std::cout << line;
				break;
			}
			fileStream >> num;
			fileStream >> line;
			if (line != "from") {
				break;
			}
			fileStream >> from;
			fileStream >> line;
			if (line != "to") {
				break;
			}
			fileStream >> to;
			for (int i = 0; i < num; i++) {
				temp = cargo.at(from - 1).at(cargo.at(from - 1).size() - 1);
				cargo.at(from - 1).pop_back();
				cargo.at(to - 1).push_back(temp);
			}
		}
		fileStream.close();
	}
}

void organizeCargo2(std::vector<std::vector<char>>& cargo) {

	std::ifstream fileStream;
	fileStream.open("inputMoves.txt");
	std::string line;
	int num, from, to;
	std::vector<char> temp;
	if (fileStream.is_open()) {
		while (!fileStream.eof()) {
			fileStream >> line;
			if (!(line == "move" || line == "\nmove")) {
				break;
			}
			fileStream >> num;
			fileStream >> line;
			if (line != "from") {
				break;
			}
			fileStream >> from;
			fileStream >> line;
			if (line != "to") {
				break;
			}
			fileStream >> to;
			for (int i = 0; i < num; i++) {
				temp.push_back(cargo.at(from - 1).at(cargo.at(from - 1).size() - 1));
				cargo.at(from - 1).pop_back();
			}
			while (temp.size() > 0) {
				cargo.at(to - 1).push_back(temp.at(temp.size() - 1));
				temp.pop_back();
			}
		}
		fileStream.close();
	}
}

void printCargo(std::vector<std::vector<char>>& cargo) {
	for (int i = 0; i < cargo.size(); i++) {
		std::cout << cargo.at(i).at(cargo.at(i).size() - 1);
	}
	std::cout << std::endl;
}


void main() {
	std::vector<std::vector<char>> cargo;

	try {
		cargo = loadCargo();
	}
	catch (std::exception e) {
		std::cout << "Problem reading inputLayout.txt" << std::endl;
	}

	try {
		organizeCargo1(cargo);
	}
	catch (std::exception e) {
		std::cout << "Problem reading inputMoves.txt" << std::endl;
	}

	printCargo(cargo);

	std::vector<std::vector<char>> cargo9001;

	try {
		cargo9001 = loadCargo();
	}
	catch (std::exception e) {
		std::cout << "Problem reading inputLayout.txt" << std::endl;
	}

	try {
		organizeCargo2(cargo9001);
	}
	catch (std::exception e) {
		std::cout << "Problem reading inputMoves.txt" << std::endl;
	}

	printCargo(cargo9001);

}