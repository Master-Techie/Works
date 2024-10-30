from random import randint

print("Let's play the 'Guess the Number' game.\n")
print("Rule : Guess the correct 4-digit number in 5 attempts.\n")
print("Clue : Lets say the correct number is 1983 and your guess is 6937, then the clue will be shown as X '9' 3 X, since 9 is correctly placed and 3 is incoorectly placed, and the rest of your guessed digits are not present.\n")

while True:
    ques = input("Do you want to play (y/n) : ").lower()
    print()

    if ques[0] == 'y':
        ans = str(randint(1001,9999))

        guesses = 5
        correct = False

        while guesses>0:
            num = input("Enter your guess : ")

            if num == ans:
                print("Congratulations, you guessed the correct number!\n")
                correct = True
                break

            else:
                guesses -= 1

                print(f"After {5-guesses} guesses, your clues : ")

                for i in range(4):
                    if num[i] in ans:
                        if num[i] == ans[i]:
                            print(f"'{num[i]}'", end=" ")

                        else:
                            if num.count(num[i]) > ans.count(num[i]):
                                print("X", end=" ")
                            else:
                                print(f"{num[i]}", end=" ")

                    else:
                        print("X", end=" ")

                print()

        if correct == False:
            print(f"You failed to guess the correct number, {ans} !\n")

    elif ques[0] == 'n':
        break