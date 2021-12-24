#include<bits/stdc++.h> //I put this header file in the /include/bits/ folder of my compiler. 
//the user can put this header file wherever they want but please link the header file appropriately.
//the above file will also include the chrono header also.
//Will try to include the header file in the project zip.

using namespace std::chrono;
using namespace std;

//function declaration
double ForLoop(int* coefficient, double x, int degree);
double PowFunction(int* coefficient, double x, int degree);
double HornersRule(int* coefficient, double x, int degree);

//main program
int main(){
    //random number generator
    srand(time(0)); 
    int pol_degree;
    //user input polinomial degree
    again:
    cout<<"\nEnter the degree of the polynomial in the range 100000 to 200000: ";
    cin>>pol_degree; 
    if (pol_degree<100000 || pol_degree>200000)
    {
        goto again;
    }
    int* coefficient = new int[pol_degree+1];
    //generate random coefficient
    for(int i=0; i<=pol_degree; i++){
        coefficient[i] = 1 + rand()%100;
    }
    //get x value between 0 and 1
    float x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    while(x==1 || x==0){
        x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }

    //Main UI
    cout<<"\nEvaluate polynomial at x = "<<x<<endl;
    cout<<"\nMenu"<<endl;
    cout<<"1. Momonial Evaluation using For Loop"<<endl;
    cout<<"2. Monomial Evaluation using Power Function"<<endl;
    cout<<"3. Evaluation By Horner's Rule"<<endl;
    cout<<"0. Exit The Program"<<endl;

    //Sub UI
    while(true){
        int UI;
        UI4:
        cout<<"\nPlease enter 1, 2 or 3 to select the evaluation method or 0 to end the program : ";
        cin>>UI;
        auto start = high_resolution_clock::now(); //referenced from https://en.cppreference.com/w/cpp/chrono/high_resolution_clock/now 
        switch(UI){
            case 0: cout<<"Bye!"<<endl;exit(0);
                    break;
            case 1: cout<<"\nPolynomial evaluates to: "<<ForLoop(coefficient, x, pol_degree)<<endl;
                    break;
            case 2: cout<<"\nPolynomial evaluates to: "<<PowFunction(coefficient, x, pol_degree)<<endl;
                    break;
            case 3: cout<<"\nPolynomial evaluates to: "<<HornersRule(coefficient, x, pol_degree)<<endl;
                    break;
            default: goto UI4; //just in case user inputs wrong input to run the loop again on questions
        }
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start); 
        switch(UI){
            case 1: cout<<"\nTime wasted by evaluating using For Loop method:";
                    break;
            case 2: cout<<"\nTime wasted by evaluating using Power Function method:";
                    break;
            case 3: cout<<"\nTime wasted by evaluating using Horner's Rule method:";
                    break;
        }
        cout << duration.count() <<" Milliseconds"<< endl;
    }
    return 0;
}

//functions operation
double ForLoop(int* coefficient, double x, int degree){
    double answer = 0;
    for (int i=0; i<=degree; i++){
        double nextCoeff = coefficient[i];
        for(int j=0; j<degree-i; j++){
            nextCoeff = nextCoeff*x;
        }
        answer += nextCoeff;
    }
    return answer;
}
double PowFunction(int* coefficient, double x, int degree){
    double answer = 0;
    for (int i=0; i<=degree; i++){
        double nextCoeff = coefficient[i]*pow(x,degree-i);
        answer += nextCoeff;
    }
    return answer;
}
double HornersRule(int* coefficient, double x, int degree){
    double answer = coefficient[0];
    for (int i=1; i<=degree; i++){
        answer = answer*x + coefficient[i];
    }
    return answer;
}