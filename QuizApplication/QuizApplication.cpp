#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Question {
    string questionText;
    string option[3];
    int ans;
};

void PrintQuestion(Question question) {
    cout << question.questionText << endl;
    for(int i = 0; i < 3; ++i) {
        cout << i+1 << ". " << question.option[i] << endl;
    }
}

void IsCorrectAnswer(Question question) {
    cout << "Choose 1-3 : ";
    int userAns;
    cin >> userAns;

    if(userAns == question.ans) {
        cout << "Correct !" << endl;
    }
    else if(userAns <=3 && userAns >=1) {
        cout << "Incorrect." << endl;
    }
    else {
        cout << "Invalid answer. Please try again." << endl;
        cout << endl;
        IsCorrectAnswer(question);
    }
    cout << endl;
}

int main() {
    
    Question Q1;
    Q1.questionText = "What is the biggest animal in the world ?"; 
    Q1.option[0] = "Elephant";
    Q1.option[1] = "Blue whale";
    Q1.option[2] = "Great white shark";
    Q1.ans = 2;

    Question Q2;
    Q2.questionText = "49 % 5 - 4! / 6 = ?"; 
    Q2.option[0] = "0";
    Q2.option[1] = "4";
    Q2.option[2] = "5";
    Q2.ans = 1;

    Question Q3;
    Q3.questionText = "How many elements are there in the periodic table of element ?"; 
    Q3.option[0] = "117 elements";
    Q3.option[1] = "118 elements";
    Q3.option[2] = "119 elements";
    Q3.ans = 2;

    Question Q4;
    Q4.questionText = "Where is Bali ?"; 
    Q4.option[0] = "Malaysia";
    Q4.option[1] = "Venezuela";
    Q4.option[2] = "Indonesia";
    Q4.ans = 3;

    Question Q5;
    Q5.questionText = "What is the hottest planet in the Solar System?"; 
    Q5.option[0] = "Mercury";
    Q5.option[1] = "Venus";
    Q5.option[2] = "Mars";
    Q5.ans = 2;

    Question questionList[5] = {Q1,Q2,Q3,Q4,Q5};
    for(int i = 0; i < 5; ++i) {
        PrintQuestion(questionList[i]);
        IsCorrectAnswer(questionList[i]);
    }
    
    return 0;
}
