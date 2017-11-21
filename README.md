# DotLibrary
A simple visualization library

##### Dependencies:
* SDL2 library
* Visual Studio

## SDL2 Installation:
#### 1. Download Package
  1. Download the library via SDL's own website:
   https://www.libsdl.org/download-2.0.php
  2. Scroll down to "Development Libraries" and choose: 
   **Visual C++**

#### 2. Create folders
  1. Now go into your solution directory (where your [.sln] file is).
Create a folder in the directory, the name of the folder is optional but we call it **"deps"**. 
     * _**Note:** If your folder name is something else then remember to stick with that. Change every **deps** to whatever you've called your file._

  2. Extract your downloaded SDL2 package.
  3. Navigate inside the SDL2 package to the _"include"_ folder and drag folder (with it's content) inside **deps**.
  4. Open the _"lib"_ file in the package, depending on your system choose either 64bit(x64) or 32bit(x86).
Create a new folder inside **"deps"** called **lib** and drag all [.lib] files to that position.
  5. Notice that the [.dll] file left. Drag this one to your code output file (same folder as your [.exe] file), if you don't have one, run your code once and it will be automatically created. 

#### 3. Link library
  1. Open your project in visual studio. 
  2. Navigate to **Project->Properties**. 
  3. Click **VC++ Directories**. 
  4. Open **Include libraries** and add [_$(SolutionDir)**deps**/include/_] in the upper bar. 
  5. Do exactly the same thing for **Library Directories** but instead insert [_$(SolutionDir)**deps**/lib/_]
  6. Now locate **Linker->Input** and open **Additional Dependencies**. Now paste **SDL2.lib** click enter and paste **SDL2main.lib**.
     * **Note:** Don't forget to click **OK** when you leave this window.
  7. Lastly locate **Linker->System** open **SubSystem** and choose **Console (/SUBSYSTEM:CONSOLE)**.

## DotLibrary Installation:
#### 1. Download Package
  1. Find the DotLibrary download via github on the link bellow: https://github.com/Hampfh/DotLibrary/releases
  2. Download the latest version of _DotLibrary.zip_

#### 2. Add library
  1. Locate **DotLibrary->include** and drag all it's content inside **deps->include**
  2. Locate **DotLibrary->lib** and drag the it's content inside **deps->lib**

#### 3. Link library
  1. Open your project in visual studio. 
  2. Navigate to **Project->Properties**. 
  3. Now locate **Linker->Input** and open **Additional Dependencies**. On a new line add **DotLibrary.lib**.
     * **Note:** Don't forget to click **OK** when you leave this window.
