#include <iostream>
using namespace std;

class List {
private:
    int size;
public:
    List() : size(0) {}

    List(int s) : size(s) {}

    int GetByPos(int pos)
    {
        if(size == 0) return 1;
        if(pos < 1 || pos >= size) return 2;

        return rand() % 10;

    }

};

float Divide(float a, float b)
{
    // try , catch , throw



    float res;

    if(b == 0)
    {
        throw ("You can't divide by zero!");
    }
    if(b == 1)
    {
        throw 404;
    }
    if(b == 5)
    {
        throw "Divide by 5";
    }

    res = a / b;
    cout << "Result: " << res << endl;
    return res;

}

class PasswordInvalidException: public exception
{
public:
    PasswordInvalidException(const char* message): exception(message) {}
};

class PasswordIsShortException: public exception
{
    int length;
public:
    PasswordIsShortException(const char* message, int length):length(length), exception(message) {}

    void Message() const
    {
        cout << what() << endl;
        cout << "Actual length: " << length << endl;
    }
};

void Login(const char* login, const char* password)
{
    if(strlen(password) < 6)
        cout << "The password is too short." << endl;
    if(!islower(password[0]) || isalpha(password[0]))
        cout << "The password is invalid." << endl;
    if(!isupper(login[0]) || isalpha(login[0]))
        cout << "The login is invalid." << endl;
    cout << "Loading..." << endl;
}

int main()
{
    /*
    float a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;


    try
    {
        float res = Divide(a, b);
        cout << "Result in the main: " << res << endl;
    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
    }
    catch(int ex)
    {
        cout << ex << endl;
    }
    catch(...)
    {
        cout << "Unknown exception." << endl;
    }
     */

    char login[100];
    char pass[100];



    for (int i = 0; i < 5; ++i)
    {
        cout << "Enter login: ";
        cin >> login;
        cout << "Enter password: ";
        cin >> pass;



        try
        {
            Login(login, pass);
                break;
        }
        catch (PasswordInvalidException& e)
        {
            cout << "Invalid... do something:\n";
            cout << e.what() << endl;
            cout << "A-Z, a-z, 0-9\n";
        }
        catch (PasswordIsSmallException& e)
        {
            cout << "Small... do something:\n";
            e.Message();
            cout << "Length must be more than 6 symbols\n";
        }
        catch (exception& e)
        {
            cout << "General error...\n";
            cout << e.what() << endl;
        }
        catch (...)
        {
            cout << "Unknown exception!\n";
            }
        }






    return 0;
}
