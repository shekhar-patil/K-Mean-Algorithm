#include<iostream>
#include<vector>
#include<math.h>
#include <stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;

class kmean{
    public:

        vector <int> age;
        vector <int> w;
        vector <int> h;
        vector <int> marks;
        int size,ageM,wM,hM,marksM;


		void readCSV();
		void display(int *, int);
		void mean();
		void cluster();


};

void kmean :: readCSV(){

	int n = 0;
	string k;
	int value;
	ifstream ip("data.csv");
	if(!ip.is_open()){
		cout <<"\nError";
	}else{
		while(ip.good()){
			getline(ip,k,',');
			value = atoi(k.c_str());
			age.push_back(value);

			getline(ip,k,',');
			value = atoi(k.c_str());
			w.push_back(value);

			getline(ip,k,',');
			value = atoi(k.c_str());
			h.push_back(value);

			getline(ip,k,'\n');
			value = atoi(k.c_str());
			marks.push_back(value);

		}

	}
	ip.close();
	size= age.size()-1;				//column size
}

void kmean :: display(int *k, int x ){

	int z = 0;
	for(int i = 0;i < x; i ++ ){
		z = k[i];
		cout <<"\n Age:"<< age[z];
		cout <<"\n w:"<<w[z];
		cout <<"\n h:"<< h[z];
		cout <<"\n marks:"<< marks[z];
		cout <<"\n-------------------";

	}


}

void kmean :: mean(){
	int sum = 0;
	for(int i = 0; i < size; i++){
		sum = sum + age[i];
	}
	ageM = sum/size;
	sum = 0;
	for(int i = 0; i < size; i++){
		sum = sum + h[i];
	}
	hM = sum/size;
	sum = 0;
	for(int i = 0; i < size; i++){
		sum = sum + w[i];
	}
	wM = sum/size;
	sum = 0;
	for(int i = 0; i < size; i++){
		sum = sum + marks[i];
	}
	marksM = sum/size;

}

void kmean :: cluster(){

	int arr[size], k1[size], k2[size];
	int k1size = 0, k2size = 0;
	int sum = 0;
	for(int i =0 ; i < size; i++){
		arr[i] = sqrt( (age[i] - ageM)*(age[i] - ageM) + (w[i] - wM)*(w[i] - wM) + (h[i] - hM)*(h[i] - hM) + (marks[i] - marksM)* (marks[i] - marksM) );
		sum = sum + arr[i];
	}

	int arrM = sum/size;

	for(int i = 0; i < size; i++){
		if(arr[i] < arrM){
			k1[k1size] = i;
			k1size = k1size + 1;
		}else{
			k2[k2size] = i;
			k2size = k2size + 1;
		}
	}
cout << "Cluster 1::::\n\n\n";
display(k1 , k1size);
cout << "Cluster 2::::\n\n\n";
display(k2, k2size);

}

int main(){

kmean a;
a.readCSV();
a.mean();
a.cluster();

return 0;

}


