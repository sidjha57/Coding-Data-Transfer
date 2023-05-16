#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Hashmap_chaning {
     private:
     ll B,size;
     vector<pair<ll,string>> hashmap[20];
     public:

     Hashmap_chaning () {
         size = 0;
         B = 20;
     }
     ll hash (ll phone_num) {
         return phone_num%B;
     }

     void insert (ll phone_num,string name) {
         ll index = hash (phone_num);
         hashmap[index].push_back({phone_num,name});
         return;
     }
     
    void remove (ll phone_num) {
        ll index = hash (phone_num); 
        for (ll i=0; i<hashmap[index].size(); i++) {
            if (hashmap[index][i].first == phone_num) {
                swap (hashmap[index][i],hashmap[index][hashmap[index].size()-1]);
                hashmap[index].pop_back();
                cout << "Phone number found and contact deleted \n";
                return;
            }
        }
        cout << "Phone number not found \n";
    }

    string search (ll phone_num) {
        ll index = hash (phone_num);
        for (auto& entry : hashmap[index]) {
            if (entry.first == phone_num) {
                return entry.second;
            }
        }
        return "NIL";
    }
    
    void print () {
        for (ll i=0; i<B; i++) {
            cout << "#Bucket "<<i<<" ";
            for (auto& entry: hashmap[i]) {
                cout << "{ Phone no. "<<entry.first << ":" <<"Name "<<entry.second <<" } ";
            }
            cout <<"\n";
        }
    }
};

class Hashmap_probing {
    private:
    pair <ll,string> hashmap[7];
    bool isFresh[7];
    ll B,size;
    public:
    
    Hashmap_probing () {
        size = 0,B=7;
        for (ll i=0; i<7;i++) isFresh[i] = true;
    }

    ll hash (ll phone_num) {
        return phone_num%B;
       
    }

    void insert (ll phone_num,string name) {
          ll index = hash (phone_num);
           ll i = 1;
         while (isFresh[index] != true) {
            index = hash(phone_num+i);
            i++;
         }
          isFresh[index] = false;
          hashmap[index] = {phone_num,name};
          size++;
          return;
    }

    void remove (ll phone_num) {
           ll index;
           for (ll i=0; i<B; i++) {
               index = hash (phone_num+i);
               if (hashmap[index].first == phone_num) {
                  isFresh[index] = true;
                  size--;
                  cout << "Successfully removed \n";
                  return;
               }
           }
    }

    string search (ll phone_num) {
        ll index;
        for (ll i=0; i<B; i++) {
               index = hash (phone_num+i);
               if (hashmap[index].first == phone_num) {
                  return hashmap[index].second;
               }
           }
           return "NIL";
    }
    ll get_size () {
        return size;
    }
    void print () {
        for (ll i=0;i<B;i++) {
            if (isFresh[i] == false) 
                cout << "#" << i+1 << "{ Phone no. "<<hashmap[i].first<<" Name: " << hashmap[i].second<< " }\n";
            else 
                cout << "#" << i+1 << "\n";
        }
        return;
    }

   
};

int main () {
    Hashmap_probing m;

    m.insert (27,"Ram");
    m.insert (7,"Shyam");
    m.insert (5,"sid");
    m.insert (13,"abha");
    m.remove(7);
    m.print();
    cout << m.get_size();
    //m.remove (7);
    //cout << m.search(7);
    //m.print();

}