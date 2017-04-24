#include <string.h>
#include <iostream>
#include <fstream>
#include<string>



class HeaderIO {

public:
	struct Header {
		std::string name;
		//char name[15];
		int length;
		int count;
	};

private:
	Header hlist[10];
	int listLen;

public:
	void addHeader(std::string str, int len, int cnt) {
		hlist[listLen].name = str;
		hlist[listLen].length = len;
		hlist[listLen].count = cnt;
		listLen++;
	}

	Header getHeader(int index) {
		return hlist[index];
	}

	int getListLen() {
		return listLen;
	}

	void store(char datafile[]) {
		std::fstream fs;

		fs.open(datafile, std::fstream::out | std::fstream::binary);
		for (int i = 0; i < listLen; i++) {
			fs.write((char*)&hlist[i], sizeof(hlist[i]));
		}
		fs.close();
	}
	
	void load(char datafile[]) {
		std::fstream fs;

		fs.open(datafile, std::fstream::in | std::fstream::binary);
		for (int i = 0; i < listLen; i++) {
			fs.read((char*)&hlist[i], sizeof(hlist[i]));
		}
		fs.close();
	}
};


int main() {
	char datafile[] = "test";
	HeaderIO hio;
	
	hio.addHeader("string1", 11, 22);
	hio.addHeader("string2", 222, 333);

	hio.store(datafile);

	hio.load(datafile);

	for (int i = 0; i < hio.getListLen(); i++) {
		HeaderIO::Header h = hio.getHeader(i);
		std::cout << h.name << " " << h.length << " " << h.count <<  std::endl;
	}
}