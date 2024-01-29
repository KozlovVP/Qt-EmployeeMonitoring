# Qt-EmployeeMonitoring 
Приложение Coffee_boss позволяет работодателю:
* Получить скриншот с компьютера работника в любое время
* Открыть чат с работником
* Написать список заданий и отправить его работнику

Приложение Coffee позволяет работнику:
* Видеть задания, отправленные работодателем
* Открыть чат с работодателем

## Техническое исполнение
Приложение работодателя Coffee_boss представляет собой TCP-сервер. При запуске приложения работодатель запускает сервер, к которому могут подключиться работники. 

Если сервер еще не запущен, то приложение работника Coffee ждет возможности подключиться и автоматически
подключается, когда появляется возможность.

## Запуск приложения Coffee_boss (приложение для работодателя)
После запуска приложения вы увидите список работников, которые уже подключились

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/29f30a3e-67b6-49e6-b79c-56027b4802b6)

После выбора номера работника и нажатия на "->" вы увидите меню
![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/6ebc9755-e7f3-472d-8370-38266cbf88cf)

Вы можете кликнуть на кнопку "Get Screenshot" (Mark сейчас использует Google)
![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/c9ea9480-9e66-46a0-a95c-ae0760420769)

Или начать чат с работником, кликнув на "Start Chat"

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/df56da1f-0829-4f12-90c4-59f0735ea4d9)

Также можно давать задания работнику, нажав на "Change Tasks"

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/e1769b3f-1913-4ce8-babb-a5ad76f3d21f)



## Starting the Coffee app (приложение для работника)
Введите ваше имя и нажмите на "connect"

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/a6bf6281-d9df-4427-af94-60ff3933222b)

Перед вами откроется окно с заданиями

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/44ac51f9-52c2-4b37-80e1-55f2b834ed9e)

Вы можете начать чат с работодателем, нажав на "Chat with Boss" 

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/faea0153-6652-444a-a375-d70b1103416d)


## Как установить мое приложение
1) Удостоверьтесь, что у вас установлены Qt Creator и Git CMD 
2) Создайте папку "Git" на рабочем столе

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/45e6e0d7-e09b-4fd8-9c74-55246530dcb9)

3) Откройте Git CMD и введите "git clone https://github.com/KozlovVP/Qt-EmployeeMonitoring"

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/61e41d25-c9c9-460e-aa88-9d05e867983f)

4) Скопируйте PATH к папке "git", которую вы создали, и введите "cd \<PATH\>"

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/c53cb437-f68d-4a53-968c-b38eee295eaa)

5) Введите "git clone https://github.com/KozlovVP/Qt-EmployeeMonitoring" повторно

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/791a10e3-7c2d-45fe-a63b-8081f7868549)

6) Теперь все файлы программы находятся в папке "git"

7) Откройте Qt Creator, нажмите на "Open project"->C:\Users\\..\Desktop\git\Qt-EmployeeMonitoring\EmployeeMonitoring\EmployeeMonitoring.pro
Вы увидите исходные файлы приложения Coffee_boss

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/79183998-3185-4640-8fd7-acdd0797c405)

8) Откройте Qt Creator, нажмите на "Open project"->C:\Users\\..\Desktop\git\Qt-EmployeeMonitoring\Client\Client.pro
Вы увидите исходные файлы приложения Coffee

![image](https://github.com/KozlovVP/Qt-EmployeeMonitoring/assets/114473389/1b12ee4c-9053-4d1b-b2cc-be8aeee18f79)

Спасибо за установку!
