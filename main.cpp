#include <iostream>
#include <tuple>
#include <vector>
#include <chrono>
#include <fstream>
#include <sstream>
#include "shellsort.h"
#include "heapsort.h"
using namespace std;
using namespace chrono;

tuple<string,string,string> menuStartUp(){
    string option;
    string range;
    string songRange;

    cout << "Welcome to our silly little program!" << endl;
    cout << endl;
    cout << "****************************************" << endl;
    cout << "Pick what description you'd like to sort by (Type Number)" << endl;
    cout << "   1) Danceability" << endl;
    cout << "   2) Energy" << endl;
    cout << "   3) Etc." << endl;

    cin >> option;

    cout << "What order would you like it in? (Type Number)" << endl;
    cout << "   1) Ascending" << endl;
    cout << "   2) Descending" << endl;

    cin >> range;

    cout << "How many songs would you like to be shown after sorting? (Type Number (1-352000))" << endl;

    cin >> songRange;

    if (stoi(songRange) > 352000 || stoi(songRange) < 1) {
        cout << "Invalid input, terminating" << endl;
        exit(0);
    }

    cout << endl;


    if(option == "1"){
        option = "Danceability";
    }
    else if(option == "2"){
        option = "Energy";
    }
    else if(option == "3"){
        option = "Etc.";
    }

    if(range == "1"){
        range = "Ascending";
    }else if(range == "2"){
        range = "Descending";
    }

    return make_tuple(option,range,songRange);
}

void fileRead(vector<tupInfo> &data){
    string info;
    ifstream fileRead("../scrubbed dat (version 1).xlsb.csv");
    int cnt = 0;
    if (fileRead.is_open())
    {
        while(getline(fileRead, info)){
            istringstream inStream(info);
            string id, name, album, album_id, artists, artist_ids, track_number, disc_number, explit, danceability,
                    energy, key, loudness, mode, speechiness, acousticness, instrumentalness, liveness, valence, tempo, duration_ms,
                    time_signature, year, release_date;
            getline(inStream, id, ','); // get<0>
            getline(inStream, name, ','); // get<1>
            getline(inStream, album, ','); // get<2>
            getline(inStream, album_id, ','); // get<3>
            getline(inStream, artists, ','); // get<4>
            getline(inStream, artist_ids, ','); // get<5>
            getline(inStream, track_number, ','); // get<6>
            getline(inStream, disc_number, ','); // get<7>
            getline(inStream, explit, ','); // get<8>
            getline(inStream, danceability, ','); // get<9>
            size_t find = danceability.find("E");
            if(find != string::npos){
                danceability = "0";
            }
            getline(inStream, energy, ','); // get<10>
            find = energy.find("E");
            if(find != string::npos){
                energy = "0";
            }
            getline(inStream, key, ','); // get<11>
            getline(inStream, loudness, ','); // get<12>
            getline(inStream, mode, ','); // get<13>
            getline(inStream, speechiness, ','); // get<14>
            getline(inStream, acousticness, ','); // get<15>
            find = acousticness.find("E");
            if(find != string::npos){
                acousticness = "0";
            }
            getline(inStream, instrumentalness, ','); // get<16>
            find = instrumentalness.find("E");
            if(find != string::npos){
                instrumentalness = "0";
            }
            getline(inStream, liveness, ','); // get<17>
            getline(inStream, valence, ','); // get<18>
            getline(inStream, tempo, ','); // get<19>
            getline(inStream, duration_ms, ','); // get<20>
            getline(inStream, time_signature, ','); // get<21>
            getline(inStream, year, ','); // get<22>
            getline(inStream, release_date); // get<23>

            tupInfo tup = make_tuple(id, name, album, album_id, artists, artist_ids, track_number, disc_number, explit, danceability,
                                     energy, key, loudness, mode, speechiness, acousticness, instrumentalness, liveness, valence, tempo, duration_ms,
                                     time_signature, year, release_date);

            if(get<1>(tup) == "" && get<2>(tup) == ""){
                break;
            }
            data.push_back(tup);
        }
    }
    else
    {
        cout << "Could not open file " << endl;
    }
}

int main() {
    /* Time Finding Code
    auto start = system_clock::now();
     // put code to run timer with here
    auto end = system_clock::now();
    auto elapsed = duration_cast<seconds>(end - start);
    cout << elapsed.count() << endl;
    */

    // vector that has a tuple containing every single data variable for each data point in our set.
    vector<tupInfo> dataInfo;
    // this reads the file and updates our vector to now hold all 300k+ data points
    fileRead(dataInfo);

    string userInput,userSorting,userRange;

    // determines the variable we must sort by, through user input
    tuple<string,string,string> userPairing = menuStartUp();
    userInput = get<0>(userPairing);
    userSorting = get<1>(userPairing);
    userRange = get<2>(userPairing);

    int choiceNum;

    if(userInput == "Danceability"){
        choiceNum = 9;
    }else if(userInput == "Energy"){
        choiceNum = 10;
    }

    auto shellCopy = dataInfo;
    auto heapCopy = dataInfo;
    ShellSorting(shellCopy, choiceNum);
    heapSort(heapCopy,  choiceNum);
    if(choiceNum == 9) {
        if (userSorting == "Ascending") {
            for (int i = 1; i < stoi(userRange); i++) {
                cout << i << ". " << get<1>(dataInfo[i]) << " " << get<9>(dataInfo[i]) << endl;
            }
        } else if (userSorting == "Descending") {
            int counter = 1;
            for (int i = dataInfo.size() - 5; i > dataInfo.size() - (stoi(userRange) + 5); i--) {
                cout << counter << ". " << get<1>(dataInfo[i]) << " " << get<9>(dataInfo[i]) << endl;
                counter += 1;
            }
        }
    }else if(choiceNum == 10){
        if (userSorting == "Ascending") {
            for (int i = 1; i < stoi(userRange); i++) {
                cout << i << ". " << get<1>(dataInfo[i]) << " " << get<10>(dataInfo[i]) << endl;
            }
        } else if (userSorting == "Descending") {
            int counter = 1;
            for (int i = dataInfo.size() - 5; i > dataInfo.size() - (stoi(userRange) + 5); i--) {
                cout << counter << ". " << get<1>(dataInfo[i]) << " " << get<10>(dataInfo[i]) << endl;
                counter += 1;
            }
        }
    }

    return 0;
}

