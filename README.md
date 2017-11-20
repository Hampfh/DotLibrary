# DotLibrary
A simple visualization library

##### Dependencies:
* SDL2 library
* Visual Studio

## SDL2 Installation:
#### 1. Download Package
Download the library via SDL's own website:
https://www.libsdl.org/download-2.0.php
Scroll down to "Development Libraries" and choose: 
**Visual C++**

#### 2. Create folders
1. Now go into your project folder. At the same place where your [.sln] is create a new directory.
The name of the folder is optional but here it's called **"deps"**. _**Note:** if you name your folder something else remember to stick with that. Change **deps** to whatever you've called your file._

2. Extract your downloaded SDL2 package.
3. Navigate inside the SDL2 package to the "include" folder and drag it inside "deps".
4. Open the "lib" file in the package, depending on your system chose either 64bit(x64) or 32bit(x86).
Create a new folder inside **"deps"** called **"lib"** and drag all [.lib] files to that position.
5. Notice that the [.dll] file left. Drag this one to your output file, if you don't have one, run your code once and it will be automatically created.

#### 3. Link library
1. Open your project in visual studio. 
2. Navigate to **Project->Properties**. 
3. Click **VC++ Directories**. 
4. Open **Include libraries** and add _$(SolutionDir)**deps**/include/_ in the upper bar. 
5. Do exactly the same thing for **Library Directories** but instead insert _$(SolutionDir)**deps**/lib/_
6. Now locate to **Linker->Input** and open **Additional Dependencies**. Now paste **SDL2.lib** click enter and paste **SDL2main.lib**.
## DotLibrary Installation:
