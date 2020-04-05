#include <string>
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
//Interface mà back-end A quy định cho user
class BackendAUserInterface
{
public:
    virtual void setName(std::string name) = 0;
    virtual std::string getName() = 0;

};
//Class User hiện tại đang implement BackendAUserInterface

class User : public BackendAUserInterface
{
private:
    std::string mName;

public:
    void setName(std::string name)
    {
        mName = name;
    }

    std::string getName()
    {
        return mName;
    }
};
//Interface mà Back-end B quy định cho đối tượng user
class BackendBUserInterface
{
public:
    virtual void setFirstName(std::string firstName) = 0;
    virtual void setLastName(std::string lastName) = 0;
    virtual std::string getFirstName() = 0;
    virtual std::string getLastName() = 0;
};
//Tạo adapter
class UserAtoBAdapter : public BackendBUserInterface
{
private:
    User mUser;
    std::string mFirstname;
    std::string mLastname;

public:
    UserAtoBAdapter(User user)
    {
        mUser = user;

        // split first name and last name
        unsigned int splitPostion = user.getName().find_first_of(" ");
        if (splitPostion != std::string::npos)
        {
            mFirstname = user.getName().substr(0, splitPostion + 1);
            mLastname = user.getName().substr(splitPostion + 1, user.getName().length() - mFirstname.length());
        }
    }

    void setFirstName(std::string firstName)
    {
        mFirstname = firstName;
    }

    void setLastName(std::string lastName)
    {
        mLastname = lastName;
    }

    std::string getFirstName()
    {
        return mFirstname;
    }

    std::string getLastName()
    {
        return mLastname;
    }
};
int main()
{
    // create User object
    User user;
    user.setName("Huy Nguyen Quang");

    // create adapter
    UserAtoBAdapter adapter(user);
    cout << "First name: " << adapter.getFirstName() << endl;
    cout << "Last name: " << adapter.getLastName() << endl;


    return 0;
}