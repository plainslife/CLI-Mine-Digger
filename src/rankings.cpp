/*
 * Code Mine Digger
 * MP2 and MP3: Application of Bubble, Insertion and Selection Sort
 * Class: BSCpE - 2A
 * Members:
 *     Matt Rohan Alagaban
 *     Hoechst Mostaza
 *     Paul Owen Belga
 *     Gian Tandog
 *     Robert Beralde
*/

// ketsup@asura
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iomanip>
#include "rankings.h"

// Leaderboard -> class
// initializer
Leaderboard::Leaderboard(const std::string& filename) 
: filename(filename) {}

void Leaderboard::selectionSort(std::vector<LeaderboardEntry>& leaderboard) {
    for (int i = 0 ; i < leaderboard.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < leaderboard.size(); j++) {
            if (leaderboard[min].score < leaderboard[j].score) {
                min = j;
            }
        }

        LeaderboardEntry temp = leaderboard[i];
        leaderboard[i] = leaderboard[min];
        leaderboard[min] = temp;
    }
}

void Leaderboard::bubbleSort(std::vector<LeaderboardEntry>& leaderboard) {
    for (int i = 0; i < leaderboard.size() - 1; i++) {
        for (int j = 0; j < leaderboard.size() - i - 1; j++) {
            if(leaderboard[j].score > leaderboard[j+1].score) {
                LeaderboardEntry temp = leaderboard[j];
                leaderboard[j] = leaderboard[j+1];
                leaderboard[j+1] = temp;
            }
        }
    }
}

void Leaderboard::insertionSort(std::vector<LeaderboardEntry>& leaderboard) {
    for (int i = 1; i < leaderboard.size(); i++) {
        LeaderboardEntry temp = leaderboard[i];
        int j = i - 1;

        while (j >= 0 && leaderboard[j].score > temp.score) {
            leaderboard[j+1] = leaderboard[j];
            j--;
        }
        leaderboard[j + 1] = temp;
    }
}


// format to print the leaderboard of difficulty levels  game
void Leaderboard::printDifficultyLevels() {
    std::cout << "\t+--------------+-------------------------+--------------------+\n";
    std::cout << std::right << std::setw(12) << "\t|     Rank     |";
    std::cout << std::right << std::setw(12) << "       Player Name       |";
    std::cout << std::right << std::setw(12) <<  "        Time        |\n";
    std::cout << "\t+--------------+-------------------------+--------------------+\n";

    int rank = 1;
    for (const LeaderboardEntry& entry : leaderboard) {
        std::string hours = std::to_string(entry.score / 3600);
        std::string minutes = std::to_string((entry.score % 3600) / 60);
        std::string seconds = std::to_string(entry.score % 60);
        std::string gameTime = hours + ":" + minutes + ":" + seconds;

        // Display the sorted leaderboard
        std::cout << "\t|      " << rank << "       |";  
        std::cout << "  " <<  std::left << std::setw(12) << entry.player_name << "           |";
        std::cout << "  "<< std::left << std::setw(12)  << gameTime << "      |\n";
        std::cout << "\t+--------------+-------------------------+--------------------+\n";

        //std::cout << rank << ". Name: " << entry.player_name << ", Completion Time: " << gameTime << "\n";
        rank++;
    }
}

// format to print the leaderboard of infinite roulette game
void Leaderboard::printInfiteRoulette() {
    std::cout << "\t+--------------+-------------------------+--------------------+\n";
    std::cout << std::right << std::setw(12) << "\t|     Rank     |";
    std::cout << std::right << std::setw(12) << "       Player Name       |";
    std::cout << std::right << std::setw(12) <<  "     Win Streak     |\n";
    std::cout << "\t+--------------+-------------------------+--------------------+\n";

    int rank = 1;
    for (const LeaderboardEntry& entry : leaderboard) {
        std::cout << "\t|      " << rank << "       |";  
        std::cout << "  " <<  std::left << std::setw(12) << entry.player_name << "           |";
        std::cout << "  "<< std::left << std::setw(12)  << entry.score << "      |\n";
        std::cout << "\t+--------------+-------------------------+--------------------+\n";

        rank++;
    }
}

bool Leaderboard::isFileExistAndNotEmpty() {
    bool isFileValid = true;
    std::string path = "data/" + filename;

    std::fstream fhand(path, std::ios::in);

    // does the file exist
    if (!fhand.is_open()) { isFileValid = false; }

    // is the file empty
    if (fhand.peek() == std::ifstream::traits_type::eof()) { isFileValid = false; }

    fhand.close();
    return isFileValid;
}

void Leaderboard::readLeaderboardFromFile() {
    // clears the leader board before putting the data in the vector
    leaderboard.clear();

    // open the file in read mode
    std::fstream fhand;
    std::string path = "data/" + filename;
    fhand.open(path, std::ios::in);

    // since the format of data is (name time)
    LeaderboardEntry entry;
    
    // until there is data from the file continue putting it in the vector
    // first it will put the data from the fhand to the entry.player_name until it encounter ','
    // and put the remaining data which is the score of the  player in the entry.score
    while (std::getline(fhand, entry.player_name, ',') && fhand >> entry.score) {
        fhand.ignore(); // ignore's the newline character, eof of line
        leaderboard.push_back(entry);
    }
    fhand.close();

}


void Leaderboard::appendDataToFile(const std::string& name, int score) {
    std::string dataToAppend = name + "," + std::to_string(score);

    // open the file in append mode
    std::fstream fhand;
    std::string path = "data/" + filename;
    fhand.open(path, std::ios::app);

    fhand << dataToAppend;
    fhand.close();
    
}

// this will overwrite the contents of the File
// the sorted one will be the one it will contain
void Leaderboard::writeLeaderboardToFile() {

    // open the file in write mode
    std::fstream fhand;
    std::string path = "data/" + filename;
    fhand.open(path, std::ios::out);

    std::string dataToWrite;
    for (const LeaderboardEntry& entry : leaderboard) {
        dataToWrite = entry.player_name + "," + std::to_string(entry.score) + "\n";
        fhand << dataToWrite;
    }
    fhand.close();
}

void Leaderboard::displayLeaderboard() {

     if (isFileExistAndNotEmpty()) {
        readLeaderboardFromFile();
        writeLeaderboardToFile();
    } else {
        std::cout << "The Leaderboard is empty!\n\n\n";
        system("pause");
        return;
    }

    // sort according to what the game leaderboard needs
    if (filename == "easyLeaderboard.txt") {
        bubbleSort(leaderboard);
    } else if (filename == "mediumLeaderboard.txt") {
        bubbleSort(leaderboard);
    } else if (filename == "hardLeaderboard.txt") {
        insertionSort(leaderboard);
    } else {
        selectionSort(leaderboard);
    }


    // filter
    // Remove duplicates based on player_name, the second occurence will be the one to be deleted
    leaderboard.erase(std::unique(leaderboard.begin(), leaderboard.end(),
        [](const LeaderboardEntry& a, const LeaderboardEntry& b) {
            return a.player_name == b.player_name;
        }), leaderboard.end());


    if (filename == "easyLeaderboard.txt" || filename == "mediumLeaderboard.txt" || filename == "hardLeaderboard.txt") {
        printDifficultyLevels();
    }

    if (filename == "infinite.txt") {
        printInfiteRoulette();
    }

    std::cout << "\n\n";
    system("pause");
}


