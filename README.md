##Information

This doc will include information on the things I have learned while developing this clone. No outside help is being used, there is
one specific turotial that uses SDL to build a galaga clone and it is my goal not to use them for help. Every time I feel I learn
something useful I will record it here.

##Finite State Machines
These are basically a way to structure your code in game development. It allows me to use object oriented programming to its fullest
capabilities. For this project I can split the different modes of the game into states. For this project the modes I will implement
are main menu, game, game over. The game state will have its own array of states, each one being its own unique level. Not sure how I
will be generating these levels that will have to be figured out at a different time. Each of my characters will also have a finite
state machine associated with their state in the world. My hope is that I can render their entry state, idle state, attack state, and
death state, animating them all seperately. should be a fun process.

##Delta Time
While researching framerate I came upon the problem of different framerates on different machines. If I am to be moving items, I need
to account for times when frame rate might dip. So instead of moving my entities pixels per frame, I move them in pixels per second.
The equation for this would look something like this:

float deltaTime = (SDL_GetTicks() - pastCount) / 1000.0f;
pastCount = SDL_GetTicks();

What this code does is takes the current tick count and subtracts it by the past count, then divides it by 1000. The end calculation
is the amount of time that has passed since the last frame in seconds. So now, every time I move a character I need to multiply by
this deltaTime value. So "X \* deltaTime" translates to X pixels moved per second. For this project I am going to try making deltaTime
a global variable. Maybe this approach is wrong we will find out.

##Background Generation Brainstorming
When looking at emulators of galaga it looks like the stars blink in and out, not all at the same time though. It looks like there are 4
different times every second that a star can blink in out out, so either I need to make 4 sheets of random stars that blink in and out at
seperate times, or I need to modulate it and make a star class, within the star class I would have a color, x and y pos. I would then 
randomly generate a value that determines when they blink in or out. I like this approach more :). Will try this one out later.

#March 16, 2023

##Background Generation
This took me way longer than I thought it would. My first approach was to modulate the background by having an array of stars. Each star
had its own texture associated with it. I quickly figured out that I should store my textures in my background structure, and then just
pass a pointer to the correct texture in the constructor. This solved most of my issues. My approach was to randomly generate 100 stars
25 of each possible color. I also assigned 4 possible speeds to each star. So some stars more faster and some dont. This creates almost
the exact effect I am looking for. The last thing I need to do is blink the stars which I will work on tomorrow.

##Memory Leaks
A quick update on what I learned about memory leaks today. In C++ you only have a memory leak when you do not call DELETE on an object you
called NEW on. Any variable that you do not call new on should its constructor called automatically after the object is out of scope. So 
when I create a new class, I only need a destructor if I NEW something. However, most online sites recommend calling the destructor on 
custom objects just to be safe. They also recommend setting any pointers I used to NULL. I had a question about wether I should be calling
DELETE on pointers that I never call new on. For example:

myptr = thisptr

In this example I never call new when setting myptr. Online they told me I should not be calling DELETE on this pointer as it might crash
my program if other parts of my program use "thisptr". But they recommended setting the "myptr" to NULL in my destructor so that is what I
will be doing in the future.


