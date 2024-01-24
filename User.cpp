#include <string>
#include "User.h"


User::User(string ID) {
    userID = ID;
    numVotes = 0;
}

User::User(){
    numVotes = 0;
}