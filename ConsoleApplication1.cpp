// Waheed Anwar
// NetID: wxa200000
// 4375.004
// Assignment 1

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include "ConsoleApplication1.h" //I'm using visual studio

using namespace std;

void numericVectorSum(vector<double>);
void numericVectorMean(vector<double>);
void numericVectorMedian(vector<double>);
void numericVectorRange(vector<double>);
void covar(vector<double>, vector<double>);
void cor(vector<double>, vector<double>);

int main(int argc, char** argv)
{
    ifstream inFS;
    string line;
    string rm_in, medv_in;
    const int MAX_LEN = 1000;
    vector<double> rm(MAX_LEN);
    vector<double> medv(MAX_LEN);

    //Try to open file
    cout << "Opening file Boston.csv." << endl;

    inFS.open("Boston.csv");
    if (!inFS.is_open()) {
        cout << "Could not open file Boston.csv." << endl;
        return 1; //1 indicates error
    }

    cout << "Reading line 1" << endl;
    getline(inFS, line);

    //echo heading
    cout << "heading: " << line << endl;

    int numObservations = 0;
    while (inFS.good()) {
        getline(inFS, rm_in, ',');
        getline(inFS, medv_in, '\n');
        rm.at(numObservations) = stof(rm_in);
        medv.at(numObservations) = stof(medv_in);

        numObservations++;
    }

    rm.resize(numObservations);
    medv.resize(numObservations);

    cout << "new length" << rm.size() << endl;

    cout << "Closing file Boston.csv." << endl;
    inFS.close();

    cout << "Number of records: " << numObservations << endl;

    cout << "\nStats for rm" << endl;
    numericVectorSum(rm);
    numericVectorMean(rm);
    numericVectorMedian(rm);
    numericVectorRange(rm);

    cout << "\nStats for medv" << endl;
    numericVectorSum(medv);
    numericVectorMean(medv);
    numericVectorMedian(medv);
    numericVectorRange(medv);

    cout << "\n Covariance = "; 
    covar(rm, medv); 
    cout << endl;

    cout << "\n Correlation = ";
    cor(rm, medv);
    cout << endl;

    cout << "\nProgram terminated.";

    return 0;
}

void numericVectorSum(vector<double> rm_or_medv) {
    double sum = 0;
    for (double i : rm_or_medv) {
        sum += i;
    }
    cout << "The sum of this vector is " << sum << endl;
};
void numericVectorMean(vector<double> rm_or_medv) { //found the sum again but also counted total number of entries
    double sum = 0;
    int count = 0;
    for (double i : rm_or_medv) {
        sum += i;
        count += 1;
    }
    cout << "The mean of this vector is " << (sum / count) << endl;
};
void numericVectorMedian(vector<double> rm_or_medv) { //median formula, diving the size by 2 to find middle
    sort(rm_or_medv.begin(), rm_or_medv.end());
    int count = 0;
    double middle_num = 0;
    for (double i : rm_or_medv) {
        if (count == rm_or_medv.size() / 2) {
            middle_num = i;
            break;
        }
        count++;
    }
    cout << "The median of this vector is " << middle_num << endl;
    
};
void numericVectorRange(vector<double> rm_or_medv) { //sorting and then finding the first and last value
    sort(rm_or_medv.begin(), rm_or_medv.end());
    int count = 0;
    double min = 0, max = 0;
    for (double i : rm_or_medv) {
        if (count == 0)
            min = i;
        else if (count = rm_or_medv.size() - 1)
            max = i;
        count++;
    }
    cout << "The range of this vector is " << min << " as the minimum value and " << max << " as the maximum value" << endl;
};
void covar(vector<double> rm, vector<double> medv) {  //for rm and medv together
    int n_dataPts = rm.size(); //total number of data points (n)
    double sum = 0; //finding the mean for rm
    int count = 0;
    for (double i : rm) {
        sum += i;
        count += 1;
    }
    double mean_rm = (sum / count);

    sum = 0; //reset sum and count for the next vector
    count = 0;

    for (double i : medv) { //finding the mean for medv
        sum += i;
        count += 1;
    }
    double mean_medv = (sum / count);

    sum = 0;
    int count_rm = 0;
    int count_medv = 0;

    //covariance formula
    for (double i : rm) {
        for (double n : medv) {
            if (count_medv == count_rm) {
                sum += ((i - mean_rm) * (n - mean_medv));
                count_medv++;
                break;
            }
            else if (count_medv < count_rm)
                continue;
            else
                break;
        }
        count_rm++;
        count_medv = 0;
    }

    cout << "The covariance is " << (sum / (n_dataPts - 1)) << endl;
};
void cor(vector<double> rm, vector<double> medv) {  //for rm and medv together
    cout << "The correlation is " << endl;
};