#include <iostream>
using namespace std;

enum enLevel {easy = 1, medium = 2, hard = 3, mixLevel = 4};
enum enType {add = 1, subtruct = 2, times = 3, over = 4, mixType = 5};

struct stQuestionInfo {
    short numberOfQuestion;
    enLevel level;
    enType type;
    int number1, number2;
    int playerAnswer, rightAnswer;
    bool result;    
};
struct stGameInfo {
    int numberOfQuestions;
    enLevel level;
    enType type;
    short rightAnswers = 0, wrongAnswers = 0;
};

int readNum() {
    int num;
    cin >> num;
    return num;
}
int readNum(string massege) {
    cout << massege << endl;
    int num;
    cin >> num;
    return num;
}
int randomNumber(int from, int to) {
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}

enLevel readGameLevel() {
    return (enLevel)readNum("Select level :\n[1] Easy\n[2] Medium\n[3] Hard\n[4] Mix");
}
enType readGameType() {
    return (enType)readNum("Select Type :\n[1] Add\n[2] Minus\n[3] Times\n[4] Over\n[5] Mix");
}
void getGameInfo(stGameInfo& game) {
    game.numberOfQuestions = readNum("enter number of questions");
    game.level = readGameLevel();
    game.type = readGameType();
}

enLevel getQuestionLevel(stGameInfo game) {
    if (game.level == mixLevel)
        return (enLevel)randomNumber((int)easy, (int)hard);
    return game.level;
}
enType getQuestionType(stGameInfo game) {
    if (game.type == mixType)
        return (enType)randomNumber((int)add, (int)over);
    return game.type;
}
int getQuestionNumber(enLevel level) {
    switch (level) {
    case easy:
        return randomNumber(1, 9);
    case medium:
        return randomNumber(10, 99);
    case hard:
        return randomNumber(100, 999);
    }
}
int getQuestionRightAnswer(int number1, int number2, enType type) {
    switch (type) {
        case add:
            return number1 + number2;
        case subtruct:
            return number1 - number2;
        case times:
            return number1 * number2;
        case over:
            return number1 / number2;
    }
}
bool getQuestionBoolean(int rightAnswer, int playerAnswer) {
    return rightAnswer == playerAnswer;
}
string printQuestionType(enType type) {
    switch (type) {
    case add:
        return " + ";
    case subtruct:
        return " - ";
    case times:
        return " x ";
    case over:
        return " / ";
    }
}
void printQuestionResult(bool value, int rightAnswer) {
    if (value)
        cout << "Right answer!\n";
    else {
        cout << "Wrong answer!\nRight is : " << rightAnswer << endl;
    }

}

void getQuestionInfo(stQuestionInfo& question, stGameInfo game, int numberOfQuestion) {
    question.numberOfQuestion = numberOfQuestion;
    question.level = getQuestionLevel(game);
    question.type = getQuestionType(game);
    question.number1 = getQuestionNumber(question.level);
    question.number2 = getQuestionNumber(question.level);
    question.rightAnswer = getQuestionRightAnswer(question.number1, question.number2, question.type);

}
void PrintQuestion(stQuestionInfo& question , int numberOfQuestions) {
    cout << "Question [" << question.numberOfQuestion << "/" << numberOfQuestions << "] :" << endl;
    cout << question.number1 << endl << question.number2 << printQuestionType(question.type) << endl << "_________" << endl;
    question.playerAnswer = readNum();
    question.result = getQuestionBoolean(question.rightAnswer, question.playerAnswer);
    printQuestionResult(question.result, question.rightAnswer);    
}
bool playQuestion(stGameInfo game, int numberOfQuestion) {
    stQuestionInfo question;
    getQuestionInfo(question, game, numberOfQuestion);
    PrintQuestion(question, game.numberOfQuestions);
    return question.result;
}

string printGameType(enType type) {
    switch (type) {
    case add:
        return " Add ";
    case subtruct:
        return " Subtruct ";
    case times:
        return " Times ";
    case over:
        return " Over ";
    case mixType:
        return " Mix ";
    }
}
string printGameLevel(enLevel level) {
    switch (level) {
    case easy:
        return " Easy ";
    case medium:
        return " Medium ";
    case hard:
        return " Hard ";
    case mixLevel:
        return " Mix ";
    }
}
stGameInfo PlayGame(stGameInfo game) {
    getGameInfo(game);
    for (int i = 1; i <= game.numberOfQuestions; i++)
    {
        if (playQuestion(game, i))
            game.rightAnswers++;
        else
            game.wrongAnswers++;
    }
    return game;
}
void printGame(stGameInfo game) {
    cout << "____________________________________________________________" << endl;
    cout << "\t\t\tGame Results\t\t\t\n";
    cout << "____________________________________________________________" << endl;
    cout << "Number of questions: " << game.numberOfQuestions << endl;
    cout << "Game level: " << printGameLevel(game.level) << endl;
    cout << "Game Type: " << printGameType(game.type) << endl;
    cout << "Right answers: " << game.rightAnswers << endl;
    cout << "Wrong answers: " << game.wrongAnswers << endl;
}
void games() {
    stGameInfo game;
    printGame(PlayGame(game));
}
void resetScreen() {
    system("cls");
    system("color 0f");

}
void startGame() {
    char c;
    do {
        games();
        cout << "wanna play? [Y/y]\n";
        cin >> c;
        if (c == 'y' || c == 'Y') {
            resetScreen();
        }
    } while (c == 'y' || c == 'Y');
}

int main()
{
    srand((unsigned)time(NULL));
    startGame();
}