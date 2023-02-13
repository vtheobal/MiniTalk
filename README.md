<h1 align="center">
	:busts_in_silhouette: MiniTalk
</h1>

#### Целью этого проекта является создание двух исполняемых файлов: сервера и клиента.

#### - Клиент будет отправлять информацию (строку) на сервер, используя сигналы UNIX.

#### - Сервер должен правильно получить и интерпретировать эту информацию, а затем отобразить ее.

#### Makefile используется для простой компиляции исполняемых файлов сервера и клиента.

### Tutorial:

1) Запустите исполняемый файл сервера, чтобы получить идентификатор (pid) своего процесса:
![](images/server_start.png)

2) Запустите клиент с идентификатором процесса, полученного от сервера, чтобы отправлять текст на сервер.
![](images/client_base.png)

3) Сервер получает биты, содержащие информацию, переводит их в символы и выводит результат в терминале:
![](images/server_base.png)

