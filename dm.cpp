#include <iostream>
#include <conio.h>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

long long permutation(int n, int r) {
    if (r > n) return 0;
    return factorial(n) / factorial(n - r);
}

long long combination(int n, int r) {
    if (r > n) return 0;
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Forward declaration
void Ballandurn();

void passwordApplication() {
    cout << "\n";
    cout << "========================================\n";
    cout << "  APPLICATION 1: PASSWORD/PIN SECURITY\n";
    cout << "         (PERMUTATION)\n";
    cout << "========================================\n\n";
    
    string digits;
    cout << "Enter digits for PIN (e.g., 1234): ";
    cin >> digits;
    
    cout << "\nYou entered: " << digits << "\n";
    cout << "PIN Length: " << digits.length() << " digits\n\n";
    
    sort(digits.begin(), digits.end());
    
    int count = 0;
    cout << "All Possible PINs:\n";
    cout << "-------------------\n";
    
    do {
        cout << digits << "  ";
        count++;
        if (count % 8 == 0) cout << "\n";
    } while (next_permutation(digits.begin(), digits.end()));
    
    cout << "\n\n";
    cout << "========================================\n";
    cout << "RESULTS:\n";
    cout << "========================================\n";
    cout << "Total Possible PINs: " << count << "\n";
    
    int n = digits.length();
    cout << "Formula Verification: " << n << "! = " << factorial(n) << "\n";
}

void generateTeamCombinations(vector<string>& players, int teamSize,
                              vector<vector<string>>& allTeams,
                              vector<string>& currentTeam, int startIndex) {
    if (currentTeam.size() == teamSize) {
        allTeams.push_back(currentTeam);
        return;
    }
    
    for (int i = startIndex; i < players.size(); i++) {
        currentTeam.push_back(players[i]);
        generateTeamCombinations(players, teamSize, allTeams, currentTeam, i + 1);
        currentTeam.pop_back();
    }
}

void teamSelectionApplication() {
    cout << "\n\n";
    cout << "========================================\n";
    cout << "    APPLICATION 2: TEAM SELECTION\n";
    cout << "           (COMBINATION)\n";
    cout << "========================================\n\n";
    
    int numPlayers, teamSize;
    
    cout << "How many players are available? ";
    cin >> numPlayers;
    
    vector<string> players;
    cout << "\nEnter player names:\n";
    for (int i = 0; i < numPlayers; i++) {
        string name;
        cout << "  Player " << (i + 1) << ": ";
        cin >> name;
        players.push_back(name);
    }
    
    cout << "\nHow many players do you need in the team? ";
    cin >> teamSize;
    
    if (teamSize > numPlayers) {
        cout << "\nError: Team size cannot be greater than available players!\n";
        return;
    }
    
    cout << "\nTotal Possible Teams: C(" << numPlayers << "," << teamSize
         << ") = " << combination(numPlayers, teamSize) << "\n\n";
    
    vector<vector<string>> allTeams;
    vector<string> currentTeam;
    generateTeamCombinations(players, teamSize, allTeams, currentTeam, 0);
    
    for (int i = 0; i < allTeams.size(); i++) {
        cout << "Team " << (i + 1) << ": { ";
        for (int j = 0; j < allTeams[i].size(); j++) {
            cout << allTeams[i][j];
            if (j < allTeams[i].size() - 1) cout << ", ";
        }
        cout << " }\n";
    }
}

void calculatorMode() {
    cout << "\n\n";
    cout << "========================================\n";
    cout << "   PERMUTATION & COMBINATION CALCULATOR\n";
    cout << "========================================\n\n";
    
    int choice;
    cout << "1. Permutation P(n, r)\n";
    cout << "2. Combination C(n, r)\n";
    cout << "3. Ball and Urn Problem\n";
    cout << "\nYour choice: ";
    cin >> choice;
    
    if (choice == 1 || choice == 2) {
        int n, r;
        cout << "Enter value of n: ";
        cin >> n;
        cout << "Enter value of r: ";
        cin >> r;
        
        if (choice == 1)
            cout << "P(" << n << "," << r << ") = " << permutation(n, r) << "\n";
        else
            cout << "C(" << n << "," << r << ") = " << combination(n, r) << "\n";
    }
    else if (choice == 3) {
        Ballandurn();
    }
}

int main() {
    cout << "\n**********************************************\n";
    cout << "*   Combinatorial Problem Solver      *\n";
    cout << "**********************************************\n";
    
    int choice;
  do  {
        cout << "\n========================================\n";
        cout << "           MAIN MENU\n";
        cout << "========================================\n";
        cout << "1. Password/PIN Generator\n";
        cout << "2. Team Selection\n";
        cout<<  "3. Student grouping\n";
        cout << "4. Calculator Mode\n";
        cout << "5. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: passwordApplication(); break;
            case 2: teamSelectionApplication(); break;
            case 3: Ballandurn(); break;
            case 4: calculatorMode(); break;
            case 5: cout << "\nThank you for using the program!\n"; break;
            default: cout << "\nInvalid choice!\n";
        }
    } while (choice != 5);
    
    return 0;
}

// ===== BALLS AND URNS APPLICATION (FIXED & MATCHED) =====
void Ballandurn() {
    cout << "\n\n";
    cout << "========================================\n";
    cout << "  APPLICATION 3: STUDENT GROUPING\n";
    cout << "        (BALLS AND URNS MODEL)\n";
    cout << "========================================\n\n";

    int N, R;

    cout << "Enter number of students (balls): ";
    cin >> N;
    cout << "Enter number of groups (urns): ";
    cin >> R;

    cout << "\nEach student can join any group.\n";
    cout << "More than one student can be in a group.\n\n";

    long long ways = pow(R, N);

    cout << "========================================\n";
    cout << "RESULTS:\n";
    cout << "========================================\n";
    cout << "Total Possible Groupings = " << R << "^" << N
         << " = " << ways << "\n";
         getch();
}
