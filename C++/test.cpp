#include <iostream>
#include <fstream>
using namespace std;

int main() {
	string test;
	string out;
	cout << "Input -\n";
	ofstream teststream("test.bin", ios::binary);
	for (int i = 0; i < 6; i++){
		int len;
		test = "test";
		len = test.length();
		cout << test << endl;
		teststream.write((char*) &len, sizeof(len));
		teststream.write((char*) test.c_str(), len);		
	}
	
	for (int i = 0; i < 6; i++){
		test = "Good";
		int len;
		cout << test << endl;
		len = test.length();
		teststream.write((char*) &len, sizeof(len));
		teststream.write((char*) test.c_str(), len);
	}
	teststream.close();
	ifstream teststream1("test.bin", ios::binary);
	cout << "Output - \n";
	while(!teststream1.eof()){	
	  	int len;
		teststream1.read((char*) &len, sizeof(len));
		out.resize(len);
		teststream1.read((char*) out.c_str(), len);
		cout << out << endl;
	}
	teststream1.close();
	return 0;
}