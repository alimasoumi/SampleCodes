//
//  BigPositiveInteger.h
//  Algorithms
//
//  Created by Ali on 5/3/19.
//  Copyright © 2019 Ali. All rights reserved.
//

#ifndef BigPositiveInteger_h
#define BigPositiveInteger_h


#include "test_utils.h"
using namespace std;


class PositiveBigInt{
public:
    
    PositiveBigInt(vector<int> vec): num(vec){};
    PositiveBigInt(int n){
        while(n>0){
            num.push_back(n%10);
            n = (n - n%10)/10;
        }
    };
    PositiveBigInt add( PositiveBigInt & pbi);
    PositiveBigInt multiply( PositiveBigInt & pbi);
    friend ostream& operator << (ostream& os, PositiveBigInt pbi){
        for (auto it = pbi.num.rbegin(); it!= pbi.num.rend(); it++) {
            os<<*it;
        }
        return os;
    }
    
private:
    vector<int> num;
};

PositiveBigInt PositiveBigInt::add( PositiveBigInt & pbi){
    vector<int> longer, shorter;
    if (this->num.size() >= pbi.num.size()) {
        longer = this->num;
        shorter = pbi.num;
    }
    else{
        longer = pbi.num;
        shorter = this->num;
    }
    for(int i=0; i< shorter.size(); i++)
        longer[i] += shorter[i];
    for(int i=0; i< longer.size()-1; i++)
        if (longer[i]>9) {
            longer[i] -= 10;
            longer[i+1] += 1;
        }
    if(longer[longer.size()-1]>10){
        longer[longer.size()-1] -= 10;
        longer.push_back(1);
        
    }
    return PositiveBigInt(longer);
}

PositiveBigInt PositiveBigInt::multiply(PositiveBigInt & pbi){
    vector<int> result(this->num.size()+ pbi.num.size(),0);
    for(int i=0; i< this->num.size(); i++)
        for (int j=0; j<pbi.num.size(); j++)
            result[i+j] += this->num[i]* pbi.num[j];
    for(int i=0; i< result.size()-1; i++)
        if (result[i]>9) {
            result[i+1] += result[i]/10;
            result[i] = result[i]%10;
        }
    if(result[result.size()-1]>10){
        result.push_back(result.back()/10);
        result[result.size()-2] %= 10;
    }
    if (result.back()==0) {
        result.pop_back();
    }
    
    return PositiveBigInt(result);
}

void test_bigInt1(){
    start_test("test multuplying and adding large numbers", "");
    PositiveBigInt pbi1(212347), pbi2(13);
    cout << pbi1<< "+" << pbi2 <<"=" << pbi1.add(pbi2)<<endl;
    cout << pbi1<< "*" << pbi2 <<"=" << pbi1.multiply(pbi2)<<endl;
    end_test(true);
}


#endif /* BigPositiveInteger_h */
