
// PROGRAM 1 //

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;


//declarations for metric functions
int calculate_accuracy(int, int);
void calculate_sensitivity();
void calculate_specificity();

//creating structure to make each individual line of data a different instance of an object
//For some reason I tried to use structs instead of vectors because I somehow thought it would be easier.

struct survivorDataset {
    //variables for data set
    int pclass;
    int survived;
    int sex;
    int age;
};

void sigmoid(survivorDataset []);

//main
int main(int argc, char** argv)
{
    /*After using a while loop to calculate the number of lines in the file
      I am creating an array of objects to store the structures for each person*/

    ifstream inFS;
    string line;
    string quoted_value, pclass_value, survived_value, sex_value, age_value;
    const int MAX_LEN = 1046;
    survivorDataset survivor_info[MAX_LEN];

    //Try to open file
    cout << "Opening file titanic_project.csv." << endl;

    inFS.open("titanic_project.csv");
    if (!inFS.is_open()) {
        cout << "Could not open file titanic_project.csv." << endl;
        return 1; //1 indicates error
    }

    cout << "Reading line 1" << endl;
    getline(inFS, line);

    //echo heading
    cout << line << endl;

    int numObservations = 0;
    while (inFS.good()) {
        getline(inFS, quoted_value, ','); //the value in quotes before the first comma
        getline(inFS, pclass_value, ','); //the pclass value
        survivor_info[numObservations].pclass = stoi(pclass_value); //converting pclass string value to int for structure
        getline(inFS, survived_value, ',');
        survivor_info[numObservations].survived = stoi(survived_value); //converting survived string value to int for structure
        getline(inFS, sex_value, ',');
        survivor_info[numObservations].sex = stoi(sex_value); //converting sex string value to int for structure
        getline(inFS, age_value, '\n');
        survivor_info[numObservations].age = stoi(age_value); //converting age string value to int for structure
        numObservations++;
    }
    cout << "Closing file titanic_project.csv." << endl;
    inFS.close();
    
    for (int i = 0; i < MAX_LEN; i++) {
        cout << survivor_info[i].pclass << ",";
        cout << survivor_info[i].survived << ",";
        cout << survivor_info[i].sex << ",";
        cout << survivor_info[i].age << "\n";
    }
    
    cout << "Number of records: " << numObservations << endl;

    cout << "\nProgram terminated.\n";

    sigmoid(survivor_info);

    return 0;
}

//sigmoid function
void sigmoid(survivorDataset survivor_info[]) {
    int outputData[800];
    for (int i = 0; i < 799; i++) {
        outputData[i] = 1 / (1 + exp((-1) * survivor_info[i].sex));
        cout << outputData[i] << endl;
    }
}
//metric functions
int calculate_accuracy(int total_nums, int correct_nums) {
    int accuracy_value = correct_nums / total_nums;
    return accuracy_value;
};
void calculate_sensitivity() {};
void calculate_specificity() {};