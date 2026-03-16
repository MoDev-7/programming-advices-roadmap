#include <iostream>
using namespace std;
enum gameChoice { stone = 1, paper = 2, scissor = 3, drow = 4, win = 5, lose = 6 };
struct player {
    int choice = 0;
    int points = 0;
};
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
int checkResult(player computer, player user) {
    if (user.choice == paper && computer.choice == stone)
        return win;
    if (user.choice == stone && computer.choice == scissor)
        return win;
    if (user.choice == stone && computer.choice == stone)
        return drow;
    if (user.choice == scissor && computer.choice == paper)
        return win;
    if (user.choice == paper && computer.choice == paper)
        return drow;
    if (user.choice == scissor && computer.choice == scissor)
        return drow;
    if (user.choice == stone && computer.choice == paper)
        return lose;
    if (user.choice == scissor && computer.choice == stone)
        return lose;
    if (user.choice == paper && computer.choice == scissor)
        return lose;
}

int playerChoice() {
    int choice = readNum("Your choice :\n[1] stone\n[2] paper\n[3] scissor");
    return choice;
}
int computerChoice() {
    int choice = randomNumber(1, 3);
    return choice;
}
string numToString(int num) {
    if (num == 1)
        return "stone";
    if (num == 2)
        return "paper";
    if (num == 3)
        return "scissor";
}
void round(int roundNUmber, player& computer, player& user) {
    cout << "Round [" << roundNUmber << "] begains:" << endl << "_______________" << "round [" << roundNUmber << "] _______________" << endl;
    computer.choice = computerChoice();
    user.choice = playerChoice();
    cout << "Your choice : " << numToString(user.choice) << endl << "computer choice : " << numToString(computer.choice) << endl;
    int result = checkResult(computer, user);
    if (result == win) {
        user.points++;
        cout << "Winner : You" << endl;
    }
    if (result == lose) {
        computer.points++;
        cout << "Winner : Computer" << endl;
    }
    if (result == drow)
        cout << "Winner : No one" << endl;
    cout << "_______________________________________" << endl;
}
void rounds() {
    player computer;
    player user;
    int numberOfRounds = readNum("How many rounds 1 to 10 ?");
    for (int i = 1; i <= numberOfRounds; i++)
    {
        round(i, computer, user);
    }
    cout << "Results :" << endl << "Computer = " << computer.points << endl;
    cout << "You = " << user.points << endl << "Drow : " << numberOfRounds - computer.points - user.points;
}
int main()
{
    srand((unsigned)time(NULL));
    rounds();
}