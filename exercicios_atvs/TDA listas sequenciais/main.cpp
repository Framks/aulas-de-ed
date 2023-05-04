#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
	Vector list1;
	for(int i = 0; i < 30;i++){
		list1.push_back(i*i%2*i);
	}
	for(int i = 0; i < list1.size();i++){
		cout << list1[i] << endl;
	}
	
}