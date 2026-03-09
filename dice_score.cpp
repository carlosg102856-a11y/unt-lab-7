#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int CheckSingles(vector<int> dice, int goal) {
    int sum = 0;
    for (int i = 0; i < dice.size(); i++) {
        if (dice[i] == goal) {
            sum += goal;
        }
    }
    return sum;
}

int CheckThreeOfKind(vector<int> dice) {
    for (int i = 0; i < 3; i++) {
        if (dice[i] == dice[i+1] && dice[i] == dice[i+2]) {
            return 30;
        }
    }
    return 0;
}

int CheckFourOfKind(vector<int> dice) {
    for (int i = 0; i < 2; i++) {
        if (dice[i] == dice[i+1] && dice[i] == dice[i+2] && dice[i] == dice[i+3]) {
            return 40;
        }
    }
    return 0;
}

int CheckFiveOfKind(vector<int> dice) {
    if (dice[0] == dice[1] && dice[0] == dice[2] && dice[0] == dice[3] && dice[0] == dice[4]) {
        return 50;
    }
    return 0;
}

int CheckFullHouse(vector<int> dice) {
    if ((dice[0]==dice[1] && dice[2]==dice[3] && dice[2]==dice[4]) ||
        (dice[0]==dice[1] && dice[0]==dice[2] && dice[3]==dice[4]) ||
        (dice[0]==dice[1] && dice[1]==dice[2] && dice[2]==dice[3] && dice[3]==dice[4])) {
        return 35;
    }
    return 0;
}

int CheckStraight(vector<int> dice) {
    if ((dice[0]==1 && dice[1]==2 && dice[2]==3 && dice[3]==4 && dice[4]==5) ||
        (dice[0]==2 && dice[1]==3 && dice[2]==4 && dice[3]==5 && dice[4]==6)) {
        return 45;
    }
    return 0;
}

int FindHighScore(vector<int> dice) {
    int highScore = 0;
    int score;

    for (int i = 1; i <= 6; i++) {
        score = CheckSingles(dice, i);
        if (score > highScore) {
            highScore = score;
        }
    }

    score = CheckThreeOfKind(dice);
    if (score > highScore) highScore = score;

    score = CheckFourOfKind(dice);
    if (score > highScore) highScore = score;

    score = CheckFiveOfKind(dice);
    if (score > highScore) highScore = score;

    score = CheckFullHouse(dice);
    if (score > highScore) highScore = score;

    score = CheckStraight(dice);
    if (score > highScore) highScore = score;

    return highScore;
}

int main() {
    vector<int> dice(5);

    for (int i = 0; i < 5; i++) {
        cin >> dice[i];
    }

    sort(dice.begin(), dice.end());

    cout << "High score: " << FindHighScore(dice) << endl;

    return 0;
}