#include "Table.h"
using namespace std;

Table::Table(){
}

Table::~Table(){
	var.clear(); // 清空var，防止vector造成的内存空洞
}

void Table::get_variable_number(){
	cout<<"Please put in the number of the variable in your expression: ";
	(cin>>variables).get();
	length = int(pow(2,variables));
}

void Table::get_truth(){
	cout<<"Then type your conclusion of the tabulation(Just \'T\' and \'F\'' ! Press Enter key to finish):";
	getline(cin,putin);
}

void Table::exp_format(){
	char str[putin.size()+1];
	char * p = (char *)putin.c_str();
	strcpy(str,p);
	char q[length+1];
	for (int i = 0; i < length; ++i){
		q[i]='F';
	}
	q[length]='\0';
	p = str;
	for (int i=0;*(p+i)!='\0';++i){
		if(!((*(p+i)=='T'||*(p+i)=='F'))){
			for(int j=i;*(p+j)!='\0';++j){
				*(p+j)=*(p+j+1);
			}
			--i;
		}
	}
	for (int i=0;*(p+i)!='\0';++i){
		q[i]=p[i];
	}
	value = q;
}

void Table::ergodic(){
	int binary = length - 1; //用于遍历赋值
	int e = binary; //遍历判断变量
	var.resize(length);
	for (int i = 0; i < length; ++i){var[i].resize(variables);} //展开动态数组
	for (int i = 0; i < length; ++i){
		for (int j = variables - 1; j >= 0; --j){ //位操作所以从最低位开始！
			if (0x01&e){var[i][j] = true;}else{var[i][j] = false;} //使用掩码取内存最低位
			e >>= 1;
		}
		e = --binary; //继续下一个条件，重置e
	}
}

void Table::print_table(){
	cout<<"Truthtable export:"<<endl<<"┌";
	for (int i = 0; i < variables*3; ++i){
		cout<<"─";	
	}
	cout<<"┬───┐"<<endl<<"│";
	for (int i = 0; i < variables; ++i){
		cout<<" "<<char('P'+i)<<" ";
	}
	cout<<"│Ans│"<<endl<<"├";
	for (int i = 0; i < variables*3; ++i){
		cout<<"─";	
	}
	cout<<"┼───┤"<<endl;
	for (int i = 0; i < length; ++i){
		cout<<"│";
		for (int j = 0; j < variables; ++j){
			cout<<" ";
			if (var[i][j]){cout<<"T ";}else{cout<<"F ";}
		}
		cout<<"│ "<<value[i]<<" │"<<endl;
	}
	cout<<"└";
	for (int i = 0; i < variables*3; ++i){
		cout<<"─";	
	}
	cout<<"┴───┘"<<endl;
}

void Table::primary_disjunctive(){
	cout<<"primary disjunctive normal form export:"<<endl<<"T=";
	for (int i = 0; i < length; ++i){
		char alpha = 'P';
		if (value[i]=='T'){
			cout << "(";
				for(int j = 0; j < variables; j++){
					if(var[i][j]){cout<<char(alpha++);}else{cout <<"┐"<<(char)(alpha++);}
					cout << "∧";
				}
			cout<<'\b'<<")∨";
		}
	}
	cout<<"\b "<<endl;
}

void Table::principal_conjunctive(){
	cout<<"principal conjunctive normal form export:"<<endl<<"T=";
	for (int i = 0; i < length; ++i){
		char alpha = 'P';
		if (value[i]=='F'){
			cout << "(";
				for(int j = 0; j < variables; j++){
					if(!(var[i][j])) {cout<<char(alpha++);}else{cout <<"┐"<<(char)(alpha++);}
					cout << "∨";
				}
			cout<<'\b'<<")∧";
		}
	}
	cout<<"\b "<<endl;
}