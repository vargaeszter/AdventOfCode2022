#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <exception>


void main() {
	std::ifstream fileStream;
	std::vector<std::vector<char>> cargo;
	try {
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

				for (int i = 0; 4 * i < line.size() - 2; i ++) {
					temp = line[i * 4 + 1];
					if (temp != ' ')
						cargo.at(i).push_back(temp);
				}
			
			}
			fileStream.close();
		}
	}
	catch (std::exception e) {
		std::cout << "Problem reading inputLayout.txt" << std::endl;
	}

	//for (int i = 0; i < cargo.size(); i++) {
	//	for(int j = 0; j < cargo.at(i).size() - 1; j++)
	//		std::cout << cargo.at(i).at(j) << ' ';
	//	std::cout << std::endl;
	//}
	
	try {
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
					temp = cargo.at(from - 1).at(0);
					cargo.at(from - 1).erase(cargo.at(from - 1).begin());
					cargo.at(to - 1).insert(cargo.at(to - 1).begin(),temp);
				}
			}
			fileStream.close();
		}
	
	}
	catch (std::exception e) {
		std::cout << "Problem reading inputMoves.txt" << std::endl;
	}

	for (int i = 0; i < cargo.size(); i++) {
		std::cout << cargo.at(i).at(0);
	}

}