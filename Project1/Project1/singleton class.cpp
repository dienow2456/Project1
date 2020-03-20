#include <string>
#include <iostream>

using namespace std;

class Database
{
private:
    static Database* mInstancePtr;
    int mRecord;
    string mName;

    Database(string name)
    {
        mName = name;
        mRecord = 0;
    }

public:
    void editRecord(string operation)
    {
        cout << "Performing a " << operation <<
            "operation on record " << mRecord <<
            " in database " << mName << endl;
    }

    string getName()
    {
        return mName;
    }

    static Database* getInstance(string name)
    {
        if (nullptr == mInstancePtr) {
            mInstancePtr = new Database(name);
        }
        return mInstancePtr;
    }
};


Database* Database::mInstancePtr = nullptr;
int main()
{
    Database* database;
    database = Database::getInstance("products");
    cout << "This is the " << database->getName() << " database." << endl;
    database = Database::getInstance("employees");
    cout << "This is the " << database->getName() << " database." << endl;
    return 0;
}