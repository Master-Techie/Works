import pygame
import random
pygame.init()

#Screen Dimensions
screen_width = 900
screen_height = 600

#Creating a Window
gameWindow = pygame.display.set_mode((screen_width, screen_height))

#Setting title of Window
pygame.display.set_caption("Snake Game")
pygame.display.update()


font = pygame.font.SysFont(None, 50)
def score_on_screen(text, color, x, y):
    screen_text = font.render(text, True, color)
    gameWindow.blit(screen_text, [x,y])

def plot_snake(gameWindow, color, snake_list, snake_size):
    for x,y in snake_list:
        pygame.draw.rect(gameWindow, color, [x, y, snake_size, snake_size])

def gameloop():
        
    #Colours
    light = (120, 120, 255)
    red = (255, 0, 0)
    black = (0, 0, 0)

    #Game specific variables
    exit_game = False
    game_over = False

    snake_x = 0
    snake_y = 50

    vel_x = 0
    vel_y = 0
    init_velocity = 10

    margin = 50

    food_x = random.randrange(margin, screen_width - margin, 10)
    food_y = random.randrange(50 + margin, screen_height - margin, 10)

    snake_size = 10
    score = 0

    clock = pygame.time.Clock()
    fps = 30

    snake_list = []
    snake_length = 1

    while not exit_game:
        if game_over:
            gameWindow.fill(light)
            
            score_on_screen(f"Score : {score}", red, screen_width/4 + 150, screen_height/2 - 50)
            score_on_screen("KO! Press Enter to Continue.", red, screen_width/4, screen_height/2)

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    exit_game = True

                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_RETURN:
                        gameloop()

        else: 
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    exit_game = True

                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_RIGHT:
                        vel_x = init_velocity
                        vel_y = 0

                    if event.key == pygame.K_LEFT:
                        vel_x = -init_velocity
                        vel_y = 0

                    if event.key == pygame.K_DOWN:
                        vel_y = init_velocity
                        vel_x = 0

                    if event.key == pygame.K_UP:
                        vel_y = -init_velocity
                        vel_x = 0

            snake_x += vel_x
            snake_y += vel_y

            if (snake_x == food_x) and (snake_y == food_y):
                score += 1
                food_x = random.randrange(margin, screen_width - margin, 10)
                food_y = random.randrange(50 + margin, screen_height - margin, 10)
                snake_length += 1

            gameWindow.fill(light)
            score_on_screen(f"Score : {score}", black, 0, 0)
            pygame.draw.rect(gameWindow, red, [food_x, food_y, snake_size, snake_size])

            head = []
            head.append(snake_x)
            head.append(snake_y)
            snake_list.append(head)

            if len(snake_list) > snake_length:
                del snake_list[0]

            if (snake_x < 0) or (snake_x < 0) or (snake_x < 0) or (snake_x < 0):
                game_over = True

            plot_snake(gameWindow, black, snake_list, snake_size)

        pygame.display.update()
        clock.tick(fps)

    pygame.quit()
    quit()

gameloop()