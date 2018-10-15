# FDF
# Introduction

The representation in 3D of a landscape is key in modern mapping. For example, in these times of spatial exploration, to have a 3D representation of Mars is prerequisite condition to the conquest of this planet. As another example, comparing various 3D representations of a zone where tectonic activities are important will allow you to bet- ter understand these phenomenon and their evolution, allowing you to be better prepared.

It’s your turn today to practice this and modelize in 3D some magnificent landscapes, imaginary or not...

# Objectives

You will discover in this project the bases of graphic programming, and in particular how to place points in space, how to join them with segments and mostly how to observe the scene from a particular point of view.

You will also discover your first graphic library: miniLibX This library developed internally musters the minimum necessary to open a window, light a pixel and deal with events linked to this window: keyboard, mouse and “expose”. It will be for you an opportunity to begin a programming “events”. Do not forget to watch the videos available in e–learning!

# General Instructions

• You must submit a Makefile.

• Your Makefile will have to compile the project and must contain the usual rules. It can only recompile the program if necessary.

• If you are clever, you will use your library for you fdf, submit also your folder libft including its own Makefile at the root of your repository. Your Makefile will have to compile the library, and then compile your project.

• You cannot use global variables.

• Your project must be written in accordance with the Norm.

• You have to handle errors in a sensitive manner. In no way can your program quit in an unexpected manner (Segmentation fault, bus error, double free, etc).

• You’ll have to submit at the root of your folder, a file called author containing your username followed by a ’\n’

  $>cat -e author
  xlogin$
• You must use miniLibX. Either in the version that is in available on the system, or from its sources. If you choose to work from the sources, you will need to apply the same rules for your libft as those written above.

• Within your mandatory part, you are allowed to use the following functions:

  ◦ open
  
  ◦ read
  
  ◦ write
  
  ◦ close
  
  ◦ malloc
  
  ◦ free
  
  ◦ perror
  
  ◦ strerror 
  
  ◦ exit
  
  ◦ All the functions defined in the library math (-lm et man 3 math) 
  
  ◦ All the functions defined in the library miniLibX.
  
• You are allowed to use other functions to carry out the bonus part as long as their use is justified during your defence. Be smart!

• You can ask your questions on the forum.

# Mandatory part

This project is about creating a simplified graphic “wireframe” (“fils de fer” in french) representation of a relief landscape linking various points (x, y, z) via segments. The coordinates of this landscapte will be stocked in a file converted in parameters, here is an example:

      $>cat 42.fdf
  
      0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  
      0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  
      0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
  
      0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
  
      0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
  
      0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
  
      0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
  
      0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
  
      0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
  
      0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  
      0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
  
      $>
  

Each number corresponds to a point in space:
• The horizontal position corresponds to its axis. 

• The vertical position corresponds to its ordinate. 

• The value corresponds to its altitude.


Remember to exploit your libft! The use of get_next_line, ft_split and ft_getnbr will allow you to quickly and simply read the data from the file.

Regarding the graphic representation:

• You can choose the type of projection: parallel, iso, conic.

• You must manage expose correctly.
• You must be able to quit the program by pressing ’esc’.
• The use of images from minilibX is strongly encouraged.
• You will find in the subject’s attachements files related to the topic (a binary called fdf as well as the example 42.fdf inside fdf.zip).

# Bonus part

Here are a few interesting ideas of bonuses to create, or even to use. You can of course add your own original bonuses that will then be evaluated directly by your correctors.
• Fill in the boxes with a color according to altitude (green at the bottom, then brown, then white on top for ex.)
• Able to specify in parameter a spectrum of color.
• Correct management of hidden faces.
• Able to change these type of projections.
