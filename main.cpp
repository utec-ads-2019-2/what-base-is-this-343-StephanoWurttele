#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


vector<char> vector_comun={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int get_valor_de_letra(char a){
	for (int i=0;i<vector_comun.size();i++){
		if (vector_comun[i]==a){
			return i+10;
		}
	}
}

int main(){
	string input;
	string input2;
	while(cin>>input>>input2){
		vector<int> number1;
		vector<int> number2;
		int max[]={2,2};
		unsigned long int respuestas1[37]={0};
		unsigned long int respuestas2[37]={0};
		unsigned long int ans=0;
		unsigned long int ans2=0;
		unsigned long int res=0;
		unsigned long int res2=0;
		for(int i=0;i<input.length();i++){
			if(isdigit(input[i])){
				number1.insert(number1.begin(),(input[i]-'0'));
			}
			else{
				number1.insert(number1.begin(),(get_valor_de_letra(input[i])));
			}
				
			if((number1[0])>=max[0])
				max[0]=number1[0]+1;
		}

		for(int i=0;i<input2.length();i++){
			if(isdigit(input2[i]))
				number2.insert(number2.begin(),(input2[i]-'0'));
			else{
				number2.insert(number2.begin(),(get_valor_de_letra(input2[i])));
			}

			if((input2[i]-'0')>=max[1])
				max[1]=number2[0]+1;
		}

		for(int i=max[1];i<37;i++){
			res2=0;
			for(int j=0;j<number2.size();j++){
				res2+=number2[j]*pow(i,j);
			}
			respuestas2[i]=res2;
		}


		for(int i=max[0];i<37;i++){
			res=0;
			for(int j=0;j<number1.size();j++){
				res+=number1[j]*pow(i,j);
			}
			for(int j=max[1];j<37;j++){
				if(res==respuestas2[j]){
					ans=j;
					ans2=i;
					break;
				}
			}
			if(ans!=0){
				break;
			}
		}
		if (ans)
			cout<<input<<" (base "<<ans2<<") = "<<input2<<" (base "<<ans<<")"<<endl;
		else
			cout<<input<<" is not equal to "<<input2<<" in any base 2..36"<<endl;
	}
		return 0;	

}
