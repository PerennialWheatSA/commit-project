#include <thread>
#include <iostream>
#include <vector>

// commit info
int amountOfCommitsNeeded;
int currentAmountOfCommits = 1;

void Printer() {
  
  //starts while loop for commits
  while (currentAmountOfCommits < amountOfCommitsNeeded) 
  {
    // the command being executed
    std::string str = "git commit --allow-empty -m \"Commit " + std::to_string(currentAmountOfCommits) + " out of " + std::to_string(amountOfCommitsNeeded) + "\"";
    
    // coverting the command to a c string and exeuting it
    system(str.c_str());

    // adding +1 to the amount of commits
    currentAmountOfCommits++;

  }
}


int main() {
  // asks for amount of commits
  std::cout << "Enter Amout Of Commits: ";
  std::cin >> amountOfCommitsNeeded;

  //asks for amount of threads
  std::cout << "Enter Amout Of Threads: ";
  int threadAmount;
  std::cin >> threadAmount;
  
  // creates array for threads and joins the threads
  std::vector<std::thread> ThreadContainer;
  for (int i = 0; i < threadAmount; i++) ThreadContainer.push_back(std::thread(Printer)); // adds values to array
  for (int i = 0; i < ThreadContainer.size(); i++) ThreadContainer[i].join(); // joins threads
  
  // print result
  std::cout << "Done! The Final Result: " << currentAmountOfCommits << std::endl;
  
  return 0;
}