# Qt-EmployeeMonitoring 
Coffee_boss app allows the employer to:
* Get screenshot from worker's computer at any time
* Start chat with a worker
* Make a task list for each worker

Coffee app allows the worker to:
* See tasks given by the employer
* Start chat with the employer

## Tech performance
By starting "Coffee_boss" the employer starts server to which workers may connect via "Coffee" app. If the server isn't started, worker's app waits and autoconnects when the server is available

## Starting the Coffee_boss app (employer side)
After opening app you will see list of workers who have connected

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/29f30a3e-67b6-49e6-b79c-56027b4802b6)

After choosing worker and pressing the "->" button you will see menu
![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/6ebc9755-e7f3-472d-8370-38266cbf88cf)

You may press "Get screenshot button" (Oh no, Mark is watching youtube!😡)
![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/dca0ac73-580a-492f-a581-b2127386d26f)

Or start chat with worker

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/ee3ce48b-3111-405d-9243-67536803a114)

It is also possible to set tasks

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/4ce1bc51-9639-4df4-9338-684feb87c984)


## Starting the Coffee app (worker side)
Enter your username

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/a6bf6281-d9df-4427-af94-60ff3933222b)

And press "connect button"

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/ae0de0e6-7cf5-44fa-a111-ebf979a9b978)


Chat with boss by pressing the "Chat with Boss" button

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/c781bc61-5ec9-4f1a-82b4-491f3dd54502)

## How to install my app
1) Make sure you have Qt Creator and Git CMD installed
2) Create a "git" folder on your Dekstop

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/45e6e0d7-e09b-4fd8-9c74-55246530dcb9)

3) Open Git CMD and type "git clone https://github.com/KozlovVP/Qt-EmployeeMonitoring"

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/61e41d25-c9c9-460e-aa88-9d05e867983f)

4) Copy PATH to the "git" folder on your Dekstop and type "cd \<PATH\>"

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/c53cb437-f68d-4a53-968c-b38eee295eaa)

5) Type "git clone https://github.com/KozlovVP/Qt-EmployeeMonitoring" one more time

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/791a10e3-7c2d-45fe-a63b-8081f7868549)

6) Congrats! Now you have all src files in your "git" folder

7) Open Qt Creator and press "Open project"->C:\Users\..\Desktop\git\Qt-EmployeeMonitoring\EmployeeMonitoring\EmployeeMonitoring.pro
You will see the following (src file for Coffee_boss [employer side])

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/79183998-3185-4640-8fd7-acdd0797c405)

8) Open Qt Creator and press "Open project"->C:\Users\..\Desktop\git\Qt-EmployeeMonitoring\Client\Client.pro
You will see the following (src file for Coffee [worker side])

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/1b12ee4c-9053-4d1b-b2cc-be8aeee18f79)


