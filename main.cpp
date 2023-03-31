//Kacper Czajka
// 31-03-23



#include <math.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//Login function 
void login(){
    string username,password;
    string entname,entpass;
    bool rejected = true;
    bool accepted = true; 
    int n = 0;
    int tries = 3;

    cout << "\n ----Please Login To Your Account----\n";
    while(accepted){
        fstream user;
        user.open("users.txt",ios::in);
        if(n < 3 && rejected && user.is_open()){
            if(n > 0){
                std::cout << "\n Incorrect Username or Password" << endl;
                std::cout << "\n You have" << tries << "left" << endl;
            }
            std::cout << "Enter Login" << endl;
            getline(cin,entname);
            std::cout << "Enter Password" << endl;
            getline(cin,entpass);

            tries++;
            string read;

            while(getline(user,read)){
                stringstream converter(read);
                converter >> username >> password;
                if(entname == username && entpass == password){
                    rejected = false;
                } 
                else if(!rejected){
                    std::cout << "\n Welcome" << endl;
                    user.close();
                    accepted = false;
                }
                else{
                    std:cout << "\n Try again later" << endl;
                    user.close();
                    accepted = false;
                }
            }
        }
    }
}
//Registraion function
void registration(){
    string newUsername,newPassword;
    string checkUsername,checkPassword;
    int verif;
    bool signup = true;
    bool reg = true;

    std::cout << "\n Create an Account" << endl;

    while(reg){
        std::cout << "\n Insert Username" << endl;
        getline(cin,newUsername);
        verif = newUsername.length();
        fstream yusers;
    yusers.open("Users.txt",ios::in);
    if(signup && verif >= 1 && yusers.is_open()){
        string readd;
        while(getline(yusers,readd)){
            stringstream OnlyUsers(readd);
            OnlyUsers >> checkUsername;
            if(newUsername == checkUsername){
                std::cout <<"\n*"<< newUsername <<"* UserName already exists Try another one\n" << endl;
                signup = false;
            }
        }
    yusers.close();
    if(!verif){
       verif = true;
    }
    else{
        reg = false;
    }
    }

    }
}
int main(){

    login();











return 0; 
}