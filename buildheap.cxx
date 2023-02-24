#include "json.hpp"
#include<vector>
#include<string>
#include<fstream>
#include "priorityqueue.h"
#include<iostream>
int main(int argc, char** argv) {

    std::ifstream file1(argv[1]);

    nlohmann::json data = nlohmann::json::parse(file1);

    if(!file1.is_open()){
        std::cout<<"failed";
        return 0;
    }



    int msize = data["metadata"]["maxHeapSize"];
    // int numop = data["metadata"]["numOperations"];
    // int sizeh = data["metadata"]["size"];
    std::string opn; 
    double storekey;
    PriorityQueue runi(msize);
    for(auto it = data.begin();it != std::prev(data.end(),1);++it){


        std::cout<<"xxxxxxxxxxxxxxxxx"<<runi.size_<<std::endl;
        std::cout<<it.key()<<std::endl<<std::endl;

        opn = it.value()["operation"];
        std::cout<<opn;
        if(opn=="insert"){
            storekey = it.value()["key"];
            runi.insert(storekey);
        }
        else if(opn=="removeMin"){
            runi.removeMin();
        }
   std::cout<<runi.JSON().dump(2)<<std::endl;
    }
    std::cout<<runi.JSON().dump(2)<<std::endl;


    return 0;
}
