// AdventOfCode2023.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

#include <vector>
#include <string>
#include <numeric>
#include <random>
#include <sstream>
#include <chrono>
#include <regex>
#include <tuple>
#include <variant>
#include <map>


//#include "Day1.h"
//#include "Day2.h"
//#include "Day3.h"
//#include "Day4.h"
//#include "Day5.h"
//#include "Day6.h"
//#include "Day7.h"
#include "Day8.h"

static bool isInt(const char& c) {
    return c >= '0' && c <= '9';
}

// TODO : make the vector generic to take modify any vector type
static void stringToVec(const std::string& str, std::vector<long long>& vec) {
    std::string s;
    std::stringstream ss(str);
    while (std::getline(ss, s, ' ')) {
        if(!s.empty())
            vec.emplace_back(std::stoi(s));
    }
}

//


int main()
{
    Day8 day8;
    std::ifstream myfile; 
    
    std::string myLine, s;
    myfile.open("Day8Test.txt");
    long long val, j, pos = 0, sum = 0;
    std::map<std::string, std::pair<std::string, std::string> > map;
    std::vector < std::tuple<std::string, int, int> > start;
    std::tuple<std::string, int, int> curr;
    //std::string inst = "LRRRLRRLLLRRRLRLRRLRRRLRLRRRLLLRRLRRLRRRLRRRLRLLRLRRLRRLLRRLRLRRRLRRLRRLRRLLRRRLRLRLRLRLLRRLLLRRLRLRRLRLLLLRRLRRRLRRLRRRLLRRRLRRLRRRLRLLRLRRLRRLLRRRLLLRLRRRLLLRRLLRRRLLRRLRRLRRLRLRRRLLRRRLRLLRLRRLLRLRRLRLLRLRRLRRRLLRRLLRRRLRRLRLRLRRRLRLRRRLRRRLRRLRRRLRLLRRRLLRRRR";
    std::string inst = "LR";
    std::string key;
    std::pair<std::string, std::string> value;
     if (myfile.is_open()) { 
         while (std::getline(myfile, myLine))
         {
             key = myLine.substr(0, myLine.find(' '));
             if (key[2] == 'A') {
                 std::get<0>(curr) = key;
                 start.emplace_back(curr);

             }
            int valLeft = myLine.find('('), valRight = myLine.find(',');
            std::string left = myLine.substr(valLeft+1, 3), right = myLine.substr(valRight+2, 3);
            value = { left, right };
            map.insert(std::pair<std::string, std::pair<std::string, std::string>>(key, value));
        }
    }
    sum += day8.SumNumberInstructionsP2(inst, start, map);
    std::cout << "SUM = " << sum << "\n";
}

//void day7() {
//    Day7 day7;
//    std::ifstream myfile;
//
//    std::string myLine, s;
//    myfile.open("Day7Test.txt");
//    long long val, j, pos = 0, sum = 0;
//    std::vector < std::tuple < std::string, int, int> > handBetValueScore;
//    if (myfile.is_open()) {
//        while (std::getline(myfile, myLine))
//        {
//            std::tuple < std::string, int, int> curr;// = { std::string(), int(), int() };
//            std::stringstream ss(myLine);
//            pos = 0;
//            while (std::getline(ss, s, ' ')) {
//                if (!s.empty()) {
//                    switch (pos) {
//                    case 0: {std::get<0>(curr) = s; break; }
//                    case 1: {std::get<1>(curr) = std::stoi(s); break; }
//                    default: {std::cout << "oops ...\n"; break; }
//                    }
//                }
//                pos++;
//            }
//            handBetValueScore.push_back(curr);
//        }
//    }
//    sum += day7.SumBets(handBetValueScore);
//    std::cout << "SUM = " << sum << "\n";
//}

//void day6() {
//    Day6 day6;
//    std::ifstream myfile;
//    std::string myLine, s;
//    myfile.open("Day6Test.txt");
//    unsigned long val, j, pos = 0, sum = 0;
//
//    // part 1
//    //std::vector<long long> time;
//    //std::vector<long long> dist;
//
//    // check if file is open
//    // if (myfile.is_open()) { 
//    //    while (std::getline(myfile, myLine))
//    //    {
//    //        std::string sub;
//    //        if (myLine.find("Time") != -1) {
//    //            sub = myLine.substr(myLine.find(":") + 1);
//    //            //  removes leading white space
//    //            sub = std::regex_replace(sub, std::regex("^ +"), "");
//    //            stringToVec(sub, time);
//    //            
//    //        }
//    //        else if (myLine.find("Distance") != -1) {
//    //            sub = myLine.substr(myLine.find(":") + 1);
//    //            // removes leading white space
//    //            sub = std::regex_replace(sub, std::regex("^ +"), "");
//    //            stringToVec(sub, dist);
//    //        }
//
//
//    //    }
//    //}
//
//    // part 2
//    long long time = 56977875;
//    long long dist = 546192711311139;
//    sum += day6.TotalAmountOfTimeBeatRecord(time, dist);
//    std::cout << sum;
//}

//void day5() {
//    Day5 day5;
//    std::ifstream myfile;
//    std::string myLine, s;
//    myfile.open("Day5Test.txt");
//    unsigned long val, j, pos = 0, sum = 0;
//    std::vector< std::vector< std::vector<long long> > > maps;
//    std::vector< std::vector<long long> > currMap;
//    std::vector<long long> currLine;
//
//    // check if file is open
//    if (myfile.is_open()) {
//        while (std::getline(myfile, myLine))
//        {
//            pos++;
//            if (myLine.empty()) {
//                maps.push_back(currMap);
//                currMap = {};
//            }
//            else if (isInt(myLine[0])) {
//                std::string num = " ";
//                myLine += " ";
//                for (const auto& c : myLine) {
//                    if (isInt(c))
//                        num += c;
//                    if (c == ' ') {
//                        currLine.emplace_back(std::stoll(num));
//                        num = "";
//                    }
//                }
//                currMap.push_back(currLine);
//                currLine = {};
//            }
//        }
//        if (!currMap.empty())
//            maps.push_back(currMap);
//    }
//    sum += day5.LowestLocation(maps, true);
//    std::cout << sum;
//}

//void day4() {
//    Day4 day4;
//    std::ifstream myfile;
//    std::string myLine;
//    myfile.open("Day4Test.txt");
//    unsigned long val, j, pos, sum = 0;
//    std::vector<std::string> cards;
//    // check if file is open
//    if (myfile.is_open()) {
//        while (std::getline(myfile, myLine))
//        {
//            // sum += day4.scratchOff(myline);
//            cards.emplace_back(myLine);
//        }
//    }
//    sum += day4.pileOfScratchOff(cards);
//    std::cout << sum;
//}

//void day3(){
//    Day3 day3;
//    std::ifstream myfile;
//    std::string myline;
//    myfile.open("Day3Test.txt");
//    std::vector<std::string> field;
//    unsigned long val, j, pos, sum = 0;
//    if (myfile.is_open()) { // always check whether the file is open
//        while (std::getline(myfile, myline))
//        {
//            field.emplace_back(myline);
//        }
//    }
//    sum = day3.sumGearRatio(field);
//    std::cout << sum;
//}

//void day2(){
//    Day2 day2;
//    std::ifstream myfile;
//    std::string myline;
//    myfile.open("Day2Test.txt");
//    unsigned val, j, pos, sum = 0;
//    if (myfile.is_open()) { // always check whether the file is open
//        while (std::getline(myfile, myline))
//        {
//
//            // Part 2
//            day2 = Day2();
//            sum += day2.powerFromGame(myline);
//
//            // Part 1
//            //pos = myline.find(":");
//            //j = pos - 1;
//            //for (; j >= 0 && isInt(myline[j]); j--);
//            //val = std::stoi(myline.substr(j + 1, pos - 1 - j));
//            //sum += val  * day2.isValidGame(myline);
//        }
//    }
//    std::cout << sum;
//}

//void day1() {
//
//    Day1 day1;
//    std::ifstream myfile;
//    std::string myline;
//    myfile.open("Day1Test.txt");
//    unsigned sum = 0;
//    if (myfile.is_open()) { // always check whether the file is open
//        while (std::getline(myfile, myline)) {
//
//            sum += day1.findNumsInstring(myline);
//        }
//    }
//    std::cout << sum;
//}
