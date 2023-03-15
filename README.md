#Information

This doc will include information on the things I have learned while developing this clone. No outside help is being used, there is
one specific turotial that uses SDL to build a galaga clone and it is my goal not to use them for help. Every time I feel I learn
something useful I will record it here.

#Finite State Machines
These are basically a way to structure your code in game development. It allows me to use object oriented programming to its fullest
capabilities. For this project I can split the different modes of the game into states. For this project the modes I will implement
are main menu, game, game over. The game state will have its own array of states, each one being its own unique level. Not sure how I
will be generating these levels that will have to be figured out at a different time. Each of my characters will also have a finite
state machine associated with their state in the world. My hope is that I can render their entry state, idle state, attack state, and
death state, animating them all seperately. should be a fun process.

#Delta Time
While researching framerate I came upon the problem of different framerates on different machines. If I am to be moving items, I need
to account for times when frame rate might dip. So instead of moving my entities pixels per frame, I move them in pixels per second.
The equation for this would look something like this:

float deltaTime = (SDL_GetTicks() - pastCount) / 1000.0f;
pastCount = SDL_GetTicks();

What this code does is takes the current tick count and subtracts it by the past count, then divides it by 1000. The end calculation
is the amount of time that has passed since the last frame in seconds. So now, every time I move a character I need to multiply by
this deltaTime value. So "X \* deltaTime" translates to X pixels moved per second. For this project I am going to try making deltaTime
a global variable. Maybe this approach is wrong we will find out.

#Background Generation Brainstorming
When looking at emulators of galaga it looks like the stars blink in and out, not all at the same time though. It looks like there are 4
different times every second that a star can blink in out out, so either I need to make 4 sheets of random stars that blink in and out at
seperate times, or I need to modulate it and make a star class, within the star class I would have a color, x and y pos. I would then 
randomly generate a value that determines when they blink in or out. I like this approach more :). Will try this one out later.

