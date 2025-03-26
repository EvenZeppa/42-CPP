#include <iostream>
#include <fstream>

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return (std::cout << "Error: need 3 arguments !" << std::endl, 1);
	std::string fileName = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream file(fileName.c_str());
	if (!file.is_open())
		return (std::cout << "Error: could not open file !" << std::endl, 1);

	std::ofstream outFile((fileName + ".replace").c_str());
	if (!outFile.is_open())
		return (std::cout << "Error: could not create output file !" << std::endl, 1);

	std::string line;
	while (std::getline(file, line))
	{
		size_t pos = 0;
		size_t newPos = 0;
		size_t size = line.size();
		std::string newLine;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			newLine += line.substr(newPos, pos - newPos) + s2;
			pos += s1.length();
			newPos = pos;
		}
		newLine += line.substr(newPos, size - newPos);
		outFile << newLine;
		if (!file.eof())
			outFile << std::endl;
	}
	return (0);
}