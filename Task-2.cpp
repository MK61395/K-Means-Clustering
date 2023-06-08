#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <random>
#include <ctime>

using namespace std;

const int num_customers = 200;//number of rows
const int NUM_ATTRIBUTES = 3;//number if columns
const int num_dimensions = 3;//3d
int cluster_number;

//const int NUM_CLUSTERS = 4;

//int clusterAssignment[num_customers];
//int prevClusterAssignment[num_customers];

//2d customer array for double 
double customers[num_customers][num_dimensions];
int cluster[200]; // to store the cluster number for each customer


//calculating the distanc of clusters
double euclideanDistance(double x[3], double y[3]) {
    // calculates the euclidean distance between two 3-dimensional points
    return sqrt(pow(x[0]-y[0], 2) + pow(x[1]-y[1], 2) + pow(x[2]-y[2], 2));
}

//loading data from customers.csv to 3D array
void loadData(string data[][NUM_ATTRIBUTES][1]) {
  ifstream file("customers.csv");
  string line, cell;
  int row = 0, col = 0;

  while (getline(file, line)) {
    col = 0;
    stringstream lineStream(line);
    if (row == 0) {
      row++;
      continue;
    }
    while (getline(lineStream, cell, ',')) {
      if (col < 2) {
        col++;
        continue;
      }
      data[row-1][col-2][0] = cell;
      col++;
    }
    row++;
  }
  file.close();
}

//converting data from srting 3d to double 3d array
void convertData(string data[][NUM_ATTRIBUTES][1], double convertedData[][NUM_ATTRIBUTES]) {
  for (int i = 0; i < num_customers; i++) {
    for (int j = 0; j < NUM_ATTRIBUTES; j++) {
      char* endptr;
      convertedData[i][j] = strtod(data[i][j][0].c_str(), &endptr);
      if (*endptr != '\0') {
        cout << "Error: Could not convert value to float" << endl;
        exit(1);
      }
    }
  }
}


//displaying data stored in double array
void displayData(double data[][NUM_ATTRIBUTES]) {
    cout << "Age\tAnnual Income\tSpending Score" << endl;
    for (int i = 0; i < num_customers; i++) {
        for (int j = 0; j < NUM_ATTRIBUTES; j++) {
            cout << data[i][j] << "\t\t";
        }
        cout << endl;
    }
}



int main() {
   // string data[num_customers][NUM_ATTRIBUTES][1];
    double convertedData[num_customers][NUM_ATTRIBUTES];

    string data[num_customers][NUM_ATTRIBUTES][1];
    loadData(data);

    //loadData("customers.csv", data);
    convertData(data, convertedData);
    displayData(convertedData);

    //rand function calling
     srand(time(0));

    // Generate a random number between 0 and 9
    int randomnumber1 = rand() % 200;
    cout << randomnumber1 << endl;

    int randomnumber2 = rand() % 200;
    cout << randomnumber2 << endl;

    int randomnumber3 = rand() % 200;
    cout << randomnumber3 << endl;

    int randomnumber4 = rand() % 200;
    cout << randomnumber4 << endl;

    //checking to make sure randonumbers are not similar
    if(randomnumber1 == randomnumber2 || randomnumber1 == randomnumber3 || randomnumber1 == randomnumber4)
    {
        randomnumber1 = rand() % 200;
    }
    if(randomnumber2 == randomnumber1 || randomnumber2 == randomnumber3 || randomnumber2 == randomnumber4)
    {
        randomnumber2 = rand() % 200;
    }
    if(randomnumber3 == randomnumber1 || randomnumber3 == randomnumber2 || randomnumber3 == randomnumber4)
    {
        randomnumber3 = rand() % 200;
    }
    if(randomnumber4 == randomnumber1 || randomnumber4 == randomnumber2 || randomnumber4 == randomnumber3)
    {
        randomnumber4 = rand() % 200;
    }

    //double k1[][][];
    //double k2[][][];
    //double k3[][][];
    //double k4[][][];


    //selecting random points using random numbers generated
    ifstream file1("customers.csv");

    string line;
    int currentLine = 0;
    double k1[3]; //Array to store the data for the selected customer

    //Parse the file line by line
    while (getline(file1, line)) {
        if (currentLine == randomnumber1) {
            stringstream lineStream(line);
            string cell;
            int column = 0;
            //Parse the line by comma
            while (getline(lineStream, cell, ',')) {
                if (column == 2 || column == 3 || column == 4) {
                    //Convert the string value to a double and store it in k1
                    k1[column - 2] = stod(cell);
                }
                column++;
            }
            break; //Exit the loop since we found the line we wanted
        }
        currentLine++;
    }

    //Print out the data for the selected customer
    cout << "Age: " << k1[0] << endl;
    cout << "Income: " << k1[1] << endl;
    cout << "Spending Score: " << k1[2] << endl;


//second
     ifstream file2("customers.csv");

    //string line;
    currentLine = 0;
    double k2[3]; //Array to store the data for the selected customer

    //Parse the file line by line
    while (getline(file2, line)) {
        if (currentLine == randomnumber2) {
            stringstream lineStream(line);
            string cell;
            int column = 0;
            //Parse the line by comma
            while (getline(lineStream, cell, ',')) {
                if (column == 2 || column == 3 || column == 4) {
                    //Convert the string value to a double and store it in k1
                    k2[column - 2] = stod(cell);
                }
                column++;
            }
            break; //Exit the loop since we found the line we wanted
        }
        currentLine++;
    }

    //Print out the data for the selected customer
    cout << "Age: " << k2[0] << endl;
    cout << "Income: " << k2[1] << endl;
    cout << "Spending Score: " << k2[2] << endl;

//third

    ifstream file3("customers.csv");

    //string line;
    currentLine = 0;
    double k3[3]; //Array to store the data for the selected customer

    //Parse the file line by line
    while (getline(file3, line)) {
        if (currentLine == randomnumber3) {
            stringstream lineStream(line);
            string cell;
            int column = 0;
            //Parse the line by comma
            while (getline(lineStream, cell, ',')) {
                if (column == 2 || column == 3 || column == 4) {
                    //Convert the string value to a double and store it in k1
                    k3[column - 2] = stod(cell);
                }
                column++;
            }
            break; //Exit the loop since we found the line we wanted
        }
        currentLine++;
    }

    //Print out the data for the selected customer
    cout << "Age: " << k3[0] << endl;
    cout << "Income: " << k3[1] << endl;
    cout << "Spending Score: " << k3[2] << endl;

//fourth
   ifstream file4("customers.csv");

    //string line;
    currentLine = 0;
    double k4[3]; //Array to store the data for the selected customer

    //Parse the file line by line
    while (getline(file4, line)) {
        if (currentLine == randomnumber4) {
            stringstream lineStream(line);
            string cell;
            int column = 0;
            //Parse the line by comma
            while (getline(lineStream, cell, ',')) {
                if (column == 2 || column == 3 || column == 4) {
                    //Convert the string value to a double and store it in k1
                    k4[column - 2] = stod(cell);
                }
                column++;
            }
            break; //Exit the loop since we found the line we wanted
        }
        currentLine++;
    }

    //Print out the data for the selected customer
    cout << "Age: " << k4[0] << endl;
    cout << "Income: " << k4[1] << endl;
    cout << "Spending Score: " << k4[2] << endl;

   // cout << *k4 << *(k4+1) << *(k4+2) << endl;



   // k_means(k1, k2, k3, k4);

/*
   for (int i = 0; i < 200; i++) {
        double minDistance = euclideanDistance(convertedData[i], k1);
        int nearestK = 1;
        double distance = euclideanDistance(convertedData[i], k2);
        if (distance < minDistance) {
            minDistance = distance;
            nearestK = 2;
        }
        distance = euclideanDistance(convertedData[i], k3);
        if (distance < minDistance) {
            minDistance = distance;
            nearestK = 3;
        }
        distance = euclideanDistance(convertedData[i], k4);
        if (distance < minDistance) {
            nearestK = 4;
        }
        cluster[i] = nearestK;
    }

    // write the results to file
    ofstream outputFile("output2.csv");
    outputFile << "id,gender,age,income,spending_score,cluster" << endl;
    for (int i = 0; i < 200; i++) {
        outputFile << i + 1 << ",?,," << convertedData[i][0] << "," << convertedData[i][1] << "," << convertedData[i][2] << "," << cluster[i] << endl;
    }
    outputFile.close();
*/






ifstream customers_file("customers.csv");
int id;
char gender;
double age, income, score;
int cluster_number;
double customer_data[200][3];
int i = 0;
while (customers_file >> id >> gender >> age >> income >> score) {
    customer_data[i][0] = age;
    customer_data[i][1] = income;
    customer_data[i][2] = score;
    i++;
}
customers_file.close();



// for each customer, find the closest k value
for (int j = 0; j < 200; j++) {
    double min_distance = distance(convertedData[j], k1);
    cluster_number = 1;
    double d = distance(convertedData[j], k2);
    if (d < min_distance) {
        min_distance = d;
        cluster_number = 2;
    }
    d = distance(convertedData[j], k3);
    if (d < min_distance) {
        min_distance = d;
        cluster_number = 3;
    }
    d = distance(convertedData[j], k4);
    if (d < min_distance) {
        min_distance = d;
        cluster_number = 4;
    }

    // output the results to the output2.csv file
    ofstream output_file("output2.csv", ios::app);
    output_file << id << "," << gender << "," << age << "," << income << "," << score << "," << cluster_number << endl;
    output_file.close();
}






    return 0;
}





