#include <iostream>
#include <thread>
#include <cstdlib> 
#include <chrono>
#define RESET   "\033[0m"  // THESE ARE THE COLORS
#define RED     "\033[31m" // IN ABLE TO CHANGE
#define GREEN   "\033[32m" // THE TERMINAL TEXTS
using namespace std;

// FINAL PROJECT
// TITLE: QUIZ GAME
// STATUS: DONE 12 / 02 / 23

// NOTES:
// system("clear") = is to clear the console or termninal in your screen
// this_thread::sleepfor(chrono::) = is having a delay before your desired output show up

class Info {
  private:
  string Username, Password;

  public:

    // part1. registration logics
    int reg(string user, string password){
      this->Username = user;
      this->Password = password;

      return (this->Username.empty() || this->Password.empty()) ? 0 :
             (this->Username.length() < 6 && this->Password.length() >= 8) ? 1 :
             (this->Username.length() >= 6 && this->Password.length() < 8) ? 2 :
             (this->Username.length() < 6 && this->Password.length() < 8) ? 3 :
             (this->Username.length() > 10 && this->Password.length() >= 8 && this->Password.length() <= 15) ? 4 :
             (this->Password.length() > 15) ? 5 :
             (this->Username == this->Password) ? 6 : 7;

            //     --these are my placeholders--
            //      return 0;  both are empty
            //      return 1;  username is below 6 characters
            //      return 2;  password is below 8 characters
            //      return 3;  both aren't met the requirements of length
            //      return 4;  username were above the maximum length
            //      return 5;  password were above the maximum length
            //      return 6;  username and password were the same
            //      return 7;  registration successfull
      };

      // part1. login logics
      int Log(string username, string password) {
              
        if(this->Username.empty() || this->Password.empty()){
          return 8; // both are empty
        }
        else if(this->Username != username || this->Password != password){
          if(this->Username != username && this->Password == password){
            return 9; // username is wrong
          }
          else if(this->Username == username && this->Password != password){
            return 10; // password is wrong
          }
          else{
            return 11; // both are wrong
          }
        }
        else { 
          return 12; // login sucessfull
        }
      }
};

  // display forwarded message
void displayForwardedMsg(){
    this_thread::sleep_for(chrono::seconds(1));
    cout << GREEN << "\n> You are being forwarded to Registration..." << RESET <<endl;
    this_thread::sleep_for(chrono::seconds(2));
    system("clear");
    this_thread::sleep_for(chrono::seconds(1));
}

  // display exit message
void displayExitMsg(){
    this_thread::sleep_for(chrono::seconds(1));
    cout << RED << "\n> :( Well that's sad, anyway goodbye have a nice day!" << RESET << endl;
    this_thread::sleep_for(chrono::seconds(1));
}

  // display invalid message
void displayInvalidMsg(){
    this_thread::sleep_for(chrono::seconds(1));
    cout << RED << "\n> Invalid selection" << RESET << endl;
    this_thread::sleep_for(chrono::seconds(1));
}
 
  // part2. registration logics
void displayReg(string& ru, string& rp, Info& details){ 
  
  // ru means = RegisterUsername
  // rp means = RegisterPassword
  int regAttempt = 0;
  while(regAttempt < 5){
  cout << endl;
  cout << "||=================================||" << endl;
  cout << "||                                 ||" << endl;
  cout << "||           REGISTRATION          ||" << endl;
  cout << "||                                 ||" << endl;
  cout << "||=================================||" << endl;
  cout << endl;
  cout << "--------------- NOTE ----------------" << endl;
  cout << endl;
  cout << "     Username: 6 to 10 characters" << endl;
  cout << "     Password: 8 to 15 characters" << endl;
  cout << endl;

  cout << "\nEnter your username: "; getline(cin,ru);
  cout << "Enter your password: "; getline(cin,rp);
  int reg = details.reg(ru,rp); // stored the ru and rp into the reg function

  if(reg == 0){
    this_thread::sleep_for(chrono::seconds(1));
    cout << RED << "\n> Please input all the required field/s" << RESET << endl;
    cout << RED << "> Try again" << RESET << endl;
    regAttempt++;
    this_thread::sleep_for(chrono::seconds(2));
    system("clear");
  }
  else if(reg == 1){
    this_thread::sleep_for(chrono::seconds(1));
    cout << RED << "\n> Username must have at least 6 characters!" << RESET <<endl;
    cout << RED  << "> Try again"  << RESET<< endl;
    regAttempt++;
    this_thread::sleep_for(chrono::seconds(2));
    system("clear");
  }
  else if(reg == 2){
    this_thread::sleep_for(chrono::seconds(1));
    cout << RED << "\n> Password must have at least 8 characters!" << RESET << endl;
    cout << RED << "> Try again" <<RESET << endl;
    regAttempt++;
    this_thread::sleep_for(chrono::seconds(2));
    system("clear");
  }
  else if(reg == 3){
    this_thread::sleep_for(chrono::seconds(1));
    cout << RED << "\n> Useraname must have at least 6 characters!" << RESET << endl;
    cout << RED << "> Password must have at least 8 characters!" << RESET << endl;
    cout << RED << "> Try again" <<RESET << endl;
    regAttempt++;
    this_thread::sleep_for(chrono::seconds(2));
    system("clear");
  }
  else if(reg == 4){
    this_thread::sleep_for(chrono::seconds(1));
    cout << RED << "\n> Useraname must below the maximum characters!" << RESET << endl;
    cout << RED << "> Try again" <<RESET << endl;
    regAttempt++;
    this_thread::sleep_for(chrono::seconds(2));
    system("clear");
  }
  else if(reg == 5){
    this_thread::sleep_for(chrono::seconds(1));
    cout << RED << "\n> Password must below the maximum characters!" << RESET << endl;
    cout << RED << "> Try again" <<RESET << endl;
    regAttempt++;
    this_thread::sleep_for(chrono::seconds(2));
    system("clear");
  }
  else if(reg == 6){
    this_thread::sleep_for(chrono::seconds(1));
    cout << RED << "\n> Username and Password must be different!" << RESET << endl;
    cout << RED << "> Try again" <<RESET << endl;
    regAttempt++;
    this_thread::sleep_for(chrono::seconds(2));
    system("clear");
  }
  else if(reg == 7){
    this_thread::sleep_for(chrono::seconds(1));
    cout << GREEN << "\n> Registration complete" << RESET << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << GREEN << "\n> You are being forwarded to Login..." << RESET <<endl;
    this_thread::sleep_for(chrono::seconds(2));
    system("clear");
    break;
    }

  if(regAttempt == 5){
    this_thread::sleep_for(chrono::seconds(1));
    cout << RED << "\n> Due to several Registration attempts!" << RESET << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << RED << "> The program will be terminated.." <<RESET << endl;
    cout << endl;
    this_thread::sleep_for(chrono::seconds(2));
    exit(1);
  }
}
}
  // end of registration logics

  // part2. login logics
void displayLog(string& lu, string& lp, Info& details){
  
  // lu means = LoginUsername
  // lp means = LoginPassword
  int LoginAttempt = 0;

while(LoginAttempt < 5){
  cout << endl;
  cout << "||=================================||" << endl;
  cout << "||                                 ||" << endl;
  cout << "||              LOGIN              ||" << endl;
  cout << "||                                 ||" << endl;
  cout << "||=================================||" << endl;
  cout << "\nUsername: ";
  getline(cin,lu);
  cout << "Password: "; 
  getline(cin,lp);
  int result = details.Log(lu,lp); // stored the lu and lp to the Log function();
  if(result == 8){
    this_thread::sleep_for(chrono::seconds(1));
    cout << RED << "\n> Invalid, please input all the required field/s"  << RESET << endl;
    cout << RED << "> Try again" << RESET<<endl;
    LoginAttempt++;
    this_thread::sleep_for(chrono::seconds(2));
    system("clear");
  }
  else if(result == 9){
    this_thread::sleep_for(chrono::seconds(1));
    cout << RED <<"\n> Invalid username!" << RESET << endl;
    cout <<  RED << "> Try again" << RESET << endl;
    LoginAttempt++;
    this_thread::sleep_for(chrono::seconds(2));
    system("clear");
  }
  else if(result == 10){
    this_thread::sleep_for(chrono::seconds(1));
    cout << RED << "\n> Invalid password!" << RESET << endl;
    cout <<RED <<  "> Try again" << RESET << endl;
    LoginAttempt++;
    this_thread::sleep_for(chrono::seconds(2));
    system("clear");
  }
  else if(result == 11){
    this_thread::sleep_for(chrono::seconds(1));
    cout << RED << "\n> Invalid username and password!" << RESET<< endl;
    cout << RED << "> Try again" << RESET<<endl;
    LoginAttempt++;
    this_thread::sleep_for(chrono::seconds(2));
    system("clear");  
  }
  else if(result == 12){
    this_thread::sleep_for(chrono::seconds(1));
    cout << GREEN << "\n> Loggin in......" << RESET << endl;
    this_thread::sleep_for(chrono::seconds(2));
    system("clear");
    break;
  }

  if(LoginAttempt == 5){
    this_thread::sleep_for(chrono::seconds(1));
    cout << RED << "\n> Due to several Login attempts!" << RESET <<endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << RED << "> You are being log out...."  << RESET << endl;
    this_thread::sleep_for(chrono::seconds(1));
    exit(1);
  }  
}
}
  // end of login logics

  // this Ans function is for setters
void Ans(string QuestionTitle, int QuestionNumber, string* Answers, int AnswersSize, int currentIndex, int& correct, int& incorrect, string playerName){

    int userInputTarget;
    correct = 0;
    incorrect = 0;

    cout << "\nID: " << playerName << endl;
    cout << endl;
    cout << "|===========================================================|" << endl;
    cout << endl;
    cout <<"                          QUESTION"<< " #"<<QuestionNumber<< endl;
    cout << endl;
    cout <<"         "<<QuestionTitle<<endl;
    cout << endl;
    cout << endl;
    cout << "|===========================================================|" << endl;
    cout << endl;

    for(int i =0; i < AnswersSize; i++){
      cout << "[" << i+1 << "] " << Answers[i] << endl;
    }
    cout << endl;
    cout << "Input: ";
    cin >> userInputTarget;
    cout << endl;

    if(userInputTarget >= 1 && userInputTarget <= AnswersSize){
      if(userInputTarget - 1 == currentIndex){
      this_thread::sleep_for(chrono::seconds(1));
      cout << GREEN << "\n> You got it correct!" << RESET << endl;
      correct++;
      this_thread::sleep_for(chrono::seconds(2));
      system("clear");
      }
      else {
      this_thread::sleep_for(chrono::seconds(1));
      cout << RED << "\n> You got it wrong!" << RESET << endl;
      incorrect++;
      this_thread::sleep_for(chrono::seconds(2));
      system("clear");
      }
    }
    else {
      this_thread::sleep_for(chrono::seconds(1));
      cout << RED << "\n> Invalid answer!" << RESET << endl;
      incorrect++;
      this_thread::sleep_for(chrono::seconds(2));
      system("clear");
    }
    
};

  // disply the scores
void displayScore(int totalCorrect, int totalIncorrect){
  cout << endl;
  cout << "||=================================||" << endl;
  cout << "||                                 ||" << endl;
  cout << "||          SCORE RESULTS          ||" << endl;
  cout << "||                                 ||" << endl;
  cout << "||=================================||" << endl;
  cout << endl;

    cout << (totalCorrect <= 0 ? "You are so bad at this game!"
            : totalCorrect >= 1 && totalCorrect <= 4 ? "Try harder next time!"
            : totalCorrect == 5 ? "You got the half correct answers!"
            : totalCorrect >= 6 && totalCorrect <= 7 ? "Try a bit harder next time!"
            : totalCorrect >= 8 && totalCorrect <= 9 ? "That was so close, better luck next time :)"
            : "Congratulations, you aced it!") << endl;

  
  cout << endl;
  cout << "Total of correct answer/s: " << totalCorrect << endl;
  cout << "Total of incorrect answer/s: " << totalIncorrect << endl;
  cout << "You got: " << totalCorrect << "/10" << endl;
  cout << endl;
}

  // display the Instructions
void Instructions(){
  cout << "\n      --Before the game starts--       " << endl;
  this_thread::sleep_for(chrono::seconds(1));
  cout << endl;
  cout << "||=================================||" << endl;
  cout << "||                                 ||" << endl;
  cout << "||           INSTRUCTIONS          ||" << endl;
  cout << "||                                 ||" << endl;
  cout << "||=================================||" << endl;
  this_thread::sleep_for(chrono::seconds(1));
  cout << "\nThis quiz game consists of 10 questions." << endl;
  cout << "Please type the corresponding numbers based on your correct answer; each question has 4 choices." << endl;
  cout << "After the game, it will tally your correct and incorrect answers." << endl;
  this_thread::sleep_for(chrono::seconds(1));
  cout << "\nPlease press ENTER to proceed to the game!" << endl;
}

int main(){
  Info details;
  string ru,rp, lu, lp;
  int selection;

  cout << "\n--Welcome to the BRAIN TEASER--" << endl;
  this_thread::sleep_for(chrono::seconds(1));
  cout << "\nDo you want to play?"<<endl;
  cout << "Please type the following number options.."<<endl;
  cout << "\n[1] To play" << endl;
  cout << "[2] To exit" << endl;  
  cout << "\nInput: ";
  cin >> selection;

  switch(selection){
    case 1:
      displayForwardedMsg();
      break;
      case 2:
      displayExitMsg();
      exit(1);
      default:
      displayInvalidMsg();
      exit(1);
    }

    cin.ignore();

    // Invoke the reg and log functions  
    displayReg(ru,rp, details);
    this_thread::sleep_for(chrono::seconds(1)); 
    displayLog(lu,lp, details);
    system("clear");

  // Actual Game
  // invoke the Instructions function
  Instructions();
  string choices1[] = { "Cebu City", "Quezon City", "Davao City", "Zamboanga City" };
  string choices2[] = { "Elephant", "Popol and Kupa", "Giraffe", "Blue Whale" };
  string choices3[] = {  "10", "45", "25", "100" };
  string choices4[] = { "No", "Slightly No", "Slightly Yes", "Yes" };
  string choices5[] = { "30 hours", "10 hours", "4 hours", "1 hour" };
  string choices6[] = { "Freezing", "Burning", "Tough", "Kalayo" };
  string choices7[] = {  "A Painter", "A Carpinter", "A SecurityGuard", "A Musician" };
  string choices8[] = { "-93", "10", "-1000", "46" };
  string choices9[] = { "Good", "Lazy", "Happy", "Gambler" };
  string choices10[] = { "Mindanao", "Visayas", "Luzon", "Antartica" };
  int correct1, incorrect1, correct2, incorrect2, correct3, incorrect3,  correct4, incorrect4, correct5, incorrect5,
  correct6, incorrect6, correct7, incorrect7, correct8, incorrect8, correct9, incorrect9, correct10, incorrect10;
  cin.get(); // waiting for the user to hit ENTER
  this_thread::sleep_for(chrono::seconds(1));
  system("clear");
  this_thread::sleep_for(chrono::seconds(1));

  // after the user hit the enter -> it will proceeds to the Game

  // these are the getters
   Ans(" What is the oldest city in the philippines?", 1, choices1, 4, 0, correct1, incorrect1, lu);
   this_thread::sleep_for(chrono::seconds(1));
   Ans("    What is the largest mammal on Earth?", 2, choices2, 4, 3, correct2, incorrect2, lu);
   this_thread::sleep_for(chrono::seconds(1));
   Ans("      What is the result? (25 + 25) / 2", 3, choices3, 4, 2, correct3, incorrect3, lu);
   this_thread::sleep_for(chrono::seconds(1));
   Ans("       Is this a palindrome? RACECAR", 4, choices4, 4, 3, correct4, incorrect4, lu);
   this_thread::sleep_for(chrono::seconds(1));
   Ans("       How many hours in 240 minutes?", 5, choices5, 4, 2, correct5, incorrect5, lu);
   this_thread::sleep_for(chrono::seconds(1));
   Ans("       What is the synonyms of COLD?", 6, choices6, 4, 0, correct6, incorrect6, lu);
   this_thread::sleep_for(chrono::seconds(1));
   Ans("         Who is Vincent van Gogh?", 7, choices7, 4, 0, correct7, incorrect7, lu);
   this_thread::sleep_for(chrono::seconds(1));
   Ans("    What is the largest positive number?", 8, choices8, 4, 3, correct8, incorrect8, lu);
   this_thread::sleep_for(chrono::seconds(1));
   Ans("         What does Indolence means?", 9, choices9, 4, 1, correct9, incorrect9, lu);
   this_thread::sleep_for(chrono::seconds(1));
   Ans("What is the largest island in the philippines?", 10, choices10, 4, 2, correct10, incorrect10, lu);
   this_thread::sleep_for(chrono::seconds(1));
   system("clear");

  // after the game ends -> it will tally the scores
  int totalC = correct1 + correct2 + correct3 + correct4 + correct5 + correct6 + correct7 + correct8 + correct9 + correct10;
  int totalIC = incorrect1 + incorrect2 + incorrect3 + incorrect4 + incorrect5 + incorrect6 + incorrect7 + incorrect8 + incorrect9 + incorrect10;
  
  // invoke the displayScore function
  displayScore(totalC,totalIC);
  this_thread::sleep_for(chrono::seconds(1));
  // end of the program

  return 0;
}