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
    3.Login function -> Asks for username(dataMap[key]) and then for PIN(dataMap[value][0])
        It then inputs these into the User struct and after that it runs the checkLogin function. 
        If username and PIN check out then user is allowed in.
        If not user must exit or create a new account:
            3.5 Register function -> Asks for name, generates 4 digit pin and asks for balance and writes it into the
            userData.txt file using the saveSignUpData function;
                saveSignUpData function -> opens userData.txt file and writes user.name user.pin and user balance to its end.

DEV TOOLS:
    1. readVectorMap -> prints out all data from dataMap
