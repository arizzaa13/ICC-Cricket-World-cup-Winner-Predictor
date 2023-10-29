#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Team {
    string name;
    int points;
    Team(string n) : name(n), points(0) {}
};

bool compare(Team &t1, Team &t2) {
    return t1.points > t2.points;
}

int main() {
    vector<Team> teams;
    teams.push_back(Team("India"));
    teams.push_back(Team("England"));
    teams.push_back(Team("Pakistan"));
    teams.push_back(Team("Australia"));
    teams.push_back(Team("Netherlands"));
    teams.push_back(Team("New Zealand"));
    teams.push_back(Team("Bangladesh"));
    teams.push_back(Team("Sri Lanka"));
    teams.push_back(Team("South Africa"));
    teams.push_back(Team("Afghanistan"));

    // Taking user input for match results and points allocation
    for (int i = 0; i < teams.size(); i++) {
        for (int j = i + 1; j < teams.size(); j++) {
            int result;
            cout << "Enter the result for match between " << teams[i].name << " and " << teams[j].name << " (1 for win, 0 for loss): ";
            cin >> result;
            if (result == 1) {
                teams[i].points += 2;
            } else if (result == 0) {
                teams[j].points += 2;
            }
        }
    }

    // Sorting the teams based on points
    sort(teams.begin(), teams.end(), compare);

    // Displaying the semi-finalists
    cout << "Semi-finalists are: " << teams[0].name << ", " << teams[1].name << ", " << teams[2].name << ", " << teams[3].name << endl;

    // Taking user input for semi-final match results
    int final1, final2;
    cout << "Enter the result for semi-final 1 (1 for win, 0 for loss): ";
    cin >> final1;
    cout << "Enter the result for semi-final 2 (1 for win, 0 for loss): ";
    cin >> final2;

    // Determining the finalists and the winner
    string finalist1, finalist2, winner;
    if (final1 == 1) {
        finalist1 = teams[0].name;
        finalist2 = teams[1].name;
    } else {
        finalist1 = teams[1].name;
        finalist2 = teams[0].name;
    }

    if (final2 == 1) {
        winner = finalist1;
    } else {
        winner = finalist2;
    }

    // Displaying the winner of the ICC Cricket World Cup 2023
    cout << "The winner of the ICC Cricket World Cup 2023 is: " << winner << endl;

    return 0;
}
