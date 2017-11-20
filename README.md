# DotLibrary
A simple visualization library

**Dependencies:**
SDL2 library
Visual Studio

## SDL2 Installation:
#### Download Package
1. Download the library via SDL's own website:
https://www.libsdl.org/download-2.0.php
Scroll down to "Development Libraries" and choose: 
Visual C++

#### Create folders
2. Now go into your project folder. At the same place where your [.sln] is create a new directory.
The name of the folder is optional but here it's called "deps" for short.
Extract your downloaded SDL2 package.
Navigate inside the SDL2 package to the "include" folder and drag it inside "deps".
Open the "lib" file in the package, depending on your system chose either 64bit(x64) or 32bit(x86).
Create a new folder inside "deps" called "lib" and drag all [.lib] files to that position.
Notice that there [.dll] file left. Drag this one to your output file, if you don't have one, run your code once and it will be automatically created.

#### Link library
DotLibrary Installation:
