#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Question {
public:
    string questionText;
    vector<string> options;
    int correctAnswerIndex;

    Question(string qText, vector<string> opts, int correctIndex) {
        questionText = qText;
        options = opts;
        correctAnswerIndex = correctIndex;
    }

    bool checkAnswer(int answerIndex) {
        return answerIndex == correctAnswerIndex;
    }
};

int main() {
    // Define some sample questions
    vector<Question> quiz = {
        Question("What is the capital of France?", {"1. Berlin", "2. Madrid", "3. Paris", "4. Rome"}, 3),
        Question("What is the largest planet in our solar system?", {"1. Earth", "2. Mars", "3. Jupiter", "4. Saturn"}, 3),
        Question("Who wrote '1984'?", {"1. George Orwell", "2. J.K. Rowling", "3. Ernest Hemingway", "4. Mark Twain"}, 1),
        Question("What is the chemical symbol for water?", {"1. H2O", "2. O2", "3. CO2", "4. H2"}, 1),
        Question("What is the smallest prime number?", {"1. 1", "2. 2", "3. 3", "4. 0"}, 2)
    };

    int score = 0;
    int answer;
    int totalQuestions = quiz.size();

    cout << "Welcome to the Quiz Application!" << endl;

    // Loop through each question
    for (int i = 0; i < totalQuestions; i++) {
        cout << "\nQuestion " << i + 1 << ": " << quiz[i].questionText << endl;
        
        // Display the options
        for (const auto& option : quiz[i].options) {
            cout << option << endl;
        }

        // Get user's answer
        cout << "Please enter the number of your answer: ";
        cin >> answer;

        // Check if the answer is correct
        if (quiz[i].checkAnswer(answer)) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Incorrect!" << endl;
        }
    }

    // Display the score
    cout << "\nYou scored " << score << " out of " << totalQuestions << endl;

    return 0;
}
