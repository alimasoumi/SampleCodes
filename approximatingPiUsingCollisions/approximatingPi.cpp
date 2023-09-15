#include<iostream>


inline std::pair<long double, long double> collision(double u, double v, long long alpha){
    double uprime = (2*v + (alpha-1)*u) /(1+alpha);
    double vprime = (2*alpha*u + (1-alpha)*v)/(1+alpha);
    return {uprime, vprime};

}

long long collisions_count(long long  alpha){
    long double u = -1, v = 0;
    //auto speeds_after = [&](){return pair<long double, long double> ({(2*v + (alpha-1)*u) /(1+alpha),(2*alpha*u + (1-alpha)*v)/(1+alpha)});};
    int cnt = 0;
    while(u<v){
        cnt += 1;
        auto [up, vp] = collision(u, v, alpha);
        u = up;
        v = vp;
        if (v<0){
            cnt++;
            v = -v;
        } 
    }
    return cnt;

}

int main(){
    long long alpha = 1;
    for(int i=0; i<9; i++) {
        std::cout << "mass ratio: 10^" << 2*i << '\t' << "number of collisions: "<< collisions_count(alpha) << std::endl;
        alpha *= 100;
    }
    return 0;
}