# Inductions Site Backend 2020

## :one: The set of steps to follow to get the repo running in your local
1. Install golang 1.10+ 
2. Clone the repo into your local
3. cd into /internal/graph and run ```go generate```
4. Get back to the project root directory and run the following files: <br/>
  ```go run internal/database/migration/main.go```  <br/>
  ```go run cmd/backend/main.go```

## :two: Setup :house:

* In the project root directory, execute ```go get -v all```
* For the database migration, rename ```config_example.env``` to ```config.env```, populate it with required credentials and execute ```go run internal/database/migration/main.go``` in the project root. 

## :three: Creating user in mysql
* [Check this for creating user](../blob/master/LICENSE)

<!-- 1. goto mysql cli login as root using:

mysql -u root -p

2. db name: Spider_Inductions2020

CREATE DATABASE Spider_Inductions2020;

3. create a mysql user to handle this database:

CREATE USER 'spiderind2020user'@'localhost' IDENTIFIED BY 'spiderind@2020Pass';

4. grant it all permissions

GRANT ALL PRIVILEGES ON Spider_Inductions2020.\* TO 'spiderind2020user'@'localhost';

5. you can now close the cli in root mode

exit

6. Now you can login as newuser and check

mysql -u spiderind2020user -p

use password:spiderind@2020Pass

this user is used all across this project -->


## :four: Run :rocket:
* ```go run backend/main.go```
