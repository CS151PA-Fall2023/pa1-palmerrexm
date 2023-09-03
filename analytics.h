/**
 * @file   analytics.h
 * @brief  Declaration file
 * @author Rex Palmer
 * @date   august 25
 *
 */
// START GUARD CODES
#ifndef ANALYTICS_H
#define ANALYTICS_H

// INCLUDE THE HEADER FILES NEEDED FOR THE FUNCTIONS TO WORK
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct GradEmploymentData
{
    int demographicsTotal;     // The estimated total of people awarded degrees in this major during 2005
    string educationMajor;     // The name of the major for these graduated students
    float meanSalary;          // The average (mean) recorded salary reported for employed people with this degree
    float medianSalary;        // The median recorded salary reported for employed people with this degree
    int demographicsAsian;     // The estimated number of people identifying as Asian that were awarded degrees in this major
    int demographicsMinority;  // The estimated number of people identifying as minority 
                               // (e.g., Black, African American, Native American) that were awarded degrees in this major
    int demographicsWhite;     // The estimated number of people identifying as White that were awarded degrees in this major
    int demographicsFemales;   // The estimate number of women awarded degrees in this major
    int demographicsMales;     // The estimate number of men awarded degrees in this major
    int educationBachelor;     // The estimated number of bachelor degrees awarded in this for major
    int educationDoctorate;    // The estimated number of doctoral degrees awarded in this for major
    int educationMasters;      // The estimated number of Masters awarded in this for major
};

void openInputFile(ifstream &file, string name);
void readFileIntoVector(ifstream &file, vector<GradEmploymentData> &v);
void insertionSortMeanSalaryMax(vector<GradEmploymentData> &v);
void insertionSortMeanSalaryMin(vector<GradEmploymentData> &v);
void insertionSortMedianSalaryMax(vector<GradEmploymentData> &v);
void insertionSortMedianSalaryMin(vector<GradEmploymentData> &v);
void insertionSortAsiansMax(vector<GradEmploymentData> &v);
void insertionSortAsiansMin(vector<GradEmploymentData> &v);
void insertionSortMinoritiesMax(vector<GradEmploymentData> &v);
void insertionSortMinoritiesMin(vector<GradEmploymentData> &v);
void insertionSortFemalesMax(vector<GradEmploymentData> &v);
void insertionSortFemalesMin(vector<GradEmploymentData> &v);
void insertionSortMajor(vector<GradEmploymentData> &v);
int binarySearch(vector<GradEmploymentData> &v, string major);
void displaySelection(vector<GradEmploymentData> &v, int seek, int listSize);
int displayMenu();
void displayVector(vector<GradEmploymentData> &v);
#endif
