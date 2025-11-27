Welcome to Time Cop!


This is a 2D beat ‘em up style game where you sidescroll and detain people and creatures that are escaping their time period.


In the game’s current start you can walk left and right with A and D, you can jump with space, and rewind time with R. We have plans for adding mappable buttons later on in development. Currently, you can walk into power ups to claim them and walk into enemies to slay them.


# Progress for Final Submission (Nov 27th)
## Art Disclaimer
Since the time of the last course project progess report, Jacob Coleman has left the class and therfore left my team. However, I have received explicit permission from Jacob regarding the art assets he made for the project and have been allowed to showcase/use his work for this project.

## Improvements since last submission
Since last submission of the course project, more gameplay elements have been added to the prototype. The player is now able to attack and defeat enemies through the use of a proper attack function, thus allowing players to actually beat up enemies rather than simply colliding into them to defeat them. Furthermore, the Rewind mechanic has been properly implemented with the use of Command-based movement inputs. The player, with the press and holding of a button, begin to rewind their player character, choosing to hold it for however long they can and rewinding their position by undoing each executed command and rewinding to their previous position. The Rewind mechanic stores both the commands and location data of the player up to past last 5 seconds.

There was also some downsizing to the project, as with only one person in the team, there was not as much work that was required, thus the previously promised Mappable Buttons have been abandoned entirely in favor of Command-based inputs and th Rewind mechanic.

Also, for explanations regarding the other design patterns implemented (singleton, factory, command) please look at the previous progress report submission.

Attack blueprint:
<img width="1215" height="402" alt="image" src="https://github.com/user-attachments/assets/afde3f55-cc07-473a-9a6d-1b2ed9873772" />

Completed Time Mechanic:
<img width="1395" height="596" alt="image" src="https://github.com/user-attachments/assets/3f934891-5727-4101-ba11-c0f58a8470bf" />

## Optimization with Dirty Flag Pattern and Observer Pattern
I have utilized for the purpose of optimization, a Dirty Flag design pattern. The way this pattern has been utilized is that we check for the change in a variable for every frame that passes. Specifically we check for the isRewinding? variable to detect if the player has begun to rewind time with the time mechanic, and only if the player has begun rewinding time (thus setting he isRewinding? variable to true) can a different event be called. By doing this, we save on frames, as the alternative would be to call this event during every frame. This event called by the Dirty Flag is also connected to our Observer and State Machine, as when the event is called by our Dirty Flag, it can only be fired off if the Observer notices a change in the Player's states. These changes in the player states are also called when there are changes done to our isRewinding? variable. Our Observer pattern operates off of an enum of different states, these states being a player's state when rewinding and when not rewinding. Once a change in states happens in the enum, our Notified event is called and allows for the generation of visual effects to showcase that the Player is in fact rewinding (a simple grain filter is applied ot the screen as long as the player is acitvely rewinding).

Dirty Flag blueprint (circled in red) + Observer watching for changes (everything else):
<img width="1371" height="526" alt="Screenshot 2025-11-27 153737" src="https://github.com/user-attachments/assets/067b9f04-472a-400f-91b5-6a582ca94fc2" />

Observer's States being changed:
<img width="1135" height="386" alt="Screenshot 2025-11-27 154642" src="https://github.com/user-attachments/assets/67a998e5-46d2-41ce-b177-109314529c9e" />

Performace Profiling:
When our performance profiling was done with Unreal Insights, all major lag spikes were caused entirely by the PostProcessing effects of motion blur and grain added to our camera upon starting a rewind. Thus saving processing power by allowing the player to not consume processing power with game logic and only putting any strain on hardware through mere visual effects (as those are simpler to deal with than unoptimized game logic).

Screenshot of Unreal Insights, with each major spike being the render time for post-processng effects with a render time duration of a few milisenconds:
<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/ff50318f-e8ca-4d91-8be6-d9cb232d52aa" />

## Video Report
The entirety of my video report is in the form of this unlisted YouTube video: https://youtu.be/1jhVxDEL0JE 
