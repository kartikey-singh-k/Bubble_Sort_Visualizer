#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm> 

using namespace std;

vector<int> parseInputArray(const string& input) {
    vector<int> arr;
    stringstream ss(input);
    string value;

    while (getline(ss, value, ',')) {
        arr.push_back(stoi(value));
    }
    return arr;
}

void writeArrayAsHTML(ofstream& file, const vector<int>& arr) {
    int maxValue = *max_element(arr.begin(), arr.end()); 
    double scaleFactor = 300.0 / maxValue; 

    file << "<div class='container'>\n";
    for (int value : arr) {
        int scaledHeight = static_cast<int>(value * scaleFactor); 
        file << "<div class='bar' style='height:" << scaledHeight << "px;' title='" << value << "'></div>\n";
    }
    file << "</div>\n<hr>\n";
}

void bubbleSortAndGenerateHTML(vector<int>& arr) {
    ofstream file("visualization.html"); 

    file << "<!DOCTYPE html>\n<html>\n<head>\n<title>Bubble Sort Visualization</title>\n"
         << "<style>\n"
         << "  .bar { display: inline-block; background-color: rgb(201, 215, 45); width: 20px; margin: 2px; border-radius: 5px;  border: 2px solid white; }\n"
         << "  .container { display: flex; align-items: flex-end; justify-content: center; height: 350px; overflow-x: auto; padding: 20px; background-color: #2c3e50; border-radius: 10px;}\n"
         << "  body { font-family: 'Arial', sans-serif; text-align: center; background-color: #ecf0f1; margin: 0; padding: 20px; }\n"
         << "  h1 { color: #fff; background-color: #e74c3c; padding: 10px; border-radius: 5px; display: inline-block; }\n"
         << "  hr { border: none; height: 2px; background-color: #ccc; margin: 20px 0; }\n"
         << "</style>\n"
         << "</head>\n<body>\n<h1>Bubble Sort Visualization</h1>\n";


    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }

         
            writeArrayAsHTML(file, arr);
        }
    }


    file << "</body>\n</html>";
    file.close();
}

int main() {
    string userInput;
    cout << "Enter your array (comma-separated): ";
    getline(cin, userInput);

    vector<int> arr = parseInputArray(userInput);

    bubbleSortAndGenerateHTML(arr);

    cout << "Visualization HTML generated: open 'visualization.html' in your browser." << endl;
    return 0;
}
