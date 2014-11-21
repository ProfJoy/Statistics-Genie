//
//  main.cpp
//  Statistics Helper
//
//  Created by Abey Joy on 4/24/14.
//  Copyright (c) 2014 Abey Joy. All rights reserved.
//  Please use these functions at your own risk. I am not to be held responsible for any damages occured by implementation or usage of these functions.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

vector<double>myValues;
/* Purpose: The function add_values does not return anything. It simply creates a file and then stores user inputted values into it for usage in other functions.
 This function is primarily used so that the user can have his/her values in one place, ready to work with.
 Parameters: add_values() does not take any parameters.
 Returns: add_values() does not return anything.
 */
void add_values(){
    ofstream myFile;
    myFile.open("values.txt");
    // Initializing Values
    int how_many = 0;
    double value = 0;
    int finish = 0;
    
    cout << "How many values do you have to enter?" << endl;
    cin >> how_many;
    while(finish != how_many){
        cout << "Please enter your values, one by one." << endl;
        cin >> value;
        myFile << value << endl;
        finish++;
    }
    
}

/* Purpose: The function vector_values does not return anything. It takes values from a file and then stores it into a vector of type double. 
 Parameters: vector_values takes one parameter, a string which designates the name of the file which contains the aforementioned values. 
 Returns: vector_values does not return anything
*/
void add_vector_values(string filename){
    ifstream myFile;
    myFile.open(filename);
    double file_values;
    while(myFile >> file_values){
        myValues.push_back(file_values);
    }
}


/* Purpose: calculate_average is a function which takes values from a .txt file and calculates the average from it.
 Parameters: calculate_average takes one parameter, a string which is the name of the file which contains the values
 Returns: a double, the average of the values inside the file.
 */
double calculate_average(string filename){
    
    //Initiatlizing values
    double average = 0;
    double sum = 0;
    vector<double>stored_values;
    double file_value;
    ifstream ifs;
    ifs.open(filename);
    
    //This while loop makes sure that the file actually opens.
    while(!ifs){
        cout << "Incorrect filename! Please retry! " << endl;
        string new_file_name;
        cin >> new_file_name;
        ifs.open(new_file_name);
    }
    //This while loop takes all the values from the user specified file and adds it to a vector.
    while(ifs >> file_value){
        stored_values.push_back(file_value);
    }
    for(int i = 0; i < stored_values.size(); i++){
        sum += stored_values[i];
        average = sum / stored_values.size();
    }
    cout << "Average Value: " << average << endl;
    return average;
}

/* Purpose: find_mode is a function which takes values from a .txt file and then calculates the mode from it.
 Parameters: find_mode takes one parameter, a string which is the name of the file which contains the values.
 Returns: a double, the mode of the values inside the file.
 NOTE: This function does not work if there is more than one mode.
 */
double find_mode(string filename){
    double mode = 0;
    double inc_count = 0;
    
    for(int i = 0; i < myValues.size(); i++){
        double chall_count= 0;
        
        for(int j = 0; j < myValues.size(); j++){
            if(myValues[i] == myValues[j]){
                chall_count++;
            }
        }
        if(chall_count > inc_count){
            inc_count = chall_count;
            mode = myValues[i];
            }
            
        }
    if(inc_count > 1){
        cout << "Mode: " << mode << endl;
        return mode;
    }
    else{
        cout << "There is no mode for this set of values. " << endl;
        return 0;
    }
}


//Working on a function that finds the mode no matter how many modes there may be.
struct moders{
    double value;
    int count;
};

double find_mode2(string filename){
    double mode = 0;
    vector<moders>modeValues;
    for(int i = 0; i < myValues.size(); i++){
        int local_count = 0;
        for(int j = 0; i < myValues.size(); i++){
            if(myValues[i] == myValues[j]){
                local_count++;
                moders temp;
                temp.value = myValues[i];
                temp.count = local_count;
                modeValues.push_back(temp);
            }
        }
    }
    vector<double>modes;
    
    return mode;
}

double find_median(string filename){
    double median = 0;
    sort(myValues.begin(),myValues.end());
    //If there are an odd number of values in the vector
    if((myValues.size()%2) == 1){
        median = myValues[((myValues.size()/2))];
        cout << "Median: " << median << endl;
    }
    //If there are an even number of values in the vector
    if((myValues.size()%2) == 0){
        int first_val = (myValues.size()/2);
        int second_val = ((myValues.size()/2) - 1);
        
        median = (((myValues[first_val] + myValues[second_val])/2));
        cout << "Median: " << median << endl;
    }
    return median;
}

// This function calculates the standard deviation of values from a user specified file.
double calculate_standard_deviation(string filename){
    double average = calculate_average(filename);
    double std_dev = 0;
    
    return std_dev;
}


int main(){
    add_values();
    add_vector_values("values.txt");
    //calculate_average("values.txt");
    find_mode("values.txt");
    //find_median("values.txt");
    
}





