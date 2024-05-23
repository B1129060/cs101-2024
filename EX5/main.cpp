#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class myString {
	private: 
		string m_str;
	public:
		myString(string s){
			m_str = s;
		}		
};

class ReadClass {
	private:
		string filename;
	public:
		ReadClass(){
			filename = "main.cpp";
		}
		
		void showClass(){
			vector<string> name;
			string s;
			int num = 0;
			ifstream in;
			in.open(this->filename.c_str());
			if(in.fail()){
				cout << "fail" << endl;
				return;
			}
			while(!in.eof()){
				in >> s;
				if(s == "class"){
					in >> s;
					name.push_back(s);
					num++;
				}
			}
			in.close();
			cout << --num << " class in main.cpp\n";
			for(int i = 0; i < name.size() - 1; i++){
				cout << "class " << name[i] << endl;
			}
		}
		
};

int main(){
    ReadClass rfile;
    rfile.showClass();
    return 0;
    
}

