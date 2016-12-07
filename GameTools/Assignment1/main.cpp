#include <fstream>
#include <iostream>
#include <vector>
#include "Vector3.h"


#include "ZlibHelper.h"

void main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << " Number of arguments supplied is incorrect" << std::endl;
		return;
	}

	FILE* inputFile = nullptr;
	FILE* outputFile = nullptr;
	errno_t error = fopen_s(&inputFile, argv[1], "r");
	errno_t error2 = fopen_s(&outputFile, argv[2] , "w");

	float delta = (float)atof(argv[3]);

	if (error != 0 && error2!= 0)
	{
		return;
	}

	
	std::vector<Vector3> nodes;
	int size = 0;

	fscanf_s(inputFile, "%*s %d\n", &size);

	nodes.resize(size);
	
	for (int i = 0; i < size; ++i)
	{
		fscanf_s(inputFile, "%f %f %f\n", &nodes[i].x, &nodes[i].y, &nodes[i].z);
	}

	RemoveDuplicates(nodes, delta);

	std::string buffer = "size: ";
	buffer.append(std::to_string(nodes.size()));
	buffer.append(" ");
	buffer.append("\n");

	fprintf_s(outputFile, "size: %d\n", nodes.size());
	for(auto& node : nodes)
	{
		fprintf_s(outputFile, "%f %f %f\n", node.x, node.y, node.z);
		buffer.append(std::to_string(node.x));
		buffer.append(" ");
		buffer.append(std::to_string(node.y));
		buffer.append(" ");
		buffer.append(std::to_string(node.z));
		buffer.append(" ");
		buffer.append("\n");
	}
	
	std::string data;
	unsigned long sizeDataCompressed = 0;
	ZLib::Compress(buffer, "savedData.dat", sizeDataCompressed);
	ZLib::UnCompress(data, "savedData.dat", buffer.size(), sizeDataCompressed);

	fclose(inputFile);
	fclose(outputFile);
}

// TODO Test for constructor for Vector Class, distance formula, removing points formula. Also show a failed test!! 