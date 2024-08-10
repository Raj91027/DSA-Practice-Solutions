#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main(){

    //creation
    unordered_map<string,int> m;

    //insertion
    //1. make pair and insert

    pair<string,int> p = make_pair("Raj", 3);
    m.insert(p);

    //2. make pair another way
    pair<string,int>p2("Kumar",2);
    m.insert(p2);

    //3. insert directly
    m["Yadav"] = 1;

    //Update
    m["Yadav"] = 2;

    //searching

    cout<<m["Raj"]<<endl;

    cout<<m.at("Yadav")<<endl;

    //cout<<m.at("unknownKey")<<endl; //Return error
    cout << m["unknownKey"]<<endl; //make new entry and return zero

    cout<< m.at("unknownKey")<<endl; // now this will also return zero

    //size 
    cout << m.size()<<endl;

    //erase
    m.erase("Kumar");
    cout << m.size()<<endl;

    //iterator

    unordered_map<string,int> :: iterator it = m.begin();
    while(it != m.end()){
        cout<< it->first <<" " << it->second<<endl;
        it++;
    }


    return 0;
}