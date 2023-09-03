#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "analytics.h"

using namespace std;
/**
 * @brief opens the input file, if wrong file closes program with error
 * 
 * @param file 
 * @param name 
 */
void openInputFile(ifstream &file, string name)
{
    file.open(name);
    if (!file){
        cout<<"Error opening file\n";
        exit(1);
    }
}

/**
 * @brief reads file into vector of structures
 * 
 * @param file 
 * @param v 
 */
void readFileIntoVector(ifstream &file, vector<GradEmploymentData> &v)
{
    //variable used to read file
    string input;
    //variable used to read past qoutations
    char skip;
    //moves past the first line of the file
    getline(file, input);
    getline(file, input, ',');


    while (file.peek() != EOF)
    {
        GradEmploymentData newDegree;
        
        istringstream(input)>>newDegree.demographicsTotal;

        //logic to check if quotations are used instead of commas as a delimiter
        if (file.peek() != '"')
        {
            getline(file, input, ',');     
            newDegree.educationMajor=input;
        }
        else
        {
            file.get(skip);
            getline(file, input, '"');
            newDegree.educationMajor=input;
            file.get(skip);
        }
        
        getline(file, input, ',');     
        istringstream(input)>>newDegree.meanSalary;
        getline(file, input, ',');          
        istringstream(input)>>newDegree.medianSalary;
        getline(file, input, ',');        
        istringstream(input)>>newDegree.demographicsAsian;
        getline(file, input, ',');     
        istringstream(input)>>newDegree.demographicsMinority;
        getline(file, input, ',');  
        istringstream(input)>>newDegree.demographicsWhite;
        getline(file, input, ',');     
        istringstream(input)>>newDegree.demographicsFemales;
        getline(file, input, ',');   
        istringstream(input)>>newDegree.demographicsMales;
        getline(file, input, ',');     
        istringstream(input)>>newDegree.educationBachelor;
        getline(file, input, ',');
        istringstream(input)>>newDegree.educationDoctorate;
        getline(file, input, '\n');       
        istringstream(input)>>newDegree.educationMasters;
        getline(file, input, ',');

        v.push_back(newDegree);
    }
}

/**
 * @brief sorts vector by max mean salary
 * 
 * @param v 
 */
void insertionSortMeanSalaryMax(vector<GradEmploymentData> &v)
{
    for (long unsigned int startScan = 1; startScan < v.size(); ++startScan)
    {
        GradEmploymentData key = v[startScan];
        int index = startScan - 1;

        while (index >= 0 && v[index].meanSalary < key.meanSalary)
        {
            v[index+1] = v[index];
            --index;
        }
        v[index+1] = key;
    }
}

/**
 * @brief sorts vector by min mean salary
 * 
 * @param v 
 */
void insertionSortMeanSalaryMin(vector<GradEmploymentData> &v)
{
    for (long unsigned int startScan = 1; startScan < v.size(); ++startScan)
    {
        GradEmploymentData key = v[startScan];
        int index = startScan - 1;

        while (index >= 0 && v[index].meanSalary > key.meanSalary)
        {
            v[index+1] = v[index];
            --index;
        }
        v[index+1] = key;
    }
}

/**
 * @brief sorts vector by max median salary
 * 
 * @param v 
 */
void insertionSortMedianSalaryMax(vector<GradEmploymentData> &v)
{
    for (long unsigned int startScan = 1; startScan < v.size(); ++startScan)
    {
        GradEmploymentData key = v[startScan];
        int index = startScan - 1;

        while (index >= 0 && v[index].medianSalary < key.medianSalary)
        {
            v[index+1] = v[index];
            --index;
        }
        v[index+1] = key;
    }
}

/**
 * @brief sorts vector by min median salary
 * 
 * @param v 
 */
void insertionSortMedianSalaryMin(vector<GradEmploymentData> &v)
{
    for (long unsigned int startScan = 1; startScan < v.size(); ++startScan)
    {
        GradEmploymentData key = v[startScan];
        int index = startScan - 1;

        while (index >= 0 && v[index].medianSalary > key.medianSalary)
        {
            v[index+1] = v[index];
            --index;
        }
        v[index+1] = key;
    }
}

/**
 * @brief sorts vector by max asians
 * 
 * @param v 
 */
void insertionSortAsiansMax(vector<GradEmploymentData> &v)
{
    for (long unsigned int startScan = 1; startScan < v.size(); ++startScan)
    {
        GradEmploymentData key = v[startScan];
        int index = startScan - 1;

        while (index >= 0 && v[index].demographicsAsian < key.demographicsAsian)
        {
            v[index+1] = v[index];
            --index;
        }
        v[index+1] = key;
    }
}

/**
 * @brief sorts vector by min asians
 * 
 * @param v 
 */
void insertionSortAsiansMin(vector<GradEmploymentData> &v)
{
    for (long unsigned int startScan = 1; startScan < v.size(); ++startScan)
    {
        GradEmploymentData key = v[startScan];
        int index = startScan - 1;

        while (index >= 0 && v[index].demographicsAsian > key.demographicsAsian)
        {
            v[index+1] = v[index];
            --index;
        }
        v[index+1] = key;
    }
}

/**
 * @brief sorts vector by max minorities
 * 
 * @param v 
 */
void insertionSortMinoritiesMax(vector<GradEmploymentData> &v)
{
    for (long unsigned int startScan = 1; startScan < v.size(); ++startScan)
    {
        GradEmploymentData key = v[startScan];
        int index = startScan - 1;

        while (index >= 0 && v[index].demographicsMinority < key.demographicsMinority)
        {
            v[index+1] = v[index];
            --index;
        }
        v[index+1] = key;
    }
}

/**
 * @brief sorts vector by min minorities
 * 
 * @param v 
 */
void insertionSortMinoritiesMin(vector<GradEmploymentData> &v)
{
    for (long unsigned int startScan = 1; startScan < v.size(); ++startScan)
    {
        GradEmploymentData key = v[startScan];
        int index = startScan - 1;

        while (index >= 0 && v[index].demographicsMinority > key.demographicsMinority)
        {
            v[index+1] = v[index];
            --index;
        }
        v[index+1] = key;
    }
}

/**
 * @brief sorts vector by max females
 * 
 * @param v 
 */
void insertionSortFemalesMax(vector<GradEmploymentData> &v)
{
    for (long unsigned int startScan = 1; startScan < v.size(); ++startScan)
    {
        GradEmploymentData key = v[startScan];
        int index = startScan - 1;

        while (index >= 0 && v[index].demographicsFemales < key.demographicsFemales)
        {
            v[index+1] = v[index];
            --index;
        }
        v[index+1] = key;
    }
}

/**
 * @brief sorts vector by min females
 * 
 * @param v 
 */
void insertionSortFemalesMin(vector<GradEmploymentData> &v)
{
    for (long unsigned int startScan = 1; startScan < v.size(); ++startScan)
    {
        GradEmploymentData key = v[startScan];
        int index = startScan - 1;

        while (index >= 0 && v[index].demographicsFemales > key.demographicsFemales)
        {
            v[index+1] = v[index];
            --index;
        }
        v[index+1] = key;
    }
}

/**
 * @brief sorts vector by major
 * 
 * @param v 
 */
void insertionSortMajor(vector<GradEmploymentData> &v)
{
    for (long unsigned int startScan = 1; startScan < v.size(); ++startScan)
    {
        GradEmploymentData key = v[startScan];
        int index = startScan - 1;

        while (index >= 0 && v[index].educationMajor > key.educationMajor)
        {
            v[index+1] = v[index];
            --index;
        }
        v[index+1] = key;
    }
}

/**
 * @brief searches through sorted vector for desired major
 * 
 * @param v 
 * @param major 
 * @return int 
 */
int binarySearch(vector<GradEmploymentData> &v, string major)
{
    int first = 0, // First array element
        last = v.size() - 1, // Last array element
        middle, // Midpoint of search
        position = -1; // Position of search value
    bool found = false; // Flag

    while (!found && first <= last)
    {
        middle = (first + last) / 2; // Calculate midpoint
        if (v[middle].educationMajor == major) // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (v[middle].educationMajor > major) // If value is in lower half
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1; // If value is in upper half
        }
    }
    return position;
}

/**
 * @brief function displays menu output after user input
 * 
 * @param v 
 * @param seek 
 * @param listSize 
 */
void displaySelection(vector<GradEmploymentData> &v, int seek, int listSize)
{   
    string stat; //variable to decide what label to put on right column
    if (seek == 1)
    {
        stat = "Total Demographics";
        cout<<setw(36)<<left<<"Education Major"<<stat<<endl;
        cout<<"------------------------------------------------"<<endl;
        for (int i =0; i<listSize; i++)
        {
            
            cout<<setw(36)<<left<<v[i].educationMajor<<setw(11)<<right<<setprecision(2)<<v[i].demographicsTotal<<endl;
        }
    }
    else if (seek == 2)
    {
        stat = "Mean Salary";
        cout<<setw(36)<<left<<"Education Major"<<stat<<endl;
        cout<<"------------------------------------------------"<<endl;
        for (int i =0; i<listSize; i++)
        {
            
            cout<<setw(36)<<left<<v[i].educationMajor<<"$"<<setw(11)<<right<<fixed<<setprecision(2)<<v[i].meanSalary<<endl;
        }    
    }
    else if (seek == 3)
    {
        stat = "Median Salary";
        cout<<setw(36)<<left<<"Education Major"<<stat<<endl;
        cout<<"------------------------------------------------"<<endl;
        for (int i =0; i<listSize; i++)
        {
            
            cout<<setw(36)<<left<<v[i].educationMajor<<"$"<<setw(11)<<right<<fixed<<setprecision(2)<<v[i].medianSalary<<endl;
        } 
    }
    else if (seek == 4)
    {
        stat = "Asian Demographics";
        cout<<setw(36)<<left<<"Education Major"<<stat<<endl;
        cout<<"------------------------------------------------"<<endl;
        for (int i =0; i<listSize; i++)
        {
            
            cout<<setw(36)<<left<<v[i].educationMajor<<setw(11)<<right<<v[i].demographicsAsian<<endl;
        } 
    }
    else if (seek == 5)
    {
        stat = "Minority Demographics";
        cout<<setw(36)<<left<<"Education Major"<<stat<<endl;
        cout<<"------------------------------------------------"<<endl;
        for (int i =0; i<listSize; i++)
        {
        
            cout<<setw(36)<<left<<v[i].educationMajor<<setw(11)<<right<<v[i].demographicsMinority<<endl;
        } 
    }
    else if (seek == 6)
    {
        stat = "White Demographics";
        cout<<setw(36)<<left<<"Education Major"<<stat<<endl;
        cout<<"------------------------------------------------"<<endl;
        for (int i =0; i<listSize; i++)
        {
            cout<<setw(36)<<left<<v[i].educationMajor<<setw(11)<<right<<v[i].demographicsWhite<<endl;
        } 
    }
    else if (seek == 7)
    {
        stat = "Female Demographics";
        cout<<setw(36)<<left<<"Education Major"<<stat<<endl;
        cout<<"------------------------------------------------"<<endl;        
        for (int i =0; i<listSize; i++)
        {
            
            cout<<setw(36)<<left<<v[i].educationMajor<<setw(11)<<right<<v[i].demographicsFemales<<endl;
        } 
    }
    else if (seek == 8)
    {
        stat = "Male Demographics";
        cout<<setw(36)<<left<<"Education Major"<<stat<<endl;
        cout<<"------------------------------------------------"<<endl;        
        for (int i =0; i<listSize; i++)
        {

            cout<<setw(36)<<left<<v[i].educationMajor<<setw(11)<<right<<v[i].demographicsMales<<endl;
        } 
    }
    else if (seek == 9)
    {
        stat = "Bachelor Degrees";
        cout<<setw(36)<<left<<"Education Major"<<stat<<endl;
        cout<<"------------------------------------------------"<<endl;    
        for (int i =0; i<listSize; i++)
        {
            
            cout<<setw(36)<<left<<v[i].educationMajor<<setw(11)<<right<<v[i].educationBachelor<<endl;
        } 
    }
    else if (seek == 10)
    {
        stat = "Doctorate Degrees";
        cout<<setw(36)<<left<<"Education Major"<<stat<<endl;
        cout<<"------------------------------------------------"<<endl;    
        for (int i =0; i<listSize; i++)
        {

            cout<<setw(36)<<left<<v[i].educationMajor<<setw(11)<<right<<v[i].educationDoctorate<<endl;
        } 
    }
    else if (seek == 11)
    {
        stat = "Master Degrees";
        cout<<setw(36)<<left<<"Education Major"<<stat<<endl;
        cout<<"------------------------------------------------"<<endl;
        for (int i =0; i<listSize; i++)
        {

            cout<<setw(36)<<left<<v[i].educationMajor<<setw(11)<<right<<v[i].educationMasters<<endl;
        } 
    } 
}

/**
 * @brief displays menu before user input
 * 
 * @return int 
 */
int displayMenu()
{
    int choice;
    cout<<"2015 National Survey of Recent College Graduate"<<endl;
    cout<<"1. Top 10 Majors with the Highest Mean Salary"<<endl;
    cout<<"2. Top 10 Majors with the Lowest Mean Salary"<<endl;
    cout<<"3. Top 10 Majors with the Highest Median Salary"<<endl;
    cout<<"4. Top 10 Majors with the Lowest Median Salary"<<endl;
    cout<<"5. What are the Top 5 Majors with the Highest Number of Asians"<<endl;
    cout<<"6. What are the Top 5 Majors with the Lowest Number of Asians"<<endl;
    cout<<"7. What are the Top 5 Majors with the Highest Number of Minorities"<<endl;
    cout<<"8. What are the Top 5 Majors with the Lowest Number of Minorities"<<endl;
    cout<<"9. What are the Top 5 Majors with the Highest Number of Females"<<endl;
    cout<<"10. What are the Top 5 Majors with the Lowest Number of Females"<<endl;
    cout<<"11. Display Information for a Specific Major"<<endl;
    cout<<"12. Exit"<<endl<<endl;
    cout<<"Select a menu: ";
    cin >> choice;
    while (choice < 1 || choice > 12)
    {
        cout<<"That input is not valid. Enter an integer between 1 and 12. ";
        cin >> choice;
    }
    cout<<endl;
    return choice;   
}

/**
 * @brief shows all choices available to user
 * 
 * @param v 
 */
void displayVector(vector<GradEmploymentData> &v)
{
    for (long unsigned int i=0; i<v.size(); i++)
    {
        cout<<v[i].educationMajor<<endl;
    }
}