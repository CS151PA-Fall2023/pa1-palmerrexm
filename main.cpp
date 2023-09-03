#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "analytics.h"

using namespace std;
int main(){

    
    //vector used to hold degree information about each line in the text file
    vector<GradEmploymentData> survey;

    
    
    //opens the input file for reading after checking for correct file
    ifstream file;
    openInputFile(file, "graduates2015.csv");

    //reads file into vector of structures
    readFileIntoVector(file, survey);


    int select; //variable used for switch statement 
    bool leave = false; //flag to get out of menu
    string majorChoice; //holds user input for major of interest
    int majorInt; //holds return of binary search of majors
    string myString; //string to check if enter is pressed

    //loop takes user back to menu unless exit is selected
    do
    {
        //shows menu and reads user input
        select = displayMenu();

        //switch statement selects option based on user input
        switch (select)
        {
            //sorts vector containing file data based on user input
            case 1: insertionSortMeanSalaryMax(survey);
            //displays sorted vector  
            displaySelection(survey, 2, 10);

            //loop to verify enter input to return to menu
            do 
            {
                cout << endl << "Press enter to continue..." << endl;
                cin.ignore();
                getline(cin, myString);
            } while (myString.length() != 0);
            break;

            case 2: insertionSortMeanSalaryMin(survey);
            displaySelection(survey, 2, 10);
            do 
            {
                cout << endl << "Press enter to continue..." << endl;
                cin.ignore();
                getline(cin, myString);
            } while (myString.length() != 0);
            break;

            case 3: insertionSortMedianSalaryMax(survey); 
            displaySelection(survey, 3, 10);
            do 
            {
                cout << endl << "Press enter to continue..." << endl;
                cin.ignore();
                getline(cin, myString);
            } while (myString.length() != 0);
            break;

            case 4: insertionSortMedianSalaryMin(survey);
            displaySelection(survey, 3, 10);
            do 
            {
                cout << endl << "Press enter to continue..." << endl;
                cin.ignore();
                getline(cin, myString);
            } while (myString.length() != 0);
            break;

            case 5: insertionSortAsiansMax(survey);
            displaySelection(survey, 4, 5);
            do 
            {
                cout << endl << "Press enter to continue..." << endl;
                cin.ignore();
                getline(cin, myString);
            } while (myString.length() != 0);
            break;

            case 6: insertionSortAsiansMin(survey);
            displaySelection(survey, 4, 5);
            do 
            {
                cout << endl << "Press enter to continue..." << endl;
                cin.ignore();
                getline(cin, myString);
            } while (myString.length() != 0);
            break;

            case 7: insertionSortMinoritiesMax(survey);
            displaySelection(survey, 5, 5);
            do 
            {
                cout << endl << "Press enter to continue..." << endl;
                cin.ignore();
                getline(cin, myString);
            } while (myString.length() != 0);
            break;

            case 8: insertionSortMinoritiesMin(survey);
            displaySelection(survey, 5, 5);
            do 
            {
                cout << endl << "Press enter to continue..." << endl;
                cin.ignore();
                getline(cin, myString);
            } while (myString.length() != 0);
            break;

            case 9: insertionSortFemalesMax(survey);
            displaySelection(survey, 7, 5);
            do 
            {
                cout << endl << "Press enter to continue..." << endl;
                cin.ignore();
                getline(cin, myString);
            } while (myString.length() != 0);
            break;

            case 10: insertionSortFemalesMin(survey);
            displaySelection(survey, 7, 5);
            do 
            {
                cout << endl << "Press enter to continue..." << endl;
                cin.ignore();
                getline(cin, myString);
            } while (myString.length() != 0);
            break;            


            case 11: insertionSortMajor(survey);
            //shows list of all majors sorted alphabetically to user
            displayVector(survey);
            cout<<"Please select a major from the above list to see information: "<<endl;
            
            cin.ignore();
            getline(cin >> ws, majorChoice);
            cout<<endl;
            
            majorInt=binarySearch(survey, majorChoice);

            //loop to search for user input while also validating user input
            while(majorInt == -1)
            {
                cout<<"That input is invalid. please type in the desired major with correct capitilization: ";
                cin.sync();
                getline(cin >> ws, majorChoice);
                majorInt=binarySearch(survey, majorChoice);

            }
            cout<<"The estimated total of people awarded degrees in this major during 2005: "<<survey[majorInt].demographicsTotal<<endl;
            cout<<"The average (mean) recorded salary reported for employed people with this degree: $"<<survey[majorInt].meanSalary<<endl;
            cout<<"The median recorded salary reported for employed people with this degree: $"<<survey[majorInt].medianSalary<<endl;
            cout<<"The estimated number of people identifying as Asian that were awarded degrees in this major: "<<survey[majorInt].demographicsAsian<<endl;
            cout<<"The estimated number of people identifying as minority that were awarded degrees in this major: "<<survey[majorInt].demographicsMinority<<endl;
            cout<<"The estimated number of people identifying as White that were awarded degrees in this major: "<<survey[majorInt].demographicsWhite<<endl;
            cout<<"The estimate number of women awarded degrees in this major: "<<survey[majorInt].demographicsFemales<<endl;
            cout<<"The estimate number of men awarded degrees in this major: "<<survey[majorInt].demographicsMales<<endl;
            cout<<"The estimated number of bachelor degrees awarded in this for major: "<<survey[majorInt].educationBachelor<<endl;
            cout<<"The estimated number of doctoral degrees awarded in this for major: "<<survey[majorInt].educationDoctorate<<endl;
            cout<<"The estimated number of Masters awarded in this for major: "<<survey[majorInt].educationMasters<<endl;
            
            do 
            {
                cout << endl << "Press enter to continue..." << endl;
                cin.sync();
                getline(cin, myString);
            } while (myString.length() != 0);
            break;

            case 12: leave = true;
            break;

        }
    } while (leave != true);

    

    file.close();
    return 0;
}

