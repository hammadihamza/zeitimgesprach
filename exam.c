/*
 * This is a simple German Time Quiz (Umgangssprache).
 * The program picks a random colloquial German time.
 * The user has to choose the correct digital time from 3 options.
 * The program will tell the user if their choice is correct or not.
 */

// We need these "include" lines to use functions for:
// stdio.h  - Standard Input/Output (like printf and scanf)
// stdlib.h - Standard Library (for rand and srand)
// time.h   - Time functions (for seeding the random number)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The main function is where every C program starts
int main() {

    // --- 1. Declare Variables ---
    // We declare all the variables we will need at the top.

    int userChoice;         // The number the user types in (1, 2, or 3)
    int score = 0;          // To count how many correct answers the user has
    int questionIndex;      // The index number of the question we pick
    
    // We can use a number as a "flag" to track if the game is running.
    // 1 will mean true (the game is running)
    // 0 will mean false (the user wants to quit)
    int gameIsRunning = 1;

    // --- 2. Define the Questions ---
    
    // We use an array of strings (char*) to hold the time phrases.
    // The \n at the start makes the formatting look nice.
    char* sentences[] = {
        "\nEs ist fünf vor halb zwölf.\n  (1) 11:25, (2) 11:35, (3) 12:25",
        "\nEs ist Viertel nach drei.\n  (1) 3:45, (2) 3:15, (3) 2:45",
        "\nEs ist halb zehn.\n  (1) 10:30, (2) 9:30, (3) 8:30",
        "\nEs ist zehn vor acht.\n  (1) 8:10, (2) 7:40, (3) 7:50",
        "\nEs ist zwanzig nach eins.\n  (1) 1:20, (2) 1:40, (3) 12:40",
        "\nEs ist fünf nach halb sieben.\n  (1) 6:25, (2) 6:35, (3) 7:35",
        "\nEs ist Viertel vor elf.\n  (1) 10:45, (2) 11:15, (3) 11:45",
        "\nEs ist fünf nach eins.\n  (1) 1:05, (2) 12:55, (3) 2:05",
        "\nEs ist zwanzig vor vier.\n  (1) 4:20, (2) 3:40, (3) 3:20",
        "\nEs ist ein Uhr.\n  (1) 1:00, (2) 10:00, (3) 11:00",
        "\nEs ist kurz vor sechs.\n  (1) 6:02, (2) 5:58, (3) 5:50",
        "\nEs ist kurz nach halb zwei.\n  (1) 1:28, (2) 2:32, (3) 1:32",
        "\nEs ist fünf vor zwölf.\n  (1) 12:05, (2) 11:55, (3) 12:25",
        "\nEs ist zehn nach elf.\n  (1) 11:10, (2) 10:50, (3) 11:20",
        "\nEs ist drei Uhr.\n  (1) 3:00, (2) 12:03, (3) 3:03"
    };
    
    // This array holds the correct answer number for each sentence.
    // So, solutions[0] (which is 1) is the answer for sentences[0].
    // solutions[1] (which is 2) is the answer for sentences[1].
    // ...and so on.
    int solutions[] = {
        1,  // 11:25
        2,  // 3:15
        2,  // 9:30
        3,  // 7:50
        1,  // 1:20
        2,  // 6:35
        1,  // 10:45
        1,  // 1:05
        2,  // 3:40
        1,  // 1:00
        2,  // 5:58
        3,  // 1:32
        2,  // 11:55
        1,  // 11:10
        1   // 3:00
    };

    // We calculate the number of questions by the size of the array.
    int num_questions = sizeof(sentences) / sizeof(sentences[0]);

    // --- 3. Seed the Random Number Generator ---
    
    // "Seed" the random number generator.
    // This makes sure we get a different "random" question
    // every time we run the program.
    // Using time(0) seeds it with the current second.
    srand(time(0));

    // --- 4. Start the Game ---
    
    printf("Welcome to the German Time Quiz!\n");
    printf("I will show you a time in German (Umgangssprache).\n");
    printf("You just type the number (1, 2, or 3) for the correct digital time.\n");

    // --- 5. The Main Game Loop ---
    
    // We use a "while" loop to keep asking the user questions.
    // The loop will continue as long as the gameIsRunning flag is 1 (true).
    while (gameIsRunning == 1) {
        
        // --- 5a. Pick a Random Question ---
        
        // Get a random number.
        // rand() % num_questions gives a number between 0 and (num_questions - 1).
        questionIndex = rand() % num_questions;

        // --- 5b. Show Question and Get Input ---
        
        // Print the sentence that matches the random index number
        printf("%s\n", sentences[questionIndex]);
        
        printf("Enter your choice (1, 2, or 3): ");
        
        // Get the user's input and store it in the userChoice variable.
        // The "&" is important, it tells scanf WHERE to put the number.
        scanf("%d", &userChoice);
        
        // This 'while' loop clears any extra characters the user typed.
        // It reads characters until it finds the 'Enter' key ('\n').
        while (getchar() != '\n');

        // --- 5c. Check the Answer ---
        
        // Check if the user's choice matches the solution
        if (userChoice == solutions[questionIndex]) {
            printf("Richtig! (Correct!)\n");
            // Add 1 to the score
            score = score + 1;
        } 
        // If the guess is wrong
        else {
            printf("Falsch! (Wrong!)\n");
            // We find the correct answer from the solutions array
            int correct_answer = solutions[questionIndex];
            printf("The correct answer was number %d.\n", correct_answer);
        }
        
        printf("Your score: %d\n", score);
        
        // --- 5d. Ask to Play Again ---
        
        printf("\nDo you want to continue?\n");
        printf("Enter 1 for Yes, or 0 for No: ");
        scanf("%d", &gameIsRunning);
        
        // Clear the input buffer again
        while (getchar() != '\n');
        
    } // The loop ends here if the user enters 0

    // --- 6. End of Game ---
    
    // This code runs after the loop has finished.
    printf("\n----------------------------------------\n");
    printf("Thanks for playing!\n");
    printf("Your final score was: %d\n", score);
    printf("Auf Wiedersehen!\n");

    // Tell the operating system that the program finished successfully
    return 0; 
}
