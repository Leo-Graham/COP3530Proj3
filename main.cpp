#include <iostream>
#include <tuple>
#include <vector>
#include <chrono>
#include <fstream>
#include <sstream>
using namespace std;
using namespace chrono;

string menuStartUp(){
    string option;
    string range;

    cout << "Welcome to our silly little program!" << endl;
    cout << endl;
    cout << "****************************************" << endl;
    cout << "Pick what description you'd like to sort by (Type Number)" << endl;
    cout << "   1) Danceability" << endl;
    cout << "   2) Energy" << endl;
    cout << "   3) Etc." << endl;

    cin >> option;

    if(option == "1"){
        option = "Danceability";
    }
    else if(option == "2"){
        option = "Energy";
    }
    else if(option == "3"){
        option = "Etc.";
    }

    return option;
}

void fileRead(vector<tuple<string,string,string,string,string,string,string,string,string,string,string,string,
        string,string,string,string,string,string,string,string,string,string,string,string>> &data){
    string info;
    ifstream fileRead("../scrubbed dat.csv");
    int cnt = 0;
    if (fileRead.is_open())
    {
        while(getline(fileRead, info)){
            istringstream inStream(info);
            string id, name, album, album_id, artists, artist_ids, track_number, disc_number, explit, danceability,
                    energy, key, loudness, mode, speechiness, acousticness, instrumentalness, liveness, valence, tempo, duration_ms,
                    time_signature, year, release_date;
            getline(inStream, id, ',');
            getline(inStream, name, ',');
            getline(inStream, album, ',');
            getline(inStream, album_id, ',');
            getline(inStream, artists, ',');
            getline(inStream, artist_ids, ',');
            getline(inStream, track_number, ',');
            getline(inStream, disc_number, ',');
            getline(inStream, explit, ',');
            getline(inStream, danceability, ',');
            getline(inStream, energy, ',');
            getline(inStream, key, ',');
            getline(inStream, loudness, ',');
            getline(inStream, mode, ',');
            getline(inStream, speechiness, ',');
            getline(inStream, acousticness, ',');
            getline(inStream, instrumentalness, ',');
            getline(inStream, liveness, ',');
            getline(inStream, valence, ',');
            getline(inStream, tempo, ',');
            getline(inStream, duration_ms, ',');
            getline(inStream, time_signature, ',');
            getline(inStream, year, ',');
            getline(inStream, release_date);

            tuple<string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,string,
                    string,string,string,string,string,string> tup = make_tuple(id, name, album, album_id, artists, artist_ids, track_number, disc_number, explit, danceability,
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
    vector<tuple<string,string,string,string,string,string,string,string,string,string,string,string,
            string,string,string,string,string,string,string,string,string,string,string,string>> dataInfo;
    // this reads the file and updates our vector to now hold all 300k+ data points
    fileRead(dataInfo);

    string userInput;
    // determines the variable we must sort by, through user input
    userInput = menuStartUp();

    for(int i = 1; i < 11; i++){
        cout << i << ". " << get<1>(dataInfo[i]) << endl;
    }

    return 0;
}
