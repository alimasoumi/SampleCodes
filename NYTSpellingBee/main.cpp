#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<set>
#include<algorithm>
using namespace std;
//std::set<char> st{'t', 'l', 'n', 'p', 'a', 'b'};
std::set<char> st;
char center = 'i'; 

bool found_one_char(char c){
  return  st.find(c)!= st.end();
}

int num_of_acceptable(std::string s){
  int ctr=0;
  if(s.find(center) < s.size())
    ctr++;
  else
    return 0;
  auto unique_end = unique(s.begin(), s.end());
  for(auto it = s.begin(); it != unique_end; it++){
    if( found_one_char(*it))
	ctr++;
    else
      if( *it != center)
	return 0;
  }
  return ctr;

}

int main(){
  std::cout << "enther the surrounding six chars and press enter\n"; 
  for(int i=0; i<6; i++){
    char temp_char;
    std::cin>>temp_char;
    st.insert(temp_char);
  }
  std::cout<< "Enter the central charachter\n";
  std::cin>> center;
  /*  for(auto it = st.begin(); it!= st.end(); it++)
      std::cout<< (*it);*/
  
  std:: cout << "\nsize of the set " << st.size() <<endl;
  int ctr;
  std::string s = "wooordList";
 std::ifstream ifs("wordList");
  while(ifs >> s){
   ctr = num_of_acceptable(s);
   if(ctr>= 4)
     cout << s<< endl;
   if (ctr ==  1+  st.size())
     cout << "FOUND AN IMPORTANT ONE"<<endl;
     }
  return 0;
}
