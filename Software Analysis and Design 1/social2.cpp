#include <iostream>
#include <string>

using namespace std;

int MAX_USERS;

//Part A
class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn);
    // Default Profile constructor (username="", displayname="")
    Profile();
    // Return username
    string getUsername();
    // Return name in the format: "displayname (@username)"
    string getFullName();
    // Change display name
    void setDisplayName(string dspn);
};

//Part B
class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn);

// Part C
// friendship matrix:
// following[id1][id2] == true when id1 is following id2
bool following[MAX_USERS][MAX_USERS];  

public:
  // Constructor, makes an empty network (numUsers = 0)
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn, string dspn);
  // Part C: Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
 // return true if success (if both usernames exist), otherwise return false
 bool follow(string usrn1, string usrn2);

 //Part C
 // Print Dot file (graphical representation of the network)
 void printDot();
};

/*
//part a main function - copied from instructions

int main() {
    Profile p1("marco", "Marco");    
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    cout << p2.getUsername() << endl; // tarma1
    cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)
}
*/

/*
//Part B: Main function
int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i), 
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}
*/

//Part C main function
int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}

//Note: Make sure to include the class that the function belongs to.

//Part B: constructor: makes an empty network (numUsers = 0)
//Part C: 
Network::Network(){
	//Part B
	numUsers = 0;
	//Part C
	for (int i=0; i<MAX_USERS; i++){
		for(int j=0; j<MAX_USERS; j++){
			following[i][j] = false;
		}
	}
}

// Part C:  Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
// return true if success (if both usernames exist), otherwise return false
bool Network::follow(string usrn1, string usrn2){
	//check if first username usrn1 exist or not
	int i = findID(usrn1);
	if (i == -1){    //if it doesnt exist
		return false;
	}
	else{   //if it does exist, then look for the second username usrn2 in "profile" array
		for (int j=0; j<numUsers; j++){
			if (profiles[j].getUsername() == usrn2){
				following[i][j] = true;
				return true;
			}
		}
	}
	//if username 2 is not found, return false
	return false;
}

//Part C: used to visualize the network
void Network::printDot(){
	cout << "digraph {\n";
	for (int i=0; i<numUsers; i++){
		cout << "\t\"@" << profiles[i].getUsername() << "\"\n";
	}
	for (int i=0; i<numUsers; i++){
		for (int j=0; j<numUsers; j++){
			if (following[i][j]){
				cout << "\t\"@" << profiles[i].getUsername() << "\" -> \"@" << profiles[j].getUsername() << "\"\n";
			}
		}
	}
	cout << "}\n";
}
	

//Part B
// Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)

int Network::findID (string usrn){
	for (int i=0; i<numUsers; i++){
		if (profiles[i].getUsername() == usrn){
			return i;
		}
	}
	return -1;
}



// Attempts to sign up a new user with specified username and displayname
// return true if the operation was successful, otherwise return false
bool Network::addUser(string usrn, string dspn){
	//check if the network is already full.
	if (numUsers == MAX_USERS){
		return false;
	}
	//check if username is already taken
	for (int i=0; i<numUsers; i++){
		if (profiles[i].getUsername() == usrn){
			return false;		
		}
	}
	//check if the username is alphanumeric
	for (int i=0; i<usrn.length(); i++){
		if (!isalpha(usrn[i]) && !isdigit(usrn[i])){
			return false;
		}
	}
	
	//if the username is valid, add this user through the network
	//ass the username to the end of the "profiles" array
	profiles[numUsers] = Profile(usrn, dspn);
	//increase the number of users by 1
	numUsers++;
	return true;
}

//part A profile constructor for a user (initializing 
//private variables username=usrn, displayname=dspn)
Profile::Profile(string usrn, string dspn){
	username = usrn;
	displayname = dspn;
}

//Part A: default profile constructor (username="", displayname+"")
Profile::Profile(){
	username="";
	displayname="";
}



//Part A: Return username
string  Profile::getUsername(){
	return username;
}

//Part A: Return name in the format: "displayname (@username)"
string Profile::getFullName(){
	return displayname + "(@" + username + ")";
}

//Part A: Change display name
void Profile::setDisplayName(string dspn){
	displayname = dspn;
}