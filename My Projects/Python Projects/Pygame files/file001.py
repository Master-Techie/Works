import pygame
pygame.init()

#Initializing the game window.
gameWindow = pygame.display.set_mode((300, 200))

#Sets the title of the game window.
pygame.display.set_caption("Game 1")

#Boolean variable to check if the game is over or not.
game_over = False

#Boolean variable to turn off the game.
exit_game = False

#Creating game loop
while not exit_game:

    #Handling all events
    for event in pygame.event.get():

        #Quit event
        if event.type == pygame.QUIT:
            exit_game = True

        #"Right arrow key pressed down" event
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_RIGHT:
                print("Right arrow key pressed down.")

#Quits the application.
pygame.quit()
quit()