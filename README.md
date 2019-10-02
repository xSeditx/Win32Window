
Native Win32 Window Handler.

Messages are handled with all inputs being stored in a static singleton struct called input. 

List of things finished and those that need to be implemented X denotes complete

 WINDOW
========
~ INPUT
 =======
 - MOUSE  [ X ]
  =======
  - Position         [ x ]
  - Relative         [ x ]
  - Buttons          [   ]
 				     
 ~ KEYBOARD [ X ]     
  ==========	     
  - Keys[]           [ x ]
  - KeyDown          [ x ]
  - KeyUp            [ x ]
				     
~ EVENTS		     
 ========		     
 - Window Close      [   ]
 - GUI Events        [   ]


 Create GUI Elements [  ]
 GUI Management      [  ]



 --9/30/2019
 Begun work on a simple fat free replacement for GLFW and other Window management libraries in favor of pure Win32 API. Basically just need Input managed and stored into a Singleton struck and a Pub/Sub setup to handle the rest.
 The entire system will be base around an Application class which will by default create a standard window with default openGL context however all these parameters can be changed if one so desires. All is derivable and changable in the Users derived class however if they chose not to all defaults will still do what is needed to be done.

 A Listener class is implemented into the event system so that the use can define a Windows message they wish to subscribe to then furthermore set a response function in the event that the desired message was triggered by Windows.

 --10/2/2019 2:58am
 Finished work the Window currently only renders when glFlush() is called. This likely is due to double buffering not being properly implemented although it should be on by default in Windows.
 glDrawArrays is not throwing any errors however I also do not have any shaders active so I am doubtful it could render at all given that I am using OpenGL 4.6. I believe that would be impossible but I have seen stranger things.