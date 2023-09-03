// P08 Soccer Team Roster
//		Implement a menu of options for a user to maintain the roster
// Samantha Roldan
//

#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int> jerseyNums;
	vector<int> ratingNums;

	int i;
	int playerJersey;
	int playerRating;
	char menuOp;

	cout << "*** Soccer Team Roster ***" << endl;

	do {
		cout << "\n--Menu--" << endl;
		cout << "a - Add player" << endl;
		cout << "d - Remove player" << endl;
		cout << "u - Update player rating" << endl;
		cout << "r - Output players above a rating" << endl;
		cout << "o - Output roster" << endl;
		cout << "q - Quit" << endl << endl;

		cout << "Choose an option: ";
		cin >> menuOp;
		cout << endl;

		switch (menuOp) {
		case 'a':  //Add
			cout << "Enter a new player's jersey number: ";
			cin >> playerJersey;

			if (jerseyNums.size() == 0) { //if there is nothing inside vector, add the player number and rating
				cout << "Enter the player's rating: ";
				cin >> playerRating;
				jerseyNums.push_back(playerJersey);
				ratingNums.push_back(playerRating);
				cout << "  >>> Jersey number " << playerJersey << " added! <<<" << endl;

			}
			else { //if vector is not empty
				for (i = 0; i < jerseyNums.size(); ++i) { //check for playerJersey inside vector
					if (playerJersey == jerseyNums.at(i)) { //if playerJersey is already inside vector then break
						break;
					}
				}
                if (i == jerseyNums.size()) { //if playerJersey is not inside of vector then add it
					cout << "Enter the player's rating: ";
					cin >> playerRating;
					jerseyNums.push_back(playerJersey);
					ratingNums.push_back(playerRating);
					cout << "  >>> Jersey number " << playerJersey << " added! <<<" << endl;
                }
                else { //if playerJersey is inside of vector, state that
					cout << "  >>> Jersey number " << playerJersey << " already in use! <<<" << endl;
                }
				
			}
			break;
		case 'd': //Delete
			cout << "Enter a jersey number: ";
			cin >> playerJersey;

			for (i = 0; i < jerseyNums.size(); ++i) { //check if playerJersey is inside vector
				if (playerJersey == jerseyNums.at(i)) { //if playerJersey found inside vector then break
					break;
				}
			}
			if (i == jerseyNums.size()) { //not inside of vector, so state that
				cout << "  >>> Jersey number " << playerJersey << " not found! <<<" << endl;
			}
			else { //player jersey is inside of the vector so you can delete
				jerseyNums.erase(jerseyNums.begin() + i);
				ratingNums.erase(ratingNums.begin() + i);
				cout << "  >>> Jersey number " << playerJersey << " deleted! <<<" << endl;
			}
			break;
		case 'u': //Update
			cout << "Enter a jersey number: ";
			cin >> playerJersey;

			for (i = 0; i < jerseyNums.size(); ++i) { //check if playerJersey is inside vector
				if (playerJersey == jerseyNums.at(i)) { //if playerJersey inside of vector then break
					break;
				}
			}
			if (i == jerseyNums.size()) { //not in vector, so state that
				cout << "  >>> Jersey number " << playerJersey << " not found! <<<" << endl;
			}
			else { //inside of vector, so you can update the rating
				cout << "Enter a new rating for player: ";
				cin >> playerRating;
				ratingNums.at(i) = playerRating;
				cout << "  >>> Jersey number " << playerJersey << " rating updated! <<<" << endl;
			}
			break;
		case 'r': //Rating
			cout << "Enter a rating: ";
			cin >> playerRating;
			cout << endl;

			cout << "<<< Ranking Above " << playerRating << " >>>" << endl;
			for (i = 0; i < ratingNums.size(); ++i) { //iterate through all of vectors
				if (ratingNums.at(i) > playerRating) { //output only players whose ratings are above the specific rating
					cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNums.at(i);
					cout << ", Rating: " << ratingNums.at(i) << endl;
				}
			}
			break;
		case 'o': //Output roster
			cout << "<<< Full Roster >>>" << endl;
		
			for (i = 0; i < ratingNums.size(); ++i) { //iterate through both vectors and output everything inside of them
				cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNums.at(i);
				cout << ", Rating: " << ratingNums.at(i) << endl;
			}
			break;
		} //end switch
	} while (menuOp != 'q');

	return 0;
}