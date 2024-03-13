#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

int main(){

    system("cls");

    int term_number;

    cout<<"Enter the term number of equation: ";
    cin>>term_number;

    vector <float> equation;

    for(int i = 0 ; i < term_number ; i++){
        float number;
        cout<<"Enter "<<i+1<<". elemen: ";
        cin>>number;
        equation.push_back(number);
    }

    int power = term_number - 1;

    for(int i = 0 ; i < term_number ; i++){
        equation[i] /= power - i + 1;
    }

    if(equation[0] < 0){
        cout<<"-";
    }

    for(int i = 0 ; i < term_number ; i++){
        
        if(equation[i + 1] > 0){
            if(i == term_number - 1){
                cout<<fabs(equation[i])<<"x + c";
            }
            else{
                cout<<fabs(equation[i])<<"x^"<<(power + 1) - i<<" + ";
            }
        }
        else{
            if(i == term_number - 1){
                cout<<fabs(equation[i])<<"x + c";
            }
            else{
                cout<<fabs(equation[i])<<"x^"<<(power + 1) - i<<" - ";
            }
        }
    }

    string decide;

    cout<<endl<<"Do you want to set limit? ";
    cin>>decide;

    if(decide == "yes"){
        float up_limit, down_limit;

        cout<<"Enter limits (up, down): ";

        cin>>up_limit>>down_limit;

        if(up_limit < down_limit){
            while (up_limit < down_limit){
                cout<<"Up limit must be greater than down limit!"<<endl;
                cin>>up_limit>>down_limit;
            }
        }

        vector <float> temp_equation;

        float summary_up = 0, summary_down = 0;

        for(int i = 0 ; i < term_number ; i++){
            temp_equation.push_back(equation[i]);
            equation[i] *= pow(up_limit, term_number - i);
            summary_up += equation[i];
        }
        for(int i = 0 ; i < term_number ; i++){
            temp_equation[i] *= pow(down_limit, term_number - i);
            summary_down += temp_equation[i];
        }

        float result;
        
        result = summary_up - summary_down;

        cout<<"Result is "<<result<<endl<<"Area is "<<fabs(result);

    }
    
    else{
        exit(0);
    }
    return 0;
}