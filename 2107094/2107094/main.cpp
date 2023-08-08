#include <iostream>
#include <string>

using namespace std;
// Maximum number of candidates and voters
const int max_candidates = 10;
const int max_voters = 100;

// Candidate class
class Candidate {
public:
    string name;
    int votes;

    Candidate() : name(""), votes(0) {}
};

// Voter class
class Voter {
public:
    string name;
    bool hasVoted;

    Voter() : name(""), hasVoted(false) {}
};

// Election class
class Election {
private:
    Candidate candidates[max_candidates];
    Voter voters[max_voters];
    int numCandidates;
    int numVoters;

public:
    Election() : numCandidates(0), numVoters(0) {}

    // Functions to add roles
    void addCandidate(const string& name) {
        if (numCandidates < max_candidates) {
            candidates[numCandidates].name = name;
            numCandidates++;
            cout << "Candidate added successfully!\n";
            cout << "\n";
        } else {
            cout << "Max number of candidates reached.\n";
        }
    }

    void addVoter(const string& name) {
        if (numVoters < max_voters) {
            voters[numVoters].name = name;
            numVoters++;
            cout << "Voter added successfully!\n";
            cout << "\n";
        } else {
            cout << "Max number of voters reached.\n";
        }
    }

    // Function to start the voting process
    void startVoting() {
        if (numCandidates == 0) {
            cout << "No candidates added yet.\n";
            return;
        }

        if (numVoters == 0) {
            std::cout << "No voters added yet.\n";
            return;
        }

        cout << "===== Voting Started =====\n";

        for (int i = 0; i < numVoters; i++) {
            if (!voters[i].hasVoted) {
                cout << "Voter: " << voters[i].name << "\n";
                cout << "Select a candidate by entering its index (1 to " << numCandidates << "): ";
                int candidateIndex;
                cin >> candidateIndex;

                if (candidateIndex >= 1 && candidateIndex <= numCandidates) {
                    candidates[candidateIndex - 1].votes++;
                    voters[i].hasVoted = true;
                    cout << "Vote cast successfully!\n";
                } else {
                    cout << "Invalid candidate index.\n";
                }
            }
        }

        cout << "===== Voting Ended =====\n";
    }

    // Function to display results
    void displayResults() {
        cout << "===== Election Results =====\n";
        cout << "\n";
        for (int i = 0; i < numCandidates; i++) {
            cout << candidates[i].name << ": " << candidates[i].votes << " votes\n";
        }
        cout << "===========================\n";
    }
};

int main() {
    Election election;
    int choice;
    cout << "Online voting system\n";
    cout << "--------------------\n";
    cout << "\n";

    do {
        cout << "1. Log in as an Admin\n";
        cout << "2. Log in as a Voter\n";
        cout << "3. End the Election\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int roleChoice;
                cout << "1. Add Candidate\n";
                cout << "2. Add Voter\n";
                cout << "Enter your choice: ";
                cin >> roleChoice;

                string name;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);

                if (roleChoice == 1) {
                    election.addCandidate(name);
                } else if (roleChoice == 2) {
                    election.addVoter(name);
                } else {
                    cout << "Invalid choice.\n";
                }
                break;
            }
            case 2: {
                election.startVoting();
                break;
            }
            case 3: {
                election.displayResults();
                break;
            }
            default:
                cout << "Invalid choice.\n";
                break;
        }

    } while (choice != 3);

    return 0;
}
