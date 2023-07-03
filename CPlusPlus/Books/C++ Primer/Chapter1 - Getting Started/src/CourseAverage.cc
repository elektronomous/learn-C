//////////////////////////////////////////////////////////////
// From JAVA PROGRAMMING: FROM THE BEGINNING, by K. N. King //
// Copyright (c) 2000 W. W. Norton & Company, Inc.          //
// All rights reserved.                                     //
// This program may be freely distributed for class use,    //
// provided that this copyright notice is retained.         //
//                                                          //
// CourseAverage.cc (Chapter 2, page 65)                    //
//////////////////////////////////////////////////////////////

// Program name: CourseAverage
// Author: Muhammad Faza Akbar
// Written: 1998-04-05
// Modified: 2023-08-01
//
// Prompts the user to enter eight program scores (0-20), five
// quiz scores (0-10), two test scores (0-100), and a final
// exam score (0-100). Scores may contain digits after the
// decimal point. Input is not checked for validity. Displays
// the course average, computed using the following formula:
//
//   Programs    30%
//   Quizzes     10%
//   Test 1      15%
//   Test 2      15%
//   Final exam  30%
//
// The course average is rounded to the nearest integer.

#include <iostream>
#include <cmath>        // for using the round function

int main(void) {
    std::cout << "Welcome to the CSc 2310 average " 
              << "calculation program" 
              << std::endl;
    
    double program1 = 0,
        program2 = 0,
        program3 = 0,
        program4 = 0,
        program5 = 0,
        program6 = 0,
        program7 = 0,
        program8 = 0,
        programAverage = 0;

    // prompt user to enter the value for each given program
    std::cout << "Enter Program 1 score: ";
    std::cin >> program1;

    std::cout << "Enter Program 2 score: ";
    std::cin >> program2;

    std::cout << "Enter Program 3 score: ";
    std::cin >> program3;

    std::cout << "Enter Program 4 score: ";
    std::cin >> program4;

    std::cout << "Enter Program 5 score: ";
    std::cin >> program5;

    std::cout << "Enter Program 6 score: ";
    std::cin >> program6;

    std::cout << "Enter Program 7 score: ";
    std::cin >> program7;

    std::cout << "Enter Program 8 score: ";
    std::cin >> program8;

    programAverage = (
        program1 + program2 + 
        program3 + program4 + 
        program5 + program6 + 
        program7 + program8
    ) / 8;

    // prompt user to enter the value for each given quiz
    double quiz1 = 0,
        quiz2 = 0,
        quiz3 = 0,
        quiz4 = 0,
        quiz5 = 0,
        quizAverage = 0;
    
    std::cout << "Enter Quiz 1 score: ";
    std::cin >> quiz1;

    std::cout << "Enter Quiz 2 score: ";
    std::cin >> quiz2;

    std::cout << "Enter Quiz 3 score: ";
    std::cin >> quiz3;

    std::cout << "Enter Quiz 4 score: ";
    std::cin >> quiz4;

    std::cout << "Enter Quiz 5 score: ";
    std::cin >> quiz5;

    quizAverage = (
        quiz1 + quiz2 +
        quiz3 + quiz4 +
        quiz5
    ) / 5;

    double test1 = 0,
        test2 = 0,
        finalExam = 0;
    
    // prompt user to enter the value for each given test
    std::cout << "Enter Test 1 score: ";
    std::cin >> test1;

    std::cout << "Enter Test 2 score: ";
    std::cin >> test2;

    // prompt user to enter the value for the final exam
    std::cout << "Enter Final Exam score: ";
    std::cin >> finalExam;

    // Compute the course average from the program average,
    // quiz average, test scores and final exam score.
    // The program average (0-20) is multplied by 5 to put
    // it on a scale of 0 to 100. The quiz average (0-10) is
    // multiplied by 10 for the same reason.
    double courseAverage = .30 * programAverage * 5 +
                           .10 * quizAverage * 10 +
                           .15 * test1 +
                           .15 * test2 +
                           .30 * finalExam;

    // Round the course average to the nearest integer and
    // display it
    std::cout << std::endl << "Course average: " << round(courseAverage) << std::endl;

    return 0;   
}