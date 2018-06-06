#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	int factorial[9];
	int sign[9];
	int mul =1;
	int sum =999999;
	int tmp;
	vector<int>out;

	for(int i=0; i<10; i++){
		out.push_back(i);
	}

	for(int i=1; i<10; i++){
		mul = mul*i;
		factorial[9-i] = mul;
	}

	for(int i=0; i<9; i++){
		sign[i] = sum/factorial[i];
		sum -= sign[i]*factorial[i];
	}

	for(int i =0; i<9; i++){
		cout << i <<'\t'<< sign[i] <<'\t'<< factorial[i] << endl;
	}
	cout << endl;

	for(int i=0; i<9; i++){
		
		tmp =out[i];
		out[i] =out[sign[i]+i];
		out[sign[i]+i] = tmp;
		sort(out.begin()+i+1,out.end());
		
		for(int j=0; j<10; j++){
			cout <<out[j];
		}
		cout << endl;
	}

	return 0;
}