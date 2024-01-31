#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <int> data(20);
	int curpos = 0;
	int num;
	cin >> num;
	while (num != -2){
		if (num == -1){
			for (int i = curpos; i < data.size(); ++i){
				cout << data[i] << " ";
			}
			for (int i = 0; i < curpos; ++i){
				cout << data[i] << " ";
			} 
		} else {
			data[curpos] = num;
			curpos++;
			if (curpos == 20) curpos = 0;

		}
		cin >> num;
	}
	return 0;
}