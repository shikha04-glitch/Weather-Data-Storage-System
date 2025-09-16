#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Weather Record ADT
struct WeatherRecord {
    string date;
    string city;
    double temperature;

    WeatherRecord() {
        date = "";
        city = "";
        temperature = -9999; // sentinel for missing
    }

    WeatherRecord(string d, string c, double t) {
        date = d;
        city = c;
        temperature = t;
    }
};

// Weather Data System
class WeatherDataSystem {
private:
    int numYears, numCities;
    vector<string> years;
    vector<string> cityNames;
    vector<vector<WeatherRecord>> records; // 2D array

public:
    WeatherDataSystem() {
        numYears = 0;
        numCities = 0;
    }

    void setup() {
        cout << "Enter number of years: ";
        cin >> numYears;
        cout << "Enter number of cities: ";
        cin >> numCities;

        cin.ignore();
        years.resize(numYears);
        cityNames.resize(numCities);
        records.resize(numYears, vector<WeatherRecord>(numCities));

        cout << "Enter years:\n";
        for(int i = 0; i < numYears; i++) cin >> years[i];

        cin.ignore();
        cout << "Enter city names:\n";
        for(int i = 0; i < numCities; i++) getline(cin, cityNames[i]);
    }

    int getYearIndex(string year) {
        for(int i = 0; i < numYears; i++)
            if(years[i] == year) return i;
        return -1;
    }

    int getCityIndex(string city) {
        for(int i = 0; i < numCities; i++)
            if(cityNames[i] == city) return i;
        return -1;
    }

    // --- ADT Methods ---
    void insertWeatherRecord() {
        string date, city;
        double temp;
        cout << "Enter date (DD/MM/YYYY): ";
        cin >> date;
        cin.ignore();
        cout << "Enter city: ";
        getline(cin, city);
        cout << "Enter temperature: ";
        cin >> temp;

        int row = getYearIndex(date.substr(6,4));
        int col = getCityIndex(city);

        if(row >= 0 && col >= 0) {
            records[row][col] = WeatherRecord(date, city, temp);
            cout << "Record inserted successfully!\n";
        } else {
            cout << "Invalid year or city!\n";
        }
    }

    void deleteWeatherRecord() {
        string date, city;
        cout << "Enter date (DD/MM/YYYY) to delete: ";
        cin >> date;
        cin.ignore();
        cout << "Enter city: ";
        getline(cin, city);

        int row = getYearIndex(date.substr(6,4));
        int col = getCityIndex(city);

        if(row >= 0 && col >= 0 && records[row][col].temperature != -9999) {
            records[row][col] = WeatherRecord();
            cout << "Record deleted successfully!\n";
        } else {
            cout << "Record not found!\n";
        }
    }

    void retrieveWeatherRecord() {
        string city, year;
        cin.ignore();
        cout << "Enter city: ";
        getline(cin, city);
        cout << "Enter year: ";
        cin >> year;

        int row = getYearIndex(year);
        int col = getCityIndex(city);

        if(row >= 0 && col >= 0 && records[row][col].temperature != -9999) {
            cout << "Date: " << records[row][col].date
                 << ", City: " << records[row][col].city
                 << ", Temperature: " << records[row][col].temperature << "°C\n";
        } else {
            cout << "No record found.\n";
        }
    }

    // --- 2D Array Methods ---
    void insertTemperature() {
        string year, city, date;
        double temp;
        cin.ignore();
        cout << "Enter year: ";
        getline(cin, year);
        cout << "Enter city: ";
        getline(cin, city);
        cout << "Enter date (DD/MM/YYYY): ";
        getline(cin, date);
        cout << "Enter temperature: ";
        cin >> temp;

        int row = getYearIndex(year);
        int col = getCityIndex(city);

        if(row >= 0 && col >= 0) {
            records[row][col] = WeatherRecord(date, city, temp);
            cout << "Temperature inserted successfully!\n";
        } else {
            cout << "Invalid year or city!\n";
        }
    }

    void rowMajorAccess() {
        cout << "\nRow-Major Access:\n";
        for(int i = 0; i < numYears; i++)
            for(int j = 0; j < numCities; j++)
                if(records[i][j].temperature != -9999)
                    cout << records[i][j].date << " - "
                         << records[i][j].city << " : "
                         << records[i][j].temperature << "°C\n";
    }

    void columnMajorAccess() {
        cout << "\nColumn-Major Access:\n";
        for(int j = 0; j < numCities; j++)
            for(int i = 0; i < numYears; i++)
                if(records[i][j].temperature != -9999)
                    cout << records[i][j].date << " - "
                         << records[i][j].city << " : "
                         << records[i][j].temperature << "°C\n";
    }

    void handleSparseData() {
        cout << "\nSparse Data (Missing Records):\n";
        for(int i = 0; i < numYears; i++)
            for(int j = 0; j < numCities; j++)
                if(records[i][j].temperature == -9999)
                    cout << "Year: " << years[i] << ", City: " << cityNames[j] << " -> Missing Data\n";
    }

    void complexityAnalysis() {
    cout << "\n--- Complexity Analysis ---\n";

    // Theoretical complexities
    cout << "Time Complexity (Theoretical):\n";
    cout << " Insert/Delete/Retrieve: O(1)\n";
    cout << " Row/Column Traversal: O(years * cities)\n";

    cout << "Space Complexity (Theoretical):\n";
    cout << " Array Storage: O(years * cities)\n";

    // Actual values
    cout << "\nTime Complexity (Actual Values):\n";
    cout << " Insert/Delete/Retrieve: Constant time = 1 step\n";
    cout << " Row/Column Traversal: O(" << numYears << " * " << numCities 
         << ") = " << numYears * numCities << " steps\n";

    cout << "\nSpace Complexity (Actual Values):\n";
    cout << " Array size = " << numYears << " * " << numCities 
         << " = " << numYears * numCities << " cells\n";
}
};

// --- Main Program ---
int main() {
    WeatherDataSystem system;
    system.setup();

    int choice;
    do {
        cout << "\n--- Weather Data System Menu ---\n";
        cout << "1. Insert Weather Record (ADT)\n";
        cout << "2. Delete Weather Record (ADT)\n";
        cout << "3. Retrieve Weather Record (ADT)\n";
        cout << "4. Insert Temperature (2D Array)\n";
        cout << "5. Row Major Access\n";
        cout << "6. Column Major Access\n";
        cout << "7. Handle Sparse Data\n";
        cout << "8. Complexity Analysis\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: system.insertWeatherRecord(); break;
            case 2: system.deleteWeatherRecord(); break;
            case 3: system.retrieveWeatherRecord(); break;
            case 4: system.insertTemperature(); break;
            case 5: system.rowMajorAccess(); break;
            case 6: system.columnMajorAccess(); break;
            case 7: system.handleSparseData(); break;
            case 8: system.complexityAnalysis(); break;
            case 0: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 0);

    return 0;
}