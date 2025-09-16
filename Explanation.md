# *Weather Data System*

## *Introduction*  
This project is a *Weather Data Management System* built in C++.  
It stores temperature records for different cities across multiple years using an *Abstract Data Type (ADT)* and a *2D array structure*.  
The system supports operations like inserting, deleting, and retrieving records, handling sparse data, and performing row/column traversals along with complexity analysis.  

---

## *WeatherRecord (ADT)*  
The WeatherRecord structure represents a single weather entry.  

- *date* → stores the date in DD/MM/YYYY format  
- *city* → stores the city name  
- *temperature* → stores the recorded temperature in °C  

If no record exists, the *temperature = -9999* (sentinel value for missing data).  

---

## *WeatherDataSystem (Class)*  
The WeatherDataSystem class manages the entire dataset.  

*Private Members:*  
- *numYears, numCities* → number of years and cities  
- *years[]* → stores year values (e.g., "2023", "2024")  
- *cityNames[]* → stores city names  
- *records[][]* → 2D array (vector of vectors) where each cell holds a WeatherRecord  

*Helper Functions:*  
- *getYearIndex(year)* → returns index of the given year  
- *getCityIndex(city)* → returns index of the given city  

---

## *Functionalities Provided*  

1. *Insert Weather Record (ADT):* Insert record by date, city, and temperature.  
2. *Delete Weather Record (ADT):* Delete a record for a given date and city.  
3. *Retrieve Weather Record (ADT):* Retrieve weather details for a given city and year.  
4. *Insert Temperature (2D Array):* Insert data using direct year and city input.  
5. *Row-Major Traversal:* Display all records year by year.  
6. *Column-Major Traversal:* Display all records city by city.  
7. *Handle Sparse Data:* Show missing records (temperature = -9999).  
8. *Complexity Analysis:* Display theoretical and actual *time/space complexities*.  

---

## *Complexity Summary*  

- *Time Complexity:*  
  - Insert/Delete/Retrieve = *O(1)*  
  - Row/Column Traversal = *O(years × cities)*  

- *Space Complexity:*  
  - Array size = *(years × cities) cells*  

---

## *How to Run*  

1. *Compile the program*  
   ```bash
   g++ weather_system.cpp -o weather_system
