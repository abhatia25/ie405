#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    const int numQuestions = 20;
    char correctAnswers[numQuestions];
    char studentAnswers[numQuestions];
    
    ifstream correctAnswersFile("CorrectAnswers.txt");
    for (int i = 0; i < numQuestions; ++i) {
        correctAnswersFile >> correctAnswers[i];
    }
    correctAnswersFile.close();

    ifstream studentAnswersFile("StudentAnswers.txt");
    for (int i = 0; i < numQuestions; ++i) {
        studentAnswersFile >> studentAnswers[i];
    }
    studentAnswersFile.close();

    int numCorrect = 0;
    for (int i = 0; i < numQuestions; ++i) {
        if (studentAnswers[i] == correctAnswers[i]) {
            numCorrect++;
        }
    }

    double percentage = static_cast<double>(numCorrect) / numQuestions * 100;

    cout << "Total number of questions answered correctly: " << numCorrect << endl;
    cout << "Percentage of questions answered correctly: " << percentage << "%" << endl;

    if (percentage >= 75.0) {
        cout << "The student passed the exam." << endl;
    } else {
        cout << "The student failed the exam." << endl;
    }

    return 0;
}
