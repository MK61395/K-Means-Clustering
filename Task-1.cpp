#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <limits>
#include <random>
using namespace std;


const int MAX_ITERATIONS = 4100;
string clusters[4001];
//const int K = 3;
const int N = 4001; // Number of data points

const int k = 5; // Number of clusters

//formula for distance calculation
double euclidean_distance(double x1, double y1, double x2, double y2) {
  return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
}

int main()
{
    string checker;
    string myarr[4001][3];   //String 2D array to store 4001x3 values
    ifstream mycsvfile("driver.csv");
    //string fileCommand;

    if (!mycsvfile) //if file fails to open
        {
         cout << "Error opening file: " << "driver-data.csv" << endl;
         return 1;
        }

    if (mycsvfile.is_open())
    {
        cout << "File Opened Successfully" << endl;

        int i = 0, j = 0;
        while (getline(mycsvfile, checker, ','))
        {

            size_t found = checker.find("\n");
            if (found != string::npos)
            {
                string lastToken = checker.substr(0, found);
                string nextLineFirstTOken = checker.substr(found + 1);
                myarr[i++][j] = lastToken;
                j = 0;
                if (nextLineFirstTOken != "\n")
                    myarr[i][j++] = nextLineFirstTOken;
            }
            else
            {
                myarr[i][j++] = checker;
            }

        }

       // for (int i = 0; i < 4001; ++i)
        //{
          //  for (int j = 0; j < 3; ++j)
            //{
              //  cout << myarr[i][j] << "  ";
            //}
            //cout << endl;
        //}

    }
    mycsvfile.close();
    //printing the values to check
    for (int i = 0; i < 4001; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cout << myarr[i][j] << "  ";
            }
            cout << endl;
        }


    double double_arr[4001][3];
    for (int i = 0; i < 4001; i++)
    {
         for (int j = 0; j < 3; j++)
         {
            double_arr[i][j] = atof(myarr[i][j].c_str());
         }
    }

    //printing double array to check if conversion works
    cout << "The double array: " << endl;
    for (int i = 0; i < 4001; i++) {
    for (int j = 0; j < 3; j++) {
      cout << double_arr[i][j] << " ";
    }
    cout << endl;
  }

  //double k1[1][2] = {76, 20};
  //double k2[1][2] = {150,70};
  //double k3[1][2] = {40,5};

    //4 arrays for clustering
  double k1[1][2] = {168.47, 56};
  double k2[1][2] = {44.06,1};
  double k3[1][2] = {146.8,18};
  double k4[1][2] = {38.61,37};

 //double k1[1][2] = {57.58, 35};
  //double k2[1][2] = {170.23,13};
  //double k3[1][2] = {49.68,9};
  //double k4[1][2] = {184.96,65};

   for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 2; j++) {
      std::cout << k1[i][j] << " ";
    }}


    int k1count = 0;
    int k2count = 0;
    int k3count =0;
    int k4count = 0;

    //string clusters[4001];

    for (int i = 0; i < 4001; i++) {
    double distance = double_arr[i][1];
    double overspeed = double_arr[i][2];

    //distance calculation and mean updation
    double dist_to_k1 = euclidean_distance(distance, overspeed, k1[0][0], k1[0][1]);
    double dist_to_k2 = euclidean_distance(distance, overspeed, k2[0][0], k2[0][1]);
    double dist_to_k3 = euclidean_distance(distance, overspeed, k3[0][0], k3[0][1]);
    double dist_to_k4 = euclidean_distance(distance, overspeed, k4[0][0], k4[0][1]);

    //checking for distances
    if (dist_to_k1 <= dist_to_k2 && dist_to_k1 <= dist_to_k3 && dist_to_k1 <= dist_to_k4) {
      cout << "Point " << i << " is closest to k1" << endl;
      clusters[i] = "k1";
      k1count++;
    } else if (dist_to_k2 <= dist_to_k1 && dist_to_k2 <= dist_to_k3 && dist_to_k2 <= dist_to_k4) {
      cout << "Point " << i << " is closest to k2" << endl;
      clusters[i] = "k2";
      k2count++;
    }
    else if(dist_to_k3 <= dist_to_k1 && dist_to_k3 <= dist_to_k2 && dist_to_k3 <= dist_to_k4){
        cout << "Point " << i << " is closest to k3" << endl;
        clusters[i] = "k3";
        k3count++;
    }
    else {
      cout << "Point " << i << " is closest to k4" << endl;
      clusters[i] = "k4";
      k4count++;
    }
  }
    //printing values for each cluster
  cout << k1count << endl;
  cout << k2count << endl;
  cout << k3count << endl;
  cout << k4count << endl;

  //outputting data with cluster numbers to new file
ofstream outputFile("output.csv");
if (outputFile.is_open()) {
  // Write the header
  outputFile << "ID,Distance,Overspeed,Cluster" << endl;

  // Write the data
  for (int i = 0; i < 4001; i++) {
    outputFile << myarr[i][0] << "," << double_arr[i][1] << "," << double_arr[i][2] << "," << clusters[i] << endl;
  }

  cout << "Data has been written to output.csv successfully" << endl;
  outputFile.close();
} else {
  cout << "Error opening output.csv file" << endl;
}

  return 0;
}



