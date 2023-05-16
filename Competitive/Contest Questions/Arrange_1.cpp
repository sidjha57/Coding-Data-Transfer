//Approach 1
#include <iostream>
#include<string>

using namespace std;
void arrange(int N1,string player1,int N2,string player2,int N3, string player3) {
    if (N1>N2 && N1>N3 && N2>N3)
        cout<<N1<<" "<<player1<<"\n"<<N2<<" "<<player2<<"\n"<<N3<<" "<<player3;
 
    else if (N1>N2 && N1>N3 && N3>N2)
        cout<<N1<<" "<<player1<<"\n"<<N3<<" "<<player3<<"\n"<<N2<<" "<<player2;
    
    else if (N2>N1 && N2>N3 && N1>N3)
       cout<<N2<<" "<<player2<<"\n"<<N1<<" "<<player1<<"\n"<<N3<<" "<<player3; 
    
    else if (N2>N1 && N2>N3 && N3>N1)
       cout<<N2<<" "<<player2<<"\n"<<N3<<" "<<player3<<"\n"<<N1<<" "<<player1; 
    
    else if (N3>N1 && N3>N2 && N2>N1)
       cout<<N3<<" "<<player3<<"\n"<<N2<<" "<<player2<<"\n"<<N1<<" "<<player1; 
    
    else if (N3>N1 && N3>N2 && N1>N2)
       cout<<N3<<" "<<player3<<"\n"<<N1<<" "<<player1<<"\n"<<N2<<" "<<player2; 
    
    return;
}


int main() {
    int i,N1,N2,N3;
    string player1,player2,player3;
    
    cin>>N1>>player1>>N2>>player2>>N3>>player3;
   
    arrange(N1,player1,N2,player2,N3,player3);

  return 0;
}



