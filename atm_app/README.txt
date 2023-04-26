APP FUNCTION:
    Console based ATM app;

    Features:
        login;
        view balance;
        withdraw money;
        input money;

    userData file format:
        name PIN balance$;

CODE STRUCTURE/DESIGN:
    1. Basic input/output system; - Done
    2. getUserData function. -> At the beginning of the code so that the file is always going to be read!
        map -> string key, vector value
    3. Login function -> Asks for username(dataMap[key]) and then for PIN(dataMap[value][0])
        It then inputs these into the User struct and after that it runs the checkLogin function. 
        If username and PIN check out then user is allowed in.
        If not user must exit or create a new account:
            3.5 Register function -> Asks for name, generates 4 digit pin and asks for balance and writes it into the
            userData.txt file using the saveSignUpData function;
                saveSignUpData function -> opens userData.txt file and writes user.name user.pin and user balance to its end.
    4. Mainloop
    5. functions:
        5.1 showPersonalInfo function -> asks for users PIN
                if PIN is correct than the program prints out the personal info
                if not it throws an error

        5.2 withdraw function -> asks for user's PIN, asks for withdraw amount 
                if withdraw amount > user.balance: throw err
                else goes into userData.txt file and searches for the user.name and deletes that line using the dev tools
                `deleteLine` function, 


DEV TOOLS:
    1. readVectorMap -> prints out all data from dataMap
    2. deleteLine -> 
