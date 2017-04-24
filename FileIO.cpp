#include <string.h>
#include <iostream>
#include <fstream>


#pragma pack(push, r1, 1)
struct Header {
	char name[15];
	int length;
	int count;
};
#pragma pack(pop, r1)


void store(Header  hlist[], int len, char datafile[]) {
	std::fstream fs;

	fs.open(datafile, std::fstream::out | std::fstream::binary);
	for (int i = 0; i < len; i++) {
		fs.write((char*)&hlist[i], sizeof(hlist[i]));
	}
	fs.close();
}

void load(Header hlist[], int len, char datafile[]) {
	std::fstream fs;

	fs.open(datafile, std::fstream::in | std::fstream::binary);

	for (int i = 0; i < len; i++) {
		fs.read((char*)&hlist[i], sizeof(hlist[i]));
	}

	/*
	for (int i = 0; i < len; i++) {
		fs.read((char*)&hlist[i].name, sizeof(hlist[i].name));
		fs.read((char*)&hlist[i].length, sizeof(hlist[i].length));
		fs.read((char*)&hlist[i].count, sizeof(hlist[i].count));
	}
	*/

	fs.close();
}

int main() {
	const int len = 2;
	char datafile[] = "test";

	Header hlist[len];

	strcpy(hlist[0].name, "james");
	hlist[0].count = 2288;
	hlist[0].length = 25;

	strcpy(hlist[1].name, "sibyll");
	hlist[1].count = 222;
	hlist[1].length = 25566;

	store(hlist, len, datafile);

	load(hlist, len, datafile);

	for (int i = 0; i < 2; i++){
		std::cout << hlist[i].name << " " << hlist[i].count << " " << hlist[i].length << std::endl;
	}
}