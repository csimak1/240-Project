#ifndef _USER_h
#define _USER_h

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

class User {
    public:
        User(string userID);
        User();
        string getUserID(){return userID;}
        int getVotes(){return numVotes;}
        void setUserID(string ID){userID = ID;}
        void incrementVotes(int voteCount){numVotes += voteCount;}
        bool operator==(User& other) {
            return this->userID == other.userID;
        }
        bool operator>(User other) {
            if((this->userID).compare(other.userID) > 0) {
                return true;
            }
            return false;
            
        }
        bool operator<(User& other) {
             if((this->userID).compare(other.userID) < 0) {
                return true;
             }
             return false;
        }
        friend ostream& operator<<(ostream& os, User  u) {
            os << u.getUserID();
            return os;
        }
            

    private:
        string userID;
        int numVotes;
};

#endif